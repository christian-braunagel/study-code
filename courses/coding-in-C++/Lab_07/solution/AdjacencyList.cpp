#include <iostream>

#include "AdjacencyList.hpp"

AdjacencyList::AdjacencyList(int vertices)
{
    adjacency_list.resize(vertices);
}

void AdjacencyList::add_edge(int from, int to)
{
    adjacency_list[from].push_back(to);
}

void AdjacencyList::print_list() const
{
    std::cout << "Adjacency List:\n";

    for (int vertex = 0; vertex < adjacency_list.size(); vertex++)
    {
        std::cout << vertex << " -> ";

        for (int neighbor : adjacency_list[vertex])
        {
            std::cout << neighbor << " ";
        }

        std::cout << '\n';
    }
}

int main()
{

    AdjacencyList graph(3);

    // A = 0, B = 1, C = 2
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 0);
    graph.add_edge(1, 2);

    graph.print_list();

    return 0;
}
