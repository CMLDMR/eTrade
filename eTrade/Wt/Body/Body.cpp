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
{




    auto slider = addNew<Slider>(mUser);


    auto section = addNew<Section>();
    auto feature = addNew<Feature>();
    auto m_productManager = addNew<Product>(mUser);
    m_productManager->init();

    //TODO: Daha sonra bakilacak
    //    auto visitor = root()->addNew<Body::Visitor>();
    //    auto customer = root()->addNew<Body::CustomerReview>();
    //    root()->addNew<Body::LatestBlog>();


}
