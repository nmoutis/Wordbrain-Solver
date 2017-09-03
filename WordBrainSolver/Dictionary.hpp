//
//  Dictionary.hpp
//  WordBrainSolver
//
//  Created by Nicholas Moutis on 04/10/16.
//  Copyright © 2016 Nicholas Moutis. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <string>
#include <vector>

using namespace std;

class Dictionary
{
public:
    Dictionary(const string &filepath); //constructor that initializes the dictionary from a filepath containing the dictionary text file
    
    bool binary_search(const string &target); // performs a binary search of the sorted dictionary for a given word
    
private:
    vector<string> dictionary; // 90000 word dictionary of english words
};



#endif /* Dictionary_hpp */
