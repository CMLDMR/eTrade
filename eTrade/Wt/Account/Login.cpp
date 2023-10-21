#include "Login.h"

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "../Widget/Text.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WGridLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

using namespace Wt;

namespace Account {

Login::Login()
{

    init();

}

void Login::init()
{
    setMargin(150,Side::Top|Side::Bottom);
    setContentAlignment(AlignmentFlag::Center);

    decorationStyle().setBackgroundColor(WColor(StandardColor::LightGray));

    auto container = addNew<WContainerWidget>();

    container->setMaximumSize(1280,WLength::Auto);
    container->addStyleClass(Bootstrap::Grid::row);

    auto gLayout = container->setLayout(std::make_unique<WGridLayout>());


    auto userNameTextContainer = gLayout->addWidget(std::make_unique<WContainerWidget>(),0,0);
    userNameTextContainer->setContentAlignment(AlignmentFlag::Right);
    userNameTextContainer->setPadding(5,Side::Top|Side::Bottom);
    auto userNameInputText = userNameTextContainer->addWidget(std::make_unique<Widget::Text>("<b>Kullanıcı Adı</b>"));


    auto userNameInputContainer = gLayout->addWidget(std::make_unique<WContainerWidget>(),0,1);
    auto userNameInput = userNameInputContainer->addWidget(std::make_unique<WLineEdit>());
    userNameInput->setEchoMode(EchoMode::Normal);


    auto userNamePasswordContainer = gLayout->addWidget(std::make_unique<WContainerWidget>(),1,0);
    userNamePasswordContainer->setContentAlignment(AlignmentFlag::Right);
    userNamePasswordContainer->setPadding(5,Side::Top|Side::Bottom);
    auto userNamePasswordInput = userNamePasswordContainer->addWidget(std::make_unique<Widget::Text>("<b>Şifre</b>"));


    auto userPasswordInputContainer = gLayout->addWidget(std::make_unique<WContainerWidget>(),1,1);
    auto userPasswordInput = userPasswordInputContainer->addWidget(std::make_unique<WLineEdit>());
    userPasswordInput->setEchoMode(EchoMode::Password);


    auto loginBtn = gLayout->addWidget(std::make_unique<WPushButton>("Giriş"),2,0);
    auto lostBtn = gLayout->addWidget(std::make_unique<WPushButton>("Şifremi Unuttum"),2,1);

}

} // namespace Account
