#include "Login.h"

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "../Widget/Text.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WGridLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>



using namespace Wt;

namespace Account {

Login::Login(eCore::User::UserItem* mUser)
    :m_User(mUser)
{
    init();
}

Wt::Signal<NoClass> &Login::successLogin()
{
    return m_Success;
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
    userNameTextContainer->addWidget(std::make_unique<Widget::Text>("<b>Kullanıcı Adı</b>"));


    auto userNameInputContainer = gLayout->addWidget(std::make_unique<WContainerWidget>(),0,1);
    auto userNameInput = userNameInputContainer->addWidget(std::make_unique<WLineEdit>());
    userNameInput->setEchoMode(EchoMode::Normal);


    auto userNamePasswordContainer = gLayout->addWidget(std::make_unique<WContainerWidget>(),1,0);
    userNamePasswordContainer->setContentAlignment(AlignmentFlag::Right);
    userNamePasswordContainer->setPadding(5,Side::Top|Side::Bottom);
    userNamePasswordContainer->addWidget(std::make_unique<Widget::Text>("<b>Şifre</b>"));


    auto userPasswordInputContainer = gLayout->addWidget(std::make_unique<WContainerWidget>(),1,1);
    auto userPasswordInput = userPasswordInputContainer->addWidget(std::make_unique<WLineEdit>());
    userPasswordInput->setEchoMode(EchoMode::Password);


    auto loginBtn = gLayout->addWidget(std::make_unique<WPushButton>("Giriş"),2,0);

    //TODO: implement Forget password
    auto lostBtn = gLayout->addWidget(std::make_unique<WPushButton>("Şifremi Unuttum"),2,1);


    loginBtn->clicked().connect([=](){
        this->checkUser(userNameInput->text().toUTF8(),userPasswordInput->text().toUTF8());
    });


}

void Login::checkUser(const std::string &username, const std::string &password)
{
    eCore::User::UserItem item(m_User->db());
    item.append(eCore::User::Key::username,username);
    item.append(eCore::User::Key::password,password);

    auto val = m_User->db()->findOneItem(item);

    if( val ) {
        m_User->setDocumentView(val->view());
        m_Success.emit(NoClass());
    }
    else{
        //TODO: Login Failed Message
        std::cout << "Failed" << std::endl;
    }

}

} // namespace Account
