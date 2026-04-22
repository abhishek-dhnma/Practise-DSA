#include <bits/stdc++.h>

using namespace std;

struct Node {

    Node * children[26];
    bool isEndOfWord;

    Node() {

        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }

    }


};

class Trie {


    public:


        Node * root;

    Trie() {
        root = new Node();
    }



    void insert(string word) {

        Node * crawler = root;

        for (int i = 0; i < word.size(); i++) {


            if (crawler -> children[word[i] - 'a'] == nullptr) {
                crawler -> children[word[i] - 'a'] = new Node();

            }


            crawler = crawler -> children[word[i] - 'a'];

        }

        crawler -> isEndOfWord = true;




    }

    bool search(string word) {


        Node * crawler = root;


        for (int i = 0; i < word.size(); i++) {

            if (crawler -> children[word[i] - 'a'] == nullptr) {
                return false;
            }

            crawler = crawler -> children[word[i] - 'a'];

        }


        return crawler -> isEndOfWord == true ? true : false;



    }



    void countWord(Node * current, int & count) {


        if (!current) return;



        if (current -> isEndOfWord) count++;


        for (int i = 0; i < 26; i++) {

            if (current -> children[i] != nullptr) {

                countWord(current -> children[i], count);

            }


        }


    }

    int numberOfWords() {

        int count = 0;
        countWord(root, count);

        return count;
    }



    void display(Node * current, string & currentWord) {


        if (!current) return;



        if (current -> isEndOfWord) cout << currentWord << endl;


        for (int i = 0; i < 26; i++) {

            if (current -> children[i] != nullptr) {
                currentWord.push_back('a' + i);
                display(current -> children[i], currentWord);
                currentWord.pop_back();

            }


        }


    }


    void print() {

        string starter = "";

        display(root, starter);

    }

    bool isEmpty(Node * node) {
        for (int i = 0; i < 26; i++) {
            if (node -> children[i]) {
                return false;
            }
        }
        return true;
    }


    Node * deleteNode(Node * current, string word, int depth) {
        // base case

        if (current == nullptr) {
            return nullptr;
        }


        if (depth == word.size()) {
            current -> isEndOfWord = false;

            if (isEmpty(current)) {
                delete current;
                return nullptr;
            }

            return current;

        }

        // recursive step


        int idx = word[depth] - 'a';
        current -> children[idx] = deleteNode(current -> children[idx], word, depth + 1);

        if (!current -> isEndOfWord && isEmpty(current)) {
            delete current;
            return nullptr;
        }

        return current;

    }


    void deleteWord(string word) {
        Node * crawler = root;
        root = deleteNode(crawler, word, 0);
        if (root == nullptr) {
            root = new Node(); // If root was deleted, recreate it for the next word
        }

    }


};



int main() {


    vector < string > words = {
        "are",
        "as",
        "at",
        "do",
        "dot",
        "new",
        "news",
        "no",
        "not",
        "notp",
        "note"
    };

    Trie myTrie;

    for (auto word: words) {
        myTrie.insert(word);
    }

    myTrie.print();

    string wordsearch = "note";
    if (myTrie.search(wordsearch)) {
        cout << wordsearch + " present";
    } else {
        cout << wordsearch + " not present";
    }
    cout << endl;
    wordsearch = "happy";
    if (myTrie.search(wordsearch)) {
        cout << wordsearch + " present";
    } else {
        cout << wordsearch + " not present";
    }

    cout << endl;

    myTrie.deleteWord("as");

    myTrie.print();

}