#include "Product.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"

#include <Wt/WApplication.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>

#include "Wt/Account/CategoryManager.h"

using namespace Wt;

namespace Body {

Product::Product(eCore::User::UserItem* mUser)
    :Account::ProductManager(mUser)
{
    setAttributeValue(Style::style,Style::background::color::color(Style::color::White::OldLace));
}

void Product::init()
{
    setPadding( 50 , Side::Top|Side::Bottom );
    initHeader();
    UpdateList();
}

void Product::initHeader()
{
    header()->setMargin( 10 , Side::Bottom );
    auto textTitle = header()->addNew<WText>("<h1>Our Products</h1>");
    textTitle->addStyleClass(Bootstrap::Grid::full(12));
    textTitle->setTextAlignment(AlignmentFlag::Left);

    auto titleExpand = header()->addNew<WContainerWidget>();
    titleExpand->addStyleClass(Bootstrap::Grid::full(8));
    titleExpand->setContentAlignment(AlignmentFlag::Left);
    titleExpand->addWidget(std::make_unique<WText>("Tempor ut dolore lorem kasd vero ipsum sit eirmod sit.."));


    auto m_catControlContainer = header()->addNew<WContainerWidget>();
    m_catControlContainer->addStyleClass(Bootstrap::Grid::full(4)+Bootstrap::Components::Buttons::group);

    auto m_categoryList = createCategoryModel();
    for( int i = 0 ; i < m_categoryList->size(); i++ ) {
        auto item = m_categoryList->at(i);
        auto btnName = item.value(eCore::Category::Key::text).value().view().get_string().value.data();
        auto catBtn = m_catControlContainer->addWidget(std::make_unique<WPushButton>(btnName));
        catBtn->addStyleClass(Bootstrap::Components::Buttons::Size::Small + Bootstrap::Components::Buttons::Outline::Success);
        catBtn->clicked().connect([=, this](){
            eCore::Product filter;
            filter.setValue(eCore::Product::Key::categoryOid,item.oid().value());
            UpdateList(filter);
        });
    }

    auto catBtn = m_catControlContainer->addWidget(std::make_unique<WPushButton>("Hepsi"));
    catBtn->addStyleClass( Bootstrap::Components::Buttons::Size::Small + Bootstrap::Components::Buttons::Outline::Primary );
    catBtn->clicked().connect([=, this](){
        UpdateList();
    });

    auto moreProductContainer = footer()->addNew<WContainerWidget>();
    moreProductContainer->addStyleClass( Bootstrap::Grid::container_fluid );
    moreProductContainer->setContentAlignment( AlignmentFlag::Center );
    auto moreProductBtn = moreProductContainer->addNew<WPushButton>("Browse More Product");
    moreProductBtn->setMargin(25,Side::Top);

}


} // namespace Body

