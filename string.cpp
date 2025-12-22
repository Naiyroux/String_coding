#include "string.h"
#include<cstdlib>


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
