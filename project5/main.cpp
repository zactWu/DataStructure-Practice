#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    queue<int> customer_a;
    queue<int> customer_b;
    int input;
    int len;
    cin>>len;
    for (int i = 0; i < len; ++i) {
        cin>>input;
        if(input % 2 == 0){
            customer_b.enqueue(input);
        }
        else{
            customer_a.enqueue(input);
        }
    }
    for (int j = 0; j < len; ++j) {
        if (!customer_a.is_empty()) {
            cout << customer_a.dequeue() << " " << customer_a.dequeue() << " ";
        }
        if(!customer_b.is_empty()){
            cout << customer_b.dequeue() << " " ;
        }
        if(customer_a.is_empty() && customer_b.is_empty()){
            return 0;
        }
    }
}