#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    
  vector<int> tree;
  vector<int> arr;
  int n;
  
  public:
  SegmentTree(vector<int> input){
      arr = input;
      n = input.size();
      tree.resize(4*n);
      build(0,0,n-1);
    }
  
    void build(int node,int start,int end){
        if(start == end){
            tree[node] = arr[start];
            return;
        }
        int mid = (end-start)/2 + start;
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    void update_util(int index,int val,int node,int start,int end){
       if(start == end){
           arr[index] = val;
           tree[node] = val;
           return;
       }
        
       int mid = (end-start)/2 + start;
       if(index<=mid) update_util(index,val,2*node+1,start,mid);
       else update_util(index,val,2*node+2,mid+1,end);
       
       tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    void update(int index,int val){
        update_util(index,val,0,0,n-1);
    }
    
    int range_util(int left,int right,int node,int start,int end){
        
        //out of range
        if(right<start or end<left) return 0;
        
        //fully inside the range
        else if(left<=start and end<=right) return tree[node];
        //overlapping intervals
        else{
            int mid = (end-start)/2 + start;
            
            return range_util(left,right,2*node+1,start,mid) + range_util(left,right,2*node+2,mid+1,end);
        }
    }
    
    int rangeSum(int left,int right){
        return range_util(left,right,0,0,n-1);
    }
};

int main() {
	// your code goes here
	
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(8);
	
	SegmentTree* Tree = new SegmentTree(arr);
	Tree->update(2,2);
	cout<<Tree->rangeSum(2,4)<<endl;
	
    return 0;
}
