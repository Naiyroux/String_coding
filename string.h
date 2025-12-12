

class string {
    public:

        int length() const noexcept;
        int max_size() const noexcept;
        void resize (int n);
        void resize (int n, char c);
        string& operator= (const string& str);

        

    private:
        char* str_;
        int size_;
        int capacity_;
        static int max_size_;

};