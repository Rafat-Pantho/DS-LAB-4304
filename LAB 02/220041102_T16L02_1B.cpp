#include <iostream>
#include <string>

using namespace std;

class Circular_Queue{
    private:
        int front, rear, size, capasity, *array_1;

    public:
        Circular_Queue(int s){
            capasity = s;
            size =0;
            front = rear =-1;
            array_1 = new int [s];
        }

        void enQueue(int x){
            if(size == capasity ) {
                cout << "Overflow!!" << endl;
                return;
            }
            
            if(front == -1) front = rear = 0;
            else rear = (rear+1)%capasity;
            array_1[rear]=x;
            size++;
        }

        int deQueue(){
            if (front == -1){
                cout << "Underflow!!" <<endl;
                return -1;
            }
            
            int x = array_1[front];

            if(front == rear) front = rear = -1;
            else front = (front+1)%capasity;
            size--;
            return x;
        }

        bool isEmpty(){
            return size==0;
        }

        bool isFull(){
            return size==capasity;
        }

        int Size(){
            return size;
        }

        int Front(){
            if(front == -1) return -1;
            else return array_1[front];
        }

        int Rear(){
            return rear==-1 ? -1:array_1[rear];
        }

        void print_queue(){
            cout << "Current Size : " << size<<endl;
            cout << "Full? : " << (isFull() ? "Yes" : "No")<<endl;
            cout << "Empty? : " << (isEmpty() ? "Yes" : "No")<<endl;
            cout << "Front Element: " << (front != -1 ? to_string(array_1[front]) : "-") << endl;
            cout << "Front Index : " << (front!=-1? front: 0 )<<endl;
            cout << "Rear Element: " << (rear != -1 ? to_string(array_1[rear]) : "-") << endl;
            cout << "Rear Index : " << (rear!=-1? rear:0)<<endl;
            cout << "Queue Elements : ";
            if (size > 0) {
                int i = front;
                if (front <= rear) while (i <= rear)  cout << array_1[i++] << " ";
                else {
                    while (i < capasity) cout << array_1[i++] << " ";
                    i = 0;
                    while (i <= rear) cout << array_1[i++] << " ";
                }
            }
            else cout<<"-";
            cout << endl;
        }

        ~Circular_Queue(){
            delete [] array_1;
        }
};

int main(){
    int  size_of_queue; cin>>size_of_queue;

    Circular_Queue q(size_of_queue);
    string s;
    while(cin>>s && s!="-1"){
        switch(s[0]){
            case 'E':
                int n;cin>>n;
                q.enQueue(n);
                q.print_queue();
                break;
            case 'D':
                q.deQueue();
                q.print_queue();
                break;
        }
    }

    return 0;
}