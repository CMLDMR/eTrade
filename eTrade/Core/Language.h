#ifndef ECORE_LANGUAGE_H
#define ECORE_LANGUAGE_H

#include "Core/Core_global.h"

#include <mutex>

namespace eCore {

class ECORE_EXPORT Language
{
public:
    static Language* instance();


private:
    Language();
    static Language* m_LanguageInstance;
};

} // namespace eCore

#endif // ECORE_LANGUAGE_H
