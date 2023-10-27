#ifndef ECORE_USER_H
#define ECORE_USER_H

#include "Core/Core_global.h"

#include "MongoCore/db.h"



namespace eCore {

namespace User {

namespace Key{
inline const std::string Collection{"user"};
inline const std::string username{"username"};
inline const std::string password{"password"};
inline const std::string type{"type"};
}

class ECORE_EXPORT UserItem : public MongoCore::Item
{
public:
    UserItem();
    explicit UserItem(MongoCore::DB *mdb);
    UserItem(UserItem *mUser);

    enum class UserType{
        Admin,
        Business,
        Client,
        Public,
        Unknown = 99
    };

    UserItem &setType( const UserType type );
    UserItem &setUserName( const std::string &userName );
    UserItem &setUserPassword( const std::string &userPassword );

    std::string getUserName() const;

    UserType getType() const;

    MongoCore::DB *db() const;

private:

    MongoCore::DB* m_db{nullptr};
    UserType m_userType{UserType::Public};

};

}



} // namespace eCore

#endif // ECORE_USER_H
