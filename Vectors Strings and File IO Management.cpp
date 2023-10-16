//My name is Merdan Garlyyev, and I am taking CS231 class. The name of my project is "Vectors String and File IO Management". The program reads info from
// input document, and produces to the console the word count, the num of character (without spaces), the average word length, the maximum word length,
// and the minimum word length as well as to an output file. 
// For the second part, the while loop is used to read one word at a time from the input file stream and push that word into a vector of strings. 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// creating function to identify our variables and give them initial value
void printStats(ostream& output, const vector<string>& words) {
    int NumWords = words.size();
    int CharNumber = 0;
    int totalLength = 0;
    int maxLength = 0;
    int minLength = words[0].length();
    
// The math part of the program that calc the lenght, character num, max&min length of the sentence
    for (const auto& word : words) {
        int length = word.length();
        totalLength += length;
        CharNumber += count_if(word.begin(), word.end(), [](char c) { return !isspace(c); });
        maxLength = max(maxLength, length);
        minLength = min(minLength, length);
    }

// calc the avg length of the sentence
    int avgLength = static_cast<double>(totalLength) / NumWords;

// After the calc are made, the results will be printed on console as well as output file with these phrases
    output << "Number of words: " << NumWords << '\n'
           << "Number of Characters (without spaces): " << CharNumber << '\n'
           << "Average word length: " << avgLength << '\n'
           << "Maximum word length: " << maxLength << '\n'
           << "Minimum word length: " << minLength << '\n';
}

// reads from input file and stores info to output file
int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

// In case of misleading of input file or non-existense, the program will give an error to the user. 
    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files\n";
        return 1;
    }

// This part will read one word at a time from the input file stream and push that word into a vector of strings
    vector<string> words;
    string word;

    while (input >> word) {
        words.push_back(word);
    }

// prints calc information
    printStats(cout, words);
    printStats(output, words);

    return 0;
}


