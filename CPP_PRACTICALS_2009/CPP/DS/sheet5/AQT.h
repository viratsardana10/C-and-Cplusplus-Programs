#include <iostream>
using namespace std;
#define NUM 5
template<class X>class Queue{
    public:
    Queue(){
        front=0;
        end=0;
        array = new X[NUM];
    }   
    void pop();
    void push(X);
    bool isEmpty();
    bool isFull();
    private:
    int front;
    int end;
    X *array; 
};    
template<class X>bool Queue<X>::isEmpty(){
    if(front==0 && end==0) return true;
    else return false;
}    
template<class X>bool Queue<X>::isFull(){
    if(front==1 && end==NUM) return true;
    else return false;
}    
template<class X>void Queue<X>::dequeue(){
    if(isEmpty()){
        cout<<"The Queue is empty.\n";
    }    
    else{
        cout<<"The element popped is: "<<array[front]<<endl;
        if(front==end){
            front=end=0;
        }    
        else{
            front++;
            X* temp = new X[NUM];
            int j=0;
            for(int i=front;i<=end;i++,j++){
                temp[j]=array[i];
            }
            for(int i=0;i<j;i++){
                array[i+1]=temp[i];
            }    
            front=1;        
            end=j;
        }    
    }    
}    
template<class X>void Queue<X>::enqueue(X a){
    if(isFull()){
        cout<<"The Queue is full.\n";
    }    
    else{
        if(!isEmpty()){
            end++;
            array[end]=a;
            cout<<"The element pushed is: "<<array[end]<<endl;
        }   
        else{
            front=end=1;
            array[end]=a;
            cout<<"The element pushed is: "<<array[end]<<endl;
        }     
    }    
}    
