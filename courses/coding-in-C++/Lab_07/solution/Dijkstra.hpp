#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include <vector>

/**
 * @brief Represents a weighted edge to another vertex.
 */
struct Edge
{
    int destination;
    int distance;
};

/**
 * @brief Represents a route through the graph.
 */
struct Route
{
    std::vector<int> vertices;
    int total_distance;
};

/**
 * @brief Represents a weighted adjacency list.
 */
class AdjacencyList
{
private:
    std::vector<std::vector<Edge>> adjacency_list;

public:
    /**
     * @brief Creates an adjacency list with a given number of vertices.
     * @param vertices Number of vertices in the graph.
     */
    AdjacencyList(int vertices);

    /**
     * @brief Adds an undirected weighted edge between two vertices.
     * @param from Start vertex of the edge.
     * @param to Destination vertex of the edge.
     * @param distance Weight of the edge.
     */
    void add_edge(int from, int to, int distance);

    /**
     * @brief Finds the shortest path between two vertices using Dijkstra's algorithm.
     * @param start Start vertex.
     * @param destination Destination vertex.
     * @return Shortest route from start to destination.
     */
    Route find_shortest_path(int start, int destination) const;

    /**
     * @brief Prints the adjacency list to the console.
     */
    void print_list() const;

    /**
     * @brief Prints a route to the console.
     * @param route Route to be printed.
     */
    void print_route(const Route &route) const;
};

#endif