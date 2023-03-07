//Time Complexity = O(time)
//Space Complexity = O(1)

class Solution {
public:
    
    
    int passThePillow(int n, int time)
    {
        int i = 1;

        while(time)
        {
                while(time > 0 && i != n)
                {
                    i++;
                    time--;
                }
            
                while(time > 0 && i != 1)
                {
                    i--;
                    time--;
                }
        }
        return i;
    }
};
