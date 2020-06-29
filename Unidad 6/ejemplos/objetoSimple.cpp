#include<iostream>
using namespace std;

class Auto{
private:
	string color;
	
public:
	Auto(string);
	string getColor();
	
};

Auto::Auto(string _color){
	color = _color;
}

string Auto::getColor(){
	return color;
}


int main (int argc, char *argv[]) {
	
	Auto auto1("amarillo");
	Auto auto2("rojo");
	
	cout<<"el color de mi auto es "<< auto2.getColor()<<endl;
	cout<<"el color de mi auto es "<< auto1.getColor()<<endl;
	
	return 0;
}

