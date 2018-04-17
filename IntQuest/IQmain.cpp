#include <string>
#include <iostream>
using namespace std;
//1.1 Implement an algorithm to determine if a string has all 
//unique characters. What if you can not use additional data structures?
bool fun1_1(string m_string);
bool fun1_1_no_mem(string m_string); //same as fun1_1 except no additional data structures
//1.2 Write code to reverse a C-style String.
void fun1_2(char *  str);
//1.3 remove duplicates from a string
void fun1_3(char * str,int len);


int main() {
	char str[13] = "Hello, World";

	cout << str << endl;
	fun1_3(str,13);
	cout << str << endl;
	return 0;
}

//1.1 Implement an algorithm to determine if a string has all 
//unique characters. What if you can not use additional data structures?
bool fun1_1(string m_string) {
	//Fill array using ascii code as index;
	int chars[256];
	for(int i = 0; i< 256;i++)
		chars[i] = 0;
	
	bool all_unique = true;
	for(int i = 0; i< m_string.length();i++) {
		if (chars[m_string[i]] == 1) {
			all_unique = false;
			break;
		}
		chars[m_string[i]] = 1;
	}
}

bool fun1_1_no_dat(string m_string) {
	long bbuffer = 0;
	bool all_unique = true;
	
	int val = 0;
	long m_1;
	for(int i = 0; i< m_string.length();i++) {
		val = m_string[i];
		m_1 = 1 << val;
		if ((bbuffer & m_1) != 0) { all_unique = false;break;}
		bbuffer = bbuffer | m_1;
	}
	
	return all_unique;
}

//1.2 Write code to reverse a C-style String
void fun1_2(char * str) {
	if (*str == '\0') return;
	
	
	char * end = str;
	char cpy;
	while(*end) {
		end++;
	}
	end--;	
	while(str < end) {
		cpy = *str;
		*str = *end;
		*end = cpy;
		str++;
		end--;
	}
}

//1.3 remove duplicates from a string
void fun1_3(char * str, int len) {
	if (len < 2) 
		return;
	if (*str == '\0') return;

	int idx = 1;
	for (int i = 1;i<len;i++) {
		int j;
		for(j = 0; j<i;j++) {
			if (str[i] == str[j])
			       	break;
		}
		if (i == j) {
			str[idx] = str[i];
			idx++;
		}
	}
}

