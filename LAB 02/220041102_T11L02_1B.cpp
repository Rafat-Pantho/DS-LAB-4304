#include <iostream>

#include <string.h>

using namespace std;

void rotate_clockwise(string &s){
    char temp = s[s.size()-1];
    for(int i = s.size()-1;i>0;i--) s[i] = s[i-1];
    s[0] = temp;
}

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    int size_1= s1.size(),size_2=s2.size();

    if(size_1==size_2){
        int i =0;
        for(; i< size_1;i++){
            if( s1 != s2 ){
                rotate_clockwise(s1);
            }
            else{
                if (i == 0) cout << "Yes. Rotation not needed."<<endl;
                else cout << "Yes. After "<< i << " clockwise rotations." <<endl;
                break;
            }
        }

        if(i >= size_1) cout << "No."<<endl;
    }

    else cout << "No." <<endl;

    return 0;
}
