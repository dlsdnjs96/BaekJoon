#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct form {
	string str;

};


vector<string> split(string s1, string s2) {
	vector<string> result;
	int e_idx = 0;

	while (true) {
		e_idx = s1.find(s2);

		if (e_idx == string::npos) {
			result.push_back(s1.substr(0));
			break;
		}

		result.push_back(s1.substr(0, e_idx));
		s1 = s1.substr(e_idx + 2);
	}

	return result;
}

string replaceAll(string ss) {

	while (true) {
		ss = ss.replace(ss.find("=="), 2, "&&");
		if (ss.find("==") == string::npos)
			break;
	}
	while (true) {
		ss = ss.replace(ss.find("!="), 2, "&&");
		if (ss.find("!=") == string::npos)
			break;
	}
	return ss;
}

int main() {
	string input;
	vector<string> stk;
	vector<string> stk2;
	vector<int> remove_idx;

	FILE* f = freopen("input.txt", "r", stdin);

	cin >> input;

	stk = split(input, "&&");
	stk2 = split(replaceAll(input), "&&");

	int s_index = 0, e_index = 0, str_len = input.length();
	bool str_type = false;



	for (int i = 0; i < stk.size(); i++)
		cout << stk.at(i) << "\n";
	cout << "\n=" << string::npos << "=\n";

	for (int i = 0; i < stk2.size(); i++) {
		cout << stk2.at(i) << "\n";
		for (int j = i+1; j < stk2.size(); j++) {
			if (stk2.at(i) == stk2.at(j))
				stk2.erase(stk2.begin() + j);
		}
	}


	cout << input << "\n\n";


	return 0;
}