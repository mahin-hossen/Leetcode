class Solution 
{    
public:
    class TrieNode
    {
    public:    
        string word;
        TrieNode* next[26];

        TrieNode()
        {
            word = "";
            for(int i=0;i<26;i++)
            {
                next[i]=NULL;
            }
        }
    };
    
    TrieNode* generateTrie(vector<string>& products)
    {
        TrieNode* root = new TrieNode();        
        
        for(auto &product : products)
        {
            TrieNode* currNode = root;
            for(auto &c : product)
            {
                if(currNode->next[c-'a']==NULL)
                {
                    currNode->next[c-'a'] = new TrieNode();
                }
                currNode = currNode->next[c-'a'];
            }
            currNode->word = product;
        }
        
        return root;
    }  

    void dfs(TrieNode* u,vector<string>& threeWords)
    {        
        if(u==NULL || threeWords.size()==3) return;
        
        if(u->word.size()!=0 && threeWords.size()<3)
        {
            threeWords.push_back(u->word);            
        }
        
        for(int i=0;i<26;i++)
        {
            dfs(u->next[i],threeWords);                
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        TrieNode* root = generateTrie(products);
        
        vector<vector<string>> suggestions;       
        
        for(auto &c : searchWord)
        {
            root = root && root->next[c-'a'] ? root->next[c-'a'] : NULL;            
            vector<string> threeWords;

            dfs(root,threeWords);
            suggestions.push_back(threeWords);            
        }        
        
        return suggestions;
    }
};