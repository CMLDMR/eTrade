#ifndef ACCOUNT_PANEL_H
#define ACCOUNT_PANEL_H

#include <Wt/WContainerWidget.h>

#include "Core/User.h"

namespace Account {

class Login;

class Panel : public Wt::WContainerWidget
{
public:
    Panel(MongoCore::DB* mdb);

private:
    void init();

    MongoCore::DB* m_db;

    eCore::User::UserItem* m_userItem;
};

} // namespace Account

#endif // ACCOUNT_PANEL_H
