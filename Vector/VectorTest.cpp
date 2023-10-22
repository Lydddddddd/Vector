// main.cpp

#include <iostream>
#include "Vector.cpp"
#include "Vector.h"

using namespace std;

int main() {
    try {
        Vector<int> v1(3);
        Vector<int> v2(3);
        cout << "Enter values for v1 (3 elements): ";
        cin >> v1;
        cout << "Enter values for v2 (3 elements): ";
        cin >> v2;

        Vector<int> sum = v1 + v2;
        cout << "v1 + v2 = " << sum << endl;

        if (v1 == v2) {
            cout << "v1 and v2 are equal." << endl;
        }
        else {
            cout << "v1 and v2 are not equal." <<endl;
        }

        Vector<int> v3(4);
        cout << "Enter values for v3 (4 elements): ";
        cin >> v3;

        Vector<int> sumInvalid;
        try {
            sumInvalid = v1 + v3; // 这会引发异常，因为维数不匹配
        }
        catch (const invalid_argument& e) {
            cerr << "Exception: " << e.what() << endl;
        }

        int value = v1[4]; // 这会引发异常，因为下标越界
    }
    catch (const std::out_of_range& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    system("pause");
    return 0;
}
