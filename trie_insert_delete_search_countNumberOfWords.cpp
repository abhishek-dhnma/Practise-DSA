#include <bits/stdc++.h>
using namespace std;

// Represents a single character in the Trie
struct Node {
    Node* children[26]; // Pointers for each letter 'a' through 'z'
    bool isEndOfWord;   // Flags if a complete word finishes at this node
  
    Node() {
        isEndOfWord = false;
        // Initialize all child pointers to null to avoid garbage memory
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node(); // Start with an empty root node
    }

    // Iteratively walks down the tree, creating nodes as needed
    void insert(string word) {
        Node* crawler = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a'; // Convert char to 0-25 index
            if(crawler->children[index] == nullptr) {
                crawler->children[index] = new Node();
            }
            crawler = crawler->children[index];
        }
        crawler->isEndOfWord = true; // Mark the end of the word
    }

    // Iteratively checks if a path exists and ends with a word flag
    bool search(string word) {
        Node* crawler = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(crawler->children[index] == nullptr) {
                return false; // Path broke; word doesn't exist
            }
            crawler = crawler->children[index];
        }
        return crawler->isEndOfWord; // Must be true for it to be a valid word
    }

    // Helper: DFS to count every node marked as isEndOfWord
    void countWord(Node* current, int& count) {
        if(!current) return;
        
        if(current->isEndOfWord) count++;
        
        for(int i = 0; i < 26; i++) {
            if(current->children[i] != nullptr) {
                countWord(current->children[i], count);
            }
        }
    }

    // Public wrapper to count total words in the dictionary
    int numberOfWords() {
        int count = 0;
        countWord(root, count);
        return count;
    }

    // Helper: DFS with backtracking to reconstruct and print words
    void display(Node* current, string& currentWord) {
        if(!current) return;
        
        // If we hit a word end, print the string we've built so far
        if(current->isEndOfWord) cout << currentWord << endl;
        
        for(int i = 0; i < 26; i++) {
            if(current->children[i] != nullptr) {
                currentWord.push_back('a' + i);    // Add current letter
                display(current->children[i], currentWord); 
                currentWord.pop_back();            // Remove letter (Backtrack)
            }
        }
    }

    // Public wrapper to print words in alphabetical order
    void print() {
        string starter = "";
        display(root, starter);
    }

    // Helper: Checks if a node has any active children
    bool isEmpty(Node* node) {
        for(int i = 0; i < 26; i++) {
            if(node->children[i]) return false;
        }
        return true;
    }

    // Recursive deletion with post-order pruning
    Node* deleteNode(Node* current, string word, int depth) {
        if(current == nullptr) return nullptr;
        
        // Base Case: We've reached the end of the string to delete
        if(depth == word.size()) {
            current->isEndOfWord = false; // Unmark the word
            
            // If the node is now useless (no children), delete it
            if(isEmpty(current)) {
                delete current;
                return nullptr;
            }
            return current;
        }
        
        // Recursive Step: Navigate to the next letter
        int idx = word[depth] - 'a';
        current->children[idx] = deleteNode(current->children[idx], word, depth + 1);
        
        // Backtracking Cleanup: After the child call returns, check if 
        // the current node has become a dead end.
        if(!current->isEndOfWord && isEmpty(current)) {
            delete current;
            return nullptr;
        }
        
        return current;
    }

    // Public wrapper to delete a word and prune memory
    void deleteWord(string word) {
        root = deleteNode(root, word, 0);
        // Ensure root always exists even if tree is empty
        if (root == nullptr) {
            root = new Node();
        }
    }
};

int main() {
    vector<string> words = {"are", "as", "at", "do", "dot", "new", "news", "no", "not", "notp", "note"};
    Trie myTrie;
    
    for(auto word : words) myTrie.insert(word);
    
    cout << "--- Dictionary ---" << endl;
    myTrie.print();
    cout << "Total words: " << myTrie.numberOfWords() << endl << endl;

    string target = "note";
    cout << "Searching for '" << target << "': " << (myTrie.search(target) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting 'as'..." << endl;
    myTrie.deleteWord("as");
    
    cout << "--- Updated Dictionary ---" << endl;
    myTrie.print();

    return 0;
}
