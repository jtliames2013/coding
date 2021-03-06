1268. Search Suggestions System
Medium

71

44

Favorite

Share
Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
 

Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.

1. binary search
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        string curr;
        auto iter=products.begin();
        for (auto c:searchWord) {
            curr+=c;
            vector<string> v;
            iter=lower_bound(iter, products.end(), curr);
            for (int i=0; i<3 && iter+i!=products.end(); ++i) {
                string s=*(iter+i);
                if (s.find(curr)==string::npos) break;
                v.push_back(s);
            }
            res.push_back(v);
        }
        
        return res;
    }
};

2. Trie
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> suggested;
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }

    void insert(string word) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children.find(word[i])==n->children.end()) n->children[word[i]]=new TrieNode();
            n=n->children[word[i]];
            n->suggested.push_back(word);
            sort(n->suggested.begin(), n->suggested.end());
            if (n->suggested.size()>3) n->suggested.pop_back();
        }
    }

    vector<string> search(string prefix) {
        TrieNode* n=root;
        for (int i=0; i<prefix.size(); ++i) {
            if (n->children.find(prefix[i])==n->children.end()) return vector<string>();
            n=n->children[prefix[i]];
        }
        return n->suggested;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        Trie trie;
        for (auto& p:products) trie.insert(p);
        string curr;
        for (auto c:searchWord) {
            curr+=c;
            res.push_back(trie.search(curr));
        }
        return res;
    }
};

