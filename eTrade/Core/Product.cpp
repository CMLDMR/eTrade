#include "Product.h"

#include <chrono>

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

long long ProductManager::secondsSinceEpoch()
{
    return std::chrono::system_clock::now().time_since_epoch().count();
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
