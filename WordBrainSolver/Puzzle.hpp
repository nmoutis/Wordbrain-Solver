//
//  Puzzle.hpp
//  WordBrainSolver
//
//  Created by Nicholas Moutis on 4/10/16.
//  Copyright © 2016 Nicholas Moutis. All rights reserved.
//

#ifndef Puzzle_hpp
#define Puzzle_hpp

#include <string>
#include <vector>
#include "Dictionary.hpp"

using namespace std;

class Puzzle{ //Puzzle class represents matrix of lettters that represents the puzzle as well as the dictionary of english words and the visited boolean matrix
    
public:
    Puzzle(const int &dimension); // constructor to initialize visited matrix of boolean values
    
    void read_letterfile(const string &filepath); // create letter_matrix from letter file
    
    void print_puzzle(); //print letter matrix
    
    vector<string> find_n_letter_words(const int &word_length); //use dfs_words to find all words in the letter_matrix of length n
    
    vector<string> filter_words(vector<string> unfiltered, Dictionary &dictionary); // filter out all non-english words and duplicate words using binary_search
    
    void dfs_words(vector<string> &word_vector,const int &row,const int &column, string current_word, const int &word_length); // performs a depth first search of the letter matrix to find all possible words given the games word creation rules
    
    void enter_puzzle(); //create letter_matrix with user input
    void update_puzzle(); //update letter_matrix with user input
    
private:
    vector<vector<char>> letter_matrix; //matrix of letters that user sees when solving puzzle
    vector<vector<bool>> visited; // matrix of boolean values that represents whether a location in the letter matrix is 'visited' during the depth first search
    int size; // length of each side of letter_matrix
    
    
    
};

#endif /* Puzzle_hpp */
