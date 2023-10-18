#include "LatestBlog.h"
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
namespace Body {

LatestBlog::LatestBlog()
{
    setHeight(650);

    decorationStyle().setBackgroundColor(Wt::StandardColor::Magenta);

    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());

    layout->addStretch(1);

    auto text = layout->addWidget(std::make_unique<Wt::WText>("<h1>Latest Blog</h1>"),0,Wt::AlignmentFlag::Center);

    layout->addStretch(1);
}

} // namespace Body
