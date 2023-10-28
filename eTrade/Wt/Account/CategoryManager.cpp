#include "CategoryManager.h"

#include <Wt/WApplication.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include <Core/Text.h>

#include <Bootstrap/Bootstrap5ThemaKeys.h>
#include <Bootstrap/inlinestyle.h>

using namespace Wt;

namespace Account {

CategoryManager::CategoryManager(eCore::User::UserItem *mUser)
    :eCore::CategoryManager(mUser)
{
    init();
}


} // namespace Account


void Account::CategoryManager::errorOccured( const std::string &errorText )
{
}

void Account::CategoryManager::onList( const std::vector<eCore::Category> &mlist )
{
    content()->clear();

    for( const auto &item : mlist ) {

        auto container = content()->addNew<WContainerWidget>();
        container->addStyleClass(Bootstrap::Grid::full(4)+Bootstrap::Utilities::Shadow::shadow_sm);
        container->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::LavenderBlush));

        container->setMargin(5,Side::Bottom);

        auto m_hLayout = container->setLayout(std::make_unique<WHBoxLayout>());

        m_hLayout->addStretch(1);

        auto m_cateText = item.value(eCore::Category::Key::text);
        if( m_cateText ) {
            m_hLayout->addWidget(std::make_unique<WText>(eCore::tr(m_cateText.value().view().get_string().value.data())));
        }
        else{
            m_hLayout->addWidget(std::make_unique<WText>(eCore::tr(item.errorStr())));
        }

        m_hLayout->addStretch(1);

        auto m_changeBtn = m_hLayout->addWidget(std::make_unique<WPushButton>(eCore::tr("Değiştir")));
        m_changeBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Warning+Bootstrap::Components::Buttons::Size::Small);

        auto m_delBtn = m_hLayout->addWidget(std::make_unique<WPushButton>(eCore::tr("Sil")));
        m_delBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Danger+Bootstrap::Components::Buttons::Size::Small);
    }
}

void Account::CategoryManager::init()
{
    initHeader();

    UpdateList();
}

void Account::CategoryManager::initHeader()
{
    auto m_hlayout = header()->setLayout(std::make_unique<WHBoxLayout>());

    m_hlayout->addStretch(1);
    m_hlayout->addWidget(std::make_unique<WText>(eCore::tr("<h4>Kategoriler</h4>")));
    m_hlayout->addStretch(1);

    auto m_addNewBtn = m_hlayout->addWidget(std::make_unique<WPushButton>(eCore::tr("Yeni Ekle+")));
    m_addNewBtn->addStyleClass(Bootstrap::Components::Buttons::Outline::Primary+Bootstrap::Components::Buttons::Size::Small);
    m_addNewBtn->clicked().connect(this,&CategoryManager::addNewCategory);
}

void Account::CategoryManager::addNewCategory()
{

    auto [mDialog,acceptBtn] = createDialog(eCore::tr("Yeni Kategori Ekle+"),eCore::tr("Kaydet"));

    auto m_categoryNameLineEdit = mDialog->contents()->addNew<WLineEdit>();
    m_categoryNameLineEdit->setPlaceholderText(eCore::tr("Kategori Adını Giriniz"));

    acceptBtn->clicked().connect([=, this](){

        eCore::Category item;
        item.setValue(eCore::Category::Key::text,m_categoryNameLineEdit->text().toUTF8());

        auto ins = this->InsertItem(item);
        if( ins.size() ) {
            showInfo(eCore::tr("Başarılı Bir Şekilde Eklendi."),Widget::ContainerWidget::InfoType::info);
            wApp->removeChild(mDialog);
            UpdateList();
        }else{
            showInfo(getLastError(),Widget::ContainerWidget::InfoType::error);
        }
    });

    mDialog->show();
}

void Account::CategoryManager::changeCategoryName()
{

}



Account::CategoryModel::CategoryModel(const std::vector<eCore::Category> &mlist)
    :m_categoryList(mlist)
{

}

const eCore::Category &Account::CategoryModel::at(const int index) const
{
    return m_categoryList.at(index);
}

int Account::CategoryModel::size() const
{
    return m_categoryList.size();
}

int Account::CategoryModel::rowCount(const Wt::WModelIndex &parent) const
{
    return m_categoryList.size();
}

cpp17::any Account::CategoryModel::data(const Wt::WModelIndex &index, Wt::ItemDataRole role) const
{
    if( index.row() < 0 || index.row() >= m_categoryList.size() )
        return cpp17::any();


    if( role == ItemDataRole::Display ) {
        auto item = m_categoryList.at(index.row());
        auto val = item.value(eCore::Category::Key::text);
        if( ! val )
            return cpp17::any();
        return val.value().view().get_string().value.data();
    }

    if( role == ItemDataRole::User+1 ) {
        auto item = m_categoryList.at(index.row());
        auto val = item.oid();
        if( ! val )
            return cpp17::any();
        return val.value().to_string();
    }

    return cpp17::any();
}
