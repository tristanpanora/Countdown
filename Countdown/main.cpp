//
//  main.cpp
//  Countdown
//
//  Created by Tristan Panora on 12/13/20.
//

#include <iostream>
#include <vector>
#include <unistd.h>
#include "lettersGame.hpp"
using namespace std;

int main()
{
    char choice;
    int count_letters = 0;
    
    
    cout << "Enter C for a consonant or V for a vowel: ";
    
    lettersGame game;
    
    while (count_letters < 9) {
        
        cin >> choice;
        game.picked_letters.push_back( game.randomLetter(choice) ); //store the picked letter in a vector
        count_letters++;
        
        cout << "\n\n";
        for (int i = 0; i < game.picked_letters.size(); i++) {
            cout << game.picked_letters[i] << " ";
        }
        cout << "\n\n";
    }
    
    
    cout << "And your time starts... now! \n";
    sleep(1); //30 second timer.
    
    string word = "";
    cout << "Time is up! What did you get? \nEnter your word: ";
    cin >> word;
    
    bool result = game.checkWord(word);
    
    if (result == true) {
        cout << "Valid word!\n";
    }
    
    else if (result == false) {
        cout << "Invalid word.\n";
    }
    
    
    


    return 0;
}


/*

Notes:

Need input from a user.
Enter C for consonants.





*/
