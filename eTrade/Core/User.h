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
    UserItem(MongoCore::DB *mdb);
    UserItem(UserItem *mUser);

    enum class UserType{
        Admin,
        Business,
        Client,
        Unknown = 99
    };

    UserType getType() const;

    MongoCore::DB *db() const;

private:

    MongoCore::DB* m_db{nullptr};

};

}



} // namespace eCore

#endif // ECORE_USER_H
