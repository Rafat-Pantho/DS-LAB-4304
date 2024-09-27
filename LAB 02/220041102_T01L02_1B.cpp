#include <iostream>

using namespace std;

class Circular_Queue{
    private:
        int front, rear, size, *array_1;

    public:
        Circular_Queue(int s){
            size = s;
            front = rear =-1;
            array_1 = new int [size];
        }

        void enQueue(int x){
            if( (front ==0 && rear == size- 1) || ( rear == (front-1)%(size-1) ) ) {
                cout << "Overflow" << endl;
                return;
            }
            
            else if(front == -1){
                front = rear = 0;
                array_1[rear] = x;
            }

            else if (rear == size-1 && front !=0){
                rear = 0;
                array_1[rear] = x;
            }

            else{
                rear++;
                array_1[rear] = x;
            }
        }

        int deQueue(){
            if (front == -1){
                cout << "Underflow" <<endl;
                return -1;
            }
            
            int x = array_1[front];
            array_1[front]=-1;

            if(front == rear) front = rear = -1;
            else if (front == size -1 ) front ==0;
            else front++;

            return x;
        }

        bool isEmpty(){
            return (front== -1 && rear == -1);
        }

        bool isFull(){
            return (rear + 1) % size == front;
        }

        int Size(){
            if(rear>= front) return rear - front +1;
            else return (rear - front +1) + size;
        }

        int Front(){
            if(front == -1) return -1;
            else return array_1[front];
        }

        ~Circular_Queue(){}
};

int main(){
    int  size_of_queue; cin>>size_of_queue;

    Circular_Queue q(size_of_queue);

    while(true){
        int choice; cin>>choice;
        if (choice ==-1){
            cout<< "Exit" <<endl;
            break;
        }

        switch (choice){
            case 1:
                int x;cin>>x;
                q.enQueue(x);
                cout<< "EnQueue: " << x << endl;
                break;

            case 2:
                cout <<"DeQueue: "; cout<< (q.deQueue()) <<endl;
                break;

            case 3:
                cout << "isEmpty: "<< (q.isEmpty()?"True":"False") <<endl;
                break;
            
            case 4:
                cout << "isFull: "<< (q.isFull()?"True":"False") <<endl;
                break;

            case 5:
                cout << "Size: "<< q.Size() <<endl;
                break;
            
            case 6:
                cout << "Front: "<< q.Front() <<endl;
                break;
        }
    }

    return 0;
}