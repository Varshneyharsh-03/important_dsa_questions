bool solve(string wild,string pattern,int i,int j){
        if(i<0 and j<0) return true;
        if(i<0 and j>=0) {
            return false;
        }
        if(i>=0 and j<0){
            for(int k=0;k<=i;k++){
                if(wild[k]!='*') return false;
            }
            return true;
        }
        
        if(wild[i]==pattern[j] || wild[i]=='?'){
            return solve(wild,pattern,i-1,j-1);
        }
        else if(wild[i]=='*'){
            return solve(wild,pattern,i,j-1) || solve(wild,pattern,i-1,j);
        }
        else return false;
    }
