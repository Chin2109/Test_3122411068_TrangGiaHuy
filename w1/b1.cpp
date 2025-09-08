using namespace std;
#include <iostream>

int findMax(int num1, int num2, int num3) {
    int max = 0;
    if ((num1 > num2) && (num1 > num3))
        max = num1;
    if ((num2 > num1) && (num2 > num3))
        max = num2;
    if ((num3 > num1) && (num3 > num2))
        max = num3;
    return max;
}

int main() {
    int a, b, c;
    cout << "Nhap 3 so nguyen: ";
    cin >> a >> b >> c;

    int result = findMax(a, b, c);
    cout << "So lon nhat la: " << result << endl;

    return 0;
}
