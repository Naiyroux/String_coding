#include "string.h"
#include<cstdlib>
#include <stdexcept> // Pour les exceptions (length_error)

size_t string::max_size_ = 100;

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

// Constructeur par défaut
string::string() : size_(0), capacity_(0) {
    str_ = new char[1];
    str_[0] = '\0';
}

string::string(const char* str) {
    if (str == nullptr) {
        size_ = 0;
        capacity_ = 0;
        str_ = new char[1];
        str_[0] = '\0';
    } else {
        size_t len = 0;
        while (str[len] != '\0') {
            len++;
        }
        size_ = len;
        capacity_ = len;
        str_ = new char[capacity_ + 1];
        for (size_t i = 0; i < size_; i++) {
            str_[i] = str[i];
        }
        str_[size_] = '\0';
        }
    }

size_t string::length() const noexcept{
    return size_;
};

size_t string::max_size() const noexcept{
    return max_size_;
};

void string::resize (size_t n){
    if (n > max_size_){
        // return error, à modifier
        throw std::length_error("String too long");
    }
    else if (n < size_){
        size_ =  n;
    }
}

void string::resize (size_t n, char c){
    if (n > max_size_){

        
    }
    if (n <= size_){
        size_ =  n;
        str_[size_] = '\0';
    }
    else if (n > size_){
        if (n > capacity_){
            reserve(n);
        }
        for (size_t i = size_; i < n;i++){
                str_[i] = c;
        }
        size_ =  n;
        str_[size_] = '\0';
        
    }
}

string& string::operator=(const string& str){
    if (this == &str){
        return *this;
    }
    else{
        delete[] str_;

        size_ = str.size_;
        str_ =  new char[capacity_  +1];

        for (size_t i = 0; i < size_ ; i++){
            str_[i] = str.str_[i];
        }
        str_[size_] = '\0';
        return *this;
    }
}

string string::operator+(const char* rhs)const{
    string newstr;

    size_t rhs_length = 0;

    while (rhs[rhs_length]!='\0'){
        rhs_length++;
    }
    
    newstr.size_ = this->size_ + rhs_length;

    if (newstr.size_ > max_size_){

        throw std::length_error("String too long");
    }

    newstr.str_ = new char[newstr.size_ + 1];

    for (size_t i = 0; i < this->size_ ; i++){
        newstr.str_[i] = this->str_[i];
    }

    for (size_t j = 0; j < rhs_length; j++){
        newstr.str_[this->size_ + j] = rhs[j];
    }

    newstr.str_[newstr.size_] = '\0';
    return newstr;

}

string string::operator+(char rhs)const{
    string newstr;
    
    newstr.size_ = this->size_ + 1;

    if (newstr.size_ > max_size_){

        throw std::length_error("String too long");
    }

    newstr.str_ = new char[newstr.size_ + 1];

    for (size_t i = 0; i < this->size_; i++){
        newstr.str_[i] = this->str_[i];
    }

    newstr.str_[this->size_] = rhs;
    newstr.str_[newstr.size_] = '\0';

    return newstr;

}
/*
string string::operator+(string&& lhs, char rhs);
string string::operator+(char lhs, const string& rhs);

string string::operator+(char lhs, string&& rhs);

string::~string() {
	delete [] this->values;
}

bool string::empty() const {
	if (size_ == 0) {
		return True;
	}
	else {
		return False;
	}
	
}

string operator+ (const string& lhs, const string& rhs){
	return lhs + rhs;
}*/
