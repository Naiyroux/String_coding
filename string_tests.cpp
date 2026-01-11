#include <iostream>
#include <string>    // Pour comparer
#include "string.h"

int main() {
    std::cout << "--- TEST DE MA CLASSE STRING ---" << std::endl;

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

	// Tests Eleve B
	
	std::cout << "Test Length : " << (s1.length() == realS1.length() ? "OK" : "ERREUR") << std::endl;

    return 0;

}
