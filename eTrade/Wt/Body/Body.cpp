#include "Body.h"

using namespace Wt;

Body::Body::Body()
{




    auto slider = addNew<Slider>();


    auto section = addNew<Section>();
    auto feature = addNew<Feature>();
    auto product = addNew<Product>();
    //TODO: Daha sonra bakilacak
    //    auto visitor = root()->addNew<Body::Visitor>();
    //    auto customer = root()->addNew<Body::CustomerReview>();
    //    root()->addNew<Body::LatestBlog>();


}
