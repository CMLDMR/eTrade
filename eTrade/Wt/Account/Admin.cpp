#include "Admin.h"

#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include "Bootstrap/Bootstrap5ThemaKeys.h"


using namespace Wt;

namespace Account {


Admin::Admin(UserItem *mUser)
    :eCore::User::UserItem(mUser)
{
    init();
}

void Admin::init()
{
    addStyleClass(Bootstrap::Grid::container_fluid);
    setContentAlignment(AlignmentFlag::Center);

    auto m_menuBar = addNew<WContainerWidget>();
    m_menuBar->addStyleClass(Bootstrap::Grid::row);
    m_menuBar->setMaximumSize(1280,WLength::Auto);

{
    auto userListBtn = m_menuBar->addNew<WPushButton>("Kullanıcılar");
    userListBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Secondary+
                               Bootstrap::Components::Buttons::Size::Small);
}

{
    auto userListBtn = m_menuBar->addNew<WPushButton>("Kullanıcılar");
    userListBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Secondary+
                               Bootstrap::Components::Buttons::Size::Small);
}

{
    auto userListBtn = m_menuBar->addNew<WPushButton>("Kullanıcılar");
    userListBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Secondary+
                               Bootstrap::Components::Buttons::Size::Small);
}

{
    auto userListBtn = m_menuBar->addNew<WPushButton>("Kullanıcılar");
    userListBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Secondary+
                               Bootstrap::Components::Buttons::Size::Small);
}



}

} // namespace Account
