/**
 * @file search_query.hpp
 * @brief Declaration of the SearchQuery class.
 *
 * This module defines a search query consisting of query text
 * and a maximum number of results.
 */

#ifndef SEARCH_QUERY_HPP
#define SEARCH_QUERY_HPP

#include <string>

class SearchQuery
{
private:
    static constexpr int DEFAULT_MAX_RESULTS = 3;

    std::string query;
    int max_results;

public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty query with a default maximum number of results.
     */
    SearchQuery();

    /**
     * @brief Constructs a search query with initial values.
     *
     * @param[in] query        Search text
     * @param[in] max_results  Maximum number of results
     */
    SearchQuery(const std::string &query, int max_results);

    /**
     * @brief Checks whether the query is valid.
     *
     * A query is valid if it is not empty or whitespace-only and if the
     * maximum number of results is greater than zero.
     *
     * @return true if the query is valid, otherwise false
     */
    bool isValid() const;

    /**
     * @brief Returns the search text.
     *
     * @return Query text
     */
    std::string getQuery() const;

    /**
     * @brief Sets the search text.
     *
     * @param[in] query  New search text
     */
    void setQuery(const std::string &query);

    /**
     * @brief Returns the maximum number of results.
     *
     * @return Maximum number of results
     */
    int getMaxResults() const;

    /**
     * @brief Sets the maximum number of results.
     *
     * If the provided value is invalid, a default value is used.
     *
     * @param[in] max_res  New maximum number of results
     */
    void setMaxResults(int max_res);
};

#endif