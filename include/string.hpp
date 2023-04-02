//
// Created by juandiego on 3/30/23.
//

#ifndef STRING_SIMULATOR_STRING_HPP
#define STRING_SIMULATOR_STRING_HPP

#include <utility>
#include <cstring>
#include <iostream>

namespace non_std {
    class string;
}

namespace std {
    void getline(std::istream &in, non_std::string &a);

    void swap(non_std::string &a, non_std::string& b);
}

namespace non_std {
    class string {
    private:

        char *m_text = nullptr; //< pointer to array of chars
        std::size_t m_size;     //< access to array size

    public:

        // friend relationship
        friend std::ostream &operator<<(std::ostream &os, const non_std::string &string);

        friend std::istream &operator>>(std::istream &in, non_std::string &string);

        friend non_std::string operator^(non_std::string &a, non_std::string &b);

        friend non_std::string operator^(non_std::string &a, std::string &b);

        friend non_std::string operator^(non_std::string &a, const char *b);

        friend void operator^=(non_std::string &a, non_std::string &b);

        friend void operator^=(non_std::string &a, std::string &b);

        friend void operator^=(non_std::string &a, const char *b);

        friend void std::swap(non_std::string &a, non_std::string& b);

        friend void std::getline(std::istream &in, non_std::string &a);

        /// constructors
        explicit string();

        explicit string(const char *i_text);

        string(const non_std::string &another);

        string(non_std::string &&another) noexcept;

        /// destructor
        ~string();

        /// `operator =` overloading
        non_std::string &operator=(const non_std::string &another);

        non_std::string &operator=(non_std::string &&another) noexcept;

        non_std::string &operator=(std::string &a);

        /// `const` access member functions
        [[nodiscard]] std::size_t length() const;

        [[nodiscard]] const char *c_str() const;
    };
}


#endif //STRING_SIMULATOR_STRING_HPP
