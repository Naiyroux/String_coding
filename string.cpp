#include "string.h"
#include<cstdlib>

//Constructeur Copie 
string::string(const string& str) {
    size_ = str.size_;
    capacity_ = str.capacity_;
    str_ = new char[capacity_ + 1]; //+1 pour la valeur 0
    for (size_t i = 0; i < size_; i++) {
        str_[i] = str.str_[i];
    }
    str_[size_] = '\0'; //il faut rajoute \0 pour annoncer la fin du mot
}

//C string equivalent
const char* string::c_str() const noexcept {
    return str_;
}

//Taille du string
size_t string::size() const noexcept {
    return size_;
}

// Suppression du mot
void string::clear() noexcept {
    size_ = 0;
    str_[0] = '\0';
}

//Opération d'attribution d'un str par un caractere 
string& string::operator=(char c) {
    size_ = 1;
    str_[0] = c;
    str_[1] = '\0';
    return *this;
}

// je n'ai pas réussi la fonction string operator+(const string& lhs, const char* rhs)


size_t string::length(){
    return size_t size_;
};

size_t string::max_size(){
    return size_t max_size_;
};

void string::resize (size_t n){
    if (n > max_size_){
        // return error, à modifier
        return std::length_error;
    }
    elif (n < size_){
        size_ =  n;
    }
};  return 1;

void string::resize (size_t n, char c){
    if (n > max_size_){
        // return error, à modifier
        return ;
    }
    elif (n <= size_){
        size_ =  n;
        data_[size_] = '\0';
    }
    else{
        if (n > capacity_){
            reserve(n)
        }
        for (size_t i = size_; i < n;i++){
                str_[i] = c;
        }
        size_ =  n;
        data_[size_] = '\0';
        
    }
}

string& string::operator=(const string& str){
    if (this == &str){
        return *this;
    }
    else{
        delete[] str_;

        length = str.length;
        str_ =  new char[length+1];

        for (size_t i = 0; i<length ; i++){
            str_[i] = str.str_[i];
        }
        str_[length] = '\0';
        return *this;
    }
}

string string::operator+(const string& lhs, char rhs){
    string newstr;
    
    newstr.length = lhs.length + rhs.length;

    if (n > max_size_){
        // return error, à modifier
        return ;
    }

    newstr.str_ = new char[newstr.length + 1]

    for (size_t i = 0; i < lhs.length; i++){
        newstr.str_[i] = lhs.str_[i];
    }

    for (size_t j = 0; j < rhs.length; j++){
        newstr.str_[lhs.length + j] = rhs.str_[j];
    }

    newstr_[newstr.length] = '\0';
    return newstr;

}
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
