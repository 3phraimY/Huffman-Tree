#include "huffmanTree.hpp"
#include <iostream>

HuffmanTree::HuffmanTree(const std::unordered_map<char, int> & frequencyTable) : frequencyTable(frequencyTable) 
{
    buildMinHeap();
    while(this->minHeap.size() > 1) 
    {
        // create pairs of leaves, then create intermediary nodes 
        // which have a frequency which is the sum of the two leaves
        HuffNode * left = minHeap.top();
        minHeap.pop();

        HuffNode * right = minHeap.top();
        minHeap.pop();

        HuffNode * sumNode = new HuffNode;

        // no "info" on connective nodes
        sumNode->info = '\0'; 
        sumNode->frequency = left->frequency + right->frequency;
        sumNode->llink = left;
        sumNode->rlink = right;

        minHeap.push(sumNode);
    }
    
    //set root to final element of minHeap    
    this->root = minHeap.top();
}

void HuffmanTree::buildMinHeap() 
{
    for(const std::pair<const char, int> & entry : this->frequencyTable) 
    {
        HuffNode * newNode = new HuffNode;
        newNode->info = entry.first;
        newNode->frequency = entry.second;
        newNode->llink = nullptr;
        newNode->rlink = nullptr;
        this->minHeap.push(newNode);
    }
}

void HuffmanTree::generateHuffmanCodes(HuffNode * curNode, const std::string & code, std::unordered_map<char, std::string> & huffmanCodes) 
{
    if(curNode == nullptr) 
    {
        std::cout << "Error: curNode is nullptr" << std::endl;
        return;
    }
    
    // update code for node if not connective node
    if(curNode->info != '\0') 
    {
        huffmanCodes[curNode->info] = code;
    }

    // recursivily call generateHuffmanCodes on children nodes

    if(curNode->llink != nullptr) 
    {
        // add 0 to code when moving left
        generateHuffmanCodes(curNode->llink, code + "0", huffmanCodes);
    }
    
    if(curNode->rlink != nullptr) 
    {
        // add 1 to code when moving right
        generateHuffmanCodes(curNode->rlink, code + "1", huffmanCodes);
    }
    return;
}

std::unordered_map<char, std::string> HuffmanTree::getHuffmanCode() 
{
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(this->root, "", huffmanCodes);
    return huffmanCodes;
}