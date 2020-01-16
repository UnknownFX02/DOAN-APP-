#include<cstring>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>

using namespace std;

const int MAXSV=100;
const int MAXK=10;
int tongkhoa=0;
int tongsinhvien=0;
struct SinhVien //tao kieu du lieu sinh vien
{
    //string ho[20];
    char ho[20];
    char ten[10];
    int namsinh;
    char mssv[11];
    char lop[10];
    int diem[2];
};
struct Khoa
{
    char tenkhoa[20];
    SinhVien ds[MAXSV];
    int tongsvkhoa;
};
Khoa Dskhoa[MAXK];    //tao ds khoa gom ds sinh vien

void themkhoa (Khoa dsk[])
{
    cout<<">>[Nhap so luong khoa muon them]<<\n";
    int sokhoa;cin>>sokhoa;
    cin.ignore();
    for(int i=0;i<sokhoa;i++)
    {
        cout<<"Nhap ten khoa :"<<i+1<<endl;
        cin.getline(dsk[i].tenkhoa,20);
        tongkhoa++;
    }
    cout<<endl;
}
void xuatkhoa (Khoa dsk[])
{
    for(int i=0;i<tongkhoa;i++)
        cout<<i+1<<" ."<<dsk[i].tenkhoa<<endl;
    cout<<"\nTong So Khoa : "<<tongkhoa<<endl;
}
SinhVien themsv ()  //ham them 1 sinh vien
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
    //do
    //{
    cout<<setw(20)<<"[Nhap mssv]\n";
    cout<<setw(20)<<"{A-Z,a-z,0-9}{10}\n";
    cin>>sv.mssv;
    //}while();
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
    tongsinhvien++;
    return sv;
}

