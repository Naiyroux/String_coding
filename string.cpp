#include "string.h"
#include<cstdlib>

// Student A

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

// Student B

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



// Student C

// Destructor
string::~string() {
	delete [] str_;
}

// Capacité du string
size_t string::capacity() const (size_t n){
    return capacity_;
}

// Test si une string est vide
bool string::empty() const {
	if (str.length() == 0 or str_[0]== '\0') { // Check si la liste est vide ou ne contient que le dernier caractère rajouté à la fin d'une string
		return True;
	}
	else {
		return False;
	}
	
}
// Change la capacité du string
void string::reserve (size_t n){
	if (n > max_size_) { // Pour éviter d'alouer une capacité supérieure à la taille max
		n = max_size_;	
	}
	if (n > capacity_) { // Si la nouvelle capacité est plus grande que la précédente sinon la fonction ne fait rien (garde la capacité actuelle)
			size_t new_capacity_ = std::max(n, 2 * capacity_); // Stratégie d'allocation de mémoire 
			char* new_str_ = new char[new_capacity_ +1]; // La taille + 1 permet de prendre en compte le caractère de fin de chaîne \0
			for (size_t i=0; i<size_; i++) {
    				new_str_[i] = str_[i]; // Copie les données de l'ancienne string
			}
			new_str_[size_] = '\0'; // Ajoute le caractère de fin de chaîne
			delete[] str_; // supprime l'ancienne chaîne et libère la mémoire associée
			str_ = new_str_; // Maj du pointer str_
			capacity_ = new_capacity_;
		}
}

// Opération d'attribution d'une string par un pointer
string& string::operator=(const char* str) {                                                                              
	if (str == nullptr){ // Vérifier que str n'est pas un nullptr
		str = "";
	}	

	size_t new_size = 0;
	while(str[new_size]!= '\0') {
		new_size = new_size +1;
	}
	
	reserve(new_size); // Allocation de l'espace mémoire avec la fonction reserve
	
	for (size_t i = 0; i < new_size; ++i) { // Copie dans str_
		str_[i] = str[i];
	}
	str_[new_size] = '\0';
	size_ = new_size;

	return *this; // Retourne objet pointé
}

// Opération d'ajout de deux chaînes
string operator+ (const string& lhs, const string& rhs){
	string new_str;
	size_t new_size = lhs.size() + rhs.size();
	
	new_str.reserve(new_size); // Allocation de la mémoire pour les deux chaînes
	
	for (size_t i = 0; i < lhs.size(); ++i) { // Copie de la première chaîne
	    new_str.str_[i] = lhs.str_[i];
	}

	for (size_t i = 0; i < rhs.size(); ++i) { // Ajout de la deuxième chaîne
	    new_str.str_[i +lhs.size()] = rhs.str_[i];
	}

	new_str.str_[new_size] = '\0';
	new_str.size_ = new_size;
	
	return new_str;
}
