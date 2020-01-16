#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<iomanip>
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
void menu_main ()   //menu mang hinh chinh
{
    cout<<"\n+----------------------Menu---------------------------+\n";
    cout<<"|                Quan Ly Sinh Vien                    |\n";
    cout<<"|    1. [Them thong tin sinh vien]                    |\n";               
    //cout<<". Xoa sinh vien\n";
    //cout<<". Sua sinh vien\n";
    cout<<"|    2. [Hien thi danh sach sinh vien]                |\n";
    cout<<"|    3. [Tim kiem thong tin sinh vien]                |\n";
    cout<<"|    4. [Sua thong tin sinh vien]                     |\n";
    cout<<"|    5. [Xoa thong tin sinh vien]                     |\n";
    cout<<"|    6. [Nhap file]                                   |\n";
    cout<<"|    7. [Xuat file]                                   |\n";
    cout<<"|                                       0. [de thoat] |\n";
    cout<<"+-----------------------------------------------------+\n";
}
void TAB()  //TAB hien thi danh sach
{
    cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
    cout<<"| "<<"STT"<<" |"<<setw(12)<<"Ho"<<setw(11)<<"|"<<"  Ten  "<<"|"<<"  Nam Sinh  "<<"|"<<"     MSSV     "<<"|"<<"  Lop   "<<"|"<<" Diem Toan "<<"|"<<" Diem Van "<<"|"<<" Diem TB "<<" |\n";
    cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
}
void  menu_find ()  //tuy chon tim kiem
{
    cout<<"3-1. [Tim kiem theo ten]\n";
    cout<<"3-2. [Tim kiem theo nam sinh]\n";
    cout<<"3-3. [Tim kiem theo MSSV]\n";
    cout<<"3-4. [Tim kiem theo lop]\n";
    cout<<"3-5. [Tim kiem theo diem TB]\n";
}
int hashing(char mssv[11])
{
    int n=11;
    int sum = 0;
    while( n-- ) 
        sum = sum + *mssv++;
    return sum % 256;
}
void outsv(SinhVien sv)
{
    cout<<left;
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
        cout<<setw(7)<<(float)((sv.diem[0]+sv.diem[1])/2.0)<<"   |";
        cout<<endl;
}
int find_name (vector < list<SinhVien> > vlsv,char ten[])    //3-1 tim kiem theo ten
{
    int dem=0;
    int tam=0;
    for(vector< list<int> >::size_type i = 0; i < 10; i++)
        for(list<SinhVien>::iterator j = vlsv[i].begin(); j != vlsv[i].end(); j++)
        {
            dem++;
            if(strcmp(j->ten,ten)==0)
            {
                cout<<left;
                cout<<"| "<<setw(4)<<dem<<"|";outsv(*j);
                cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
                tam++;
            }
        }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_bird (vector < list<SinhVien> > vlsv,int namsinh)    //3-1 tim kiem theo ten
{
    int dem=0;
    int tam=0;
    for(vector< list<int> >::size_type i = 0; i < 10; i++)
        for(list<SinhVien>::iterator j = vlsv[i].begin(); j != vlsv[i].end(); j++)
        {
            dem++;
            if(j->namsinh==namsinh)
            {
                cout<<left;
                cout<<"| "<<setw(4)<<dem<<"|";outsv(*j);
                cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
                tam++;
            }
        }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_ID (vector < list<SinhVien> > vlsv,char ID[11])    //3-1 tim kiem theo ten
{
    int dem=0;
    int tam=0;
    int key=hashing(ID);
        for(list<SinhVien>::iterator j = vlsv[key%10].begin(); j != vlsv[key%10].end(); j++)
        {
            dem++;
            if(strcmp(j->mssv,ID)==0)
            {
                cout<<left;
                cout<<"| "<<setw(4)<<dem<<"|";outsv(*j);
                cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
                tam++;
            }
        }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_class (vector < list<SinhVien> > vlsv,char lop[])    //3-1 tim kiem theo ten
{
    int dem=0;
    int tam=0;
    for(vector< list<int> >::size_type i = 0; i < 10; i++)
        for(list<SinhVien>::iterator j = vlsv[i].begin(); j != vlsv[i].end(); j++)
        {
            dem++;
            if(strcmp(j->lop,lop)==0)
            {
                cout<<left;
                cout<<"| "<<setw(4)<<dem<<"|";outsv(*j);
                cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
                tam++;
            }
        }
    if(tam>0)
        return 1;
    else
        return 0;
}
int find_point (vector < list<SinhVien> > vlsv,int diem)    //3-5 tim kiem theo diem TB
{
    int tam=0;
    int dem=0;
    for(vector< list<int> >::size_type i = 0; i < 10; i++)
        for(list<SinhVien>::iterator j = vlsv[i].begin(); j != vlsv[i].end(); j++)
    {
        dem++;
        if(((j->diem[0]+j->diem[1])/2)==diem)
        {
            cout<<left;
            cout<<"| "<<setw(4)<<dem<<"|";outsv(*j);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
            tam++;
        }
    }
    if(tam>0)
        return 1;
    else
        return 0;
}
int Delsv(vector < list<SinhVien> > &vlsv, char mssv[11])
{
    int key=hashing(mssv);
        for(list<SinhVien>::iterator j = vlsv[key%10].begin(); j != vlsv[key%10].end(); j++)
            if(strcmp(j->mssv,mssv)==0)
            {
                vlsv[key%10].erase(j);
                return 1;
            }
        return 0;
}
SinhVien insv()
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
    //}while(find_IDadd(listsv,sv.mssv)==1);
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
    return sv;
}
void choose_find (vector < list<SinhVien> > &vlsv) //menu chon tim kiem
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
            find_name(vlsv,ten);
        break;
        }
        case 2:
        {
            cout<<"3-2. [Tim kiem theo nam sinh]\n";
            cout<<"Nhap nam sinh sinh vien can tim \n";
            int namsinh;cin>>namsinh;
            TAB();
            find_bird(vlsv,namsinh);
        }
        case 3:
        {
            cout<<"3-3. [Tim kiem theo MSSV]\n";
            cout<<"Nhap mssv sinh vien can tim \n";
            char mssv[11];cin>>mssv;
            TAB();
            find_ID(vlsv,mssv);
        break;
        }
        case 4:
        {
            cout<<"3-4. [Tim kiem theo lop]\n";
            cout<<"Nhap lop sinh vien can tim \n";
            char lop[7];cin>>lop;
            TAB();
            find_class(vlsv,lop);
            break;
        }
        case 5:
        {
            cout<<"3-5. [Tim kiem theo diem TB]\n";
            cout<<"Nhap diem TB sinh vien can tim\n";
            float diem;cin>>diem;
            TAB();
            find_point(vlsv,diem);
            break;
        }
    }
}
/*void init(vector< list<SinhVien> > vlsv)
{
    for(int i=0;i<20;i++)
        vlsv[i]=NULL;

}*/
void IN(vector < list<SinhVien> > &vlsv)
{
    cout<<"Nhap so luong sinh vien muon them\n";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap Sinh Vien Thu "<<i+1<<endl;
        SinhVien tam=insv();
        int key = hashing(tam.mssv);
        vlsv[key%10].push_back(tam);
    }
}
void OUT(vector < list<SinhVien> > vlsv)
{
    int dem=0;
    TAB();
    for(vector< list<int> >::size_type i = 0; i < 10; i++)
        for(list<SinhVien>::iterator j = vlsv[i].begin(); j != vlsv[i].end(); j++)
        {
            cout<<left;
            dem++;
            cout<<"| "<<setw(4)<<dem<<"|";outsv(*j);
            cout<<"+-----+----------------------+-------+------------+--------------+--------+-----------+----------+----------+\n";
        }
}
void nhapfile(vector < list<SinhVien> > &vlsv)
{
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
            int key = hashing(tam.mssv);
            vlsv[key%10].push_back(tam);
        }
        cout<<"Thanh cong\n";
    }
    filei.close();
}
void xuatfile(vector < list<SinhVien> > vlsv)
{
    int tongsv=0;
    for(vector< list<int> >::size_type i = 0; i < 10; i++)
        for(list<SinhVien>::iterator j = vlsv[i].begin(); j != vlsv[i].end(); j++)
            tongsv++;
    ofstream fileo("Dssinhvien.txt");
    if(fileo.fail())
        cout<<"Tao file that bai\n";
    else
    {
        fileo<<tongsv;
        for(vector< list<int> >::size_type i = 0; i < 10; i++)
            for(list<SinhVien>::iterator j = vlsv[i].begin(); j != vlsv[i].end(); j++)
                {
                    fileo<<endl<<j->ho<<endl;
                    fileo<<j->ten<<endl;
                    fileo<<j->namsinh<<endl;
                    fileo<<j->mssv<<endl;
                    fileo<<j->lop<<endl;
                    fileo<<j->diem[0]<<endl;
                    fileo<<j->diem[1];
                }
        cout<<"Tao file thanh cong\n";
    }
    fileo.close();
}
void choose_main (vector < list<SinhVien> > &vlsv) //menu chon main
{  
    menu_main ();
    cout<<"Chon chuc nang \n";
    cout<<"[Menu]> ";
    int chon;
    cin>>chon;
    while(chon>=0&&chon<8)
    {
        switch(chon)
        {
            case 1:
            {
                cout<<"1. [Them sinh vien]\n";
                cout<<"[Menu]>[Add]> \n";
                IN(vlsv);
                choose_main (vlsv);
                break;
            }
            case 2:
            {
                cout<<"2. [Hien thi danh sach sinh vien]\n";
                cout<<"[Menu]>[Show]> \n";
                OUT(vlsv);
                cout<<"Nhan (y) de quay lai\n";
                char d;cin>>d;
                choose_main (vlsv);
                break;
            }
            case 3:
            {
                cout<<"3. [Tim kiem sinh vien]\n";
                cout<<"[Menu]>[Find]> \n";
                menu_find ();
                choose_find(vlsv);
                choose_main (vlsv);
                break;
            }
            case 4:
            {
                cout<<"4. [Sua thong tin sinh vien]\n";
                cout<<"[Menu]>[Edit]> \n";
                cout<<"Nhap mssv muon sua\n";
                char ms[11];cin>>ms;
                TAB();
                if(find_ID(vlsv,ms)==1)
                {
                    Delsv(vlsv,ms);
                    SinhVien tam=insv();
                    int key = hashing(tam.mssv);
                    vlsv[key%10].push_back(tam);
                    cout<<"Sua thanh cong\n";
                    cout<<"Nhan (y) de quay lai\n";
                    char d;cin>>d;
                }
                else
                    cout<<"[>?<]Khong tim thay[>?<]";
                choose_main (vlsv);
                break;
            }
            case 5:
            {
                cout<<"5. [Xoa thong tin sinh vien]\n";
                cout<<"[Menu]>[Del]> ";
                cout<<"Nhap mssv muon xoa\n";
                char ms[11];cin>>ms;
                TAB();
                if(find_ID(vlsv,ms)==1)
                {
                    Delsv(vlsv,ms);
                    cout<<"Xoa thanh cong\n";
                    cout<<"Nhan (y) de quay lai\n";
                    char d;cin>>d;
                }
                else
                    cout<<"[>?<]Khong tim thay[>?<]";
                choose_main (vlsv);
                break;
            }
            case 6:
            {
                nhapfile(vlsv);
                cout<<"Nhan (y) de quay lai\n";
                char tam;cin>>tam;
                choose_main(vlsv);
                break;
            }
            case 7:
            {
                xuatfile(vlsv);
                cout<<"Nhan (y) de quay lai\n";
                char tam;cin>>tam;
                choose_main(vlsv);
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
vector < list<SinhVien> > VLsv(10);
int main()
{
    choose_main(VLsv);
    return 0;
}