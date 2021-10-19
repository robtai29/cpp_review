#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>

template <class Item>
class graph{
    private:
        inline static const MAX_VERTICES = 20;
        vector<Item> vertices;
        vector<vector<int>> adjacencyList;
    public:
        graph();
        void add_vertex(const Item& label);
        void add_edge(int from, int to);
        void remove_edge(int from, int to);
        std::size_t size() const;
        bool is_edge(std::size_t, std::size_t) const;
        Item operator[](int index);  
};

    