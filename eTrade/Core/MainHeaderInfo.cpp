#include "MainHeaderInfo.h"


//#define key(x)  magic_enum::enum_name(x)

namespace eCore {
namespace HeaderInfo {

const std::string Collection{"HeaderInfo"};

MainHeaderInfo::MainHeaderInfo()
    :MongoCore::Item(Collection)
{



}

void MainHeaderInfo::setDefination(const Key key, const DefinationKey defKey)
{
    append(magic_enum::enum_name(key).data(),magic_enum::enum_name(defKey).data());
}

std::optional<bsoncxx::types::bson_value::value> MainHeaderInfo::value(const Key key) const
{
    return element( magic_enum::enum_name(key).data());
}

MainHeaderInfo::DefinationKey MainHeaderInfo::valueType() const
{
    auto val = element(magic_enum::enum_name(Key::defination).data());
    if( val ) {
        auto stringValue = std::string(val.value().view().get_string().value.data());
        auto keyValue = magic_enum::enum_cast<DefinationKey>(stringValue);
        if( keyValue.has_value() ){
            return keyValue.value();
        }
        return DefinationKey::unKnownKey;
    }
    return DefinationKey::unKnownKey;
}

std::string MainHeaderInfo::keyToString(const Key key)
{
    return magic_enum::enum_name(key).data();
}

MainHeaderInfo::Key MainHeaderInfo::stringToKey(const std::string &string)
{
    auto m_key = magic_enum::enum_cast<Key>(string);
    if( m_key.has_value() ) {
        return m_key.value();
    }
    return Key::unKnown;
}

MainHeaderInfoManager::MainHeaderInfoManager(MongoCore::DB *mDB)
    :MongoCore::ListItem<MainHeaderInfo>(mDB)
{


}


} // namespace HeaderInfo

} // namespace eCore


void eCore::HeaderInfo::MainHeaderInfoManager::errorOccured(const std::string &errorText)
{
}

void eCore::HeaderInfo::MainHeaderInfoManager::onList(const std::vector<MainHeaderInfo> &mlist)
{
}
