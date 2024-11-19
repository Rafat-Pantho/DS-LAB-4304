#include <iostream>
#include <vector>

using namespace std;

class HashTable{
    private:
        vector<int> table;
        int tabSize,elem;

        int hash(int x){
            return x%tabSize;
        }
        int hash2(int x){
            return 7 - (x%7);
        }
    public:
        HashTable(int a):tabSize(a),elem(0){
            table.resize(a,-1);
        }
        void insert(int x,int choice){
            int index = hash(x);
            int attempts = 0;
            bool flag = false;
            while (attempts<6){
                int newIndex;
                if(table[index]==-1){
                    table[index]=x;
                    elem++;
                    cout<<"Insertd: index- "<<index<< " (L.F="<< static_cast<double>(elem)/tabSize<<")"<<endl;
                    flag = true;
                    break;
                }
                else{
                    cout<<"Collision:Index- "<<index<<endl;
                    if(choice == 1)newIndex = (index+attempts+1)%tabSize;
                    else if (choice ==2)newIndex = (index+(attempts+1)*(attempts+1))%tabSize;
                    else newIndex = (index + (attempts+1)*hash2(x))%tabSize;
                    index = newIndex;
                    attempts++;
                }
            }
            if(!flag)cout<<"Input Abandoned"<<endl;
        }
};

int main(){
    int choice, size, query_cnt;
    cin>>choice>>size>>query_cnt;
    HashTable ht(size);
    for(int i=0;i<query_cnt;i++){
        int x;
        cin>>x;
        ht.insert(x,choice);
    }

    return 0;
}