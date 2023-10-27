#include "Slider.h"

namespace eCore {

const std::string SliderCollection{"Slider"};

Slider::Slider()
    :MongoCore::Item("Slider")
{

}

std::optional<bsoncxx::types::bson_value::value> Slider::value(const Key key) const
{
    return element( magic_enum::enum_name(key).data());
}

std::string Slider::keyToString(const Key key)
{
    return magic_enum::enum_name(key).data();
}

Slider::Key Slider::stringToKey(const std::string &string)
{
    auto m_key = magic_enum::enum_cast<Key>(string);
    if( m_key.has_value() ) {
        return m_key.value();
    }
    return Key::unKnown;
}

SliderManager::SliderManager(User::UserItem *_mUser)
    :MongoCore::ListItem<Slider>(_mUser->db()),
    m_User(_mUser)
{

}

} // namespace eCore


void eCore::SliderManager::errorOccured(const std::string &errorText)
{
}

void eCore::SliderManager::onList(const std::vector<Slider> &mlist)
{
}
