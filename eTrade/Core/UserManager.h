#ifndef ECORE_USER_MANAGER_H
#define ECORE_USER_MANAGER_H


#include "User.h"
#include "MongoCore/listitem.h"

namespace eCore {
namespace User {

class ECORE_EXPORT Manager : public MongoCore::ListItem<UserItem>
{
public:
    Manager( MongoCore::DB* _mDB );

    virtual void onList( const std::vector<UserItem> &mList ) override;
};

} // namespace User
} // namespace eCore

#endif // ECORE_USER_MANAGER_H
