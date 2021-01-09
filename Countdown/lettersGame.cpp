//
//  lettersGame.cpp
//  Countdown
//
//  Created by Tristan Panora on 12/13/20.
//

#include "lettersGame.hpp"
#include <vector>
#include <random>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <iostream>

lettersGame::lettersGame() //preprocess the dictionary 
{
    consonants = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
    vowels = {'A','E','I','O','U'};
    
    //process smalldic here.
    
    std::ifstream fin("smalldic.txt");
    std::string line = "";
    
    while ( getline(fin, line) ) {
        dictionary.push_back(line); //store every word in the dictionary into the dictionary vector
    }
    
//    for (int i = 0; i < dictionary.size(); i++) {
//        std::cout << dictionary[i] <<  "\n";
//    }
    
    
    
}

char lettersGame::randomLetter (char choice)
{
    
    std::random_device dev;
    std::mt19937 rng(dev());                                //eight colors
    std::uniform_int_distribution<std::mt19937::result_type> cons(0,20); //21 consonants
    std::uniform_int_distribution<std::mt19937::result_type> vows(0,4); //5 vowels
    
    int random_cons = cons(rng);
    int random_vowel = vows(rng);
    
    //take in either C or V
    
    if (choice == 'C' || choice == 'c') //consonant
    {
        return consonants[random_cons];
    }
    
    else if (choice == 'V' || choice == 'v') //vowel
    {
        return vowels[random_vowel];
    }
    
    else
    {
        throw std::invalid_argument ("MUST ENTER C OR V.");
    }
    
    return '!';
}


bool lettersGame::checkWord (std::string wordy)
{
    std::string lowercase = wordy;
    std::string word = "";
    for (int i = 0; i < wordy.size(); i++) {
        word += toupper(wordy[i]);
    }
    
    std::sort(word.begin(), word.end()); //sort the word the user has found
    std::sort(picked_letters.begin(), picked_letters.end()); //sort the randomly picked letters
    
    //TEST
//    std::cout << "Sorted word: " << word << "\n";
//
//    for (int j = 0; j < picked_letters.size(); j++) {
//        std::cout << picked_letters[j];
//    }
//    std::cout << "\n";
    //END TEST
    
    int count = 0;
    for (int i = 0; i < word.length(); i++) {
        char comparison = word[i];
        
        for (int j = 0; j < picked_letters.size(); j++) {
            if (comparison == picked_letters[j]) {
                count++;
                break;
            }
        }
    }
    
    //testing count
    //std::cout << "count: " << count << "\n";
    
    if ( count != word.length() ) {
        return false;
    }
    //std::cout << "count: " << count << "\n";
    
    //check if the word is in the dictionary but also if it uses the letters in the selection.
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i] == lowercase) {
            return true;
        }
    }
    
    return false;
    
}
