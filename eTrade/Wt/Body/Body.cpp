#include "Body.h"

#include <Wt/Body/Slider.h>
#include <Wt/Body/Section.h>
#include "Wt/Body/Feature.h"
#include "Wt/Body/Product.h"
//#include "Wt/Body/Visitor.h"
//#include "Wt/Body/CustomerReview.h"
//#include "Wt/Body/LatestBlog.h"



using namespace Wt;

Body::Body::Body(eCore::User::UserItem *mUser)
    :m_User(mUser)
{
    init();
}

void Body::Body::init()
{
    clear();
    auto slider = addNew<Slider>(m_User);
    auto section = addNew<Section>();
    auto feature = addNew<Feature>();
    auto m_productManager = addNew<Product>(m_User);
    m_productManager->init();

    //TODO: Daha sonra bakilacak
    //    auto visitor = root()->addNew<Body::Visitor>();
    //    auto customer = root()->addNew<Body::CustomerReview>();
    //    root()->addNew<Body::LatestBlog>();
}
