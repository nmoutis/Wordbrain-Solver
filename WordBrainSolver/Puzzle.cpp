//
//  Puzzle.cpp
//  WordBrainSolver
//
//  Created by Nicholas Moutis on 4/10/16.
//  Copyright © 2016 Nicholas Moutis. All rights reserved.
//

#include "Puzzle.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


Puzzle::Puzzle(const int &dimension)
{
    size = dimension;
    for (int i=0; i<dimension; i++)
    {
        vector<bool> visited_row;
        for (int j=0; j<dimension; j++)
        {
            visited_row.push_back(false);
        }
        visited.push_back(visited_row);
    }
}

void Puzzle::read_letterfile(const string &filepath)
{
    ifstream file(filepath);
    string line;
    vector<string> tempgrid;
    while(getline(file,line))
    {
        tempgrid.push_back(line);
    }
    for(int i=0;i<tempgrid.size();i++)
    {
        vector<char> tempchars;
        for(int j=0;j<size;j++)
        {
            tempchars.push_back(tempgrid[i].at(j));
        }
        letter_matrix.push_back(tempchars);
    }
}

void Puzzle::print_puzzle()
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << letter_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<string> Puzzle::find_n_letter_words(const int &word_length) 
{
    vector<string> n_word_vector;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size;j++)
        {
            string begin_word = "";
            vector<string> word_vector;
            dfs_words(word_vector, i, j, begin_word, word_length);
            for (int k=0;k<word_vector.size();k++)
            {
                n_word_vector.push_back(word_vector[k]);
            }
            visited[i][j] = false;
        }
    }
    return n_word_vector;
}

void Puzzle::dfs_words(vector<string> &word_vector,const int &row,const int &column, string current_word, const int &word_length)
{
    visited[row][column] = true;
    current_word += letter_matrix[row][column];
    if (current_word.length() == word_length)
    {
        word_vector.push_back(current_word);
        visited[row][column] = false;
    }
    else if (current_word.length() < word_length)
    {
        if ((column + 1 <= size - 1) && (visited[row][column+1] == false))//right
        {
            dfs_words(word_vector, row, column+1, current_word, word_length);
            visited[row][column+1] = false;
        }
        if ((row + 1 <= size - 1) && (column + 1 <= size - 1) && (visited[row+1][column+1] == false))//downright
        {
            dfs_words(word_vector, row+1, column+1, current_word, word_length);
            visited[row+1][column+1] = false;
        }
        if ((row + 1 <= size - 1) && (visited[row+1][column] == false))//down
        {
            dfs_words(word_vector, row+1, column, current_word, word_length);
            visited[row+1][column] = false;
        }
        if ((column - 1 >=0) && (row + 1 <= size - 1) && (visited[row+1][column-1] == false))//downleft
        {
            dfs_words(word_vector, row+1, column-1, current_word, word_length);
            visited[row+1][column-1] = false;
        }
        if ((column - 1 >=0) && (visited[row][column-1] == false))//left
        {
            dfs_words(word_vector, row, column-1, current_word, word_length);
            visited[row][column-1] = false;
        }
        if ((row - 1 >=0) && (column - 1 >=0) && (visited[row-1][column-1] == false))//upleft
        {
            dfs_words(word_vector, row-1, column-1, current_word, word_length);
            visited[row-1][column-1] = false;
        }
        if ((row - 1 >=0) && (visited[row-1][column] == false))//up
        {
            dfs_words(word_vector, row-1, column, current_word, word_length);
            visited[row-1][column] = false;
        }
        if ((row - 1 >=0) && (column + 1 <= size - 1) && (visited[row-1][column+1] == false))//upright
        {
            dfs_words(word_vector, row-1, column+1, current_word, word_length);
            visited[row-1][column+1] = false;
        }
    }
}

vector<string> Puzzle::filter_words(vector<string> unfiltered, Dictionary &dictionary)
{
    vector<string> real_list;
    vector<string> unique_real_list;
    for (int i = 0; i < unfiltered.size(); i++)
    {
        bool real_word = dictionary.binary_search(unfiltered[i]);
        if (real_word)
        {
            real_list.push_back(unfiltered[i]);
        }
    }
    for (int i = 0; i < real_list.size(); i++)
    {
        bool add_to_list = true;
        for (int j = 0; j< unique_real_list.size(); j++)
        {
            if (real_list[i].compare(unique_real_list[j]) == 0)
            {
                add_to_list = false;
            }
        }
        if (add_to_list)
        {
            unique_real_list.push_back(real_list[i]);
        }
    }
    return unique_real_list;
}

void Puzzle::enter_puzzle()
{
    for (int i = 0; i<size; i++)
    {
        cout<<"enter row"<<endl;
        string instring;
        cin>>instring;
        vector<char> tempchars;
        for (int j =0; j<size; j++)
        {
            tempchars.push_back(instring[j]);
        }
        letter_matrix.push_back(tempchars);
    }
}

void Puzzle::update_puzzle()
{
    for (int i = 0; i<size; i++)
    {
        cout<<"enter row ('_' for blank space)"<<endl;
        string instring;
        cin>>instring;
        for (int j =0; j<size; j++)
        {
            letter_matrix[i][j] = instring[j];
        }
    }
}

