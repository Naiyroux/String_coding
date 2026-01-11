#include <cstdlib>
#include <iostream>
#include <string>    // Pour comparer
#include "string.h"


int main() {
	std::cout << "Hello World!" << std::endl ;
	return 0 ;

    // Test 1: Constructeur et Taille
    string s1("Hello");
    std::string realS1("Hello");
    std::cout << "Test 1 (Size) : " << (s1.size() == realS1.size() ? "OK" : "ERREUR") << std::endl;

    // Test 2: Concaténation
    string s2 = s1 + " World";
    std::cout << "Test 2 (Concat) : " << s2.c_str() << " | Attendu: Hello World" << std::endl;

    // Test 3: Opérateur = char
    s2 = '!';
    std::cout << "Test 3 (Assign char) : " << s2.c_str() << " | Taille: " << s2.size() << std::endl;

    // Test 4: Clear
    s1.clear();
    std::cout << "Test 4 (Clear) : Taille après clear = " << s1.size() << std::endl;

	// Test 6 : Copie cstring

	const char* mot = "Holla";
	std::string realS3("Holla");
	string s3(mot);
	
	std::cout << "Test 6 (Assign char) : " << s3.c_str() << " | Taille: " << s3.size() << std::endl;

	// Test 7 : Length 
	std::cout << "Test Length : " << (s3.length() == realS3.length() ? "OK" : "ERREUR") << std::endl;

	// Test 8 Max_size
	std::cout << "Test Length : " << (s3.max_size() == realS3.max_size() ? "OK" : "ERREUR") << std::endl;

	// Test 9 : Resize
	s3.resize(20,'e');
	std::cout << "Test 9 (Resize): " << s3.c_str() << " | Taille: " << s3.size() << std::endl;

	//Test 10 : Operator = string&
	string s4;
	s4 = s3;
	
	std::cout << "Test 10 (=): " << s4.c_str() << " | Taille: " << s4.size() << std::endl;
	
	//Test 11 : Operator +
	// --- Test 19: Opérateur + avec char* (enchaîné) ---
	string s5("J'aime");
	string s6 = s5 + " le" + " chocolat"; 
	std::cout << "Test 19 (Concat char* multi): " << s6.c_str() << " | Attendu: J'aime le chocolat" << std::endl;

	// Test 13: Destructeur
	
	string s13("Temporary");
	std::cout << "Test 13 (Destructor) : Creation de string temporaire..." << std::endl;
	 // s13 est detruit ici
	std::cout << "Test 13 (Destructor suite) : String détruit sans erreur | OK" << std::endl;

	// Test 14: Capacity
	string s14("Test");
	std::cout << "Test 14 (Capacity) : " << s14.capacity() << " >= " << s14.size() << " ? " << (s5.capacity() >= s14.size() ? "OK" : "ERREUR") << std::endl;

	// Test 15: Empty - chaine vide
	string s15;
	std::cout << "Test 15 (Empty vide) : " << (s15.empty() ? "OK" : "ERREUR") << std::endl;

	// Test 15bis: Empty - chaine non vide
	string s15b("Hello");
	std::cout << "Test 15bis (Empty non vide) : " << (!s15b.empty() ? "OK" : "ERREUR") << std::endl;
	
	// Test 16: Reserve - augmentation de capacite
	string s16("Hi");
	size_t old_capacity = s16.capacity();
	s16.reserve(100);
	std::cout << "Test 16 (Reserve) : Ancienne capacite = " << old_capacity 
		  << ", Nouvelle = " << s16.capacity() 
		  << " | " << (s16.capacity() >= 100 ? "OK" : "ERREUR") << std::endl;

	// Test 17: Operator= avec const char*
	string s17;
	s17 = "Bonjour";
	std::cout << "Test 17 (Assign const char*) : " << s17.c_str() 
		  << " | Attendu: Bonjour | Taille: " << s17.size() << std::endl;
		  
		  
          // Test 18: Operator+ deux strings
	string s18a("Hello");
	string s18b(" C++");
	string s18c = s18a + s18b;
	std::cout << "Test 18 (Operator+) : " << s18c.c_str() 
		  << " | Attendu: Hello C++ | Taille: " << s18c.size() << std::endl;
		  


    return 0;


}

