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
#include "Wt/Widget/Text.h"

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




void Body::Product::addProduct(const eCore::Product &item)
{
    auto rcontainer = content()->addNew<WContainerWidget>();
    rcontainer->addStyleClass( Bootstrap::Grid::full( 3 ) );
    rcontainer->setMargin( 10 , Side::Bottom );

    auto container = rcontainer->addNew<WContainerWidget>();
    container->addStyleClass(Bootstrap::Utilities::Background::bg_primary+
                             Bootstrap::Utilities::Background::bg_light+
                             Bootstrap::Utilities::Shadow::shadow_lg);

    auto m_vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    auto m_imgOid = item.value(eCore::Product::Key::imgOid);
    if( m_imgOid ) {
        auto m_imgUrl = downloadFileWeb(m_imgOid.value().view().get_oid().value.to_string(),wApp->docRoot());
        auto m_img = m_vLayout->addWidget(std::make_unique<WImage>(WLink(m_imgUrl)));
        m_img->setHeight(250);
        m_img->setWidth(WLength::Auto);
    }
    else {
        auto m_img = m_vLayout->addWidget(std::make_unique<WImage>(WLink("img/imgerror.jpg")));
        m_img->setHeight(250);
        m_img->setWidth(WLength::Auto);
    }
    auto m_titleVal = item.value(eCore::Product::Key::urunAdi);
    if( m_titleVal ) {
        auto m_titleText = m_vLayout->addWidget(std::make_unique<WText>(m_titleVal.value().view().get_string().value.data()));
    }
    else {
        m_vLayout->addWidget(std::make_unique<WText>(item.errorStr()));
    }

    auto m_catVal = item.value(eCore::Product::Key::category);
    if( m_catVal ) {
        auto m_catText = m_vLayout->addWidget(std::make_unique<WText>(m_catVal.value().view().get_string().value.data()));
    }
    else {
        m_vLayout->addWidget(std::make_unique<WText>(item.errorStr()));
    }

    auto m_priceVal = item.value(eCore::Product::Key::price);
    if( m_priceVal ) {
        auto m_priceText = m_vLayout->addWidget(std::make_unique<WText>(WString("{1} TUUL").arg(m_priceVal.value().view().get_double().value)));
    }
    else {
        m_vLayout->addWidget(std::make_unique<WText>(item.errorStr()));
    }

    auto m_btnController = m_vLayout->addWidget(std::make_unique<WContainerWidget>());
    m_btnController->addStyleClass(Bootstrap::Grid::row+Bootstrap::Components::Buttons::group);

    auto m_viewDetailsBtn = m_btnController->addNew<WPushButton>(eCore::tr("Detay"));
    m_viewDetailsBtn->addStyleClass(Bootstrap::Grid::full(6)+Bootstrap::Components::Buttons::Outline::Danger+Bootstrap::Components::Buttons::Size::Small);
    m_viewDetailsBtn->clicked().connect([=](){
        auto mDialog  = createInfoDialog("Ürün Detayı");

        auto m_context = mDialog->contents()->addNew<WText>("");
        auto m_explainValue = item.value(eCore::Product::Key::explainHtml);
        if ( m_explainValue ) {
            m_context->setText( m_explainValue.value().view().get_string().value.data() );
        }
        mDialog->show();
    });

    auto m_addToCartbtn = m_btnController->addNew<WPushButton>(eCore::tr("Sepete Ekle"));
    m_addToCartbtn->addStyleClass(Bootstrap::Grid::full(6)+Bootstrap::Components::Buttons::Outline::Success+Bootstrap::Components::Buttons::Size::Small);


}
