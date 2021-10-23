#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
#include <cassert>

template <class Item>
class graph{
    private:
        inline static const int MAX_VERTICES = 20;
        std::vector<Item> vertices;
        std::vector<std::set<int>> adjacencyList;

        void dfsTraversal(std::vector<std::vector<int>>&paths, std::vector<int>path, 
                            std::vector<bool>& seen, int start);
    public:
        graph() {}
        void add_vertex(const Item& label);
        void add_edge(int from, int to);
        bool remove_edge(int from, int to);
        int size() const;
        bool is_edge(int from, int to) const;
        Item operator[](int index);
        void printPaths(int start);
};

    template <class Item>
    void graph<Item>::add_vertex(const Item& label){
        if (vertices.size() < MAX_VERTICES){
        vertices.push_back(label);
        adjacencyList.push_back(std::set<int>());
        }
    }

    template <class Item>
    void graph<Item>::add_edge(int from, int to){
        if (to >= 0 && to < adjacencyList.size() && from >= 0 && from < adjacencyList.size()){
            adjacencyList[from].insert(to);
        }else{
            throw std::invalid_argument("out of range");
        }
    }

    template <class Item>
    bool graph<Item>::remove_edge(int from, int to){
        if (adjacencyList.size() > from && adjacencyList[from].count(to) != 0){
            adjacencyList[from].erase(to);
            return true;
        }
        return false;

    }

    template <class Item>
    int graph<Item>::size() const{
        
        return vertices.size();
    }

    template <class Item>
    bool graph<Item>::is_edge(int from, int to) const{
         if (to >= 0 && to < adjacencyList.size() && from >= 0 && from < adjacencyList.size()){
            return adjacencyList[from].count(to) > 0;
        }
        return false;
    }

    template <class Item>
    Item graph<Item>::operator[](int index){
        return vertices[index];
    }
    
    template <class Item>
    void graph<Item>::printPaths(int start){
        std::vector<std::vector<int>> paths;
        std::vector<bool> seen(vertices.size(), false);
        std::vector<int> path;
        dfsTraversal(paths, path, seen, start);
        
        for (const auto& vect : paths){
            int i;
            for (i = 0; i < vect.size() -1; i++){
                std::cout << vect[i] << " -> ";
            }
            std::cout << vect[i];
            std::cout << std::endl;
        }

    }

    template <class Item>
    void graph<Item>::dfsTraversal(std::vector<std::vector<int>>&paths, std::vector<int>path, 
        std::vector<bool>& seen, int start){
            path.push_back(start);

            if (adjacencyList[start].size() == 0){
                paths.push_back(path);
                return;
            }

            if (seen[start] == true){
                paths.push_back(path);
                return;
            }

            seen[start] = true;

            for (auto itr = std::begin(adjacencyList[start]); itr != std::end(adjacencyList[start]); itr++){
                dfsTraversal(paths, path, seen, *itr);
            }

        }