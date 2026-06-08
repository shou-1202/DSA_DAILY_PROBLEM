class Trie{
public:  
    bool isWord;
    Trie* children[26];
    Trie(){
        isWord = false;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
    }

    void insert(string& word){
        Trie* curr = this;
        for(char c: word){
            if(!curr->children[c-'a']){
                Trie* newNode = new Trie();
                curr->children[c-'a'] = newNode;
            }
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }

    void search(string& word, int i, Trie* root, vector<string>& output, string ans){
        if(i==word.length()){
            ans.pop_back();
            output.push_back(ans);
            return;
        }
        Trie* curr = root;
        for(int j = i; j<word.length();j++){
            if(curr->children[word[j] - 'a'] == NULL){
                return;
            }
            ans.push_back(word[j]);
            curr = curr->children[word[j] - 'a'];
            if(curr->isWord){
                ans+=" ";
                search(word, j+1, root, output, ans);
                ans.pop_back();
            }
        }
        return;
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>output;
        int n = s.length();
        Trie* obj = new Trie();
        for(int i = 0; i<wordDict.size();i++){
            obj->insert(wordDict[i]);
        }
        string ans = "";
        obj->search(s, 0, obj, output, ans);
        return output;
    }
};