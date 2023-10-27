#include "Panel.h"
#include "Login.h"

#include <Wt/WText.h>
#include "Admin.h"

using namespace Wt;

namespace Account {

Panel::Panel(MongoCore::DB *mdb)
    :m_db(mdb)
{
    m_userItem = new eCore::User::UserItem(mdb);
    init();
}

void Panel::init()
{

    //TODO: Geliştirme Tamamlanınca Burası Kaldırılacak
    this->addNew<Admin>(m_userItem);
    return;

    auto loginWidget = addNew<Account::Login>(m_userItem);

    loginWidget->successLogin().connect([=](){


        this->clear();

        switch (m_userItem->getType()) {
        case eCore::User::UserItem::UserType::Admin:
            this->addNew<Admin>(m_userItem);
            break;
        case eCore::User::UserItem::UserType::Business:
            this->addNew<WText>("Business USER");
            break;
        case eCore::User::UserItem::UserType::Client:
            this->addNew<WText>("Client USER");
            break;
        default:
            this->addNew<WText>("UNKNOWN USER");
            break;
        }

    });

}

} // namespace Account
