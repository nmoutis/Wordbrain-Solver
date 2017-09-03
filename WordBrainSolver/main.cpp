//
//  main.cpp
//  WordBrainSolver
//
//  Created by Nicholas Moutis on 4/10/16.
//  Copyright © 2016 Nicholas Moutis. All rights reserved.
//

/* This program is a solver for the game Wordbrain, available on the app store. In this game, the user is presented with a square grid of letters and are supposed to find words within this grid by connecting only adjacent letters. The user is made aware of the number of words to find, and the number of letters per word. Once a correct word is found, the letters from this word dissapear and the remaining letters cascade towards the bottom of the screen, leaving blank spaces. All letters in each puzzle are used to complete the words. This program takes a grid of letters from a text file named after an animal or from user input. The user can then specify the number of letters in the word they want to find and the program retruns all english words within the grid of letters of that specified length. The user can then update the puzzle, enter a different word length to search for, or end the game.
*/

#include <iostream>
#include <fstream>
#include "Puzzle.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Puzzle solvepuzzle(4);//initialize puzzle
    Dictionary dictionary("");
    
//    solvepuzzle.read_letterfile("");// choose puzzle file
    solvepuzzle.enter_puzzle();
    solvepuzzle.print_puzzle();// print puzzle
    
    cout<<"Enter number of letters"<<endl;
    int wordlen;
    cin>>wordlen;
    vector<string> n_word_list = solvepuzzle.find_n_letter_words(wordlen);// find words of length n
    vector<string> real_list = solvepuzzle.filter_words(n_word_list, dictionary);// filter out non-english words
    if (real_list.size() ==0)
    {
        cout<<"No valid words of length "<<wordlen<<endl;
    }
    else
    {
        for (int i = 0; i<real_list.size(); i++)
        {
            cout<<real_list[i]<<endl;
        }
    }
    bool continueplay = true;
    while(continueplay == true)
    {
        cout<<"Update board? (y or n)"<<endl;
        char update;
        cin>>update;
        if (update == 'n')
        {
            cout<<"End game? (y or n)"<<endl;
            char endgame;
            cin>>endgame;
            if (endgame == 'y')
            {
                continueplay = false;
            }
            else if (endgame == 'n')
            {
                cout<<"Enter number of letters"<<endl;
                cin>>wordlen;
                vector<string> n_word_list = solvepuzzle.find_n_letter_words(wordlen);
                vector<string> real_list = solvepuzzle.filter_words(n_word_list, dictionary);
                if (real_list.size() ==0)
                {
                    cout<<"No valid words of length "<<wordlen<<endl;
                }
                else
                {
                    for (int i = 0; i<real_list.size(); i++)
                    {
                        cout<<real_list[i]<<endl;
                    }
                }
            }
            else
            {
                cout<<"Did not enter y or n"<<endl;
            }
        }
        else if (update == 'y')
        {
            solvepuzzle.update_puzzle();
            solvepuzzle.print_puzzle();
            cout<<"Enter number of letters"<<endl;
            cin>>wordlen;
            vector<string> n_word_list = solvepuzzle.find_n_letter_words(wordlen);
            vector<string> real_list = solvepuzzle.filter_words(n_word_list, dictionary);
            if (real_list.size() ==0)
            {
                cout<<"No valid words of length "<<wordlen<<endl;
            }
            else
            {
                for (int i = 0; i<real_list.size(); i++)
                {
                    cout<<real_list[i]<<endl;
                }
            }
        }
        else
        {
            cout<<"Did not enter y or n"<<endl;
        }
    }
    return 0;
}


