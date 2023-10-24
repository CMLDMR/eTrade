#include "HeaderInfo.h"

#include <Wt/WGridLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>

#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"
#include "Core/Text.h"

using namespace eCore::HeaderInfo;

namespace Account {

HeaderInfo::HeaderInfo(eCore::User::UserItem *mUser)
    :eCore::HeaderInfo::MainHeaderInfoManager(mUser->db())
{
    init();

    UpdateList();
}

} // namespace Account


void Account::HeaderInfo::errorOccured(const std::string &errorText)
{

}

void Account::HeaderInfo::onList(const std::vector<eCore::HeaderInfo::MainHeaderInfo> &mlist)
{
    for( const auto &item : mlist ) {
        if( item.valueType() == MainHeaderInfo::DefinationKey::address ){
            if( m_adresLineEdit ) {
                m_adresLineEdit->setText(item.value(MainHeaderInfo::Key::text).value().view().get_string().value.data());
                m_adresLineEdit->setAttributeValue(Style::dataoid,item.oid().value().to_string());
            }
        }

        if( item.valueType() == MainHeaderInfo::DefinationKey::mail ){
            if( m_mailadresLineEdit && m_mainUrlAddressLine ) {
                m_mailadresLineEdit->setText(item.value(MainHeaderInfo::Key::text).value().view().get_string().value.data());
                m_mailadresLineEdit->setAttributeValue(Style::dataoid,item.oid().value().to_string());
                m_mainUrlAddressLine->setText(item.value(MainHeaderInfo::Key::clickUrl).value().view().get_string().value.data());
            }
        }
    }
}

void Account::HeaderInfo::init()
{
    auto pageTitleContainer = header()->addNew<Wt::WText>("<h4>"+eCore::tr("Header Bilgileri")+"</h4>");


{
    auto addressLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    m_adresLineEdit = addressLineEditContainer->addNew<Wt::WLineEdit>();
    addressLineEditContainer->addStyleClass(Bootstrap::Grid::full(10));
    m_adresLineEdit->setPlaceholderText(eCore::tr("Adres Bilgisi"));

    auto adresDegisBtn = content()->addNew<Wt::WPushButton>(eCore::tr("Adres Bilgisi Değiştir"));
    adresDegisBtn->addStyleClass(Bootstrap::Components::Buttons::Normal::Success);
    adresDegisBtn->addStyleClass(Bootstrap::Grid::full(2));

    adresDegisBtn->clicked().connect(this,&Account::HeaderInfo::updateAddress);
}

{
    auto blank = content()->addNew<Wt::WContainerWidget>();
    blank->addStyleClass(Bootstrap::Grid::full(12));
    blank->setHeight(5);

    auto addressLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    addressLineEditContainer->addStyleClass(Bootstrap::Grid::full(5));

    m_mailadresLineEdit = addressLineEditContainer->addNew<Wt::WLineEdit>();
    m_mailadresLineEdit->setPlaceholderText(eCore::tr("eMail Bilgisi"));

    auto emailLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    emailLineEditContainer->addStyleClass(Bootstrap::Grid::full(5));

    m_mainUrlAddressLine = emailLineEditContainer->addNew<Wt::WLineEdit>();
    m_mainUrlAddressLine->setPlaceholderText(eCore::tr("url( mailto:test@test.net )"));

    auto adresDegisBtn = content()->addNew<Wt::WPushButton>(eCore::tr("eMail Bilgisi Değiştir"));
    adresDegisBtn->addStyleClass(Bootstrap::Components::Buttons::Normal::Success);
    adresDegisBtn->addStyleClass(Bootstrap::Grid::full(2));
    adresDegisBtn->clicked().connect(this,&Account::HeaderInfo::updateMailAddress);

}

{
    auto blank = content()->addNew<Wt::WContainerWidget>();
    blank->addStyleClass(Bootstrap::Grid::full(12));
    blank->setHeight(5);

    auto addressLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    auto addressLine = addressLineEditContainer->addNew<Wt::WLineEdit>();
    addressLineEditContainer->addStyleClass(Bootstrap::Grid::full(10));
    addressLine->setPlaceholderText(eCore::tr("Facebook URL"));

    auto adresDegisBtn = content()->addNew<Wt::WPushButton>(eCore::tr("Değiştir"));
    adresDegisBtn->addStyleClass(Bootstrap::Components::Buttons::Normal::Success);
    adresDegisBtn->addStyleClass(Bootstrap::Grid::full(2));
}

{
    auto blank = content()->addNew<Wt::WContainerWidget>();
    blank->addStyleClass(Bootstrap::Grid::full(12));
    blank->setHeight(5);

    auto addressLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    auto addressLine = addressLineEditContainer->addNew<Wt::WLineEdit>();
    addressLineEditContainer->addStyleClass(Bootstrap::Grid::full(10));
    addressLine->setPlaceholderText(eCore::tr("Twitter URL"));

    auto adresDegisBtn = content()->addNew<Wt::WPushButton>(eCore::tr("Değiştir"));
    adresDegisBtn->addStyleClass(Bootstrap::Components::Buttons::Normal::Success);
    adresDegisBtn->addStyleClass(Bootstrap::Grid::full(2));
}

{
    auto blank = content()->addNew<Wt::WContainerWidget>();
    blank->addStyleClass(Bootstrap::Grid::full(12));
    blank->setHeight(5);

    auto addressLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    auto addressLine = addressLineEditContainer->addNew<Wt::WLineEdit>();
    addressLineEditContainer->addStyleClass(Bootstrap::Grid::full(10));
    addressLine->setPlaceholderText(eCore::tr("Linkedin URL"));

    auto adresDegisBtn = content()->addNew<Wt::WPushButton>(eCore::tr("Değiştir"));
    adresDegisBtn->addStyleClass(Bootstrap::Components::Buttons::Normal::Success);
    adresDegisBtn->addStyleClass(Bootstrap::Grid::full(2));
}

{
    auto blank = content()->addNew<Wt::WContainerWidget>();
    blank->addStyleClass(Bootstrap::Grid::full(12));
    blank->setHeight(5);

    auto addressLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    auto addressLine = addressLineEditContainer->addNew<Wt::WLineEdit>();
    addressLineEditContainer->addStyleClass(Bootstrap::Grid::full(10));
    addressLine->setPlaceholderText(eCore::tr("Instagram URL"));

    auto adresDegisBtn = content()->addNew<Wt::WPushButton>(eCore::tr("Değiştir"));
    adresDegisBtn->addStyleClass(Bootstrap::Components::Buttons::Normal::Success);
    adresDegisBtn->addStyleClass(Bootstrap::Grid::full(2));
}

//TODO: Logo Değiştirme Eklenecek

}

