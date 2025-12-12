

class string {
    public:
        int test;
        ~string();
        
        size_t capacity() const capacity_;
        bool empty() const ;
        void reserve (size_t size_);
        string& operator=(const char*);
        friend string operator+ (const string& lhs, const string& rhs);

    private:
        char* str_;
        size_t size_;
        size_t capacity_;
        static size_t max_size_;

};
