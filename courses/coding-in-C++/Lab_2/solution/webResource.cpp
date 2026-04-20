/**
 * @file web_resource.cpp
 * @brief Implementation of the WebResource class.
 */

#include "webResource.hpp"

WebResource::WebResource()
    : url(""), content(""), ranking(0)
{
}

WebResource::WebResource(
    const std::string &url,
    const std::string &content,
    int ranking)
    : url(url), content(content), ranking(ranking)
{
}

std::string WebResource::getUrl() const
{
    return url;
}

void WebResource::setUrl(const std::string &url)
{
    this->url = url;
}

std::string WebResource::getContent() const
{
    return content;
}

void WebResource::setContent(const std::string &content)
{
    this->content = content;
}

int WebResource::getRanking() const
{
    return ranking;
}

void WebResource::setRanking(int ranking)
{
    this->ranking = ranking;
}

bool WebResource::isPopular() const
{
    return ranking >= POPULARITY_THRESHOLD;
}