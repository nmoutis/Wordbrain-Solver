//
//  Dictionary.cpp
//  WordBrainSolver
//
//  Created by Nicholas Moutis on 04/10/16.
//  Copyright © 2016 Nicholas Moutis. All rights reserved.
//

#include "Dictionary.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

Dictionary::Dictionary(const string &filepath)
{
    ifstream file(filepath);
    string line;
    while(getline(file,line))
    {
        dictionary.push_back(line);
    }
}

bool Dictionary::binary_search(const string &target)
{
    int first = 0;
    int last = (int)dictionary.size();
    while(first<last)
    {
        int mid = (first+last)/2;
        string midword = dictionary[mid];
        if(target.compare(midword)==0)
        {
            return true;
        }
        else if (target.compare(midword) < 0)
        {
            last = mid;
        }
        else if (target.compare(midword) > 0)
        {
            first = mid+1;
        }
    }
    return false;
}