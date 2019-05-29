#include <simplecpp>
#define LEN 200

void draw_tree(int depth, double x, double y, double angle){
	if(depth == 0){
		return;
	}

	Turtle t1;
	t1.penUp();
	t1.moveTo(x, y);
	t1.penDown();
	t1.left(90);

	t1.right(angle/2);
	t1.forward(LEN);
	t1.left(angle/2);
	draw_tree(depth-1, t1.getX(), t1.getY(), angle/2);
	t1.left(180 - angle/2);
	t1.forward(LEN);
	t1.right(180 - angle/2);
	t1.left(angle/2);
	t1.forward(LEN);
	t1.right(angle/2);
	draw_tree(depth-1, t1.getX(), t1.getY(), angle/2);
}

int main(void){
	int depth;
	cout << "Depth:  ";
	cin >> depth;

	initCanvas("Tree", 1854, 1026);

	draw_tree(depth, 927, 1026, 150);
	wait(5);
}