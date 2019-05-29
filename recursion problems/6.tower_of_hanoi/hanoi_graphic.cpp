#include <simplecpp>

#define LX 427
#define MX 927
#define RX 1427

// globally defined variables to hold the number of disks in l, r, m rods
int d_l = 0;
int d_m = 0;
int d_r = 0;

void move(char start, char end, Rectangle disks[], int num, int dis_l[], int dis_m[], int dis_r[]){
	if(start == 'L' && end == 'M'){
		if(d_l == 0){
			cout << "Error in move\n";
			return;
		}

		int target = dis_l[d_l-1];

		if(target == -1){
			cout << "Error in move\n";
			return;
		}

		disks[target].setFill(true);	wait(0.5);

		disks[target].moveTo(LX, 50);	wait(0.5);
		disks[target].moveTo(MX, 50);	wait(0.5);
		disks[target].moveTo(MX, 950 - d_m*100);	wait(0.5);
		disks[target].setFill(false);
		dis_m[d_m] = dis_l[d_l-1];
		dis_l[d_l-1] = -1;
		d_m++;
		d_l--;

	}
	else if(start == 'L' && end == 'R'){

		if(d_l == 0){
			cout << "Error in move\n";
			return;
		}

		int target = dis_l[d_l-1];

		if(target == -1){
			cout << "Error in move\n";
			return;
		}
		
		disks[target].setFill(true);	wait(0.5);
		
		disks[target].moveTo(LX, 50);	wait(0.5);
		disks[target].moveTo(RX, 50);	wait(0.5);
		disks[target].moveTo(RX, 950 - d_r*100);	wait(0.5);
		disks[target].setFill(false);
		dis_r[d_r] = dis_l[d_l-1];
		dis_l[d_l-1] = -1;
		d_r++;
		d_l--;
	}
	else if(start == 'M' && end == 'L'){
		
		if(d_m == 0){
			cout << "Error in move\n";
			return;
		}

		int target = dis_m[d_m-1];

		if(target == -1){
			cout << "Error in move\n";
			return;
		}
		disks[target].setFill(true);	wait(0.5);
		
		disks[target].moveTo(MX, 50);	wait(0.5);
		disks[target].moveTo(LX, 50);	wait(0.5);
		disks[target].moveTo(LX, 950 - d_l*100);	wait(0.5);
		disks[target].setFill(false);
		dis_l[d_l] = dis_m[d_m-1];
		dis_m[d_m-1] = -1;
		d_l++;
		d_m--;	
	}
	else if(start == 'M' && end == 'R'){
		
		if(d_m == 0){
			cout << "Error in move\n";
			return;
		}

		int target = dis_m[d_m-1];

		if(target == -1){
			cout << "Error in move\n";
			return;
		}
		disks[target].setFill(true);	wait(0.5);
		
		disks[target].moveTo(MX, 50);	wait(0.5);
		disks[target].moveTo(RX, 50);	wait(0.5);
		disks[target].moveTo(RX, 950 - d_r*100);	wait(0.5);
		disks[target].setFill(false);
		dis_r[d_r] = dis_m[d_m-1];
		dis_m[d_m-1] = -1;
		d_r++;
		d_m--;
	}
	else if(start == 'R' && end == 'L'){
		
		if(d_r == 0){
			cout << "Error in move\n";
			return;
		}

		int target = dis_r[d_r-1];

		if(target == -1){
			cout << "Error in move\n";
			return;
		}
		disks[target].setFill(true);	wait(0.5);
		
		disks[target].moveTo(RX, 50);	wait(0.5);
		disks[target].moveTo(LX, 50);	wait(0.5);
		disks[target].moveTo(LX, 950 - d_l*100);	wait(0.5);
		disks[target].setFill(false);
		dis_l[d_l] = dis_r[d_r-1];
		dis_r[d_r-1] = -1;
		d_l++;
		d_r--;
	}
	else if(start == 'R' && end == 'M'){

		if(d_r == 0){
			cout << "Error in move\n";
			return;
		}

		int target = dis_r[d_r-1];

		if(target == -1){
			cout << "Error in move\n";
			return;
		}
		disks[target].setFill(true);	wait(0.5);
		
		disks[target].moveTo(RX, 50);	wait(0.5);
		disks[target].moveTo(MX, 50);	wait(0.5);
		disks[target].moveTo(MX, 950 - d_m*100);	wait(0.5);
		disks[target].setFill(false);
		dis_m[d_m] = dis_r[d_r-1];
		dis_r[d_r-1] = -1;
		d_m++;
		d_r--;
	}
	else{
		cout << "Error in moving\n";
		return;
	}
}

void solve_hanoi(int n, char start, char temp, char final, Rectangle disks[], int num, int dis_l[], int dis_m[], int dis_r[]){
	
	if(n == 1){
		printf("Move disk1 from %c to %c\n", start, final);
		move(start, final, disks, num, dis_l, dis_m, dis_r);
	}
	else{
		solve_hanoi(n-1, start, final, temp, disks, num, dis_l, dis_m, dis_r);
		printf("Move disk%i from %c to %c\n", n, start, final);
		move(start, final, disks, num, dis_l, dis_m, dis_r);
		solve_hanoi(n-1, temp, start, final, disks, num, dis_l, dis_m, dis_r);
	}


}

int main(void){
	int num;
	do{
		cout << "How many disks in 'L' Tower (not more than 7):  ";
		cin >> num;	
	} while(num > 7 || num < 1);	
	d_l = num;

	// arrays to hold the sequence of disks in all rods
	int dis_l[num];
	int dis_m[num];
	int dis_r[num];


	// -1 indicates no disk
	for(int i = 0; i < num; i++){
		dis_l[i] = num - i - 1;
		dis_m[i] = -1;
		dis_r[i] = -1;
	}

	initCanvas("Hanoi", 1854, 1026);

	Line ground(0, 1000, 1854, 1000);
	Line R(RX, 1000, RX, 200);
	Line M(MX, 1000, MX, 200);
	Line L(LX, 1000, LX, 200);

	Rectangle disks[num];

	for(int i = 0; i < num; i++){
		Rectangle r1(LX, 950 - 100*i, 400 - 50*i, 100);
		r1.setColor(COLOR("red"));
		disks[num - 1 - i]= r1;
	}

	solve_hanoi(num, 'L', 'M', 'R', disks, num, dis_l, dis_m, dis_r);
	wait(10);

	//solve_hanoi(disks, 'L', 'M', 'R');
	cout << endl;
}