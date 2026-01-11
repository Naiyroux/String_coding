#ifndef MY_STRING_H
#define MY_STRING_H
#include <cstddef>
using std::size_t;
 
class string {
    public:
     string ();
     string (const string& str);
     string(const char* str);
     int test;
     ~string();
     const char* c_str() const noexcept;
     bool empty() const;
     void reserve (size_t n);
     size_t size() const noexcept;
     void clear() noexcept;
     size_t length() const noexcept;
     size_t max_size() const noexcept;
     size_t capacity() const;
     void resize (size_t n);
     void resize (size_t n, char c);
     // Operator functions
     string& operator= (char c);
     string& operator=(const char* str);
     string& operator=(const string& str);
     /*
     friend string operator+ (const string& lhs, const char* rhs);
     friend string operator+ (const string& lhs, const string& rhs);
     friend string operator+(const string& lhs, char rhs);
     friend string operator+(string&& lhs, char rhs);
     friend string operator+(char lhs, const string& rhs);
     friend string operator+(char lhs, string&& rhs);
    */
     string operator+(const char* rhs)const;
     string operator+(char rhs)const;
        

    protected:
        char* str_;
        size_t size_;
        size_t capacity_;
        static size_t max_size_;
};

#endif





