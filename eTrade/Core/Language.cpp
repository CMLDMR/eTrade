#include "Language.h"

std::once_flag m_LanguageInstanceFlag;

namespace eCore {

Language* Language::m_LanguageInstance{nullptr};

Language *Language::instance()
{
    std::call_once(m_LanguageInstanceFlag,[=](){
        m_LanguageInstance = new Language();
    });
    return m_LanguageInstance;
}

Language::Language()
{

}

} // namespace eCore
