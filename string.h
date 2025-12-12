

class string {
    public:

        size_t length() const noexcept;
        size_t max_size() const noexcept;
        void resize (size_t n);
        void resize (size_t n, char c);

        string& operator=(const string& str);
        
        string operator+(const string& lhs, char rhs);
        string operator+(string&& lhs, char rhs);
        string operator+(char lhs, const string& rhs);
        string operator+(char lhs, string&& rhs);

        

    private:
        char* str_;
        size_t size_;
        size_t capacity_;
        static size_t max_size_;

};