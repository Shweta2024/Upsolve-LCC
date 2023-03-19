/*
Intuition :- find out the binary expression of the given number and then iterate over it to count 1's at even and odd indices each.

Time Complexity = O(n)
Space Complexity = O(n), n->size of the binary expression*/

class Solution {
public:
    
    string decimalToBinary(int n)
    {
        string binary = "";
        while( n>0 )   
        {    
            binary += to_string(n%2);    
            n = n/2;  
        }    
        return binary;
    }
    
    vector<int> evenOddBit(int n)
    {
        vector<int>ans(2,0);
        string binary = decimalToBinary(n);
        // for(auto i : binary)
        //     cout<<i<<" ";
        
        for(int i = 0; i < binary.size(); i++)
        {
            if(binary[i] == '1')
            {
                if(i%2==0)
                    ans[0]++;
                else
                    ans[1]++;
            }
        }
        return ans;
    }
};
