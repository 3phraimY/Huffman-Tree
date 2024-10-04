#include <iostream>
#include <queue>
#include <unordered_map>
#include "huffmanTree.hpp"

using namespace std;

int main() 
{
    std::unordered_map<char, int> frequencyTable;
    std::string characters;
    std::vector<int> frequencies;
    int freq;

    cout << "Input your string of unique characters: ";
    cin >> characters;
    cout << endl << "Input the frequency for the following strings:" << endl;
    for(int i = 0; i < characters.size(); i++) 
    {
        cout << characters[i] << ": ";
        cin >> freq;
        frequencies.push_back(freq);
        frequencyTable[characters[i]] = frequencies[i];
    }

    HuffmanTree * Hello = new HuffmanTree(frequencyTable);

    cout << "Generating Huffman codes: " << endl;

    std::unordered_map<char, std::string> outputMap = Hello->getHuffmanCode();

    for(const auto& pair : outputMap) 
    {
        cout << "Character: " << pair.first << "\tValue: " << pair.second << endl;
    }

    return 0;
};