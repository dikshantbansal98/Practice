class Node {
public:
    vector<Node*>children;
	int maxValue;
	Node() {
        children = vector<Node*>(27, NULL);
        maxValue = -1;
	}
};

class Trie {
public:
	Node *Root;
	Trie() {
		Root = new Node();
	}
    void insertAllCombinations(string str, int index) {
       string suffix = "";
        for(int i = str.size()-1; i >=0; --i) {
            suffix += str[i];
            string newString = suffix + "#" + str;
            insert(newString, index);
        }
    }
	void insert(string str, int index) {
		Node *root = Root;
        bool isPrefix = false;
		for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '#') {
                if(root->children[26] == NULL)
                    root->children[26] = new Node();
                root = root->children[26];
                isPrefix = true;
                continue;
            }
			if(root->children[str[i]-'a'] == NULL) {
				root->children[str[i]-'a'] = new Node();
			}
			root = root->children[str[i]-'a'];
            if(isPrefix) {
                root->maxValue = max(root->maxValue,index);
            }
		}
	}
	int getIndex(string str) {
		Node *root = Root;
        bool isPrefix = false;
		for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '#') {
                root = root->children[26];
                isPrefix = true;
                continue;
            }
			if(root->children[str[i]-'a'] == NULL) {
				return -1;
			}
			root = root->children[str[i]-'a'];
		}
		return root->maxValue;
	}
};


class WordFilter {
public:
	Trie *trie;
    WordFilter(vector<string> words) {
        trie = new Trie();
        for(int i = 0; i < words.size(); ++i) {
            trie->insertAllCombinations(words[i],i);
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(),suffix.end());
        return trie->getIndex(suffix+"#"+prefix);
    }
};
