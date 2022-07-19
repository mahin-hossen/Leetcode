class Solution {
public:
vector<vector<int>>adjacentNodes;
int totalMinutes(int headID,vector<int>& informTime)
{
    int minutes = 0;
    for(auto subordinate : adjacentNodes[headID])
    {        
        minutes = max(minutes,totalMinutes(subordinate,informTime));
    }
    return minutes+informTime[headID];
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
{    
    adjacentNodes.clear();
    adjacentNodes.resize(n+1);
    for(int i=0;i<n;i++)
    {
        if(manager[i]!=-1)
            adjacentNodes[manager[i]].push_back(i);
    }

    return totalMinutes(headID,informTime);
}
};