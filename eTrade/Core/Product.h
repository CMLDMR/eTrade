#ifndef ECORE_PRODUCT_H
#define ECORE_PRODUCT_H

#include <Core/Core_global.h>
#include "User.h"
#include <MongoCore/listitem.h>
#include "magic_enum.hpp"




namespace eCore {

class ECORE_EXPORT Product : public MongoCore::Item
{
public:
    Product();

    enum class Key{
        categoryOid = 0,
        category,
        urunAdi,
        imgOid,
        price,
        explainHtml,
        lastUpdateTime,
        unknown = 99
    };

    template< typename T>
    void setValue( const Key key , const T &value ){
        append(magic_enum::enum_name(key).data(),value);
    }

    std::optional<bsoncxx::types::bson_value::value> value( const Key key ) const;
};


class ECORE_EXPORT ProductManager : public MongoCore::ListItem<Product>
{
public:
    ProductManager( eCore::User::UserItem* mUser );

private:
    User::UserItem* m_User;


    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<Product> &mlist) override;
    User::UserItem *User() const;
};

} // namespace eCore

#endif // ECORE_PRODUCT_H
