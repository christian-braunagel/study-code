#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include <vector>

class AdjacencyList
{
private:
    std::vector<std::vector<int>> adjacency_list;

public:
    AdjacencyList(int vertices);

    void add_edge(int from, int to);

    void print_list() const;
};

#endif