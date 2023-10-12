#ifndef BOOTSTRAP5THEMAKEYS_H
#define BOOTSTRAP5THEMAKEYS_H

#include <string_view>
#include <string>

//https://getbootstrap.com/docs/5.0/layout/grid/

namespace Bootstrap{


namespace Grid {

inline const std::string_view row{"row "};
inline const std::string_view col{"col "};

const std::string xs( const int index );
const std::string sm( const int index );
const std::string md( const int index );
const std::string lg( const int index );
const std::string xl( const int index );
const std::string xxl( const int index );

}

}


#endif // BOOTSTRAP5THEMAKEYS_H
