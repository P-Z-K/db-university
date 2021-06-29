#pragma once

#include <regex>

namespace RegexPattern
{
    inline std::regex ForNumbersOnly {"[0-9]{1,20}"};
    inline std::regex ForFirstName {"[a-zA-Z¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯]{4,20}"};
    inline std::regex ForLastName {"[a-zA-Z¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯]{4,20}"};
    inline std::regex ForGradeNumber {"[0-9]{1,10}"};
    inline std::regex ForPesel {"[0-9]{11}"};
    inline std::regex ForStreetName {"[a-zA-Z¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯]{3,20}"};
    inline std::regex ForTownName {"[a-zA-Z¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯]{3,20}"};
    inline std::regex ForCountryName {"[a-zA-Z¹æê³ñóœ¿Ÿ¥ÆÊ£ÑÓŒ¯]{4,20}"};
}
