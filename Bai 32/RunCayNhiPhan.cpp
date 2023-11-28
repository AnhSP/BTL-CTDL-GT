#include<iostream>
#include"CayNhiPhan.cpp"
using namespace std;
int main() {
    int n, x;
    cout<<"Kiem tra dau thu hai co the thang hay khong.\n";
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap x: ";
    cin >> x;
    BinaryTree binaryTree(n);
    if (binaryTree.canSecondPlayerWin(x)) {
        cout<< "Dau thu hai co the thang";
    } else {
        cout<< "Dau thu hai khong the thang";
    }
    return 0;
}
