#ifndef BODY_PRODUCT_H
#define BODY_PRODUCT_H

#include <Wt/WContainerWidget.h>

#include <memory.h>

namespace Body {

class Product : public Wt::WContainerWidget
{
public:
    Product();

private:
    void init();

    void initHeader();

    std::unique_ptr<Wt::WContainerWidget> addProduct( const std::string &name,
                    const double price,
                    const double oldPrice,
                    const std::string &productUrl );

    Wt::WContainerWidget* m_ProductContainer{nullptr};
};

} // namespace Body

#endif // BODY_PRODUCT_H
