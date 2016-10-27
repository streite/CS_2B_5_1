#include <iostream>
#include "mystring.h"
#include <fstream>
#include <cstring>
#include <cassert>


using namespace std;
using namespace cs_mystring;

namespace cs_mystring
{
    MyString::MyString()
    {
        desc = new char[1];
        strcpy(desc, "");
    }

    MyString::MyString(const char *inDesc)
    {
        desc = new char[strlen(inDesc) + 1];
        strcpy(desc, inDesc);
    }


    MyString::MyString(const MyString& right)
    {
        desc = new char[strlen(right.desc) + 1];
        strcpy(desc, right.desc);
    }


    int MyString::length() const
    {
        int tempLength;
        tempLength = strlen(desc);
        return tempLength;
    }

    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right)
        {
            delete [] desc;
            desc = new char[strlen(right.desc) + 1];
            strcpy(desc, right.desc);
        }
        return *this;
    }

    ostream& operator<<(ostream& out, const MyString& source)
    {
        out << source.desc;
        return out;
    }

    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(desc));
        return desc[index];
    }

    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(desc));
        return desc[index];
    }
    bool operator<(const MyString& left, const MyString& right)
    {
        if(strcmp(left.desc, right.desc) < 0)
        {
            return true;
        }
        else
            return false;
    }
    bool operator<=(const MyString& left, const MyString& right)
    {
        if(strcmp(left.desc, right.desc) <= 0)
        {
            return true;
        }
        else
            return false;
    }
    bool operator>(const MyString& left, const MyString& right)
    {
        if(strcmp(left.desc, right.desc) > 0)
        {
            return true;
        }
        else
            return false;
    }
    bool operator>=(const MyString& left, const MyString& right)
    {
         if(strcmp(left.desc, right.desc) >= 0)
         {
         return true;
         }
         else
         return false;
    }
    bool operator==(const MyString& left, const MyString& right)
    {
        if(strcmp(left.desc, right.desc) == 0)
        {
            return true;
        }
        else
            return false;
    }
    bool operator!=(const MyString& left, const MyString& right)
    {
        if(strcmp(left.desc, right.desc) != 0)
        {
            return true;
        }
        else
            return false;
    }

}

/*----------------------------------RESULT--------------------------------------
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing apple to
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing  to Banana
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing Banana to Banana
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing why to wackity
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky
------------------------------------------------------------------------------*/