void Account::HeaderInfo::updateAddress()
{
    MainHeaderInfo infoItem;
    infoItem.setDefination(MainHeaderInfo::Key::defination,MainHeaderInfo::DefinationKey::address);

    auto count = countItem(infoItem);
    if( count == 0 ) {
        infoItem.setValue(MainHeaderInfo::Key::text,m_adresLineEdit->text().toUTF8());
        auto ins = InsertItem(infoItem);
        if( ins.size() ) {
                //TODO: updated information appearing must implement
        }
    }else{
        infoItem.setOid(m_adresLineEdit->attributeValue(Style::dataoid).toUTF8());
        infoItem.setValue(MainHeaderInfo::Key::text,m_adresLineEdit->text().toUTF8());
        auto upt = UpdateItem(infoItem);
        if( upt ) {
                //TODO: updated information appearing must implement
        }
    }
}

void Account::HeaderInfo::updateMailAddress()
{
    MainHeaderInfo infoItem;

    auto count = countItem(infoItem);
    if( count == 0 ) {
        infoItem.setDefination(MainHeaderInfo::Key::defination,MainHeaderInfo::DefinationKey::mail);
        infoItem.setValue(MainHeaderInfo::Key::text,m_mailadresLineEdit->text().toUTF8());
        infoItem.setValue(MainHeaderInfo::Key::clickUrl,m_mainUrlAddressLine->text().toUTF8());

        auto ins = InsertItem(infoItem);
        if( ins.size() ) {
            //TODO: updated information appearing must implement
        }
    }else{
        infoItem.setOid(m_mailadresLineEdit->attributeValue(Style::dataoid).toUTF8());
        infoItem.setDefination(MainHeaderInfo::Key::defination,MainHeaderInfo::DefinationKey::mail);
        infoItem.setValue(MainHeaderInfo::Key::text,m_mailadresLineEdit->text().toUTF8());
        infoItem.setValue(MainHeaderInfo::Key::clickUrl,m_mainUrlAddressLine->text().toUTF8());

        auto upt = UpdateItem(infoItem);
        if( upt ) {
            //TODO: updated information appearing must implement
        }
    }
}
