#include "Widget.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"
#include "MenuBar.h"

#include <memory.h>

#include <Wt/WHBoxLayout.h>
#include <Wt/WLink.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace eCore::HeaderInfo;

namespace Header {

Widget::Widget(DB *_mDB)
    :eCore::HeaderInfo::MainHeaderInfoManager(_mDB)
{

    init();

}

Wt::Signal<NoClass> &Widget::clickAccount()
{
    return m_clickAccount;
}

void Widget::init()
{
    m_HeaderList = List();
    addStyleClass(Bootstrap::Grid::container_fluid);
    setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));

    m_AddressContainer = addNew<AddressContainer>();
    m_AddressContainer->addStyleClass(Bootstrap::Grid::container_fluid);


    m_MenuBar = addNew<MenuBar>();
    m_MenuBar->addStyleClass(Bootstrap::Grid::container_fluid);

    m_MenuBar->accoutContainer()->clicked().connect([=](){
        m_clickAccount.emit(NoClass());
    });

    UpdateList();

}

void Widget::errorOccured(const std::string &errorText)
{

}

void Widget::onList(const std::vector<eCore::HeaderInfo::MainHeaderInfo> &mlist)
{
    for( const auto &item : mlist ) {
        if( item.valueType() == MainHeaderInfo::DefinationKey::address ){
            m_AddressContainer->setAdress(item.value(MainHeaderInfo::Key::text).value().view().get_string().value.data());
        }

        if( item.valueType() == MainHeaderInfo::DefinationKey::mail ){
            m_AddressContainer->setMailAddress(item.value(MainHeaderInfo::Key::text).value().view().get_string().value.data(),
                                               item.value(MainHeaderInfo::Key::clickUrl).value().view().get_string().value.data());
        }
    }
}


AddressContainer::AddressContainer()
{
    init();
}

void AddressContainer::setAdress(const std::string &addressText)
{
    m_addressText->setText(addressText);
}

void AddressContainer::setMailAddress(const std::string &mailAddressText, const std::string &clickUrl)
{
    m_mailAnchor->setText(mailAddressText);
    m_mailAnchor->setLink(WLink(clickUrl));
}

void AddressContainer::init()
{
    setAttributeValue(Style::style,Style::Border::bottom::border("1px solid gray"));
    m_AddressLayout = setLayout(std::make_unique<Wt::WHBoxLayout>());

    m_AddressLayout->addSpacing(20);

    auto m_addressTextContainer = m_AddressLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    m_addressTextContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::DarkGray)+Style::color::color(Style::color::White::AliceBlue));
    m_addressText = m_addressTextContainer->addNew<WText>("Address");
    m_addressTextContainer->setPadding(15,Side::Left|Side::Right);

    auto m_mailIcon = m_AddressLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    m_mailIcon->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::DarkGray)+Style::color::color(Style::color::White::AliceBlue));
    m_mailIcon->setPadding(15,Side::Left|Side::Right);

    Wt::WLink eMaillink = Wt::WLink("https://www.webtoolkit.eu/");
    eMaillink.setTarget(Wt::LinkTarget::NewWindow);

    std::unique_ptr<Wt::WAnchor> anchor =
        std::make_unique<Wt::WAnchor>(eMaillink,
                                      "Wt homepage (in a new window)");

    m_mailAnchor = anchor.get();
    m_mailIcon->addWidget(std::move(anchor));


    m_AddressLayout->addStretch(1);


    auto m_socialIcon = m_AddressLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    m_socialIcon->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::DarkGray)+Style::color::color(Style::color::White::AliceBlue));
    m_socialIcon->addNew<WText>("Follow us:");
    m_socialIcon->setPadding(15,Side::Left|Side::Right);

    auto m_socialFaceIcon = m_AddressLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    m_socialFaceIcon->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::DarkGray)+Style::color::color(Style::color::White::AliceBlue));
    m_socialFaceIcon->addNew<WText>("F");
    m_socialFaceIcon->setPadding(15,Side::Left|Side::Right);

    auto m_socialTwitterIcon = m_AddressLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    m_socialTwitterIcon->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::DarkGray)+Style::color::color(Style::color::White::AliceBlue));
    m_socialTwitterIcon->addNew<WText>("T");
    m_socialTwitterIcon->setPadding(15,Side::Left|Side::Right);

    auto m_socialLinkedIcon = m_AddressLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    m_socialLinkedIcon->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::DarkGray)+Style::color::color(Style::color::White::AliceBlue));
    m_socialLinkedIcon->addNew<WText>("L");
    m_socialLinkedIcon->setPadding(15,Side::Left|Side::Right);

    auto m_socialinstIcon = m_AddressLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    m_socialinstIcon->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::DarkGray)+Style::color::color(Style::color::White::AliceBlue));
    m_socialinstIcon->addNew<WText>("I");
    m_socialinstIcon->setPadding(15,Side::Left|Side::Right);


    m_AddressLayout->addSpacing(20);
}

} // namespace Header


