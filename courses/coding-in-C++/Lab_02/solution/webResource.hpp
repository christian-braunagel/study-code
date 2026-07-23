/**
 * @file web_resource.hpp
 * @brief Declaration of the WebResource class.
 *
 * This module defines a searchable web resource with URL, textual content,
 * and a ranking value.
 */

#ifndef WEB_RESOURCE_HPP
#define WEB_RESOURCE_HPP

#include <string>

class WebResource
{
private:
    static constexpr int POPULARITY_THRESHOLD = 80;

    std::string url;
    std::string content;
    int ranking;

public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty web resource with default values.
     */
    WebResource();

    /**
     * @brief Constructs a web resource with initial values.
     *
     * @param[in] url      Unique address of the resource
     * @param[in] content  Textual content of the resource
     * @param[in] ranking  Ranking value of the resource
     */
    WebResource(const std::string &url, const std::string &content, int ranking);

    /**
     * @brief Returns the URL of the resource.
     *
     * @return URL string
     */
    std::string getUrl() const;

    /**
     * @brief Sets the URL of the resource.
     *
     * @param[in] url  New URL of the resource
     */
    void setUrl(const std::string &url);

    /**
     * @brief Returns the textual content of the resource.
     *
     * @return Content string
     */
    std::string getContent() const;

    /**
     * @brief Sets the textual content of the resource.
     *
     * @param[in] content  New textual content
     */
    void setContent(const std::string &content);

    /**
     * @brief Returns the ranking value of the resource.
     *
     * @return Ranking value
     */
    int getRanking() const;

    /**
     * @brief Sets the ranking value of the resource.
     *
     * @param[in] ranking  New ranking value
     */
    void setRanking(int ranking);

    /**
     * @brief Checks whether the resource is considered popular.
     *
     * The popularity is derived from the ranking value.
     *
     * @return true if the resource is popular, otherwise false
     */
    bool isPopular() const;
};

#endif