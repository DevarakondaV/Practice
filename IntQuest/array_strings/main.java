public class Main() {
	public static void main(String[] args) {
		System.out.println("Hello World");
	}
	
	//1.8 Assume s2.isSubstring(s1) checks if s1 is a substring of s2.
	//Determine if s2 is a rotation of s1 by calling isSubstring only once
	//Rotation->("waterbottle is a rotation of "erbottlewat"
	public static bool fun1_8(String s1, String s2) {
		if (s1.length() != s2.length() )
			return false;
		//My Solution
		//Find where s1[0] occurs in s[2]
		//determine length of remaining string in s2.
		// This gives you a starting idx
		//Grab substring from s1 from idx to end
		//Check if this substring is a substring of s2
		int idx_f = 0;
		for(idx_f;idx_f<s2.length();idx_f++) {
			if (s2.charAt[idx_f] == s1.charAt[0])
				break;
		}
		
		int str_len = s2.length()-idx_f;
		String sub = s1.substring(str_len-1,s1.length());
		if (s2.isSubstring(sub))
			return true;
		else
			return false;
		
		//A far better solution
		//concatinate the s1 with itself-> erbottlewaterbottleway
		//check to make sure s2 is a substring of the concatination-> waterbottle is a substring of erbottlewaterbottleway
		
		String concat = s1+s1;
		if (concat.isSubstring(s2))
			return true;
		else
			return false;
		
	}	
}	
