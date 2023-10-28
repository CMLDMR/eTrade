#ifndef ACCOUNT_CATEGORYMANAGER_H
#define ACCOUNT_CATEGORYMANAGER_H

#include <Wt/WAbstractListModel.h>

#include <Wt/Widget/ContainerWidget.h>
#include <Core/User.h>
#include <Core/Category.h>

namespace Account {


class CategoryManager : public Widget::ContainerWidget, public eCore::CategoryManager
{
public:
    CategoryManager( eCore::User::UserItem* mUser );


    // DB interface
public:
    virtual void errorOccured( const std::string &errorText ) override;

    // CategoryManager interface
public:
    virtual void onList( const std::vector<eCore::Category> &mlist ) override;

private:
    void init();
    void initHeader();

    void addNewCategory();
    void changeCategoryName();
};


class CategoryModel : public Wt::WAbstractListModel
{
public:
    CategoryModel( const std::vector<eCore::Category> &mlist );

    const eCore::Category &at( const int index ) const;

    // WAbstractItemModel interface
public:
    virtual int rowCount(const Wt::WModelIndex &parent) const override;
    virtual Wt::cpp17::any data(const Wt::WModelIndex &index, Wt::ItemDataRole role) const override;

private:
    std::vector<eCore::Category> m_categoryList;
};


} // namespace Account

#endif // ACCOUNT_CATEGORYMANAGER_H
