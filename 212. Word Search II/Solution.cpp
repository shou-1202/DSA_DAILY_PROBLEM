class Trie{
public:
    bool isWord;
    Trie* children[26];

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
                Trie* node = new Trie();
                curr->children[c-'a'] = node;
            }
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }

    bool search(string& word){
        Trie* curr = this;
        for(char c: word){
            if(curr->children[c-'a'] == NULL){
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return curr->isWord;
    }
};
class Solution {
public:
    void helper(vector<vector<char>>& board, Trie* root, vector<string>& ans, int i, int j, string& word){
        Trie* curr = root;
        if(curr->isWord){
            ans.push_back(word);
            curr->isWord = false;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '#'|| !curr->children[board[i][j]-'a'])return;
        if(curr->children[board[i][j]-'a']){
            word.push_back(board[i][j]);
            char c = board[i][j];
            board[i][j] = '#';
            helper(board, curr->children[c-'a'], ans, i+1, j, word);
            helper(board, curr->children[c-'a'], ans, i-1, j, word);
            helper(board, curr->children[c-'a'], ans, i, j+1, word);
            helper(board, curr->children[c-'a'], ans, i, j-1, word);
            board[i][j] = c;
            word.pop_back();
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* obj = new Trie();
        for(int i = 0;i<words.size(); i++){
            obj->insert(words[i]);
        }
        vector<string>ans;
        string word = "";
        for(int i =0; i<board.size();i++){
            for(int j = 0; j<board[0].size();j++){
                helper(board, obj, ans, i, j, word);
            }
        }
        return ans;
    }
};