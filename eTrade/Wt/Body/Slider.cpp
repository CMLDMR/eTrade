#include "Slider.h"
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include "Bootstrap/inlinestyle.h"
#include "Bootstrap/Bootstrap5ThemaKeys.h"
#include "Wt/WApplication.h"

using namespace Wt;

namespace Body {

Slider::Slider(eCore::User::UserItem *mUser)
    :eCore::SliderManager(mUser)
{
    init();
    UpdateList();

}

void Slider::addSlide(const std::string &title, const std::string &backgroundImg )
{

    auto container = std::make_unique<WContainerWidget>();

    container->setAttributeValue(Style::style,Style::background::url(backgroundImg)+
                                                   Style::background::size::cover+
                                                   Style::background::repeat::norepeat);


    auto layout = container->setLayout(std::make_unique<WVBoxLayout>());
    layout->addStretch(1);
    auto titleText = layout->addWidget(std::make_unique<WText>("<h1>"+title+"</h1>"));
    titleText->setTextAlignment(AlignmentFlag::Center);
    layout->addStretch(1);
    container->setHeight(650);

    insertWidget(0,std::move(container));

}

void Slider::init()
{

    clicked().connect([=](){
        setCurrentIndex((currentIndex()+1)%count());
    });

}

} // namespace Body


void Body::Slider::errorOccured(const std::string &errorText)
{
}

void Body::Slider::onList(const std::vector<eCore::Slider> &mlist)
{
//    clear();

    //TODO: Slider Sekiyor ama ekran değişmiyor
    int index = 0;
    for( const auto &item : mlist ){
        std::string title = item.value(eCore::Slider::Key::text).value().view().get_string().value.data();
        auto imgUrl = downloadFileWeb(item.value(eCore::Slider::Key::imgOid).value().view().get_oid().value.to_string(),wApp->docRoot());
        addSlide(title,imgUrl);
    }

}
