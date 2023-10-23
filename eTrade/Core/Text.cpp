#include "Text.h"

namespace eCore {

//Text::Text()
//{

//}

Text::Text(const Text &other)
    :m_text(other.m_text)
{

}

Text::Text(const std::string &str)
    :m_text(str)
{


}

Text::Text(const char *str)
    :m_text(str)
{

}

Text Text::operator=(const Text &other)
{
    m_text = other.m_text;
    return *this;
}

std::string Text::text() const
{
    return m_text;
}

std::string Text::operator()()
{
    return text();
}

Text Text::operator=(const std::string &str)
{
    m_text = str;
    return *this;
}

const std::string tr(const std::string &str)
{
    return eCore::Text(str).text();
}

} // namespace eCore


