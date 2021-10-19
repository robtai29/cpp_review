#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <set>


template <class Item>
class graph{
    private:
    inline static const int MAX_VERTICES = 20;
    bool matrix[MAX_VERTICES][MAX_VERTICES]{};
    std::size_t num_vertices;
    Item vertices[MAX_VERTICES];

    public:
    graph();
    void add_vertex(const Item& label);
    void add_edge(size_t from, size_t to);
    std::size_t size() const;
    bool is_edge(std::size_t, std::size_t) const;
    Item operator[](std::size_t);
    std::set<std::size_t> neighbors(std::size_t vertex) const;


};

template <class Item>
graph<Item>::graph(){
    num_vertices = 0;
}

template <class Item>
void graph<Item>::add_vertex(const Item& item){
    assert(num_vertices < MAX_VERTICES);
    vertices[num_vertices] = item;
    num_vertices++;
}

template <class Item>
void graph<Item>::add_edge(std::size_t from, std::size_t to){
    assert(from < num_vertices);
    assert(to < num_vertices);

    matrix[from][to] = 1;
}

template <class Item>
std::size_t graph<Item>::size() const{
    return num_vertices;
}

template <class Item>
bool graph<Item>::is_edge(std::size_t from, std::size_t to) const{
    assert(from < num_vertices);
    assert(to < num_vertices);
    return matrix[from][to];
}

template <class Item>
Item graph<Item>::operator[](std::size_t index){
    assert(index < num_vertices);
    return vertices[index];
}

template <class Item>
std::set<std::size_t> graph<Item>::neighbors(std::size_t vertex) const{
    assert(vertex < num_vertices);
    std::set<std::size_t> res;
    for (std::size_t i = 0; i < num_vertices; i++){
        if (matrix[vertex][i]){
            res.insert(i);
        }
    }
    return res;
}

#endif