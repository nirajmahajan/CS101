#include <iostream>
using namespace std;

void num_choc(int wrappers, int &ans, int offer_n){
	if(wrappers < offer_n)
	{
		return;
	}

	int new_choc = wrappers/offer_n;
	wrappers = wrappers - offer_n*new_choc + new_choc;
	ans = ans + new_choc;
	num_choc(wrappers, ans, offer_n);

}

int main(void){
	int money, cost, offer_n;
	cout << "Initial Money:  ";
	cin >> money;
	cout << "Cost of one Chocolate:  ";
	cin >> cost;
	cout << "Number of chocolates that can be traded:  ";
	cin >> offer_n;

	int ans = money/cost;
	num_choc(money/cost, ans, offer_n);

	cout << "Number of chocolates that can be eaten = " << ans << endl;

}