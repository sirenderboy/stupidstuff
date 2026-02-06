#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "trie.h"
int main(int argc, char* argv[]) {
      if(argc != 3){
        std::cout << "Must include file to read and file to write from in that order." << std::endl;
        return 0;
      }
    Trie root;
     //First we take in the file to read
     std::ifstream fileReader;
     fileReader.open(argv[1]);
     if(!fileReader)
     {
      std::cout << argv[1] << " is not a valid file name. Please re-enter." << std::endl;
      return 0;
     }
     std::string line;
     //Then for each word in the trie, add the word to the trie
     while(getline(fileReader, line))
     {
      //If all lowercase, we can continue to add the word, otherwise exit.
        for(int i = 0; i < line.length(); i++) {
          char charToCheckCase = line.at(i);
        
          if(!int(charToCheckCase)<=122 & !int(charToCheckCase) >= 97) {
            //Improper word, report this
            std::cout << "Improper word " << line << " there can be no capital letters in character" << charToCheckCase << std::endl;
            return 0;
          }
        }
          root.addWord(line);
     }
     //Now for each word find it
     std::ifstream queryReader;
     queryReader.open(argv[2]);

     if (queryReader.is_open())
      {
        if(!queryReader)
          {
            std::cout << argv[2] << " is not a valid file name. Please re-enter." << std::endl;
            return 0;
          }
        while ( getline(queryReader,line) )
        {
          std::vector<std::string> words = root.allWordsStartingWithPrefix(line);
      if(root.isWord(line)) {
          words.push_back(line);
        std::cout << "checking word: " << line << std::endl;
        std::cout << "Word Found" << std::endl;
      }
      else 
      {
        std::cout << "Word not Found" <<std::endl;
      }

      std::cout << words.size() << std::endl;
      for(int i = 0; i < words.size(); i++) {
          std::cout << i;
          std::cout << words[i] << " ";
          std::cout << std::endl;

      }
        
        }
        queryReader.close();
      }
     
    
  
    //TASK 2
    Trie secondTrie(root);
    Trie thirdTrie(root);
    // modify secondTrie and check that it doesn't modify others.
    secondTrie.addWord("abjkjskdjfksjadlfksjdfkljadsf");
    if(root.isWord("abjkjskdjfksjadlfksjdfkljadsf"))
    {
      std::cout << "Root has been modified." << std::endl;
    }
    
    //thirdTrie = secondTrie;

    // Check that thirdTrie now has the modifications from secondTrie.
    // modify thirdTrie and check that it doesn't modify others.
}