class Trie{
public:
     Trie* children[26];
     bool isWord;
     Trie(){
        isWord = false;
        for(int i = 0; i<26;i++){
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
     bool search(string& word, int startIndex, Trie* root){
        if(startIndex == word.length())return true;
        Trie* curr = root;
        for(int i = startIndex; i<word.length();i++){
             if(curr->children[word[i]-'a'] == NULL){
                return false;
            }
            curr = curr->children[word[i]-'a'];
            if(curr->isWord){
                if(search(word, i+1, root)) return true;
            }
        }
        return false;
     }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        sort(words.begin(), words.end(), [](const string&a, const string& b){
            return a.length() < b.length();
        });
        Trie* obj = new Trie();
        for(int i = 0; i<words.size(); i++){
            if(obj->search(words[i], 0, obj)){
                ans.push_back(words[i]);
            }
            else{
                obj->insert(words[i]);
            }
        }
        return ans;
    }
};