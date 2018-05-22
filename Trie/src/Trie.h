#ifndef __TRIE__H
#define __TRIE__H

#define ALPHA_SIZE 26

class Trie {
	public:
		Trie();
		//~Trie();
		bool insert(const char* array);
		bool remove(const char* array);
		bool find(const char* val);

	private:
		Trie* child[ALPHA_SIZE];
		bool end;

		char get_lower(char letter);
};
#endif
