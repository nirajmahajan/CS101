#include <iostream>
using namespace std;

int reach(int x2, int y2, int x1, int y1){
	bool violation;
	if(x2 == x1 && y2 == y1){
		return 0;
	}
	else if(x2 < x1 || y2 < y1){
		return -1;
	}

	int temp1 = reach(x2, y2, x1, x1+y1);
	int temp2 = reach(x2, y2, x1+y1, y1);

	if(temp1 == -1 && temp2 == -1){
		return -1;
	}
	else if(temp1 == -1){
		return (1 + temp2);
	}
	else if(temp2 == -1){
		return (1 + temp1);
	}
	else{
		return (1 + min(temp1, temp2));
	}
}

int main(void){
	int x1, x2, y1, y2;
	cout << "x1:  ";
	cin >> x1;
	cout << "y1:  ";
	cin >> y1;
	cout << "x2:  ";
	cin >> x2;
	cout << "y2:  ";
	cin >> y2;

	int ans = reach(x2, y2, x1, y1);

	if(ans == -1){
		cout << "Cannot reach the point\n";
	}
	else{
		cout << "Can reach the point in " << ans << " steps\n";
	}

}