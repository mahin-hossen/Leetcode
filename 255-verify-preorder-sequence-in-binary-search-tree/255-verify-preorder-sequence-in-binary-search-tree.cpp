class Solution {
public:

bool traversePreorder(vector<int>& preorder,int &currIdx,int L,int R)
{    
    if(currIdx==preorder.size()) return true;
    
    int V = preorder[currIdx];
    if(V<L || V>R) return false;
    currIdx++;
    
    auto left = traversePreorder(preorder,currIdx,L,V-1);
    auto right = traversePreorder(preorder,currIdx,V+1,R);
    return left||right;
}
bool verifyPreorder(vector<int>& preorder)
{
    int currIdx = 0;
    return traversePreorder(preorder,currIdx,INT_MIN,INT_MAX);
}

};