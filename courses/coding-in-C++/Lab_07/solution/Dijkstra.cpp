#include <iostream>
#include <vector>

#include "Dijkstra.hpp"

// constants for the starting values
const int NO_PREVIOUS_VERTEX = -1;
const int INFINITE_DISTANCE = 999999;

AdjacencyList::AdjacencyList(int vertices)
{
    adjacency_list.resize(vertices);
}

void AdjacencyList::add_edge(int from, int to, int distance)
{
    // non directed graph means distance is valid in both ways
    adjacency_list[from].push_back({to, distance});
    adjacency_list[to].push_back({from, distance});
}

Route AdjacencyList::find_shortest_path(int start, int destination) const
{
    // Support variables
    // list of all visited nodes
    std::vector<bool> visited(adjacency_list.size(), false);
    // list of previous nodes corresponding to the shortest distances
    std::vector<int> previous(adjacency_list.size(), NO_PREVIOUS_VERTEX);
    // list of all shortest distances
    std::vector<int> distances(adjacency_list.size(), INFINITE_DISTANCE);

    distances[start] = 0;

    for (std::size_t i = 0; i < adjacency_list.size(); ++i)
    {
        int current_vertex = NO_PREVIOUS_VERTEX;
        int shortest_distance = INFINITE_DISTANCE;

        for (std::size_t vertex = 0; vertex < adjacency_list.size(); ++vertex)
        {
            if (!visited[vertex] && distances[vertex] < shortest_distance)
            {
                shortest_distance = distances[vertex];
                current_vertex = vertex;
            }
        }

        if (current_vertex == NO_PREVIOUS_VERTEX)
        {
            break;
        }

        visited[current_vertex] = true;

        // update the edges of the current vertex
        for (const Edge &edge : adjacency_list[current_vertex])
        {
            int new_distance = distances[current_vertex] + edge.distance;

            // is the new route of shorter distance?
            if (new_distance < distances[edge.destination])
            {
                distances[edge.destination] = new_distance;
                previous[edge.destination] = current_vertex;
            }
        }
    }

    Route route;
    route.total_distance = distances[destination];

    int current_vertex = destination;

    // Rebuild the route from destination to start
    while (current_vertex != NO_PREVIOUS_VERTEX)
    {
        route.vertices.insert(route.vertices.begin(), current_vertex);
        current_vertex = previous[current_vertex];
    }

    return route;
}

void AdjacencyList::print_list() const
{
    std::cout << "Weighted Adjacency List:\n";

    for (std::size_t vertex = 0; vertex < adjacency_list.size(); ++vertex)
    {
        std::cout << vertex << " -> ";

        for (const Edge &edge : adjacency_list[vertex])
        {
            std::cout << edge.destination << "(" << edge.distance << ") ";
        }

        std::cout << '\n';
    }
}

void AdjacencyList::print_route(const Route &route) const
{
    std::cout << "Shortest path: ";

    for (std::size_t i = 0; i < route.vertices.size(); ++i)
    {
        std::cout << route.vertices[i];

        if (i < route.vertices.size() - 1)
        {
            std::cout << " -> ";
        }
    }

    std::cout << "\nTotal distance: " << route.total_distance << '\n';
}

int main()
{
    AdjacencyList graph(4);

    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 2, 2);
    graph.add_edge(0, 3, 5);
    graph.add_edge(1, 2, 3);
    graph.add_edge(1, 3, 1);
    graph.add_edge(2, 3, 7);

    graph.print_list();

    Route shortest_route = graph.find_shortest_path(0, 3);

    graph.print_route(shortest_route);

    return 0;
}

// Dijkstra is more efficient because it does not calculate all possible paths.
// It always continues with the currently shortest known path.

// Dijkstra requires non-negative edge weights because visited vertices
// are never checked again. Negative weights could create shorter paths later.