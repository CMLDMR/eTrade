#ifndef ACCOUNT_PRODUCTMANAGER_H
#define ACCOUNT_PRODUCTMANAGER_H

#include <Wt/Widget/ContainerWidget.h>
#include <Core/User.h>

namespace Account {

class ProductManager : public Widget::ContainerWidget
{
public:
    ProductManager( eCore::User::UserItem* mUser );


private:
    eCore::User::UserItem *m_User;
};

} // namespace Account

#endif // ACCOUNT_PRODUCTMANAGER_H
