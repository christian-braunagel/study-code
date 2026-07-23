#include <iostream>
#include "AdjacencyMatrix_SecII.hpp"

AdjacencyMatrix::AdjacencyMatrix()
{
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            matrix[i][j] = false;
        }
    }
}

void AdjacencyMatrix::setEdge(int from, int to, bool exists)
{
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices)
    {
        matrix[from][to] = exists;
    }
}

void AdjacencyMatrix::printMatrix() const
{
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    AdjacencyMatrix graph;

    graph.setEdge(0, 1, true);
    graph.setEdge(1, 0, true);
    graph.setEdge(0, 2, true);
    graph.setEdge(2, 0, true);
    graph.setEdge(1, 2, true);
    graph.setEdge(2, 1, true);

    graph.printMatrix();

    return 0;
}

// The current implementation of the Adjacency Matrix uses a fixed-size 2D array.
// This approach is straightforward and efficient for small graphs, but:
// - It is inflexible because the size is determined at compile time and cannot be changed at runtime.
// - It can be memory-inefficient for larger graphs because all edges are stored, even if many of them do not exist.