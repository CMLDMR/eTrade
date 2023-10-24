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

    adresDegisBtn->clicked().connect([=](){
        MainHeaderInfo infoItem;

        auto count = countItem(infoItem);
        if( count == 0 ) {
            infoItem.setDefination(MainHeaderInfo::Key::defination,MainHeaderInfo::DefinationKey::address);
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
    });
}

{
    auto blank = content()->addNew<Wt::WContainerWidget>();
    blank->addStyleClass(Bootstrap::Grid::full(12));
    blank->setHeight(5);

    auto addressLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    auto addressLine = addressLineEditContainer->addNew<Wt::WLineEdit>();
    addressLineEditContainer->addStyleClass(Bootstrap::Grid::full(5));
    addressLine->setPlaceholderText(eCore::tr("eMail Bilgisi"));

    auto emailLineEditContainer = content()->addNew<Wt::WContainerWidget>();
    emailLineEditContainer->addStyleClass(Bootstrap::Grid::full(5));

    auto emailLine = emailLineEditContainer->addNew<Wt::WLineEdit>();
    emailLine->setPlaceholderText(eCore::tr("url( mailto:test@test.net )"));

    auto adresDegisBtn = content()->addNew<Wt::WPushButton>(eCore::tr("eMail Bilgisi Değiştir"));
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
