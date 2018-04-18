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
//1.4 Write a method to decide if two strings are anagarams or not.
//return true if they are anagrams
bool fun1_4(char * str1,int len1, char * str2, int len2);
//1.5 Write method to replace all spaces in a string with '%20'
void fun1_5(char *str, int len);
//1.6 Given an image represented by an NxN matrix, where each pixel in
//the image is 4 bytes, write a mthod to rotate the image by 90 degress.
void fun1_6(int mat[5][],int row, int col);


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

//1.4 Write a method to decide if two strings are anagrams or not.
bool fun1_4(char * str1, int len1, char * str2, int len) {
	
	int char_s1[256];
	int char_s2[256];
	
	//set all values in arrays to 0
	for (int i = 0; i< 256; i++) {
		char_s1[i] = 0; 
		char_s2[i] = 0;
	}
	
	//Adding str 1
	for(int i = 0; i< len1; i++) {
		char_s1[str1[i]]++;
	}
	
	//Adding str2
	for(int i = 0; i< len2;i++) {
		char_s2[str2[i]]++;
	}
	
	//compare arrays
	bool are_anagrams = true;
	for (int i = 0;i<256;i++) {
		if (char_s1[i] != char_s2[i]) {
			are_anagrams = false;
			break;
		}
	}
	
	return are_anagrams;
}

//1.5 write a method to replace all spaces in a string with %20
void fun1_5(char * str, int len) {
	//First count number of spaces
	int count = 0;
	for(int i = 0; i< len; i++) {
		if (*str == ' ') count++;
	}
	
	//increase the size of the string
	int n_len = len+(count*2);
	str[n_len--] = '\0';
	
	//Fill in string from the back
	for(int i = len-1; i>=0;i--) {
		if (str[i] == ' ' ) {
			str[n_len--] = '0';
			str[n_len--] = '2';
			str[n_len--] = '%';
		} else {
			str[n_len--] = str[i];
		}
	}
}

//1.6 Give an image represented by an NxN matrix, where each pixel in image 
//is 4 bytes, write amethod to rotate the image by 90 degrees.
void fun1_6(int mat[5][],int row,int col) {
	//First reflect the matrix about the horizontal axis.
	//Then reflect the matrix about y = -x;
	//This can be done in place
	
	int rb, re; rb = 0; re = row; //rb->row beginning. re->row end
	int cpy;
	while(rb < re) {
		for(int i=0;i<col;i++) {
			cpy = mat[rb][i];
			mat[rb][i] = mat[re][i];
			mat[re][i] = cpy;
		}
		rb++;
		re--;
	}
	
	//Matrix should be flipped. Now reflect about y=-x;
	int Ri,Ci,ri,ci; ri=0;ci=0;Ri=0;Ci=0; //rows and cols for iteration
	while(Ri != row && Ci != col) {
		
		if (ri == row && ci == row) {
			Ri++; Ci++; ri = Ri;ci = Ci;
		}
		cpy = Mat[Ri][ci];
		Mat[Ri][ci] = Mat[ri][Ci];
		Mat[ri][Ci] = cpy;
		ri++;ci++;
	}
	
}