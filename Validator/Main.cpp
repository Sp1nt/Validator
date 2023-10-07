#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int countError = 0;
    string file;

    cout << "Input the path to the HTML file: ";
    cin >> file;

    ifstream in(file);

    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            bool f = false;

            for (int i = 0; i < line.length(); i++) {
                char c = line[i];
                if (c == '<') {
                    f = true;
                }
                else if (c == '>') {
                    if (!f) {
                        countError++;
                    }
                    f = false;
                }
            }

            if (f) {
                countError++;
            }
        }
    }
    else {
        cout << "Failed to open file." << endl;
    }

    in.close();

    cout << "Errors: " << countError << endl;

    return 0;
}