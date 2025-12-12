
 
class string {
    public:
    	string (const string& str);
     ~string();
 
     const char* c_str() const;
     bool empty() const ;
     void reserve (size_t size_);
     size_t size() const;
     void clear() noexcept;
     size_t length() const;
     size_t max_size() const;
     size_t capacity() const (size_t n);
     void resize (size_t n);
     void resize (size_t n, char c);
     string& operator= (char c);
     string& operator=(const char*);
     string& operator=(const string& str);
     friend string operator+ (const string& lhs, const char* rhs);
     friend string operator+ (const string& lhs, const string& rhs);
     friend string operator+(const string& lhs, char rhs);
     friend string operator+(string&& lhs, char rhs);
     friend string operator+(char lhs, const string& rhs);
     friend string operator+(char lhs, string&& rhs);

        

    private:
        char* str_;
        size_t size_;
        size_t capacity_;
        static size_t max_size_ = 100;
}

