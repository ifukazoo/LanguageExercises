#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <algorithm>
#include <string>

namespace strings {
std::string trim(const std::string& s) {
    auto pred = [](char c) { return !std::isspace(c); };
    auto from = std::find_if(s.begin(), s.end(), pred);
    auto rto = std::find_if(s.rbegin(), s.rend(), pred);
    auto to(rto.base());

    /*
        reverse_iterator と iterator の関係

        vector<int> v;
        for (int i = 1; i <= 5; ++i) {  // put 1-5 in the vector
            v.push_back(i);
        }
        vector<int>::reverse_iterator ri =  // make ri point to the 3
            find(v.rbegin(), v.rend(), 3);
        vector<int>::iterator i(ri.base());  // make i the same as ri’s base

        rend()      ri      rbegin()
        |           |       |
        v           v       v
          +---+---+---+---+---+
          | 1 | 2 | 3 | 4 | 5 |
          +---+---+---+---+---+
            ^           ^       ^
            |           |       |
            begin()     i       end()
    */

    std::string ret = "";
    std::copy(from, to, std::back_inserter(ret));
    return ret;
}
}

#endif
