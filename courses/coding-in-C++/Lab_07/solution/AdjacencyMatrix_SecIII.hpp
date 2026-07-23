#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include <vector>
class AdjacencyMatrix
{
private:
    int size;
    std::vector<std::vector<int>> matrix;

public:
    AdjacencyMatrix(int size);

    void setEdge(int from, int to, int weight);
    int getEdge(int from, int to) const;

    void printMatrix() const;
};

#endif // ADJACENCY_MATRIX_HPP