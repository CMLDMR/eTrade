#include "Category.h"

namespace eCore {

Category::Category()
    :MongoCore::Item("Category")
{


}

std::optional<bsoncxx::types::bson_value::value> Category::value( const Key key ) const
{
    return element( magic_enum::enum_name(key).data() );
}

std::string Category::keyToString( const Key key )
{
    return magic_enum::enum_name( key ).data();
}

Category::Key Category::stringToKey( const std::string &string )
{
    auto m_key = magic_enum::enum_cast<Key>( string );
    if( m_key.has_value() )
        return m_key.value();

    return Key::unKnown;
}

CategoryManager::CategoryManager(User::UserItem *mUser)
    :m_User( mUser ),
    MongoCore::ListItem<Category>( mUser->db() )
{

}

User::UserItem *CategoryManager::User() const
{
    return m_User;
}

} // namespace eCore


void eCore::CategoryManager::errorOccured(const std::string &errorText)
{
}

void eCore::CategoryManager::onList(const std::vector<Category> &mlist)
{
}
