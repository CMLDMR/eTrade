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
namespace Buttons{
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
}


}


#endif // BOOTSTRAP5THEMAKEYS_H
