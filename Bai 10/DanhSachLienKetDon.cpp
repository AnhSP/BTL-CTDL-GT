#include<iostream>
#include<string>
using namespace std;
struct CanBo{ 
	string ma, hoDem, ten, chucVu;
	int phong;
	float heSoLuong;
	CanBo *next;
	friend ostream & operator <<(ostream &output, CanBo* a);
};
class DanhSachQuanLiNhanSu{
	private:
		CanBo* head;
		
		void addCanBoToList(CanBo* &head, CanBo* &tmp);
		CanBo* createCanBo();
		void insertAtIndex(CanBo* &head, CanBo* tmp, int index);
		void print();
	public:
		DanhSachQuanLiNhanSu(){
			this->head=NULL;
		}
		void createList();
		int size(CanBo *head);
		void insert();
		void printLuong();
		void printByHeSoLuong();
		void findByChucVu();
		void findByHeSoLuongAndPhongBan();
		void sortByTen();
};
void DanhSachQuanLiNhanSu::addCanBoToList(CanBo* &head, CanBo* &tmp){
	if(tmp==NULL){
		return;
		}
	if(head==NULL){
		head=tmp;
	}
	else{
		CanBo *last= head;
		while(last->next!=NULL){
			last= last->next;
		}
		last->next= tmp;
	}
}

CanBo* DanhSachQuanLiNhanSu::createCanBo(){
	CanBo *tmp= new CanBo(); 
	cout<<"Nhap ma: "; cin>> tmp->ma;
	if (tmp->ma.find_first_of("0123456789") == std::string::npos){ // Kiem tra ki tu dau tien
        cout << "Ma can bo khong hop le!\n";
       	delete tmp;
   		return NULL;
	}
	if(stoi(tmp->ma)<=0){
		delete tmp;
		return NULL;
	}
	cin.ignore();
	cout<<"Nhap ho dem: "; getline(cin, tmp->hoDem);
	cout<<"Nhap ten: "; getline(cin, tmp->ten);
	cout<<"Nhap so phong ban: "; cin>> tmp->phong;
	cin.ignore();
	cout<<"Nhap chuc vu: "; getline(cin, tmp->chucVu);
	for(char &x: tmp->chucVu){
		x = tolower(x);
	}
	cout<<"Nhap he so luong: "; cin>> tmp->heSoLuong;
	tmp->next= NULL;
	return tmp;
}

void DanhSachQuanLiNhanSu::insertAtIndex(CanBo* &head, CanBo* tmp, int index){
	int n= this->size(head); 
	if(index== n + 1){
       	addCanBoToList(head, tmp);
    }
	else if(index> 0 && index<= n){
        CanBo *middle= head;
        for(int i= 1; i< index-1; i++){
            middle= middle->next;
        }
        tmp->next= middle->next;
        middle->next= tmp;
    }
	else{
        cout << "Vi tri chen khong hop le!\n";
        delete tmp;
    }
}

void DanhSachQuanLiNhanSu::createList(){
	CanBo *x= NULL;
	cout<<"------Nhap danh sach------\n";
	do{
		x= createCanBo();
		addCanBoToList(head,x);
	}while(x!=NULL);
}

ostream & operator <<(ostream &output, CanBo* a){
	output<<endl;
	output<<"Ma can bo: "<< a->ma<<endl;
	output<<"Ho dem: "<< a->hoDem<<endl;
	output<<"Ho ten: "<< a->ten<<endl;
	output<<"Phong ban: "<< a->phong<<endl;
	output<<"Chuc vu: "<< a->chucVu<<endl;
	output<<"He so luong: "<< a->heSoLuong;
	output<<endl;
	return output;
}
int DanhSachQuanLiNhanSu::size(CanBo *head){
	int count=0;
	while(head!=NULL){
		count++;
		head= head->next; 
	}
	return count;
}

void DanhSachQuanLiNhanSu::insert(){
	int choice;
	cout<< "Ban co muon nhap vi tri khong? \n (1) Yes\n (2) No\n";
	cin>> choice;
	CanBo *tmp= createCanBo();
	if(tmp==NULL){
		return;
	}
	if (choice==1) {
    	int index;
    	cout<< "Nhap vi tri can them: "; cin >> index;
  		insertAtIndex(head, tmp, index);
   	} else if (choice == 2) {
        addCanBoToList(head, tmp);
   	}else {
        cout << "Ban nhap sai cau tra loi!";
        delete tmp;
    }	
}
void DanhSachQuanLiNhanSu::print(){
	CanBo* tmp= this->head;
	cout<<"---------------------------------------\n";
	while(tmp!=NULL){
		cout<< tmp<<endl;
		tmp=tmp->next;
	}
	cout<<"\n---------------------------------------\n";
}

void DanhSachQuanLiNhanSu::printLuong(){
	CanBo* tmp= this->head;
	string chucVU;
	int count=0;
	while(tmp!=NULL){
		if(tmp->chucVu.compare("nhan vien")==0){
			cout<<"Nhan vien "<<tmp->ten<<" co so luong la: "<<(int)tmp->heSoLuong*1350000<<"\n";
			count++;
		}
		tmp=tmp->next;
	}
	if(count== 0){
		cout<<"Khong co nhan vien nao trong danh sach!\n";
	}
}

void DanhSachQuanLiNhanSu::printByHeSoLuong(){
	CanBo* tmp= this->head;
	cout<<"---------------------------------------\n";
	while(tmp!=NULL){ // loc he so luong >= 4.4
		if(tmp->heSoLuong>=4.4){
			cout<< tmp;
		}
		tmp=tmp->next;
	}
	cout<<"\n---------------------------------------\n";
}

void DanhSachQuanLiNhanSu::findByChucVu(){
	int count=0;
	string chucVu;
	CanBo *tmp=this->head;
	cout<<"Nhap chuc vu can loc danh sach: "; cin.ignore(); getline(cin, chucVu);
	for(char &x: chucVu){ // chuyen chu hoa thanh chu thuong
		x = tolower(x);
	}
	while(tmp!=NULL){
		if(tmp->chucVu.compare(chucVu)==0){
			count++;
			cout<< tmp;
		}
		tmp= tmp->next;
	}
	if(count==0){
		cout<< "Khong co chuc vu nao nhu vay trong danh sach!\n";
	}
}

void DanhSachQuanLiNhanSu::findByHeSoLuongAndPhongBan(){
	CanBo *tmp=this->head;
	int phongBan, count=0;
	float heSoLuong;
	cout<<"Nhap chinh xac he so luong can loc danh sach: "; cin>>heSoLuong;
	cout<<"Nhap so phong ban: "; cin>> phongBan;
	while(tmp!=NULL){
		if(tmp->heSoLuong==heSoLuong && tmp->phong==phongBan){
			count++;
			cout<<tmp;
		}
		tmp=tmp->next;
	}
	if(count==0){
		cout<<"Khong co can bo nao trong danh sach co he so luong va phong ban nhu vay!\n";
	}
}

void DanhSachQuanLiNhanSu::sortByTen() {
    if (this->head == NULL || this->head->next == NULL) {
        return;
    }

    CanBo* sorted_head = NULL;
    while (head != NULL) {
        CanBo* current = head;
        head = head->next;

        if (sorted_head == NULL || current->ten < sorted_head->ten) {
            current->next = sorted_head;
            sorted_head = current;
        } else {
            CanBo* temp = sorted_head;
            while (temp->next != NULL && temp->next->ten < current->ten) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    
    cout<<"Danh sach da duoc sap xep theo dang nhu sau:\n";
    head = sorted_head;
    this->print();
}
