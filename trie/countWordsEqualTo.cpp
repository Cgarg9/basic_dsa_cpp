#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch) {
        return (links[ch-'a'] != NULL);
    }
    Node* get(char ch) {
        return links[ch-'a'];
    } 
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    void increaseEnd() {
        cntEndWith++;
    }
    void increasePrefix() {
        cntPrefix++;
    }
    void deleteEnd() {
        cntEndWith--;
    }
    void reducePrefix() {
        cntPrefix--;
    }
    int getEnd() {
        return cntEndWith;
    }
    int getPrefix() {
        return cntPrefix;
    }
};
class Trie{
    
    private: Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string &word) {
            Node* node = root;
            for(int i = 0; i < word.length(); i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
                node->increasePrefix();
            }
            node->increaseEnd();
        }
        int countWordEuqalTo(string &word) {
            Node* node = root;
            for (int i = 0; i < word.length(); i++){
                if (node->containsKey(word[i])) {
                    node = node->get(word[i]);
                }
                else {
                    return 0;
                }
            }
            return node->getEnd();
        }
        int countWordsStartWith(string &word) {
            Node* node = root;
            for(int i = 0; i < word.length(); i++) {
                if (node->containsKey(word[i])) {
                    node = node->get(word[i]);
                }
                else {
                    return 0;
                }
            }
            return node->getPrefix();
        }
        void erase(string &word) {
            Node* node = root;
            for (int i = 0; i < word.length(); i++) {
                if(node->containsKey(word[i])) {
                    node = node->get(word[i]);
                    node->reducePrefix();
                }
                else {
                    return;
                }
                node->deleteEnd();
            }
        }
};
int main()
{

    return 0;
}
