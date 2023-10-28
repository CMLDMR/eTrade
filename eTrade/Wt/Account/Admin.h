#ifndef ACCOUNT_ADMIN_H
#define ACCOUNT_ADMIN_H

#include <Wt/WContainerWidget.h>

#include <Core/Text.h>
#include <Core/User.h>

namespace Account {

class Admin : public Wt::WContainerWidget
{
public:
    Admin(eCore::User::UserItem* mUser);

private:
    void init();

    std::unique_ptr<Wt::WPushButton> createMenuButton( const eCore::Text &btnName );


    Wt::WContainerWidget* m_headerContainer;
    Wt::WContainerWidget* m_contentContainer;

    void initUsers();
    void initHeaderInfo();
    void initSliderManager();
    void initProductManager();
    void initCategoryManager();

    eCore::User::UserItem* m_User;
};

} // namespace Account

#endif // ACCOUNT_ADMIN_H
