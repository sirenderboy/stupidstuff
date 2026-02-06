/**
 * The following class defines a trie, allowing for its traversal, iteration, and manipulation
 * 
 * Petros Flagg 2/5/2026
 */



#include "trie.h"
    //The following default constructor creates an empty root node, in essence.
    Trie::Trie() {
        isWordBool = false;
        for (int i = 0; i < branches.size(); i++) {
            branches[i] = nullptr;
        }
    }
    
    Trie& Trie::operator=(Trie other){
        std::swap(branches, other.branches);
        std::swap(isWordBool, other.isWordBool);

        return *this;
    }

    Trie::Trie(const Trie& other){
        std::cout << "Copystruct";
        isWordBool = other.isWordBool;
        for(int i = 0; i < other.branches.size(); i++) {
            Trie* newTrieBranch = branches[i];
            branches[i] = new Trie(*newTrieBranch);    
        }
    }
    Trie::~Trie(){
        for(int i = 0; i < branches.size(); i++) {
            Trie* trieToDelete = branches[i];
            delete trieToDelete;
        }
    }

    Trie* Trie::traverse(std::string inputString, bool addNodes) {
        if(inputString.length() == 0) {
            return this;
        }
        else
        {
            //Acquire index of next node
            char charToCheck = inputString.at(0);
            int index = charToCheck - 'a';


            if(!branches[index]) {
                //if we add nodes, then create one here
                if(addNodes) {
                    branches[index] = new Trie;
                }
                //Otherwise, we don't add a node and return nullptr
                else
                
                    return nullptr;
            }
            std::string nextString = inputString.substr(1);
            

            return branches[index]->traverse(nextString, addNodes);
        }
    }

    void Trie::addWord(std::string wordString) {
        //Then we have a stop condition, if the string is empty, we make this isWord 
        Trie* endNode = traverse(wordString, true);
        endNode->isWordBool = true;
    }
    
    bool Trie::isWord(std::string wordString) {
        Trie* endNode = traverse(wordString, false);
        //if(endNode == nullptr)
            //return false;
        return endNode->isWordBool;
    }
    std::vector<std::string> Trie::findAllWords(std::string prefix, std::vector<std::string>& returnVector) {
        //Go through everything in branches, 
        bool endNode = true;
        if(isWordBool)
                    returnVector.push_back(prefix);
        std::vector<std::string> allChildStrings;
        for (int i = 0; i < branches.size(); i++)
        {
            //If the branch exists, we need to traverse it
            if(branches[i] != nullptr )
            {
                endNode = false;
                //Add the prefix
                char characterToAppend = 'a'+i;
                branches[i]->findAllWords(prefix + characterToAppend, returnVector);        
            }
        }
        
        for(int i = 0; i < allChildStrings.size(); i++) {
            returnVector.push_back(allChildStrings[i]);
        }
        
        return returnVector;

    }
   
    std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix){
        //First we traverse to the node that holds the prefix
        Trie* endNode = traverse(prefix, false);
        if (endNode == nullptr)
        {
            std::vector<std::string> newVector = {""};
            return newVector;
        }
        else
        {
            std::vector<std::string> returnVector;
            return endNode->findAllWords(prefix, returnVector);
        }
            
    }
