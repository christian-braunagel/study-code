/**
 * @file search_query.cpp
 * @brief Implementation of the SearchQuery class.
 */

#include "searchQuery.hpp"

SearchQuery::SearchQuery()
    : query(""), max_results(DEFAULT_MAX_RESULTS)
{
}

SearchQuery::SearchQuery(const std::string &query, int max_results)
    : query(query), max_results(DEFAULT_MAX_RESULTS)
{
    setMaxResults(max_results);
}

bool SearchQuery::isValid() const
{
    const std::size_t first_non_whitespace =
        query.find_first_not_of(" \t\n\r");

    return (first_non_whitespace != std::string::npos) && (max_results > 0);
}

std::string SearchQuery::getQuery() const
{
    return query;
}

void SearchQuery::setQuery(const std::string &query)
{
    this->query = query;
}

int SearchQuery::getMaxResults() const
{
    return max_results;
}

void SearchQuery::setMaxResults(int max_res)
{
    if (max_res > 0)
    {
        max_results = max_res;
    }
    else
    {
        max_results = DEFAULT_MAX_RESULTS;
    }
}