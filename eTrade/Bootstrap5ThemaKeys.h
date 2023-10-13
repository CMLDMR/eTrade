#ifndef BOOTSTRAP5THEMAKEYS_H
#define BOOTSTRAP5THEMAKEYS_H

#include <string_view>
#include <string>

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

const std::string xs( const int index );
const std::string sm( const int index );
const std::string md( const int index );
const std::string lg( const int index );
const std::string xl( const int index );
const std::string xxl( const int index );

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
