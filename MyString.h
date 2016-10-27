#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

namespace cs_mystring
{

    class MyString
    {
    public:
        MyString();
        MyString(const char *inDesc);
        MyString(const MyString& right);
        int length() const;
        friend std::ostream& operator<<(std::ostream& out, const MyString& printMe);
        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const MyString& right);
        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const MyString& right);
        MyString operator=(const MyString& right);
        char operator[](int index) const;
        char& operator[](int index);

    private:
        char *desc;
    };
}

#endif /* MYSTRING_H_ */
