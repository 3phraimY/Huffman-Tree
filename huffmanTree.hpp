#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <iostream>
#include <unordered_map>
#include <queue>


class HuffmanTree 
{
    // huffman node struct
    struct HuffNode 
    {
        int frequency;
        char info;
        HuffNode * llink;
        HuffNode * rlink;
    };

    private:
        HuffNode * root;
        struct CompareNodes 
        {
            bool operator()(HuffNode * a, HuffNode * b) 
            {
                return a->frequency > b->frequency;
            }
        };
        std::unordered_map<char, int> frequencyTable;
        void buildMinHeap();
        std::priority_queue<HuffNode *, std::vector<HuffNode *>, CompareNodes> minHeap;

        // recursive function to generate the bitstream representing
        // the path taken through the Huffman Tree
        void generateHuffmanCodes(HuffNode * curNode, const std::string & code, std::unordered_map<char, std::string> & huffmanCodes);

    public:
        // create priority queue from unordered map
        HuffmanTree(const std::unordered_map<char, int> & frequencyTable);
        std::unordered_map<char, std::string> getHuffmanCode();
        
};

#endif