void themsvk (Khoa dsk[],int makhoa)
{
    cout<<"nhap so luong sinh vien muon them\n";
    int sosinhvien;cin>>sosinhvien;
    for(int i=0;i<sosinhvien;i++)
    {
        cout<<"[Thong Tin Sinh Vien Thu : "<<i+1;
        dsk[makhoa].ds[dsk[makhoa].tongsvkhoa]=themsv();
        dsk[makhoa].tongsvkhoa++;
    }
}
void TAB()  //TAB hien thi danh sach
{
    cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
    cout<<"| "<<"STT"<<" |"<<setw(12)<<"Ho"<<setw(11)<<"|"<<"  Ten  "<<"|"<<"  Nam Sinh  "<<"|"<<"     MSSV     "<<"|"<<"  Lop   "<<"|"<<" Diem Toan "<<"|"<<" Diem Van "<<"|"<<" Diem TB "<<" |\n";
    cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
}
void hienthisv (SinhVien sv)    //ham hien thi 1 sinh vien  
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
void hienthiDSsv (Khoa dsk[],int makhoa)
{
    if(dsk[makhoa].tongsvkhoa!=0)
    {
    TAB();
    for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
    {
        cout<<left;
        cout<<"| "<<setw(4)<<i+1<<"|";hienthisv(dsk[makhoa].ds[i]);
        cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
    }
    cout<<"[Tong sinh vien : "<<dsk[makhoa].tongsvkhoa<<" ]"<<endl;
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
int find_name (Khoa dsk[],int makhoa,char ten[])    //3-1 tim kiem theo ten
{
    int tam=0;
    for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
        if(strcmp(dsk[makhoa].ds[i].ten,ten)==0)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<i+1<<"|";hienthisv(dsk[makhoa].ds[i]);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_bird (Khoa dsk[],int makhoa,int namsinh)   //3-2 tim kiem theo nam sinh
{
    int tam=0;
    for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
        if(dsk[makhoa].ds[i].namsinh==namsinh)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<i+1<<"|";hienthisv(dsk[makhoa].ds[i]);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_ID (Khoa dsk[],int makhoa,char ID[])       //3-3 tim kiem theo mssv 
{
    int tam=0;
    for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
        if(strcmp(dsk[makhoa].ds[i].mssv,ID)==0)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<i+1<<"|";hienthisv(dsk[makhoa].ds[i]);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    if(tam>0)
        return 1;
    else
        return 0;    
}
int find_class (Khoa dsk[],int makhoa,char lop[])   //3-4 tim kiem theo lop
{
    int tam=0;
    for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
        if(strcmp(dsk[makhoa].ds[i].lop,lop)==0)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<i+1<<"|";hienthisv(dsk[makhoa].ds[i]);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_point (Khoa dsk[],int makhoa,int diem)    //3-5 tim kiem theo diem TB
{
    int tam=0;
    for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
    if(((dsk[makhoa].ds[i].diem[0]+dsk[makhoa].ds[i].diem[1])/2)==diem)
    {
        cout<<left;
        cout<<"| "<<setw(4)<<i+1<<"|";hienthisv(dsk[makhoa].ds[i]);
        cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
        tam++;
    }
    if(tam>0)
        return 1;
    else
        return 0;
}
void edit_sv (Khoa dsk[],int makhoa,int i)  //ham sua sinh vien
{
    dsk[makhoa].ds[i]=themsv();
    cout<<"[>|<]Sua Thanh Cong[>|<]\n";
    tongsinhvien--;
}
void del_sv (Khoa dsk[],int makhoa,int i)   //ham xoa sinh vien
{
    dsk[makhoa].ds[i]=dsk[makhoa].ds[dsk[makhoa].tongsvkhoa-1];
    dsk[makhoa].tongsvkhoa--;
    cout<<"[>|<]Xoa Thanh Cong[>|<]\n";   
}
void Timthay(Khoa dsk[],int makhoa)  //kiem tra tim thay
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
                    if(p<=dsk[makhoa].tongsvkhoa)
                        edit_sv(dsk,makhoa,p-1);
                    else
                        {
                            cout<<"[>?<]Nhap sai STT[>?<]";
                        }
                }
                else if (q==2)
                {
                    cout<<"[Chon STT sv muon xoa]\n";
                    int p;cin>>p;
                    if(p<=dsk[makhoa].tongsvkhoa)
                        del_sv(dsk,makhoa,p-1);
                    else
                        {
                            cout<<"[>?<]Nhap sai STT[>?<]";
                        }
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
void choose_find (Khoa dsk[],int makhoa) //menu chon tim kiem
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
            if(find_name(dsk,makhoa,ten)==1)
                Timthay(dsk,makhoa);
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
            if(find_bird(dsk,makhoa,namsinh)==1)
                Timthay(dsk,makhoa);
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
            if(find_ID(dsk,makhoa,mssv)==1)
                Timthay(dsk,makhoa);
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
            if(find_class(dsk,makhoa,lop)==1)
                Timthay(dsk,makhoa);
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
            if(find_point(dsk,makhoa,diem)==1)
                Timthay(dsk,makhoa);
            else
                Khongtimthay();
            break;
        }
    }
}
void sort_name (Khoa dsk[],int makhoa)  //4-1 ham sap xep theo ten
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(strcmp(dsk[makhoa].ds[i].ten,dsk[makhoa].ds[j].ten)>0)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(strcmp(dsk[makhoa].ds[i].ten,dsk[makhoa].ds[j].ten)<0)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_bird (Khoa dsk[],int makhoa)  //4-2 ham sap xep theo nam sinh
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(dsk[makhoa].ds[i].namsinh>dsk[makhoa].ds[j].namsinh)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(dsk[makhoa].ds[i].namsinh<dsk[makhoa].ds[j].namsinh)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_ID (Khoa dsk[],int makhoa)    //4-3 ham sap xep theo mssv
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(strcmp(dsk[makhoa].ds[i].mssv,dsk[makhoa].ds[j].mssv)>0)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(strcmp(dsk[makhoa].ds[i].mssv,dsk[makhoa].ds[j].mssv)<0)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_class (Khoa dsk[],int makhoa) //4-4 ham sap xep theo lop
{
    cout<<"Nhap 1 : A-Z\n";
    cout<<"Nhap 2 : Z-A\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(strcmp(dsk[makhoa].ds[i].lop,dsk[makhoa].ds[j].lop)>0)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if(strcmp(dsk[makhoa].ds[i].lop,dsk[makhoa].ds[j].lop)<0)
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void sort_point (Khoa dsk[],int makhoa)  //4-5 ham sap xep theo nam sinh
{
    cout<<"Nhap 1 : 0-10\n";
    cout<<"Nhap 2 : 10-0\n";
    cout<<"Nhap 0 : quay lai\n";
    int tam;cin>>tam;
    if(tam==1)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if((float)(((dsk[makhoa].ds[i].diem[0]+dsk[makhoa].ds[i].diem[1])/2)>((dsk[makhoa].ds[j].diem[0]+dsk[makhoa].ds[j].diem[1])/2)))
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else if(tam==2)
    {
        for(int i=0;i<dsk[makhoa].tongsvkhoa-1;i++)
        {
            for(int j=i+1;j<dsk[makhoa].tongsvkhoa;j++)
            {
            if((float)(((dsk[makhoa].ds[i].diem[0]+dsk[makhoa].ds[i].diem[1])/2)<((dsk[makhoa].ds[j].diem[0]+dsk[makhoa].ds[j].diem[1])/2)))
            {
                SinhVien k=dsk[makhoa].ds[i];
                dsk[makhoa].ds[i]=dsk[makhoa].ds[j];
                dsk[makhoa].ds[j]=k;
            }
            }
        }
        cout<<"[>!<]Sap xep thanh cong[>!<]";
    }
    else
        cout<<"[>?<]Sap xep khong thanh cong[>?<]"; 
}
void choose_sort (Khoa dsk[],int makhoa) //menu chon sap xep
{
    cout<<"Chon chuc nang : ";
    int chons;
    cin>>chons;
    switch (chons)
    {
        case 1:
        {
            cout<<"4-1. [Sap xep theo ten]\n";
            sort_name(dsk,makhoa);
            break;
        }
        case 2:
        {
            cout<<"4-2. [Sap xep theo nam sinh]\n";
            sort_bird(dsk,makhoa);
            break;
        }
        case 3:
        {
            cout<<"4-3. [Sap xep theo MSSV]\n";
            sort_ID(dsk,makhoa);
            break;
        }
        case 4:
        {
            cout<<"4-4. [Sap xep theo lop]\n";
            sort_class(dsk,makhoa);
            break;
        }
        case 5:
        {
            cout<<"4-5. [Sap xep theo diem TB]\n";
            sort_point(dsk,makhoa);
        }
    }
}
void nhapfile(Khoa dsk[],int makhoa)
{
    //char* tenfile;
    //cout<<"Nhap ten file txt muon nhap\n";
    //cin>>tenfile;
    ifstream  filei("Dssinhvien.txt");
    if(filei.fail())
        cout<<"File khong ton tai\n";
    else
    {
        //filei.getline(dsk[makhoa].tenkhoa,20);
        filei>>dsk[makhoa].tongsvkhoa;
        for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
        {
            filei.getline(dsk[makhoa].ds[i].ho,20);//xuong dong
            filei.getline(dsk[makhoa].ds[i].ho,20);
            filei.getline(dsk[makhoa].ds[i].ten,10);
            filei>>dsk[makhoa].ds[i].namsinh;
            filei.getline(dsk[makhoa].ds[i].mssv,11);
            filei.getline(dsk[makhoa].ds[i].mssv,11);
            filei.getline(dsk[makhoa].ds[i].lop,10);
            
            filei>>dsk[makhoa].ds[i].diem[0];
            filei>>dsk[makhoa].ds[i].diem[1];
        }
        cout<<"Thanh cong\n";
    }
    filei.close();
}
void xuatfile(Khoa dsk[],int makhoa)
{
    //char* tenfile;
    //cout<<"Nhap ten file txt muon xuat\n";
    //cin>>*tenfile;
    ofstream fileo("Dssinhvien.txt");
    if(fileo.fail())
        cout<<"Tao file that bai\n";
    else
    {
        //fileo<<dsk[makhoa-1].tenkhoa<<endl;
        fileo<<dsk[makhoa].tongsvkhoa<<endl;
        for(int i=0;i<dsk[makhoa].tongsvkhoa;i++)
        {
            fileo<<dsk[makhoa].ds[i].ho<<endl;
            fileo<<dsk[makhoa].ds[i].ten<<endl;
            fileo<<dsk[makhoa].ds[i].namsinh<<endl;
            fileo<<dsk[makhoa].ds[i].mssv<<endl;
            fileo<<dsk[makhoa].ds[i].lop<<endl;
            fileo<<dsk[makhoa].ds[i].diem[0]<<endl;
            fileo<<dsk[makhoa].ds[i].diem[1];
            fileo<<endl;
        }
        cout<<"Tao file thanh cong\n";
    }
    fileo.close();
}

void choose_main (Khoa dsk[],int makhoa) //menu chon main
{  
    menu_main ();
    cout<<"[Quang ly Khoa : \n"<<"["<<dsk[makhoa].tenkhoa<<"]"<<endl;
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
                cout<<"[Khoa : "<<dsk[makhoa].tenkhoa<<"]\n";
                cout<<"[Menu]>[Add]> \n";
                themsvk(dsk,makhoa);
                choose_main (dsk,makhoa);
                break;
            }
            case 2:
            {
                cout<<"2. [Hien thi danh sach sinh vien]\n";
                cout<<"[Khoa : "<<dsk[makhoa].tenkhoa<<"]\n";
                cout<<"[Menu]>[Show]> \n";
                hienthiDSsv (dsk,makhoa);
                cout<<"Nhan (y) de quay lai\n";
                char d;cin>>d;
                choose_main (dsk,makhoa);
                break;
            }
            case 3:
            {
                cout<<"3. [Tim kiem sinh vien]\n";
                cout<<"[Khoa : "<<dsk[makhoa].tenkhoa<<"]\n";
                cout<<"[Menu]>[Find]> \n";
                if(tongsinhvien!=0)
                {
                    menu_find ();
                    choose_find(dsk,makhoa);
                    choose_main (dsk,makhoa);
                }
                else
                {
                    cout<<"[>?<]Danh sach rong[>?<]\n";
                    cout<<"Nhan (y) de quay lai\n";
                    char tam;cin>>tam;
                    choose_main(dsk,makhoa);
                }
                break;
            }
            case 4:
            {
                cout<<"4. [Sap xep sinh vien]\n";
                cout<<"[Khoa : "<<dsk[makhoa].tenkhoa<<"]\n";
                cout<<"[Menu]>[Sort]> \n";
                if(tongsinhvien!=0)
                {
                    menu_sort ();
                    choose_sort (dsk,makhoa);
                    choose_main (dsk,makhoa);
                }
                else
                {
                    cout<<"[>?<]Danh sach rong[>?<]\n";
                    cout<<"Nhan (y) de quay lai\n";
                    char tam;cin>>tam;
                    choose_main(dsk,makhoa);
                }
                break;                
            }
            case 5:
            {
                nhapfile(Dskhoa,makhoa);
                cout<<"Nhan (y) de quay lai\n";
                char tam;cin>>tam;
                choose_main(dsk,makhoa);
                break;
            }
            case 6:
            {
                xuatfile(Dskhoa,makhoa);
                cout<<"Nhan (y) de quay lai\n";
                char tam;cin>>tam;
                choose_main(dsk,makhoa);
                break;
            }
            case 9:
            {
                xuatkhoa(Dskhoa);
                cout<<"Nhap ma khoa muon quan ly\n";
                int makhoa1;cin>>makhoa1;
                choose_main (Dskhoa,makhoa1);
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
    themkhoa(Dskhoa);
    xuatkhoa(Dskhoa);
    cout<<"Nhap ma khoa muon quan ly\n";
    int makhoa;cin>>makhoa;
    makhoa=makhoa-1;
    choose_main (Dskhoa,makhoa);
    return 0;
}