#include "Product.h"


namespace eCore {

Product::Product()
    :MongoCore::Item("Product")
{

}

std::optional<bsoncxx::types::bson_value::value> Product::value(const Key key) const
{
    return element( magic_enum::enum_name(key).data() );
}

ProductManager::ProductManager(User::UserItem *mUser)
    :m_User( mUser ),
    MongoCore::ListItem<Product>( mUser->db() )
{

}


User::UserItem *ProductManager::User() const
{
    return m_User;
}

} // namespace eCore


void eCore::ProductManager::errorOccured(const std::string &errorText)
{
}

void eCore::ProductManager::onList(const std::vector<Product> &mlist)
{
}
