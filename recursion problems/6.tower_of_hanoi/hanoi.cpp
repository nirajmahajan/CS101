// gives instructions to solve tower of hanoi
// three towers being L, M, R
// By Niraj Mahajan IITB,CSE
#include <iostream>
using namespace std;

void solve_hanoi(int n, char start, char temp, char final){
	
	if(n == 1){
		printf("Move disk1 from %c to %c\n", start, final);
	}
	else{
		solve_hanoi(n-1, start, final, temp);
		printf("Move disk%i from %c to %c\n", n, start, final);
		solve_hanoi(n-1, temp, start, final);
	}


}

int main(void){
	int disks;
	cout << "How many disks in 'L' Tower:  ";
	cin >> disks;

	solve_hanoi(disks, 'L', 'M', 'R');
	cout << endl;
}
