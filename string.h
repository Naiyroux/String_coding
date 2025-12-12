

class string {
    public:
    	string (const string& str);
        string& operator= (char c);
        string operator+ (const string& lhs, const char*   rhs);
        const char* c_str() const noexcept;
        size_t size() const noexcept;
        void clear() noexcept;
        
        

    private:
        char* str_;
        int size_;
        int capacity_;
        static int max_size_;

};
