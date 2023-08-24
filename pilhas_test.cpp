#include <iostream>

class Stack{

    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

    public:
        Stack(){
            top = -1; //pliha vazia
        }
        
        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top == MAX_SIZE - 1;
        }

        void push(int value){
            if(isFull()){
                std::cout << "A pilha está cheia";
            }
            arr[++top] = value; //se n estiver cheia
        }

};