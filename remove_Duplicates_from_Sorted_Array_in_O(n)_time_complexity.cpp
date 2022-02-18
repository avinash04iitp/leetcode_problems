/*

*/


// Ref:- Map in c++ :-> https://appdividend.com/2022/02/14/cpp-map/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {    
        map<int, int> map1;
        map<int, int>::iterator k;
        int len = nums.size();
        int j=0;
        for(int i=0; i<len; i++)
        {
            map1[nums[i]] = 1;
        }
        for(k = map1.begin(); k!=map1.end(); k++)
        { 
            if(k->second ==1)
            {
                nums[j] = k->first;
                j++;
            }     
        }
        return j;       
    }
};
