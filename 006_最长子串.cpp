#include<iostream>
#include<unordered_set>
using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s)//最长子串
	{
		unordered_set<int> occ;//定义了一个无序集合；
		int n = s.size();//测元素个数
		int j = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
			{
				occ.erase(s[i - 1]);//去除第一个元素；
			}
			while (j < n && occ.count(s[j]) == 0)
			{
				occ.insert(s[j]);
				j++;//这里的j和指针差不多，一直往后移动，把元素加到无序集合里面来。
			}
			ans = max(ans, j - i);
		}
		return ans;
	}
};
int main()
{
	Solution question;
	char s[] = "ajaejagp";
	int ret = question.lengthOfLongestSubstring(s);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
