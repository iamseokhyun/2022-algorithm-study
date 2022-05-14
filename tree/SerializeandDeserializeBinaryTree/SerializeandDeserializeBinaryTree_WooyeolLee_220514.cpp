// Encodes a tree to a single string.    
string serialize(TreeNode* root) {    
    string ret = "";    
    preorderEncoding(root, ret);    
    return ret;    
}     
void preorderEncoding(TreeNode* root, string& ret){     
    if(root == nullptr){    
        ret = ret + "/";    
        return;    
    }    
    ret = ret + to_string(root->val) + "=";    
    preorderEncoding(root->left, ret);    
    preorderEncoding(root->right, ret);    
}
    
// Decodes your encoded data to tree.    
TreeNode* deserialize(string data) {    
    int begin = 0;    
    return preorderDecoding(data, begin);    
}        
TreeNode* preorderDecoding(string& data, int& begin){    
    if(data[begin] == '/'){
        begin++;
        return nullptr;
    }

    int len = 1;    
    while(data[begin+len] != '=') len++;    
    string val = data.substr(begin, len);    
    TreeNode* node = new struct TreeNode(stoi(val));    
   
    begin += len + 1;
    node->left = preorderDecoding(data, begin);    
    node->right = preorderDecoding(data, begin);    
    return node;    
} // runtime : 405 ms, memory usage : 762.3 MB (pretty poor performance :<)

/*
- Encode binary tree by using preorder traversal. Contain each node’s value while doing a preorder traversal.
- Divide each node’s value with delimeter ‘=’. If node is empty(=nullptr), check it with another delimeter ‘/’.
- Doing all this procedure recursively.
*/



#include <sstream>

// Encodes a tree to a single string.
string serialize(TreeNode* root) {    
    stringstream encoded;    
    preorderEncoding(root, encoded);    
    return encoded.str();    
}    
void preorderEncoding(TreeNode* root, stringstream& encoded){    
    if(root == nullptr){    
        encoded << "/ ";    
        return;    
    }    
    encoded << root->val << " ";    
    preorderEncoding(root->left, encoded);    
    preorderEncoding(root->right, encoded);    
}
    
// Decodes your encoded data to tree.    
TreeNode* deserialize(string data) {    
    stringstream encoded(data);    
    return preorderDecoding(encoded);            
}    
TreeNode* preorderDecoding(stringstream& encoded){    
    string val;    
    encoded >> val;    
    if(val == "/") return nullptr;    
    TreeNode* node = new struct TreeNode(stoi(val));            
    
    node->left = preorderDecoding(encoded);   
    node->right = preorderDecoding(encoded);   
    return node;    
} // runtime : 54 ms (faster than 75.49 %), memory usage : 31.1 MB (less than 55.91 %)

/*
- Algorithm using "stringstream" (which associates a string object with a stream allowing you to read from the string as if it were a stream (like cin))
- Time complexity: O(n) (traverse all nodes 1 time)
  Space complexity: O(n) (maximum recursive stack = O(h) = O(n))
    
- The question is that both algorithms used preorder traversal to 
  serialize and deserialize binary tree but showed huge performance difference. What makes this difference?
*/
