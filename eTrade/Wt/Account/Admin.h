#ifndef ACCOUNT_ADMIN_H
#define ACCOUNT_ADMIN_H

#include <Wt/WContainerWidget.h>

#include <Core/User.h>

namespace Account {

class Admin : public Wt::WContainerWidget, public eCore::User::UserItem
{
public:
    Admin(eCore::User::UserItem* mUser);

private:
    void init();
};

} // namespace Account

#endif // ACCOUNT_ADMIN_H
