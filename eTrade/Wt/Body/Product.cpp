#include "Product.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Bootstrap/inlinestyle.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>

using namespace Wt;

namespace Body {

Product::Product()
{

    init();

}

void Product::init()
{
    setContentAlignment(AlignmentFlag::Center);
    setPadding(50,Side::Top|Side::Bottom);
    initHeader();
}

void Product::initHeader()
{

    auto headerContainer = addNew<WContainerWidget>();
    headerContainer->addStyleClass(Bootstrap::Grid::container_fluid);
    headerContainer->setMaximumSize(1280,WLength::Auto);

    auto textTitle = headerContainer->addNew<WText>("<h1>Our Products</h1>");
    textTitle->addStyleClass(Bootstrap::Grid::full(12));
    textTitle->setTextAlignment(AlignmentFlag::Left);

    auto titleExpand = headerContainer->addNew<WContainerWidget>();
    titleExpand->addStyleClass(Bootstrap::Grid::full(12));

    auto hLayout = titleExpand->setLayout(std::make_unique<WHBoxLayout>());
    auto textExpand = hLayout->addWidget(std::make_unique<WText>("Tempor ut dolore lorem kasd vero ipsum sit eirmod sit. Ipsum diam justo sed rebum vero dolor duo."));
    textExpand->setMaximumSize(450,WLength::Auto);
    textExpand->setTextAlignment(AlignmentFlag::Left);
    hLayout->addStretch(1);

    auto vegetableBtn = hLayout->addWidget(std::make_unique<WPushButton>("Vegetable"));
    auto fruitsBtn = hLayout->addWidget(std::make_unique<WPushButton>("Fruits"));
    auto freshBtn = hLayout->addWidget(std::make_unique<WPushButton>("Fresh"));

    vegetableBtn->addStyleClass(Bootstrap::Components::Buttons::Success);
    fruitsBtn->addStyleClass(Bootstrap::Components::Buttons::Success);
    freshBtn->addStyleClass(Bootstrap::Components::Buttons::Success);


    m_ProductContainer = addNew<WContainerWidget>();
    m_ProductContainer->addStyleClass(Bootstrap::Grid::row);
    m_ProductContainer->setMaximumSize(1280,WLength::Auto);

    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-1.jpg")));
    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-2.jpg")));
    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-3.jpg")));
    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-4.jpg")));

    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-5.jpg")));
    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-6.jpg")));
    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-7.jpg")));
    m_ProductContainer->addWidget(std::move(addProduct("Fresh Tomato",19.00,18.55,"img/product-8.jpg")));


    auto moreProductContainer = addNew<WContainerWidget>();
    moreProductContainer->addStyleClass(Bootstrap::Grid::container_fluid);
    moreProductContainer->setContentAlignment(AlignmentFlag::Center);
    auto moreProductBtn = moreProductContainer->addNew<WPushButton>("Browse More Product");


}

std::unique_ptr<WContainerWidget> Product::addProduct(const std::string &name, const double price, const double oldPrice, const std::string &productUrl)
{

    auto container = std::make_unique<WContainerWidget>();
    container->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::GhostWhite));
    container->addStyleClass(Bootstrap::Grid::xxl(3)+
                             Bootstrap::Grid::xl(3)+
                             Bootstrap::Grid::lg(3)+
                             Bootstrap::Grid::md(3)+
                             Bootstrap::Grid::sm(4)+
                             Bootstrap::Grid::xs(6));

    auto vLayout = container->setLayout(std::make_unique<WVBoxLayout>());

    auto img = vLayout->addWidget(std::make_unique<WImage>(WLink(productUrl)));

    auto nameContainer = vLayout->addWidget(std::make_unique<WText>("<h3>"+name+"</h3>"));

    auto priceContainer = vLayout->addWidget(std::make_unique<WText>("<h5>"+std::to_string(price)+"</h5>"));

    auto detailContainer = vLayout->addWidget(std::make_unique<WContainerWidget>());

    auto hLayout = detailContainer->setLayout(std::make_unique<WHBoxLayout>());

    auto detailBtn = hLayout->addWidget(std::make_unique<WText>("View Detail"));
    auto addToChart = hLayout->addWidget(std::make_unique<WText>("Add to Chart"));

    return container;
}

} // namespace Body
