#ifndef ECORE_MAINHEADERINFO_H
#define ECORE_MAINHEADERINFO_H

#include "Core/Core_global.h"

#include "magic_enum.hpp"

#include <MongoCore/item.h>
#include <MongoCore/listitem.h>

namespace eCore {

namespace HeaderInfo {

class ECORE_EXPORT MainHeaderInfo : public MongoCore::Item
{
public:
    MainHeaderInfo();

    enum class Key{
        defination = 0,
        visible,
        text,
        clickUrl,
        styleSheet,
        imgOid,
        imgWidth,
        imgHeight,
        unKnown = 999
    };

    enum class DefinationKey{
        address = 0,
        mail,
        facebook,
        twitter,
        linkedin,
        instagram,
        logo,
        unKnownKey = 999
    };

    template< typename T>
    void setValue( const Key key , const T &value ){
        append(magic_enum::enum_name(key).data(),value);
    }

    void setDefination( const Key key , const DefinationKey defKey );

    std::optional<bsoncxx::types::bson_value::value> value( const Key key ) const;

    DefinationKey valueType() const;


    std::string keyToString( const Key key );
    Key stringToKey( const std::string &string );


private:



};

class ECORE_EXPORT MainHeaderInfoManager : public MongoCore::ListItem<MainHeaderInfo>
{
public:
    MainHeaderInfoManager(MongoCore::DB* mDB);



    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<MainHeaderInfo> &mlist) override;
};


}



} // namespace eCore

#endif // ECORE_MAINHEADERINFO_H
