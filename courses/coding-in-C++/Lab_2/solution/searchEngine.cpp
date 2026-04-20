/**
 * @file search_engine.cpp
 * @brief Implementation of the SearchEngine class.
 */

#include "searchEngine.hpp"

#include <iostream>

int SearchEngine::total_queries = 0;

SearchEngine::SearchEngine()
    : web_resource_count(0),
      current_query(),
      current_search_result_count(0)
{
}

void SearchEngine::printInfo() const
{
    std::cout << "SearchEngine information\n";
    std::cout << "Indexed resources: " << web_resource_count << '\n';
    std::cout << "Current query: \"" << current_query.getQuery() << "\"\n";
    std::cout << "Stored search results: "
              << current_search_result_count
              << '\n';
}

int SearchEngine::getTotalQueries()
{
    return total_queries;
}

void SearchEngine::incTotalQueries()
{
    total_queries++;
}

void SearchEngine::addResource(const WebResource &resource)
{
    if (web_resource_count >= MAX_WEB_RESOURCES)
    {
        return;
    }

    web_resources[web_resource_count] = resource;
    web_resource_count++;

    if (current_query.isValid())
    {
        updateCurrentSearchResults();
    }
}

void SearchEngine::removeResource(const std::string &url)
{
    int found_index = -1;

    for (int index = 0; index < web_resource_count; index++)
    {
        if (web_resources[index].getUrl() == url)
        {
            found_index = index;
            break;
        }
    }

    if (found_index == -1)
    {
        return;
    }

    for (int index = found_index; index < web_resource_count - 1; index++)
    {
        web_resources[index] = web_resources[index + 1];
    }

    web_resource_count--;

    if (current_query.isValid())
    {
        updateCurrentSearchResults();
    }
    else
    {
        current_search_result_count = 0;
    }
}

SearchQuery SearchEngine::getCurrentQuery() const
{
    return current_query;
}

void SearchEngine::setCurrentQuery(const SearchQuery &query)
{
    current_query = query;

    if (current_query.isValid())
    {
        incTotalQueries();
        updateCurrentSearchResults();
    }
    else
    {
        current_search_result_count = 0;
    }
}

WebResource SearchEngine::getSearchResult(int index) const
{
    if ((index < 0) || (index >= current_search_result_count))
    {
        return WebResource();
    }

    return current_search_results[index];
}

int SearchEngine::getSearchResultCount() const
{
    return current_search_result_count;
}

void SearchEngine::sortCurrentResources()
{
    for (int outer_index = 0; outer_index < current_search_result_count - 1; outer_index++)
    {
        for (int inner_index = 0; inner_index < current_search_result_count - 1 - outer_index; inner_index++)
        {
            if (current_search_results[inner_index].getRanking() <
                current_search_results[inner_index + 1].getRanking())
            {
                WebResource temp = current_search_results[inner_index];
                current_search_results[inner_index] =
                    current_search_results[inner_index + 1];
                current_search_results[inner_index + 1] = temp;
            }
        }
    }
}

void SearchEngine::printRelevantResults() const
{
    if (current_search_result_count == 0)
    {
        std::cout << "No relevant results found.\n";
        return;
    }

    std::cout << "Relevant search results for query \""
              << current_query.getQuery()
              << "\"\n";

    for (int index = 0; index < current_search_result_count; index++)
    {
        const WebResource &resource = current_search_results[index];

        std::cout << index + 1 << ". ";
        std::cout << resource.getUrl();
        std::cout << " | ranking: " << resource.getRanking();
        std::cout << " | popular: " << std::boolalpha << resource.isPopular();
        std::cout << '\n';
    }
}

bool SearchEngine::queryInResource(
    const SearchQuery &query,
    const WebResource &resource) const
{
    if (!query.isValid())
    {
        return false;
    }

    return resource.getContent().find(query.getQuery()) != std::string::npos;
}

void SearchEngine::updateCurrentSearchResults()
{
    current_search_result_count = 0;

    for (int index = 0; index < web_resource_count; index++)
    {
        const WebResource &current_resource = web_resources[index];

        if (queryInResource(current_query, current_resource))
        {
            if (current_search_result_count < MAX_WEB_RESOURCES)
            {
                current_search_results[current_search_result_count] = current_resource;
                current_search_result_count++;
            }
        }
    }

    sortCurrentResources();

    if (current_search_result_count > current_query.getMaxResults())
    {
        current_search_result_count = current_query.getMaxResults();
    }
}