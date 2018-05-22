#include <iostream>
#include "Trie.h"
#include <string>
using namespace std;

int main(){

	Trie mTrie;
	string v[8] = {"the","a","there","anwser","any","by","bye","their"};	
	for (int i = 0;i<8;i++)
		mTrie.insert(v[i].c_str());
	string v2[3] = {"ther","Hello","Bathroom"};
	for (int i = 0;i<8;i++)
	{
		if (mTrie.find(v[i].c_str()))
			cout << "Found ";
		else
			cout << "Nah ";
	}

	cout << endl;
	return 0;
}
