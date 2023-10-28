#ifndef BOOTSTRAP5THEMAKEYS_H
#define BOOTSTRAP5THEMAKEYS_H

#include <string_view>
#include <string>
#include "Bootstrap/BootstrapThemaKeys_global.h"

#ifdef _MSC_VER
#pragma warning(disable: 4251) // disable warning 4345
#endif

//https://getbootstrap.com/docs/5.0/layout/grid/

namespace Bootstrap{

namespace Grid {

inline const std::string container{"container "};
inline const std::string container_fluid{"container-fluid "};

inline const std::string row{"row "};
inline const std::string col{"col "};

const BOOTSRAPTHEMEKEYS_EXPORT std::string xs( const int index );
const BOOTSRAPTHEMEKEYS_EXPORT std::string sm( const int index );
const BOOTSRAPTHEMEKEYS_EXPORT std::string md( const int index );
const BOOTSRAPTHEMEKEYS_EXPORT std::string lg( const int index );
const BOOTSRAPTHEMEKEYS_EXPORT std::string xl( const int index );
const BOOTSRAPTHEMEKEYS_EXPORT std::string xxl( const int index );
const BOOTSRAPTHEMEKEYS_EXPORT std::string full( const int index );

}


namespace Components {

namespace Carousel {
inline const std::string carousel{"carousel "};
inline const std::string slide{"slide "};
inline const std::string carousel_indicators{"carousel-indicators "};
inline const std::string carousel_inner{"carousel-inner"};

}

namespace Buttons{

inline const std::string group{"btn-group "};

namespace Normal{
inline const std::string Primary{"btn-primary "};
inline const std::string Secondary{"btn-secondary "};
inline const std::string Success{"btn-success "};
inline const std::string Danger{"btn-danger "};
inline const std::string Warning{"btn-warning "};
inline const std::string Info{"btn-info "};
inline const std::string Light{"btn-light "};
inline const std::string Dark{"btn-dark "};
inline const std::string Link{"btn-link "};
}

namespace Outline{
inline const std::string Primary{"btn-outline-primary "};
inline const std::string Secondary{"btn-outline-secondary "};
inline const std::string Success{"btn-outline-success "};
inline const std::string Danger{"btn-outline-danger "};
inline const std::string Warning{"btn-outline-warning "};
inline const std::string Info{"btn-outline-info "};
inline const std::string Light{"btn-outline-light "};
inline const std::string Dark{"btn-outline-dark "};
inline const std::string Link{"btn-outline-link "};
}

namespace Size{
inline const std::string Large{"btn-lg "};
inline const std::string Small{"btn-sm "};
}

}
}


namespace Utilities {

namespace Display{
inline const std::string hide_all{"d-none "};
inline const std::string hide_xs{"d-none "};
inline const std::string hide_sm{"d-none d-sm-block "};
inline const std::string hide_md{"d-sm-none d-md-block "};
inline const std::string hide_lg{"d-md-none d-lg-block "};
inline const std::string hide_xl{"d-lg-none d-xl-block "};
inline const std::string hide_xxl{"d-xl-none d-xxl-block "};
}

namespace Border {
namespace Additive{
inline const std::string border{"border"};
inline const std::string border_top{"border-top"};
inline const std::string border_end{"border-end"};
inline const std::string border_bottom{"border-bottom"};
inline const std::string border_start{"border-start"};
}

namespace Size {
inline const std::string rounded_0{"rounded-0"};
inline const std::string rounded_1{"rounded-1"};
inline const std::string rounded_2{"rounded-2"};
inline const std::string rounded_3{"rounded-3"};
}

}

namespace Background {

inline const std::string gradient{"bg-gradient "};
inline const std::string bg_primary{"bg-primary "};
inline const std::string bg_secondary{"bg-secondary "};
inline const std::string bg_success{"bg-success "};
inline const std::string bg_danger{"bg-danger "};
inline const std::string bg_warning{"bg-warning "};
inline const std::string bg_info{"bg-info "};
inline const std::string bg_light{"bg-light "};
inline const std::string bg_dark{"bg-dark "};
}

namespace Shadow {
inline const std::string shadow_sm{"shadow-sm "};
inline const std::string shadow{"shadow "};
inline const std::string shadow_lg{"shadow-lg "};
}


}
}


#endif // BOOTSTRAP5THEMAKEYS_H
