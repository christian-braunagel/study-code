/**
 * @file main.cpp
 * @brief Demonstration program for the simplified SearchEngine system.
 *
 * This file creates several web resources, executes multiple queries,
 * and prints the corresponding search results.
 * How to compile: g++ main.cpp searchEngine.cpp searchQuery.cpp webResource.cpp -o searchEngineApp
 */

#include <iostream>

#include "searchEngine.hpp"
#include "searchQuery.hpp"
#include "webResource.hpp"

int main()
{
    SearchEngine search_engine;

    WebResource resource_1(
        "https://example.com/cpp-basics",
        "C++ basics classes objects encapsulation constructors search engine",
        85);

    WebResource resource_2(
        "https://example.com/uml-guide",
        "UML class diagram object diagram query method visibility datatype",
        92);

    WebResource resource_3(
        "https://example.com/python-intro",
        "Python basics variables functions loops",
        60);

    WebResource resource_4(
        "https://example.com/cpp-search",
        "Search engine implementation in C++ with query processing and ranking",
        88);

    WebResource resource_5(
        "https://example.com/search-theory",
        "Search theory indexing ranking relevance and query evaluation",
        75);

    search_engine.addResource(resource_1);
    search_engine.addResource(resource_2);
    search_engine.addResource(resource_3);
    search_engine.addResource(resource_4);
    search_engine.addResource(resource_5);

    search_engine.printInfo();
    std::cout << '\n';

    SearchQuery query_1("query", 3);
    search_engine.setCurrentQuery(query_1);
    search_engine.printRelevantResults();
    std::cout << "Total queries executed: "
              << SearchEngine::getTotalQueries()
              << "\n\n";

    SearchQuery query_2("C++", 2);
    search_engine.setCurrentQuery(query_2);
    search_engine.printRelevantResults();
    std::cout << "Total queries executed: "
              << SearchEngine::getTotalQueries()
              << "\n\n";

    search_engine.removeResource("https://example.com/cpp-search");

    SearchQuery query_3("search", 5);
    search_engine.setCurrentQuery(query_3);
    search_engine.printRelevantResults();
    std::cout << "Total queries executed: "
              << SearchEngine::getTotalQueries()
              << '\n';

    return 0;
}