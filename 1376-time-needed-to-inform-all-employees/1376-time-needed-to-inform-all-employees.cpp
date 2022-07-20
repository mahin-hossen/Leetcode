class Solution {
public:
int sumOfMinutes(int headID, vector<int>& manager, vector<int>& informTime) 
{
    if(manager[headID]!=-1)
    {
        informTime[headID] += sumOfMinutes(manager[headID],manager,informTime);
        manager[headID] = -1;    
    }   
    return informTime[headID];
    
}
    
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
{
    int minutes = 0;
    for(int i=0;i<n;i++)
    {
        minutes = max(minutes,sumOfMinutes(i,manager,informTime));
    }
    return minutes;
}
};