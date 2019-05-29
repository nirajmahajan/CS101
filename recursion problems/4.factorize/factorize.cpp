#include <iostream>
using namespace std;

void factorize(int n, int div){
	if(n == 1){
		return;
	}

	while(n%div == 0){
		n = n/div;
		cout << div << " ";
	}

	if(div == 2){
		factorize(n, div+1);
	}
	else{
		factorize(n, div+2);
	}
}

int main(void){
	int n;
	cout << "Number:  ";
	cin >> n;
	cout << "The factors are:\n";
	factorize(n, 2);
	cout << endl;
}