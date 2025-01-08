class Trie {
public:
    struct trieNode {
        bool isEnd;
        trieNode* child[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for (int i = 0; i < 26; i++) {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    Trie() { root = getNode(); }

    void insert(string word) {
        trieNode* mover = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int ind = ch - 'a';

            if (mover->child[ind] == NULL) {
                mover->child[ind] = getNode();
            }
            mover = mover->child[ind];
        }
        mover->isEnd = true;
    }

    bool search(string word) {
        trieNode* mover = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int ind = ch - 'a';

            if (mover->child[ind] == NULL) {
                return NULL;
            }
            mover = mover->child[ind];
        }
        if (mover != NULL && mover->isEnd == true)
            return true;
        return false;
    }

    bool startsWith(string word) {
        trieNode* mover = root;
        int i = 0;
        for (i = 0; i < word.size(); i++) {
            char ch = word[i];
            int ind = ch - 'a';

            if (mover->child[ind] == NULL) {
                return NULL;
            }
            mover = mover->child[ind];
        }
        if (i == word.size())
            return true;
        return false;
    }
};
