// Reverse words using stringstream
#include <iostream>
#include <sstream>
#include <algorithm>


void reverseUsingStringStream(std::string str) {

    // Use string stream 
    std::stringstream iss(str); 

    std::string word;
    while(iss >> word) {
        std::reverse(word.begin(), word.end());
        std::cout << word << " ";
    }
}

int main() {
    std::cout<<"Enter words ";
    std::string str;

    // Using getline take all words sepreted by spaces
    std::getline(std::cin,str);

    std::cout<<"\nWords reverse -\n";
    reverseUsingStringStream(str);

    return 0;
}

/*output :-
    Enter words Animal Cricket  Jahaj

    Words reverse -
    laminA tekcirC jahaJ
*/