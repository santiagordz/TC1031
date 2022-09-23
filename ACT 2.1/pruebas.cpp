#include "list.h"

int main(){
    List<int> b1;
	b1.push_front(7); 
    b1.push_front(6); 
    b1.push_front(5);
	b1.push_front(4); 
    b1.push_front(3); 
    b1.push_front(2);
    cout << b1.toString() << endl;

    cout << b1.get(0);
}