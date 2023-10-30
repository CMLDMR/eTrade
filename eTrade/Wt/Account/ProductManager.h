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
    virtual void init();

    std::shared_ptr<CategoryModel> createCategoryModel();

    virtual void addProduct( const eCore::Product &item );

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // eCore::ProductManager interface
public:
    virtual void onList(const std::vector<eCore::Product> &mlist) override;

private:

    virtual void initHeader();

    void addNewProduct();
    eCore::CategoryManager* m_categoryManager;

    void changeProduct( const eCore::Product &product );
    void deleteProduct( const std::string &oid , const std::string &imgOid );
    void changeDetails( const eCore::Product &product );





};

} // namespace Account

#endif // ACCOUNT_PRODUCTMANAGER_H
