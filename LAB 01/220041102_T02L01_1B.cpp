#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int lines;
    cin >> lines;
    cin.ignore();

    stack<string> tags_storing;
    string line, tag;
    bool errorFound = false;
    int errorLine = 0;

    for (int i = 1; i <= lines; ++i) {
        getline(cin, line);
        size_t pos = 0;
        while (pos < line.size()) {
            size_t start = line.find('<', pos);
            if (start == string::npos) break;
            size_t end = line.find('>', start + 1);
            if (end == string::npos) break;

            tag = line.substr(start, end - start + 1);
            pos = end + 1;

            if (tag[1] != '/') tags_storing.push(tag);
            else { 
                if (!tags_storing.empty() && tags_storing.top() == tag.replace(1, 1, ""))  tags_storing.pop();
                else {
                    errorFound = true;
                    errorLine = i;
                    break;
                }
            }
        }
        if (errorFound) break;
    }

    if (errorFound) cout << "Error at Line " << errorLine;
    else if (!tags_storing.empty()) cout << "Error at Line " << lines;
    else cout << "No error";

    return 0;
}
