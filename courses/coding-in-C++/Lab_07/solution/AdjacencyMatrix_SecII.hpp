#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

class AdjacencyMatrix
{
private:
    static constexpr int numVertices = 3;
    bool matrix[numVertices][numVertices];

public:
    AdjacencyMatrix();

    void setEdge(int from, int to, bool exists);

    void printMatrix() const;
};

#endif // ADJACENCY_MATRIX_HPP