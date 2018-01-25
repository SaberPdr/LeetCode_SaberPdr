//好的解法:来自LeetCode论坛
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mapping;
        //map<int, int> mapping;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) 
	{
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) 
	{
            const int gap = target - nums[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) 
	    {
                result.push_back(i );
                result.push_back(mapping[gap]);
                break;
            }
        }
        return result;
    }
};

//最开始我的想法
/********************
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> result;
	    vector<int> num2 = numbers;
        int n = num2.size();
	    sort(num2.begin(),num2.end());

        int a = 0;
        int b = n - 1;
        while(a < b)
        {
                int add = num2[a] + num2[b];
                if(add > target)
                        b--;
                else if(add < target)
                        a++;
                else if(add == target)
                        break;
        }

        vector<int>::iterator finded_a = find(numbers.begin(), numbers.end(), num2[a]);
        vector<int>::iterator finded_b = find(numbers.begin(), numbers.end(), num2[b]);  
//在出现[3,3] 6这样的数据时会有问题, 因为find函数找的只是第一个出现的位置,所以这个解法是错误的
        result.push_back(numbers.end() - finded_b);
        result.push_back(numbers.end() - finded_a);
        
	    return result;
    }
};
************************/
//还有最朴素的O(n)复杂度的,虽然慢但是一定对
/***********************
class Solution {
vector<int> twoSum(vector<int> &numbers, int target)
        {
                vector<int> result;
                int n = numbers.size();
                for(int i = 0; i < n; i++)
                {
                        int numToFind = target - numbers[i];
                        for(int j = i+1; j < n; j++)
                        {
                                if(numbers[j] == numToFind)
                                {
                                        result.push_back(i);
                                        result.push_back(j);
                                        return result;
                                }
                        }
                }
                return result;
        }
};
************************/
