#include "Trie.h"


//Public Methods
/* Constructor
 * Inserts declared array into Trie
 */
Trie::Trie(){
	end = true;
	for (int i = 0;i<ALPHA_SIZE;i++)
		child[i] = 0;

}


/* Inserts into Trie
 * Returns pointer new Trie
 */
bool Trie::insert(const char* array)
{
	if (*(array) == '\0') {
		this->end = true;
		return true;
	}

	char i_val = get_lower(*array);
	if (this->child[i_val] != 0)
		return this->child[i_val]->insert(array+1);
	else {
		Trie * new_node = new Trie();
		new_node->end = false;
		this->child[i_val] = new_node;
		return new_node->insert(array+1);
	}
}



/* if val exists in the Trie
 * return true. else false
 */
bool Trie::find(const char* val)
{		
	char i_val = get_lower(*val);
	if (this->child[i_val] == 0)
		return false;
	if (*(val+1) == '\0') {
		return this->child[i_val]->end;
	}

	
	return this->child[i_val]->find(val+1);
}
//Private methods
/* Checks if letter is a letter 
 * Returns lower if it is letter
 * or Returns letter
 */
char Trie::get_lower(char letter){
	if ( 65<=letter && letter<=90)
		letter = letter+32;
	
	return letter-97;
}

