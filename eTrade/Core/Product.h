#ifndef ECORE_PRODUCT_H
#define ECORE_PRODUCT_H

#include <Core/Core_global.h>

#include <MongoCore/listitem.h>

namespace eCore {

class ECORE_EXPORT Product : public MongoCore::Item
{
public:
    Product();
};

} // namespace eCore

#endif // ECORE_PRODUCT_H
