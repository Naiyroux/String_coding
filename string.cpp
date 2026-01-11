#include "string.h"
#include<cstdlib>


string::string(const string& str) {
    size_ = str.size_;
    capacity_ = str.capacity_;
    str_ = new char[capacity_ + 1];
    for (size_t i = 0; i < size_; i++) {
        str_[i] = str.str_[i];
    }
    str_[size_] = '\0'; // Utiliser '\0' (char) et non "\0" (string)
}

const char* string::c_str() const noexcept {
    return str_;
}

size_t string::size() const noexcept {
    return size_;
}

void string::clear() noexcept {
    size_ = 0;
    str_[0] = '\0';
}

string& string::operator=(char c) {
    size_ = 1;
    str_[0] = c;
    str_[1] = '\0';
    return *this;
}

size_t string::length(){
    return size_t size_;
};

size_t string::max_size(){
    return size_t max_size_;
};

void string::resize (size_t n){
    if (n > max_size_){
        // return error, à modifier
        return ;
    }
    elif (n < size_){
        size_ =  n;
    }
};

void string::resize (size_t n, char c){
    if (n > max_size_){
        // return error, à modifier
        return ;
    }
    elif (n < size_){
        size_ =  n;
    }
    else{
        for (int i = size_; i < n;i++){
            
        }
    }
};

string& string::operator=(const string& str);

string string::operator+(const string& lhs, char rhs);
string string::operator+(string&& lhs, char rhs);
string string::operator+(char lhs, const string& rhs);

string string::operator+(char lhs, string&& rhs);

string::~string() {
	delete [] this->values;
}

bool empty() const {
	if (str.length() == 0) {
		return True;
	}
	else {
		return False;
	}
	
}

string operator+ (const string& lhs, const string& rhs){
	return lhs + rhs;
}
