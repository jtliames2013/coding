CanWin. 给一个数组比如 [2,3,0,3,5]和一个index比如4，从这个index每次可以向左或者向右跳ary[index]的距离， 如果能跳到值为0的index则返回true。

class Solution {
public:
	bool canWin(vector<int>& data, vector<bool>& visited, int index) {
		if (index<0 || index>=data.size()) return false;
		if (visited[index]==true) return false;
		if (data[index]==0) return true;

		visited[index]=true;
		int newIdx=index+data[index];
		if (canWin(data, visited, newIdx)) return true;
		newIdx=index-data[index];
		if (canWin(data, visited, newIdx)) return true;
		visited[index]=false;
		return false;
	}

	bool canWin(vector<int> data, int index) {
		int n=data.size();
		vector<bool> visited(n, false);
		return canWin(data, visited, index);
	}
};

int main() {
	vector<int> data={1,2,3,0,4,5,7};
	Solution s;
	bool res=s.canWin(data, 6);
	return 0;
}

