#include <iostream>

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
};


int main(){
    Deque array1(6);
    /* as the question didn't mention anything about capacity
    i am taking 6 as the default capacity */
    int x;
    while(cin>>x && x!=6){
        int d;
        switch(x){
            case 1:
                cin>>d;
                array1.push_front(d);
                break;
            case 2:
                cin>>d;
                array1.push_back(d);
                break;
            case 3:
                array1.pop_front();
                break;
            case 4:
                array1.pop_back();
                break;
            case 5:
                array1.Size();
                break;
        }
    }
    return 0;
}