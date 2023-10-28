#include "Admin.h"

#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include "Bootstrap/Bootstrap5ThemaKeys.h"

#include "HeaderInfo.h"
#include "UserManager.h"
#include "SliderManager.h"
#include "ProductManager.h"
#include "CategoryManager.h"


using namespace Wt;

namespace Account {


Admin::Admin(eCore::User::UserItem *mUser)
    :m_User(mUser)
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

    auto btnListUsers = createMenuButton(eCore::tr("Kullanıcılar"));
    btnListUsers->clicked().connect(this,&Admin::initUsers);
    m_menuBar->addWidget(std::move(btnListUsers));

    auto btnHeaderInfo = createMenuButton(eCore::tr("Üst Bilgiler"));
    btnHeaderInfo->clicked().connect(this,&Admin::initHeaderInfo);
    m_menuBar->addWidget(std::move(btnHeaderInfo));

    auto btnSliderInfo = createMenuButton(eCore::tr("Slider"));
    btnSliderInfo->clicked().connect(this,&Admin::initSliderManager);
    m_menuBar->addWidget(std::move(btnSliderInfo));

    auto btnCatManager = createMenuButton(eCore::tr("Category"));
    btnCatManager->clicked().connect(this,&Admin::initCategoryManager);
    m_menuBar->addWidget(std::move(btnCatManager));

    auto btnProductManager = createMenuButton(eCore::tr("Product"));
    btnProductManager->clicked().connect(this,&Admin::initProductManager);
    m_menuBar->addWidget(std::move(btnProductManager));

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
    m_contentContainer->addNew<UserManager>(m_User->db());
}

void Admin::initHeaderInfo()
{
    m_contentContainer->clear();
    m_contentContainer->addNew<HeaderInfo>(m_User);
}

void Admin::initSliderManager()
{
    m_contentContainer->clear();
    m_contentContainer->addNew<SliderManager>(m_User);
}

void Admin::initProductManager()
{
    m_contentContainer->clear();
    m_contentContainer->addNew<ProductManager>(m_User);
}

void Admin::initCategoryManager()
{
    m_contentContainer->clear();
    m_contentContainer->addNew<CategoryManager>(m_User);
}

} // namespace Account
