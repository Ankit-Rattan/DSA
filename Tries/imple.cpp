#include <iostream>
using namespace std;

// Implementation of Tries 


class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (auto i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }


    // For insertion of element
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
                root->isTerminal = true;
                return;
        }
        int index = word[0] - 'A';   // change 'A' to 'a' if testing for small letters
        TrieNode* child;
        if(root -> children[index]!= NULL){
            child = root -> children[index];
        }else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }


    // For Search

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0) return root-> isTerminal;
    
        int index = word[0]- 'A';  //change 'A' to 'a' if testing for small letters
        TrieNode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else return false;

        // recursion
        return (searchUtil(child, word.substr(1)));
    }
    bool searchWord(string word){
        return searchUtil(root, word);
    }


};

int
main()
{
    Trie* t =  new Trie();
    t->insertWord("ABCD");
    cout<<t->searchWord("ABCD")<<endl;

    return 0;
}

int
main()
{
    Trie* t =  new Trie();
    t->insertWord("ABCD");
    cout<<t->searchWord("ABCD")<<endl;

    return 0;
}
