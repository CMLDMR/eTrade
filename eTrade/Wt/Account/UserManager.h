#ifndef ACCOUNT_USERMANAGER_H
#define ACCOUNT_USERMANAGER_H

#include "../Widget/ContainerWidget.h"
#include <Wt/WTableView.h>
#include "Core/Manager.h"


namespace Account {

class UserManager : public Widget::ContainerWidget, public eCore::User::Manager
{
public:
    UserManager(MongoCore::DB* _mDB);


private:
    void init();
    void initHeader();
    void initContent();

    void addNewUser();
    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // Manager interface
public:
    virtual void onList(const std::vector<eCore::User::UserItem> &mList) override;
};


} // namespace Account

#endif // ACCOUNT_USERMANAGER_H
