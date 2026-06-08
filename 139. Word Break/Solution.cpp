class Trie{
public:
    bool isWord;
    Trie* children[26];

    Trie(){
        isWord = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }

    void insert(string& word){
        Trie* curr = this;
        for(char c: word){
            if(curr->children[c-'a'] == NULL){
                Trie* newNode = new Trie();
                curr->children[c-'a'] = newNode;
            }
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }

    bool search(string& word, int i, Trie* root, vector<int>& memo){
        if(i == word.length())return true;
        if(memo[i] != -1){
            return memo[i] == 1;
        }
        Trie* curr = root;
        for(int j = i; j<word.length();j++){
            if(curr->children[word[j] - 'a'] == NULL){
                memo[i] = 0;
                return false;
            }
            curr = curr->children[word[j] - 'a'];
            if(curr->isWord){
                if(search(word, j+1, root, memo)){
                    memo[i] = 1;
                    return true;
                }
            }
        }
        memo[i] = 0;
        return false;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* obj = new Trie();
        for(int i = 0; i<wordDict.size();i++){
            obj->insert(wordDict[i]);
        }
        int n = s.length();
        vector<int>memo(n, -1);
        bool isSequence = false;
        if(obj->search(s, 0, obj, memo)){
            isSequence = true;
        }
        return isSequence;
    }
};