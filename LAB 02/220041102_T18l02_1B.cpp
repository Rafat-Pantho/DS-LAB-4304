#include<iostream>
#include <string>

using namespace std;

class Deque{
    private:
        int *arr;
        int front, rear, size, capasity;

    public:
        Deque(int s){
            capasity = s;
            front = -1;
            rear =0;
            size = 0;
            arr = new int [s];
        }
        ~Deque(){
            delete [] arr;
        }


        void push_front(int x){
            if(isFull()){
                cout<<"Deque Overflow"<<endl;
                return;
            }
            if(front == -1) front = rear = 0;
            else if(front == 0) front = capasity-1;
            else front = front -1 ;

            arr[front] = x;
            size++;
            print();
        }

        void push_back(int x){
            if(isFull()){
                cout<<"Deque Overflow"<<endl;
                return;
            }
            if(front == -1) front = rear = 0;
            else if(rear == capasity -1) rear =0;
            else rear = rear+1;

            arr[rear] = x;
            size++;
            print();
        }

        void pop_front(){
            if(isEmpty()){
                cout<<"Deque Underflow"<<endl;
                return;
            }
            if(front == rear) front = rear = -1;
            else if(front == capasity -1) front = 0;
            else front = front+1;
            size--;
            print();
        }

        void pop_back(){
            if(isEmpty()){
                cout<<"Deque Underflow"<<endl;
                return;
            }
            if(front == rear) front = rear = -1;
            else if (rear ==0)rear = capasity -1;
            else rear = rear-1;
            size--;
            print();
        }

        bool isFull(){
            return size == capasity;
        }

        bool isEmpty(){
            return size == 0;
        }

        void print(){
            if(isEmpty()){
                cout<<"EMPTY!!"<<endl;
                return;
            }
            if (front <=rear) for(int i = front; i<=rear; i++) cout<<arr[i]<<" ";
            else{
                for(int i = front; i<capasity; i++) cout<<arr[i]<<" ";
                for(int i = 0; i<=rear; i++) cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void Size(){
            cout<<size<<endl;
        }

        int getFront(){
            return front;
        }

        int getRear(){
            return rear;
        }
};

int main(){
    int s;cin>>s;
    Deque d(s);
    string a;
    while(cin>>a && a!="E"){
        if (a=="PF"){
            int x;cin>>x;
            d.push_front(x);
        }
        else if (a=="PB"){
            int x;cin>>x;
            d.push_back(x);
        }
        else if (a=="DF")d.pop_front();
        else if (a=="DB")d.pop_back();
        else if (a=="S")d.Size();
        else if (a=="F")cout<<d.getFront()<<endl;
        else if (a=="R")cout<<d.getRear()<<endl;
        else if (a=="STAT"){
            if (d.isFull())cout<<"FULL"<<endl;
            else if(d.isEmpty())cout<<"EMPTY"<<endl;
            else cout<<"none"<<endl;
        }
    }
}