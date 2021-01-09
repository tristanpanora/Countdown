//
//  lettersGame.hpp
//  Countdown
//
//  Created by Tristan Panora on 12/13/20.
//

#ifndef lettersGame_hpp
#define lettersGame_hpp

#include <stdio.h>
#include <vector>
#include <string>

class lettersGame {
    
private:
    std::vector<char> consonants; //randomly pick from here for C
    
    std::vector<char> vowels; //randomly pick from here for V
    
    std::vector<std::string> dictionary;
    
   
    
public:
    
    char randomLetter (const char choice);
    
    bool checkWord (const std::string word);
    
    std::vector<char> picked_letters; //saves the randomly selected letters
    
    lettersGame();
    
    
};

#endif /* lettersGame_hpp */
