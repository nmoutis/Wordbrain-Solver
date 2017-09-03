//
//  main.cpp
//  WordBrainSolver
//
//  Created by Nicholas Moutis on 4/10/16.
//  Copyright © 2016 Nicholas Moutis. All rights reserved.
//

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


