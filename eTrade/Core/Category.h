#ifndef ECORE_CATEGORY_H
#define ECORE_CATEGORY_H

#include <Core/Core_global.h>

#include <MongoCore/listitem.h>
#include <Core/User.h>
#include "magic_enum.hpp"

namespace eCore {

class ECORE_EXPORT Category : public MongoCore::Item
{
public:
    Category();

    enum class Key{
        text,
        unKnown = 99
    };

    template< typename T>
    void setValue( const Key key , const T &value ){
        append(magic_enum::enum_name(key).data(),value);
    }

    std::optional<bsoncxx::types::bson_value::value> value( const Key key ) const;

    std::string keyToString( const Key key );
    Key stringToKey( const std::string &string );
};


class ECORE_EXPORT CategoryManager : public MongoCore::ListItem<Category>
{
public:
    CategoryManager( eCore::User::UserItem* mUser );

    User::UserItem *User() const;

private:
    User::UserItem* m_User;

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<Category> &mlist) override;
};

} // namespace eCore

#endif // ECORE_CATEGORY_H
