#ifndef ECORE_TEXT_H
#define ECORE_TEXT_H

#include "Core/Core_global.h"

#include <string>
#include <string_view>


namespace eCore {

const ECORE_EXPORT std::string  tr( const std::string &str );

class ECORE_EXPORT Text
{
public:
    Text( const Text &other );

    Text( const std::string &str );
    Text( const std::string_view &str_view );
    Text( const char* str );

    Text operator=( const Text &other );
    Text operator=( const std::string &str );

    std::string text() const;
    std::string operator()();




private:
    std::string m_text;
};

} // namespace eCore

#endif // ECORE_TEXT_H
