#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col, in;
    cin >> row >> col;

    vector<vector<int>> v1, v2, v3;

    for (int i = 0; i < row; i++) {
        vector<int> vv1;
        for (int k = 0; k < col; k++) {
            cin >> in;
            vv1.push_back(in);
        }
        v1.push_back(vv1);
    }

    for (int i = 0; i < row; i++) {
        vector<int> vv2;
        for (int k = 0; k < col; k++) {
            cin >> in;
            vv2.push_back(in);
        }
        v2.push_back(vv2);
    }

    for (int i = 0; i < row; i++) {
        vector<int> vv3;
        for (int k = 0; k < col; k++) {
            vv3.push_back(v1[i][k] + v2[i][k]);
        }
        v3.push_back(vv3);
    }

    for (auto elem : v3) {
        for (auto elem2 : elem) {
            cout << elem2 << " ";
        }
        cout << endl;
    }
}