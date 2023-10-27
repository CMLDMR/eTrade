#include "UserManager.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"
#include "Wt/Widget/Text.h"
#include <Core/Text.h>

#include <Wt/WGridLayout.h>
#include <Wt/WPushButton.h>
#include <Wt/WComboBox.h>
#include <Wt/WLineEdit.h>
#include <Wt/WHBoxLayout.h>

using namespace Wt;

namespace Account {

UserManager::UserManager(MongoCore::DB *_mDB)
    :eCore::User::Manager(_mDB)
{

    init();
}

void UserManager::init()
{
    initHeader();
    initContent();

}

void UserManager::initHeader()
{
    header()->setMargin(15,Wt::Side::Top);

    auto rowContainer = header()->addNew<WContainerWidget>();
    rowContainer->addStyleClass(Bootstrap::Grid::row);

    auto container = rowContainer->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Grid::full(12));

    auto layout = container->setLayout(std::make_unique<WHBoxLayout>());
    layout->addStretch(1);


    auto newAddbtn = layout->addWidget(std::make_unique<Wt::WPushButton>(eCore::Text("Yeni Ekle").text()));
    newAddbtn->addStyleClass(Bootstrap::Components::Buttons::Size::Small+
                             Bootstrap::Components::Buttons::Outline::Primary);
    newAddbtn->clicked().connect(this,&UserManager::addNewUser);

    auto headerTitle1 = rowContainer->addNew<WText>(eCore::tr("Tip"));
    headerTitle1->addStyleClass(Bootstrap::Grid::full(4));
    headerTitle1->setAttributeValue(Style::style,Style::Border::right::border("1px solid lightgray")+Style::Border::left::border("1px solid lightgray"));

    auto headerTitle2 = rowContainer->addNew<WText>(eCore::tr("Kullanıcı Adı"));
    headerTitle2->addStyleClass(Bootstrap::Grid::full(4));
    headerTitle2->setAttributeValue(Style::style,Style::Border::right::border("1px solid lightgray"));

    auto headerTitle3 = rowContainer->addNew<WText>(eCore::tr("Onay?"));
    headerTitle3->addStyleClass(Bootstrap::Grid::full(4));
    headerTitle3->setAttributeValue(Style::style,Style::Border::right::border("1px solid lightgray"));

}

void UserManager::initContent()
{
    content()->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AntiqueWhite));
    UpdateList();
}


void UserManager::addNewUser()
{
    auto [mDialog,acceptBtn] = createDialog("Yeni Kullanıcı Ekle");
    mDialog->setWidth(640);

    auto mLayout = mDialog->contents()->setLayout(std::make_unique<WGridLayout>());

    mLayout->addWidget(std::make_unique<Widget::Text>(eCore::tr("Kullanıcı Tipi")),0,0,AlignmentFlag::Right)->setMinimumSize(200,WLength::Auto);
    auto userTypeComboBox = mLayout->addWidget(std::make_unique<WComboBox>(),0,1,AlignmentFlag::Justify);
    userTypeComboBox->addItem(eCore::tr("Bireysel"));
    userTypeComboBox->addItem(eCore::tr("Kurumsal"));
    userTypeComboBox->addItem(eCore::tr("Admin"));

    mLayout->addWidget(std::make_unique<Widget::Text>(eCore::tr("Kullanıcı Adı")),1,0,AlignmentFlag::Right)->setMinimumSize(200,WLength::Auto);
    auto userNameLineEdit = mLayout->addWidget(std::make_unique<WLineEdit>(),1,1,AlignmentFlag::Justify);
    userNameLineEdit->setPlaceholderText(eCore::tr("Kullanıcı Adını Giriniz"));

    mLayout->addWidget(std::make_unique<Widget::Text>(eCore::tr("Şifre")),2,0,AlignmentFlag::Right)->setMinimumSize(200,WLength::Auto);
    auto userPasswordLineEdit = mLayout->addWidget(std::make_unique<WLineEdit>(),2,1,AlignmentFlag::Justify);
    userPasswordLineEdit->setPlaceholderText(eCore::tr("Şifreyi Giriniz"));

    auto savebtn = mDialog->footer()->addNew<WPushButton>(eCore::tr("Kaydet"));

    savebtn->clicked().connect([=](){

        eCore::User::UserItem item;


        switch (userTypeComboBox->currentIndex()) {
        case 0:
            item.setType(eCore::User::UserItem::UserType::Client);
            break;
        case 1:
            item.setType(eCore::User::UserItem::UserType::Business);
            break;
        case 2:
            item.setType(eCore::User::UserItem::UserType::Admin);
            break;
        default:
            break;
        }

        item.setUserName(userNameLineEdit->text().toUTF8());
        item.setUserPassword(userPasswordLineEdit->text().toUTF8());

        auto ins = this->InsertItem(item);

        if( ins.size() ){
            this->UpdateList();
            removeDialog(mDialog);
        }else{
            //TODO: error Message Pop up
        }



    });

    mDialog->show();
}



} // namespace Account


void Account::UserManager::errorOccured(const std::string &errorText)
{
}

void Account::UserManager::onList(const std::vector<eCore::User::UserItem> &mList)
{

    content()->clear();

    for( const auto &item : mList ){

        auto typeContainer = content()->addNew<WText>("rtype");
        typeContainer->addStyleClass(Bootstrap::Grid::full(4));
        typeContainer->setAttributeValue(Style::style,Style::Border::right::border("1px solid lightgray"));

        auto nameContainer = content()->addNew<WText>(item.getUserName());
        nameContainer->addStyleClass(Bootstrap::Grid::full(4));
        nameContainer->setAttributeValue(Style::style,Style::Border::right::border("1px solid lightgray"));

        auto onayContainer = content()->addNew<WText>("NOT");
        onayContainer->addStyleClass(Bootstrap::Grid::full(4));
    }

}
