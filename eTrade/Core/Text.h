#ifndef ECORE_TEXT_H
#define ECORE_TEXT_H

#include "Core/Core_global.h"

#include <string>

namespace eCore {

class ECORE_EXPORT Text
{
public:
    Text();
    Text( const Text &other );

    Text( const std::string &str );
    Text( const char* str );

    Text operator=( const Text &other );
    Text operator=( const std::string &str );

    std::string text() const;




private:
    std::string m_text;
};

} // namespace eCore

#endif // ECORE_TEXT_H
