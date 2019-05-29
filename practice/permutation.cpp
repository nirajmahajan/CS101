// takes input of a string, and prints all permutations in lexographic order
// By Niraj Mahajan, IITB, CSE
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map <char, int> List;

// Invariant : List input contains all the chars in lexographic order that are left to be included
//			   curr contains the string that is currently being built
void print_permut(List input, string curr, int map_size){
	if(map_size == 0){
		cout << curr << endl;
		return;
	}
	string now;
	for(List::iterator li = input.begin(); li != input.end(); li++){	
		now = curr;
		if(li->second != 0){
			now += li->first;
			li->second--;
			print_permut(input, now, map_size-1);
			li->second++;
		}
	}
}

int main(void){
	string input;
	cin >> input;
	List l1;
	for(int i = 0, len = input.length(); i < len; i++){
		if(l1.find(input[i]) == l1.end()){
			l1[input[i]] = 1;
		}
		else{
			l1[input[i]]++;
		}
	}
	print_permut(l1, "", input.size());
}