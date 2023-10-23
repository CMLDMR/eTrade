#include "Admin.h"

#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include "Bootstrap/Bootstrap5ThemaKeys.h"

#include "HeaderInfo.h"
#include "UserManager.h"


using namespace Wt;

namespace Account {


Admin::Admin(UserItem *mUser)
    :eCore::User::UserItem(mUser)
{
    init();
}

void Admin::init()
{
    setMargin( 25 , Side::Bottom | Side::Top );
    addStyleClass(Bootstrap::Grid::container_fluid);
    setContentAlignment(AlignmentFlag::Center);

    m_headerContainer = addNew<WContainerWidget>();
    m_contentContainer = addNew<WContainerWidget>();
    m_contentContainer->addStyleClass(Bootstrap::Grid::container_fluid);


    auto m_menuBar = m_headerContainer->addNew<WContainerWidget>();
    m_menuBar->addStyleClass(Bootstrap::Components::Buttons::group);
    m_menuBar->setMaximumSize(1280,WLength::Auto);

    auto btnListUsers = createMenuButton("Kullanıcılar");
    btnListUsers->clicked().connect(this,&Admin::initUsers);
    m_menuBar->addWidget(std::move(btnListUsers));

    auto btnHeaderInfo = createMenuButton("Üst Bilgiler");
    btnHeaderInfo->clicked().connect(this,&Admin::initHeaderInfo);
    m_menuBar->addWidget(std::move(btnHeaderInfo));
}

std::unique_ptr<WPushButton> Admin::createMenuButton(const eCore::Text &btnName)
{
    auto btn = std::make_unique<WPushButton>(btnName.text());
    btn->addStyleClass(Bootstrap::Components::Buttons::Outline::Secondary+
                       Bootstrap::Components::Buttons::Size::Small);
    return btn;
}

void Admin::initUsers()
{

    m_contentContainer->clear();
    auto m_userManager = m_contentContainer->addNew<UserManager>(db());
}

void Admin::initHeaderInfo()
{
    m_contentContainer->clear();

    m_contentContainer->addNew<HeaderInfo>();

}

} // namespace Account
