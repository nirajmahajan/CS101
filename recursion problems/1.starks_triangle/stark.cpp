#include <simplecpp>

void triangle(Turtle &t1, double len){
	for(int i = 0; i < 3; i++){
		t1.forward(len);
		t1.left(120);
	}
}

void stark(int depth, double len, Turtle &t1){
	t1.penUp();
	if(depth == 0)
	{
		return;
	}
	t1.penDown();

	triangle(t1, len);
	stark(depth-1, len/2, t1);
	t1.forward(len/2);
	stark(depth-1, len/2, t1);
	t1.left(120);
	t1.forward(len/2);
	t1.right(120);
	stark(depth-1, len/2, t1);
	t1.right(120);
	t1.forward(len/2);
	t1.left(120);

	t1.penUp();
}

int main(void){
	int depth;
	cout << "Depth:  ";
	cin >> depth;

	initCanvas("Stark's Triangle", 1854, 1026);
	Turtle t1;

	stark(depth, 400, t1);
	wait(5);
}