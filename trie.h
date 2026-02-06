#ifndef TRIE
#define TRIE
/*
A Trie class that will hold a series of 26 characters, and assign words based on them. This class also knows if it is a word.
By  Petros Flagg
1/30/2026
*/
#include <iostream>
#include <vector>
class Trie {
private:
    bool isWordBool;
    //All the potential branches of the trie. Essentially, this class represents a node in a tree with 26 set potential branches based on each letter
    std::vector<Trie*> branches = std::vector<Trie*>(26);

    //The following helper method allows the traversal of the trie, returning a reference to the trie node that should have an
    //action done to it.
    //Input inputString - The string we should use to traverse through the trie.
    //Input addNodes - A boolean determining whether new nodes should be added or not.
    //Returns - a Trie node that is at the end of the input string.
    Trie* traverse(std::string inputString, bool addNodes);


    //The following helper method is used in allWordsStartingWithPrefix to return all words contained in the sub-branch. This
    //Is the recursive portion of the recursion while allWordsStartingWithPrefix is the driver portion
    //Input returnVector - The vector containing all the words currently with this prefix. 
    //Input prefix - the prefix to append to each word.
    //Output - the vector of all words 
    std::vector<std::string> findAllWords(std::string prefix, std::vector<std::string>& returnVector);
public:

    //The following default constructor creates an empty root node, in essence, defaulting all pointers in branches to nullptr.
    Trie();
    //The following assignment operator will take a pre-existing trie and set this one to share its data.
    Trie& operator=(Trie other);
    //The following Copystructor will take an existing Trie and copy it to this trie.
    Trie(const Trie& other);
    //The deconstructor for the tree which will iterate through the tree until all nodes have been dereferenced, bottom up.
    ~Trie();
    //The following method will iterate through the trie recursively and then make the input word a valid word by flagging isWord.
    //Input wordString - The word to add.
    void addWord(std::string wordString);
    //The following method will iterate through the trie recursively and then see if the inputted word is a word.
    //Input wordString - The word to check for.
    bool isWord(std::string wordString);
    //The following function will iterate through the trie until the prefix is reached, 
    //then iterate through each possible subtree (that is in prefix range) 
    //While adding any recursively returned vectors to the current vector
    //Input prefix - The prefix to iterate through the trie and look for
    //Output outputVector - A vector of strings containing all words with the following prefix
    std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);
};

#endif 