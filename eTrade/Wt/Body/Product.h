#ifndef BODY_PRODUCT_H
#define BODY_PRODUCT_H


#include <Wt/Account/ProductManager.h>
#include <Wt/Widget/ContainerWidget.h>
#include <memory.h>

namespace Body {

class Product : public Account::ProductManager
{
public:
    Product( eCore::User::UserItem* mUser );
    virtual void init() override;

private:

    virtual void initHeader() override;



    // ProductManager interface
public:
    virtual void addProduct(const eCore::Product &item) override;
};

} // namespace Body

#endif // BODY_PRODUCT_H
