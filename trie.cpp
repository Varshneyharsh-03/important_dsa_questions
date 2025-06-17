#include <bits/stdc++.h>
using namespace std;

class TrieNode {
char data;
TrieNode*  children[26];
bool flag;

TrieNode(data){
  this->data = data;
  for(int i=0;i<26;i++){
    children[i]=nullptr;
  flag = false;
}
};


class Trie{
TrieNode* root;
  Trie(){
    root= new TrieNode('/0');
  }
void insertUtil(TrieNode* root,string word){
  if(word.size()==0){
    root->flag = true;
  }
  int ind = word[0]-'A';
  TrieNode* child;

  if(root->children[ind]!=nullptr){
    child = root->children[ind];
  }
  else{
    child = new TrieNode(word[0]);
    root->children[ind]=child;
  }
  insertUtil(child,word.substr(1));
}

void insertWord(string word){
  insertUtil(root,word);
}
bool searchUtil(string word,TrieNode* root){
  if(word.size()==0) return true;
  int ind = word[0]-'A';
  if(root->children[ind]==nullptr) return false;
  return searchUtil(word.substr(1),root->children[ind]);
}

bool search(string word){
  return searchUtil(word,root);
}

void deleteUtil(string word,TrieNode* root){
  if(word.size()==0){
    root->flag = false;
    return;
  }
  deleteUtil(word.substr(1),root->chidren[word[ind]-'A']);
}

void deleteWord(string word){
  if(search(word)==false) return;

  deleteUtil(word,root);
}

};

int main(){
  Trie t;
  t.insert
  return 0;
}

