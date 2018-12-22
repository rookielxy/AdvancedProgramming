#ifndef HW4_SHELL_H
#define HW4_SHELL_H

#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Shell {
	vector<string> homedir;
	vector<string> dir;
	static vector<string> split(const string &dir);
	vector<string> calculateDir(const string &path);
public:
	explicit Shell(const string &homedir="/");
	~Shell() = default;
	void pwd();
	void cd(const string &path="");
	void distance(const string &path);
};

Shell::Shell(const string &homedir) {
	dir = this->homedir = split(homedir);
}

vector<string> Shell::split(const string &dir) {
	vector<string> temp;
	int idx = 0;
	size_t len = 0;

	for (int i = 0; i < dir.size(); ++i) {
		if (dir[i] == '/') {
			if (not dir.substr((unsigned long)idx, len).empty())
				temp.emplace_back(dir.substr((unsigned long)idx, len));
			idx = i + 1;
			len = 0;
		} else {
			++len;
		}
	}
	if (len != 0)
		temp.emplace_back(dir.substr((unsigned long)idx, len));

	return temp;
}

void Shell::pwd() {
	cout << "/";
	for (auto &str : dir)
		cout << str << "/";
	cout << endl;
}

void Shell::cd(const string &path) {
	if (path.empty())
		cd("~");
	else
		dir = calculateDir(path);

}

void Shell::distance(const string &path) {
	auto temp = calculateDir(path);
	int count = 0;
	for (int i = 0; i < temp.size() and i < dir.size(); ++i) {
		if (temp[i] == dir[i])
			++count;
		else
			break;
	}
	cout << temp.size() + dir.size() - 2*count << endl;
}

vector<string> Shell::calculateDir(const string &path) {
	vector<string> result;
	vector<string> temp = split(path);
	if (not (path[0] == '/' or path[0] == '~')) {
		result = dir;
	} else if (path[0] == '~') {
		result = homedir;
	}

	for (auto &str : temp) {
		if (str == "." or str.empty())
			continue;
		else if (str == "..") {
			if (not result.empty())
				result.pop_back();
		} else if (str == "~") {
			result = homedir;
		} else
			result.emplace_back(str);
	}
	return result;
}

#endif //HW4_SHELL_H
