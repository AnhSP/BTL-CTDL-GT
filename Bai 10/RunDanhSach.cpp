#include<iostream>
#include"DanhSachLienKetDon.cpp"
using namespace std;
int main(){
	DanhSachQuanLiNhanSu a= DanhSachQuanLiNhanSu();
	int choice=0;
	while(true){
		cout<<"-------------Menu--------------\n";
		cout<<"(1) Tao danh sach\n";
		cout<<"(2) Them can bo vao danh sach\n";
		cout<<"(3) Tinh luong cho nhan vien\n";
		cout<<"(4) In tat ca can bo co he so luong lon hon hoac bang 4.4\n";
		cout<<"(5) Tim can bo theo Chuc vu\n";
		cout<<"(6) Tim can bo theo he so luong va phong ban\n";
		cout<<"(7) Sap xep danh sach can bo theo thu tu ten\n";
		cout<<"(0) Ket thuc tien trinh!\n";
		cout<<"-------------------------------\n";
		cout<<"Lua chon cua ban: ";
		cin>> choice;
		switch(choice){
			case 1:
				a.createList();
				break;
			case 2:
				a.insert();
				break;
			case 3:
				a.printLuong();
				break;
			case 4:
				a.printByHeSoLuong();
				break;
			case 5:
				a.findByChucVu();
				break;
			case 6:
				a.findByHeSoLuongAndPhongBan();
				break;
			case 7:
				a.sortByTen();
				break;
			case 0:
				return 0;
				break;
		}
	}
}
