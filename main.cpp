//Given nums = [2, 7, 11, 15], target = 9,

//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
//本次代码是学习别人的,注释记录下思路

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

    //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
			result.push_back(hash[numberToFind]);
			result.push_back(i);
			return result;
		}
    //hash[3] = 0,第一次for不进入if,直接给hash加一个键值对
		//hash[2] = 1,第二次for也不满足if
		//hash[4] = 2,第三次满足if, 返回了hash[2]=1和i=2
    //number was not found. Put it in the map.
		hash[numbers[i]] = i;

	}
	return result;
}

int main()
{
        vector<int> num = {3,2,4};

        //cout << num.capacity() << endl;

        vector<int> n;
        n = twoSum(num, 6);
        cout << n[0] << "   " << n[1];

        return 1;
}

