//
// Created by juandiego on 3/30/23.
//

#include "../include/string.hpp"

std::ostream &non_std::operator<<(std::ostream &os, const non_std::string &string) {
    for (std::size_t i = 0; i < string.m_size; ++i) {
        os << string.m_text[i];
    }
    return os;
}

std::istream &non_std::operator>>(std::istream &in, non_std::string &string) {
    std::string input = {};
    in >> input;

    string.m_size = input.length();
    string.m_text = new char[string.m_size + 1];
    string.m_text[string.m_size] = '\0';

    for (std::size_t i = 0; i < string.m_size; ++i) {
        string.m_text[i] = input[i];
    }

    return in;
}

non_std::string non_std::operator^(non_std::string &a, non_std::string &b) {
    non_std::string concatenation;

    concatenation.m_size = (a.length() + b.length());
    concatenation.m_text = new char[concatenation.m_size + 1];
    concatenation.m_text[concatenation.m_size] = '\0';

    int j = 0;
    for (std::size_t i = 0; i < a.length(); ++i) {
        concatenation.m_text[j++] = a.m_text[i];
    }

    for (std::size_t i = 0; i < b.length(); ++i) {
        concatenation.m_text[j++] = b.m_text[i];
    }

    return concatenation;
}

non_std::string non_std::operator^(non_std::string &a, std::string &b) {
    non_std::string concatenation;

    concatenation.m_size = (a.length() + b.length());
    concatenation.m_text = new char[concatenation.m_size + 1];
    concatenation.m_text[concatenation.m_size] = '\0';

    int j = 0;
    for (std::size_t i = 0; i < a.length(); ++i) {
        concatenation.m_text[j++] = a.m_text[i];
    }

    for (char i: b) {
        concatenation.m_text[j++] = i;
    }

    return concatenation;
}

non_std::string non_std::operator^(non_std::string &a, const char *b) {
    non_std::string concatenation;

    concatenation.m_size = (a.length() + strlen(b));
    concatenation.m_text = new char[concatenation.m_size + 1];
    concatenation.m_text[concatenation.m_size] = '\0';

    int j = 0;
    for (std::size_t i = 0; i < a.length(); ++i) {
        concatenation.m_text[j++] = a.m_text[i];
    }

    for (std::size_t i = 0; i < strlen(b); ++i) {
        concatenation.m_text[j++] = b[i];
    }

    return concatenation;
}


void non_std::operator^=(non_std::string &a, non_std::string &b) {
    a = a ^ b;;
}

void non_std::operator^=(non_std::string &a, std::string &b) {
    a = a ^ b;
}

void non_std::operator^=(non_std::string &a, const char *b) {
    a = a ^ b;
}

non_std::string &non_std::string::operator=(std::string &a) {
    this->m_size = a.length();
    this->m_text = new char[m_size + 1];
    this->m_text[m_size] = '\0';

    for (std::size_t i = 0; i < m_size; ++i) {
        this->m_text[i] = a[i];
    }

    return *this;
}

non_std::string::string() : m_size(0) {
    m_text = new char;
    m_text[0] = '\0';
}

non_std::string::string(const char *i_text) : m_size(strlen(i_text)) {
    m_text = new char[m_size + 1];
    m_text[m_size] = '\0';

    for (std::size_t i = 0; i < m_size; ++i) {
        m_text[i] = i_text[i];
    }
}

non_std::string::string(const non_std::string &another) : m_size(another.m_size) {
    this->m_text = new char[m_size + 1];
    this->m_text[m_size] = '\0';

    for (std::size_t i = 0; i < m_size; ++i) {
        this->m_text[i] = another.m_text[i];
    }
}

non_std::string::string(non_std::string &&another) noexcept: m_size(another.m_size) {
    this->m_text = another.m_text;
    another.m_text = nullptr;
    another.m_size = 0;
}

non_std::string::~string() {
    delete [] m_text;
}

non_std::string &non_std::string::operator=(const non_std::string &another) {
    if (&another == this) {
        return *this;
    }

    delete[] this->m_text;

    this->m_size = another.m_size;
    this->m_text = new char[m_size + 1];
    this->m_text[m_size] = '\0';

    for (std::size_t i = 0; i < m_size; ++i) {
        this->m_text[i] = another.m_text[i];
    }

    return *this;
}

non_std::string &non_std::string::operator=(non_std::string &&another) noexcept {
    if (&another == this) {
        return *this;
    }

    delete[] this->m_text;

    this->m_size = another.m_size;
    this->m_text = another.m_text;
    another.m_text = nullptr;
    another.m_size = 0;

    return *this;
}

std::size_t non_std::string::length() const {
    return this->m_size;
}

const char *non_std::string::c_str() const {
    return this->m_text;
}

void std::getline(std::istream &in, non_std::string &a) {
    in >> a;
}

void std::swap(non_std::string &a, non_std::string& b) {
    std::swap(a.m_size, b.m_size);
    std::swap(a.m_text, b.m_text);
}
