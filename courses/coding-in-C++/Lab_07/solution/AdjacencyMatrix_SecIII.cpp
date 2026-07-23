#include <iostream>
#include <vector>
#include "AdjacencyMatrix_SecIII.hpp"

AdjacencyMatrix::AdjacencyMatrix(int size)
{
    this->size = size;
    this->matrix = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

void AdjacencyMatrix::setEdge(int from, int to, int weight)
{
    if (from >= 0 && from < this->size && to >= 0 && to < this->size)
    {
        matrix[from][to] = weight;
    }
}

int AdjacencyMatrix::getEdge(int from, int to) const
{
    if (from >= 0 && from < this->size && to >= 0 && to < this->size)
    {
        return matrix[from][to];
    }
    return -1; // Return -1 for invalid indices
}

void AdjacencyMatrix::printMatrix() const
{
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    AdjacencyMatrix graph(3);

    graph.setEdge(0, 1, true);
    graph.setEdge(1, 0, true);
    graph.setEdge(0, 2, true);
    graph.setEdge(2, 0, true);
    graph.setEdge(1, 2, true);
    graph.setEdge(2, 1, true);

    graph.printMatrix();

    return 0;
}

// The current implementation of the Adjacency Matrix uses a containerized approach
// with a 2D vector to store the edges and their weights.
// However, this approach is still not optimal for large graphs due to its O(n^2) space complexity.
// This is because it allocates space for all possible edges, even if many of them do not exist.