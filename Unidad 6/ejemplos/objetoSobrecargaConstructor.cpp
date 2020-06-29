#include<iostream>
using namespace std;

class Auto{
private:
	string color;
	
public:
	Auto(string);
	Auto();
	string getColor();
	
};

Auto::Auto(string _color){
	color = _color;
}

Auto::Auto(){
	color = "gris";
}

string Auto::getColor(){
	return color;
}


int main (int argc, char *argv[]) {
	
	Auto auto1("amarillo");
	Auto auto2;
	
	cout<<"el color de mi auto es "<< auto2.getColor()<<endl;
	cout<<"el color de mi auto es "<< auto1.getColor()<<endl;
	
	return 0;
}
