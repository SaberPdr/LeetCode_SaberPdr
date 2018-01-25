//好的解法:来自LeetCode论坛
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
                //Key is the number and value is its index in the vector.
                unordered_map<int, int> hash;
                vector<int> result;
                for (int i = 0; i < numbers.size(); i++)
                {
                        int numberToFind = target - numbers[i];

                        //if numberToFind is found in map, return them
                        if (hash.find(numberToFind) != hash.end())
                        {
                                result.push_back(hash[numberToFind]);
                                result.push_back(i);
                                return result;
                        }

                        //number was not found. Put it in the map.
                        hash[numbers[i]] = i;
                }
                return result;
        }
};

int main()
{
        Solution S;
        vector<int> numbers = {3,3};
        int target = 6;
        vector<int> anwsers = S.twoSum(numbers,target);
        cout << anwsers[0] << "," << anwsers[1] << endl;
        return 0;
}
