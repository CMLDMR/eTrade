#ifndef ECORE_SLIDER_H
#define ECORE_SLIDER_H

#include <MongoCore/item.h>
#include <MongoCore/listitem.h>
#include <Core/Core_global.h>
#include <Core/Text.h>
#include <Core/User.h>
#include "magic_enum.hpp"


namespace eCore {

class ECORE_EXPORT Slider : public MongoCore::Item
{
public:
    Slider();

    enum class Key{
        imgOid = 0,
        imgUrl,
        text,
        unKnown = 999
    };

    template< typename T>
    void setValue( const Key key , const T &value ){
        append(magic_enum::enum_name(key).data(),value);
    }

    std::optional<bsoncxx::types::bson_value::value> value( const Key key ) const;

    std::string keyToString( const Key key );
    Key stringToKey( const std::string &string );
};


class ECORE_EXPORT SliderManager : public MongoCore::ListItem<Slider>
{
public:
    SliderManager( User::UserItem* _mUser );



private:
    User::UserItem* m_User;

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<Slider> &mlist) override;
};


} // namespace eCore

#endif // ECORE_SLIDER_H
