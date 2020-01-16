#include<cstring>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>

using namespace std;

struct SinhVien
{
    char ho[20];
    char ten[10];
    int namsinh;
    char mssv[11];
    char lop[10];
    int diem[2];
};
struct NODEsv 
{
    SinhVien data;
    NODEsv* next;
};
struct LISTsv 
{
    NODEsv *head,*tail;
};
struct NODEk
{
    char tenkhoa[20];
    LISTsv data;
    NODEk* next;
};

struct LISTk
{
    NODEk *head,*tail;
};
void createlistsv(LISTsv &listsv)
{
    listsv.head=listsv.tail=NULL;
}
void createlistk(LISTk &listk)
{
    listk.head=listk.tail=NULL;
}

LISTsv listsv;
LISTk listk;
int find_IDadd (LISTsv listsv,char ID[])       //3-3 tim kiem theo mssv 
{
    for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
        if(strcmp(p->data.mssv,ID)==0)
            return 1;
        else
            return 0;    
}
SinhVien themsv (LISTsv listsv)
{
    SinhVien sv;
    cin.ignore();
    do
    {
        cout<<setw(20)<<" \n[Nhap ho]\n";
        cout<<setw(20)<<"{A-Z,a-z}{20}\n";
        
        cin.getline(sv.ho,20);
    }while((int)*sv.ho<65||(int)*sv.ho>122);
    do
    {
    cout<<setw(20)<<"[Nhap ten]\n";
    cout<<setw(20)<<"{A-Z,a-z}{10}\n";
    cin>>sv.ten;
    }while((int)*sv.ten<65||(int)*sv.ten>122);
    do
    {
    cout<<setw(20)<<"[Nhap nam sinh]\n";
    cout<<setw(20)<<"{1980-2018}\n";
    cin>>sv.namsinh;
    }while(sv.namsinh<1980||sv.namsinh>=2018);
    do
    {
    cout<<setw(20)<<"[Nhap mssv]\n";
    cout<<setw(20)<<"{A-Z,a-z,0-9}{10}\n";
    cin>>sv.mssv;
    }while(find_IDadd(listsv,sv.mssv)==1);
    //do
    //{
    cout<<setw(20)<<"[Nhap lop]\n";
    cout<<setw(20)<<"{A-Z,a-z,0-9}{7}\n";
    cin>>sv.lop;
    //}while();
    do
    {
    cout<<setw(20)<<"[Nhap diem toan]\n";
    cout<<setw(20)<<"{0-10}\n";
    cin>>sv.diem[0];
    }while(sv.diem[0]<0||sv.diem[0]>10);
    do
    {
    cout<<setw(20)<<"[Nhap diem van]\n";
    cout<<setw(20)<<"{0-10}\n";
    cin>>sv.diem[1];
    }while(sv.diem[1]<0||sv.diem[1]>10);
    //cout<<setw(20)<<"[Nhap diem anh]\n";
    //cout<<">> Dang so <<\n";
    //cin>>sv.diem[2];
    //tongsinhvien++;
    return sv;
}
void TAB()  //TAB hien thi danh sach
{
    cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
    cout<<"| "<<"STT"<<" |"<<setw(12)<<"Ho"<<setw(11)<<"|"<<"  Ten  "<<"|"<<"  Nam Sinh  "<<"|"<<"     MSSV     "<<"|"<<"  Lop   "<<"|"<<" Diem Toan "<<"|"<<" Diem Van "<<"|"<<" Diem TB "<<" |\n";
    cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
}
void hienthisv (SinhVien sv) 
{
    cout<<left;
        //cout<<"= "<<setw(4)<<i+1<<"|";
        cout<<left;
        cout<<setw(22)<<sv.ho<<"|";
        cout<<left;
        cout<<setw(7)<<sv.ten<<"|";
        cout<<internal;
        cout<<setw(10)<<sv.namsinh<<"  |";
        cout<<internal;
        cout<<setw(12)<<sv.mssv<<"  |";
        cout<<internal;
        cout<<setw(8)<<sv.lop<<"|";
        cout<<internal;
        cout<<setw(9)<<sv.diem[0]<<"  |";
        cout<<internal;
        cout<<setw(8)<<sv.diem[1]<<"  |";
        cout<<internal;
        cout<<setw(7)<<(float)((sv.diem[0]+sv.diem[1])/2)<<"   |";
        cout<<endl;
}
NODEsv* createnodesv(SinhVien sv)
{
    NODEsv* node =new NODEsv;
    if(node)
    {
        node->data=sv;
        node->next=NULL;
    }
    return node;
}
NODEk* createnodek(LISTsv &listsv)
{
    NODEk* node =new NODEk;
    if(node)
    {
        cout<<"Nhap ten khoa\n";
        cin.getline(node->tenkhoa,20);
        node->data=listsv;
        node->next=NULL;
    }
    return node;
}
void addheadsv(LISTsv &listsv,NODEsv* sv)//tail
{
    if(!listsv.head)
        listsv.head=listsv.tail=sv;
    else
    {
        listsv.tail->next=sv;
        listsv.tail=sv;
    }
}
void deltailsv(LISTsv &listsv)
{
    if(!listsv.head)
        cout<<"[>?<]Danh sach rong[>?<]\n";
    else if (listsv.head=listsv.tail)
    {
        delete listsv.head;
        listsv.head=listsv.tail=NULL;
    }
    else
    {
        NODEsv* tam =listsv.head;
        while(tam->next!=listsv.tail)
            tam=tam->next;
        delete listsv.tail;
        listsv.tail=tam;
    }
}
void addheadk(LISTk &listk,NODEk* k)
{
    if(!listk.head)
        listk.head=listk.tail=k;
    else
    {
        k->next=listk.head;
        listk.head=k;
    }
}
void themkhoa(LISTk &listk,LISTsv &listsv)  //dong goi listsv vao listkhoa
{  
    cout<<"Nhap so khoa muon them\n";
    int sokhoa;cin>>sokhoa;
    cin.ignore();
    for(int i=1;i<=sokhoa;i++)
    {
        addheadk(listk,createnodek(listsv));
    }
}
void xuatkhoa(LISTk listk)
{
    int dem=1;
    cout<<"Danh sach khoa\n";
    for(NODEk* p=listk.head;p!=NULL;p=p->next)
    {
        cout<<dem<<". "<<p->tenkhoa<<endl;
        dem++;
    }
}
void themsvlist(LISTsv &listsv)
{
    cout<<"Nhap so luong sinh vien muon them\n";
    int soluong;cin>>soluong;
    for(int i=0;i<soluong;i++)
    {
        cout<<"Nhap sinh vien thu "<<i+1<<endl;
        addheadsv(listsv,createnodesv(themsv(listsv)));
    }
}
void hienthidssv(LISTsv listsv)
{
    int dem=0;
    if(listsv.head!=NULL)
    {
        TAB();
        for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
        {
            cout<<left;
            dem++;
            cout<<"| "<<setw(4)<<dem<<"|";hienthisv(p->data);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
        }
        cout<<"[Tong sinh vien : "<<dem<<" ]\n";
    }
    else
        cout<<"[>?<]Danh sach rong[>?<]\n";
}
void menu_main ()   //menu mang hinh chinh
{
    cout<<"\n+----------------------Menu---------------------------+\n";
    cout<<"|                Quan Ly Sinh Vien                    |\n";
    cout<<"|    1. [Them thong tin sinh vien]                    |\n";               
    //cout<<". Xoa sinh vien\n";
    //cout<<". Sua sinh vien\n";
    cout<<"|    2. [Hien thi danh sach sinh vien]                |\n";
    cout<<"|    3. [Tim kiem thong tin sinh vien]                |\n";
    cout<<"|    4. [Sap xep danh sach sinh vien]                 |\n";
    cout<<"|    5. [Nhap file]                                   |\n";
    cout<<"|    6. [Xuat file]                                   |\n";
    cout<<"|                               9. [De thay doi khoa] |\n";
    cout<<"|                                       0. [de thoat] |\n";
    cout<<"+-----------------------------------------------------+\n";
}
void  menu_find ()  //tuy chon tim kiem
{
    cout<<"3-1. [Tim kiem theo ten]\n";
    cout<<"3-2. [Tim kiem theo nam sinh]\n";
    cout<<"3-3. [Tim kiem theo MSSV]\n";
    cout<<"3-4. [Tim kiem theo lop]\n";
    cout<<"3-5. [Tim kiem theo diem TB]\n";
}
void menu_sort ()   //tuy chon sap xep
{
    cout<<"4-1. [Sap xep theo ten]\n";
    cout<<"4-2. [Sap xep theo nam sinh]\n";
    cout<<"4-3. [Sap xep theo MSSV]\n";
    cout<<"4-4. [Sap xep theo lop]\n";
    cout<<"4-5. [Sap xep theo diem TB]\n";
}
int find_name (LISTsv listsv,char ten[])    //3-1 tim kiem theo ten
{
    int dem=0;
    int tam=0;
    for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
    {
        dem++;
        if(strcmp(p->data.ten,ten)==0)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<dem<<"|";hienthisv(p->data);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_bird (LISTsv listsv,int namsinh)   //3-2 tim kiem theo nam sinh
{
    int tam=0;
    int dem=0;
    for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
    {
        dem++;
        if(p->data.namsinh==namsinh)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<dem<<"|";hienthisv(p->data);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_ID (LISTsv listsv,char ID[])       //3-3 tim kiem theo mssv 
{
    int tam=0;
    int dem=0;
    for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
    {
        dem++;
        if(strcmp(p->data.mssv,ID)==0)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<dem<<"|";hienthisv(p->data);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    }
    if(tam>0)
        return 1;
    else
        return 0;    
}
int find_class (LISTsv listsv,char lop[])   //3-4 tim kiem theo lop
{
    int tam=0;
    int dem=0;
    for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
    {
        if(strcmp(p->data.lop,lop)==0)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<dem<<"|";hienthisv(p->data);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_point (LISTsv listsv,int diem)    //3-5 tim kiem theo diem TB
{
    int tam=0;
    int dem=0;
    for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
    {
        dem++;
        if(((p->data.diem[0]+p->data.diem[1])/2)==diem)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<dem<<"|";hienthisv(p->data);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    }
    if(tam>0)
        return 1;
    else
        return 0;
}
void edit_sv (LISTsv &listsv,int n)  //ham sua sinh vien
{
    NODEsv* tam=listsv.head;
    for(int i=1;i<n;i++)
    {
        tam=tam->next;
    }
    tam->data=themsv(listsv);
    cout<<"[>|<]Sua Thanh Cong[>|<]\n";
}
void removehead(LISTsv &listsv)
{
   if (listsv.head == listsv.tail)
   {
      delete listsv.head;
      listsv.head = listsv.tail = NULL;
   }
   else
   {
      NODEsv* temp = listsv.head;
      listsv.head = listsv.head->next;
      delete temp;
   }
}
void removeafter(LISTsv &listsv, NODEsv *sv)
{

    NODEsv* temp = sv->next;
    if (temp)
        sv->next = temp->next;
    delete temp;
    NODEsv* tam=listsv.head;
    while(tam->next!=NULL)
        tam=tam->next;
    listsv.tail=tam;
}
void del_sv (LISTsv &listsv,int n)   //ham xoa sinh vien
{
    if(n==1)
        removehead(listsv);
    else if (n==2)
        removeafter(listsv,listsv.head);
    else
    {
        NODEsv* tam=listsv.head;
        for(int i=2;i<n;i++)
            tam=tam->next;
        removeafter(listsv,tam);
    }
    cout<<"[>|<]Xoa Thanh Cong[>|<]\n";   
}
void Timthay(LISTsv &listsv)  //kiem tra tim thay
{   
                cout<<"[>!<]Da Tim Thay[>!<]\n";
                cout<<"[Nhap 1 : de sua sv]\n";
                cout<<"[Nhap 2 : de xoa sv]\n";
                cout<<"[Nhap 0 : de quay lai]\n";
                int q;cin>>q;
                if(q==1)
                {
                    cout<<"[Chon STT sv muon sua]\n";
                    int p;cin>>p;
                        edit_sv(listsv,p);
                }
                else if (q==2)
                {
                    cout<<"[Chon STT sv muon xoa]\n";
                    int p;cin>>p;
                        del_sv(listsv,p);
                }
}
void Khongtimthay() //kiem tra khong tim thay
{
    int tam;
    cout<<"[>?<]Khong Tim Thay[>?<]\n";
    cout<<"[Nhan : 1 de tiep tuc]\n";
    cout<<"[Nhan : 2 de thoat]\n";
    cin>>tam;
    if(tam==1)
        cout<<endl;
    else
        exit(0);
}
void choose_find (LISTsv &listsv) //menu chon tim kiem
{
    cout<<"Chon chuc nang : ";
    int chonf;
    cin>>chonf;
    switch (chonf)
    {
        case 1:
        {
            cout<<"3-1. [Tim kiem theo ten]\n";
            cout<<"Nhap ten sinh vien can tim \n";
            char ten[10];cin>>ten;
            TAB();
            if(find_name(listsv,ten)==1)
                Timthay(listsv);
            else
                Khongtimthay();
        break;
        }
        case 2:
        {
            cout<<"3-2. [Tim kiem theo nam sinh]\n";
            cout<<"Nhap nam sinh sinh vien can tim \n";
            int namsinh;cin>>namsinh;
            TAB();
            if(find_bird(listsv,namsinh)==1)
                Timthay(listsv);
            else
                Khongtimthay();
            break;
        }
        case 3:
        {
            cout<<"3-3. [Tim kiem theo MSSV]\n";
            cout<<"Nhap mssv sinh vien can tim \n";
            char mssv[11];cin>>mssv;
            TAB();
            if(find_ID(listsv,mssv)==1)
                Timthay(listsv);
            else
                Khongtimthay();
        break;
        }
        case 4:
        {
            cout<<"3-4. [Tim kiem theo lop]\n";
            cout<<"Nhap lop sinh vien can tim \n";
            char lop[7];cin>>lop;
            TAB();
            if(find_class(listsv,lop)==1)
                Timthay(listsv);
            else
                Khongtimthay();
            break;
        }
        case 5:
        {
            cout<<"3-5. [Tim kiem theo diem TB]\n";
            cout<<"Nhap diem TB sinh vien can tim\n";
            float diem;cin>>diem;
            TAB();
            if(find_point(listsv,diem)==1)
                Timthay(listsv);
            else
                Khongtimthay();
            break;
        }
    }
}
void sort_name (LISTsv &listsv)  //4-1 ham sap xep theo ten
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(strcmp(p1->data.ten,p2->data.ten)>0)
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(strcmp(p1->data.ten,p2->data.ten)<0)
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_bird (LISTsv &listsv)  //4-2 ham sap xep theo nam sinh
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
                if(p1->data.namsinh>p2->data.namsinh)
                {
                    SinhVien k=p1->data;
                    p1->data=p2->data;
                    p2->data=k;
                }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
                if(p1->data.namsinh<p2->data.namsinh)
                {
                    SinhVien k=p1->data;
                    p1->data=p2->data;
                    p2->data=k;
                }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_ID (LISTsv &listsv)    //4-3 ham sap xep theo mssv
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(strcmp(p1->data.mssv,p2->data.mssv)>0)
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(strcmp(p1->data.mssv,p2->data.mssv)<0)
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_class (LISTsv &listsv) //4-4 ham sap xep theo lop
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(strcmp(p1->data.lop,p2->data.lop)>0)
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(NODEsv* p1=listsv.head;p1->next!=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(strcmp(p1->data.lop,p2->data.lop)<0)
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_point (LISTsv &listsv)  //4-5 ham sap xep theo nam sinh
{
    cout<<"Nhap 1 : 0-10\n";
    cout<<"Nhap 2 : 10-0\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(NODEsv* p1=listsv.head;p1->next=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(((p1->data.diem[0]+p1->data.diem[1])/2)>((p2->data.diem[0]+p2->data.diem[1])/2))
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(NODEsv* p1=listsv.head;p1->next=NULL;p1=p1->next)
        {
            for(NODEsv* p2=listsv.head->next;p2!=NULL;p2=p2->next)
            {
            if(((p1->data.diem[0]+p1->data.diem[1])/2)<((p2->data.diem[0]+p2->data.diem[1])/2))
            {
                SinhVien k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void choose_sort (LISTsv &listsv) //menu chon sap xep
{
    cout<<"Chon chuc nang : ";
    int chons;
    cin>>chons;
    switch (chons)
    {
        case 1:
        {
            cout<<"4-1. [Sap xep theo ten]\n";
            sort_name(listsv);
            break;
        }
        case 2:
        {
            cout<<"4-2. [Sap xep theo nam sinh]\n";
            sort_bird(listsv);
            break;
        }
        case 3:
        {
            cout<<"4-3. [Sap xep theo MSSV]\n";
            sort_ID(listsv);
            break;
        }
        case 4:
        {
            cout<<"4-4. [Sap xep theo lop]\n";
            sort_class(listsv);
            break;
        }
        case 5:
        {
            cout<<"4-5. [Sap xep theo diem TB]\n";
            sort_point(listsv);
        }
    }
}
void nhapfile(LISTsv &listsv)
{
    //char* tenfile;
    //cout<<"Nhap ten file txt muon nhap\n";
    //cin>>tenfile;
    ifstream  filei("Dssinhvien.txt");
    if(filei.fail())
        cout<<"File khong ton tai\n";
    else
    {   
        int tam1;
        filei>>tam1;
        for(int i=0;i<tam1;i++)
        {
            SinhVien tam;
            filei.getline(tam.ho,20);//xuong dong
            filei.getline(tam.ho,20);
            filei.getline(tam.ten,10);
            filei>>tam.namsinh;
            filei.getline(tam.mssv,11);
            filei.getline(tam.mssv,11);
            filei.getline(tam.lop,10);
            
            filei>>tam.diem[0];
            filei>>tam.diem[1];
            addheadsv(listsv,createnodesv(tam));
        }
        cout<<"Thanh cong\n";
    }
    filei.close();
}
void xuatfile(LISTsv listsv)
{
    //char* tenfile;
    //cout<<"Nhap ten file txt muon xuat\n";
    //cin>>*tenfile;
    int tongsv=0;
    NODEsv* tam=listsv.head;
    while(tam!=NULL)
    {
        tam=tam->next;
        tongsv++;
    }
    ofstream fileo("Dssinhvien.txt");
    if(fileo.fail())
        cout<<"Tao file that bai\n";
    else
    {
        fileo<<tongsv;
        for(NODEsv* p=listsv.head;p!=NULL;p=p->next)
        {
            fileo<<endl<<p->data.ho<<endl;
            fileo<<p->data.ten<<endl;
            fileo<<p->data.namsinh<<endl;
            fileo<<p->data.mssv<<endl;
            fileo<<p->data.lop<<endl;
            fileo<<p->data.diem[0]<<endl;
            fileo<<p->data.diem[1];
        }
        cout<<"Tao file thanh cong\n";
    }
    fileo.close();
}
NODEk* chonkhoa(LISTk &listk)
{
   cout<<"Nhap ma Khoa muon quan ly\n";
    int makhoa;cin>>makhoa;
    NODEk* tam=listk.head;
    for(int i=0;i<makhoa-1;i++)
    {
        tam=tam->next;
    }
    return tam;
}
void choose_main (NODEk* nodek) //menu chon main
{  
    menu_main ();
    cout<<"[Quang ly Khoa : \n"<<"["<<nodek->tenkhoa<<"]"<<endl;
    cout<<"Chon chuc nang \n";
    //cout<<"[Khoa : "<<dsk[makhoa].tenkhoa<<"]\n";
    cout<<"[Menu]> ";
    int chon;
    cin>>chon;
    while(chon>=0&&chon<7||chon==9)
    {
        switch(chon)
        {
            case 1:
            {
                cout<<"1. [Them sinh vien]\n";
                cout<<"[Khoa : "<<nodek->tenkhoa<<"]\n";
                cout<<"[Menu]>[Add]> \n";
                themsvlist(nodek->data);
                choose_main (nodek);
                break;
            }
            case 2:
            {
                cout<<"2. [Hien thi danh sach sinh vien]\n";
                cout<<"[Khoa : "<<nodek->tenkhoa<<"]\n";
                cout<<"[Menu]>[Show]> \n";
                hienthidssv(nodek->data);
                cout<<"Nhan (y) de quay lai\n";
                char d;cin>>d;
                choose_main (nodek);
                break;
            }
            case 3:
            {
                cout<<"3. [Tim kiem sinh vien]\n";
                cout<<"[Khoa : "<<nodek->tenkhoa<<"]\n";
                cout<<"[Menu]>[Find]> \n";
                if(nodek->data.head!=0)
                {
                    menu_find ();
                    choose_find(nodek->data);
                    choose_main (nodek);
                }
                else
                {
                    cout<<"[>?<]Danh sach rong[>?<]\n";
                    cout<<"Nhan (y) de quay lai\n";
                    char tam;cin>>tam;
                    choose_main(nodek);
                }
                break;
            }
            case 4:
            {
                cout<<"4. [Sap xep sinh vien]\n";
                cout<<"[Khoa : "<<nodek->tenkhoa<<"]\n";
                cout<<"[Menu]>[Sort]> \n";
                if(nodek->data.head!=0)
                {
                    menu_sort ();
                    choose_sort (nodek->data);
                    choose_main (nodek);
                }
                else
                {
                    cout<<"[>?<]Danh sach rong[>?<]\n";
                    cout<<"Nhan (y) de quay lai\n";
                    char tam;cin>>tam;
                    choose_main(nodek);
                }
                break;                
            }
            case 5:
            {
                nhapfile(nodek->data);
                cout<<"Nhan (y) de quay lai\n";
                char tam;cin>>tam;
                choose_main(nodek);
                break;
            }
            case 6:
            {
                xuatfile(nodek->data);
                cout<<"Nhan (y) de quay lai\n";
                char tam;cin>>tam;
                choose_main(nodek);
                break;
            }
            case 9:
            {
                xuatkhoa(listk);
                choose_main(chonkhoa(listk));
                break;
            }
            case 0:
            {
                exit(0);
            }
        }
    }
    menu_main ();
}
int main()
{
    createlistsv(listsv);
    createlistk(listk);
    themkhoa(listk,listsv);
    xuatkhoa(listk);
    choose_main(chonkhoa(listk));
    return 0;
}