#ifndef ACCOUNT_CATEGORYMANAGER_H
#define ACCOUNT_CATEGORYMANAGER_H

#include <Wt/Widget/ContainerWidget.h>
#include <Core/User.h>
#include <Core/Category.h>

namespace Account {

class CategoryManager : public Widget::ContainerWidget, public eCore::CategoryManager
{
public:
    CategoryManager( eCore::User::UserItem* mUser );

    // DB interface
public:
    virtual void errorOccured( const std::string &errorText ) override;

    // CategoryManager interface
public:
    virtual void onList( const std::vector<eCore::Category> &mlist ) override;

private:
    void init();
    void initHeader();

    void addNewCategory();
};

} // namespace Account

#endif // ACCOUNT_CATEGORYMANAGER_H
