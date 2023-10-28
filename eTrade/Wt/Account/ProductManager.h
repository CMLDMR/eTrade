#ifndef ACCOUNT_PRODUCTMANAGER_H
#define ACCOUNT_PRODUCTMANAGER_H

#include <Core/Product.h>
#include <Wt/Widget/ContainerWidget.h>
#include <Core/User.h>
#include <Core/Category.h>

namespace Account {

class CategoryModel;


class ProductManager : public Widget::ContainerWidget, public eCore::ProductManager
{
public:
    ProductManager( eCore::User::UserItem* mUser );

    std::shared_ptr<CategoryModel> createCategoryModel();


    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ProductManager interface
public:
    virtual void onList(const std::vector<eCore::Product> &mlist) override;

private:

    void init();
    void initHeader();

    void addNewProduct();
    eCore::CategoryManager* m_categoryManager;



};

} // namespace Account

#endif // ACCOUNT_PRODUCTMANAGER_H
