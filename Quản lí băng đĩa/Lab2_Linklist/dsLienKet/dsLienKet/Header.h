#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include<istream>
#include<conio.h>
#include<stdio.h>

using namespace std;
const int MAX = 100;

typedef struct theLoai *NODETL;
typedef struct bangDia *NODEDia;

struct cuaHang
{
	char ten[30];
	char diachi[60];
	char sdt[30];
	NODETL dstheloai;
};
struct theLoai
{
	int sodia;
	char ten[200];
	NODETL nextTL;
	NODEDia dsDia;
};
struct bangDia
{
	char Maso[5];
	char ten[200];
	char namphathanh[5];
	char daoDien[200];
	char dienVien[200];
	NODEDia nextDia;
};

NODETL create_dsDia( int i) {
	NODETL p = new theLoai;
	cin.ignore();
	cout << left << "- Nhap ten the loai " << i + 1 << ": " << setw(1) << "";
	cin.getline(p->ten, 200);
	cout << setw(24) << left << " + Nhap so luong dia: ";
	cin >> p->sodia;
	p->dsDia = NULL;
	p->nextTL = NULL;
	return p;
}
NODEDia create_Dia( int j) {
	NODEDia p = new bangDia;
	cin.ignore();
	cout << left << "  Lan " << j+1 << ": " << endl;
	cout << setw(25) << left << "\tNhap ma so dia: ";
	cin.getline(p->Maso, 5);
	cout << setw(25) << left << "\tNhap ten dia: ";
	cin.getline(p->ten, 200);
	cout << setw(25) << left << "\tNhap nam phat hanh: ";
	cin.getline(p->namphathanh, 5);
	cout << setw(25) << left << "\tNhap ten dao dien: ";
	cin.getline(p->daoDien, 200);
	cout << setw(25) << left << "\tNhap ten dien vien: ";
	cin.getline(p->dienVien, 200);
	cout << setw(25) << left << "        --------------" << endl;
	p->nextDia = NULL;

	return p;
}
void inIt(cuaHang &CH) {
	CH.dstheloai = NULL;
}
void nhapCuaHang(cuaHang &a)
{
	fstream f;
	f.open("thongtincuahang.txt");
	f.ignore();
	f.getline(a.ten, 30);
	f.getline(a.diachi, 60);
	f >> a.sdt;
	f.close();
}
void xuatCuaHang(cuaHang a)
{
	cout << "Ten cua hang: " << a.ten << endl;
	cout << "Dia chi: " << a.diachi << endl;
	cout << "Sðt: " << a.sdt << endl;
	cout << "      -----------" << endl;
}
void nhapDSDia(cuaHang &CH)
{
	NODETL listTL = CH.dstheloai,tamlistTL = CH.dstheloai;
	NODEDia listDia;

	int x;
	cout << "Nhap so luong the loai: ";
	cin >> x;
	
	for (int i = 0; i < x; i++)
	{
		
		listTL = CH.dstheloai;
		if (listTL == NULL) {
			CH.dstheloai=create_dsDia(i);
			tamlistTL = CH.dstheloai;

		}
		else {
			while (listTL->nextTL != NULL) 
				listTL = listTL->nextTL;										
			listTL->nextTL = create_dsDia(i);
			tamlistTL = listTL->nextTL;					
		}

		for (int j = 0; j < tamlistTL->sodia; j++)
		{
			listDia = tamlistTL->dsDia;
			if (tamlistTL->dsDia == NULL) {
				tamlistTL->dsDia = create_Dia(j);
			}
			else {
				while (listDia->nextDia != NULL)
					listDia = listDia->nextDia;
				listDia->nextDia =  create_Dia(j);											
				}						
		}
		
	}
}
void xuatDSdia(cuaHang CH)
{
	NODETL listTL=CH.dstheloai;
	NODEDia listDia;
	int j;
	while (listTL!=NULL)
	{
		listDia = listTL->dsDia;
		cout << "The loai: " << listTL->ten << endl;
		cout << setw(25) << left << "Danh sach: " << endl;
		if (listTL->sodia == 0)
			cout << "Empty!!!" << endl;
		j = 1;
		while (listDia!=NULL)
		{
			
			cout << "\t" << j ++ << setw(23) << left << ".Ma so dia: " << listDia->Maso << endl;
			cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
			cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
			cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
			cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;

			listDia = listDia->nextDia;
		}

		listTL = listTL->nextTL;
	}
}
void them(cuaHang &CH) {

	NODETL listTL = CH.dstheloai;
	NODEDia listDia;
	int a;
	cout << "-----Nhap 1 de them the loai, nhap 2 de them dia-----"<<"CHON: ";
	cin>>a;

	switch (a)
	{
	case 2: {
		int j = 0;
		bool flap = true;
		char tenth[200];
		cout << " +Ten the loai cua dia can them: ";
		cin.ignore();
		cin.getline(tenth, 200);
		while (listTL != NULL)
		{
			if (strcmp(tenth, listTL->ten) == 0)
			{
				listDia = listTL->dsDia;
				cout << "Nhap dia can them: ";
				listTL->sodia++;
				if (listDia == NULL) {
					listTL->dsDia = create_Dia(j);
				}
				else {
					while (listDia->nextDia != NULL)
						listDia = listDia->nextDia;
					listDia->nextDia = create_Dia(j);
				}
				flap = false; break;
			}
			listTL = listTL->nextTL;
		}
		if (flap)
			cout << "Khong co the loai nay!" << endl;
		break;
	}
	case 1: {
		int i = 1;
		listTL = CH.dstheloai;
		if (listTL == NULL) 
			CH.dstheloai = create_dsDia(i);		
		else {
			while (listTL->nextTL != NULL) {
				listTL = listTL->nextTL; i++;
			}				
			listTL->nextTL = create_dsDia(i);		
			for (int j = 0; j < listTL->nextTL->sodia; j++)
			{
				listDia = listTL->nextTL->dsDia;
				if (listDia == NULL) {
					listTL->nextTL->dsDia = create_Dia(j);
				}
				else {
					while (listDia->nextDia != NULL)
						listDia = listDia->nextDia;
					listDia->nextDia = create_Dia(j);
				}
			}
		}
	}
	default:
		break;
	}
}
void xoaDia(cuaHang &CH) {
	NODETL listTL = CH.dstheloai;
	NODEDia listDia;
	bool flap = true;
	char tenxoa[200];
	cout << "-Ten the loai cua dia can xoa: ";
	cin.ignore();
	cin.getline(tenxoa, 200);
	while (listTL != NULL)
	{
		if (strcmp(tenxoa, listTL->ten) == 0)
		{
			listDia = listTL->dsDia;
			char xoa[200];
			cout << " +Ten cua dia can xoa: ";
			cin.getline(xoa, 200);
			listTL->sodia --;
			if (strcmp(listDia->ten, xoa) == 0) {
				NODEDia p = listDia;
				listTL->dsDia = listDia->nextDia; flap = false;
			}
			else
			while (listDia!=NULL)
			{
				if (strcmp(listDia->nextDia->ten, xoa) == 0) {
					NODEDia p = listDia->nextDia;
					listDia->nextDia = listDia->nextDia->nextDia;
					delete p; flap = false;
				}				
				listDia = listDia->nextDia;
			}
		}
		listTL = listTL->nextTL;
	}
	if (flap)
		cout << "khong thanh cong!!!"<<endl;
	else
		cout << "xoa thanh cong!!!"<<endl;
}
void search(cuaHang CH) {
	NODETL listTL = CH.dstheloai;
	NODEDia listDia;
	bool flap = false; 

	int a;
	cout << "-----Nhap 1 de tim theo ten, nhap 2 de tin theo maso, nhap 3 de tim theo dien vien------"<<endl<<"CHON: ";
	cin >> a;
	switch (a)
	{
	case 1: {
		char ed[200];
		cout << "- Nhap ten dia can tim: ";
		cin.ignore();
		cin.getline(ed, 200);
		while (listTL != NULL)
		{
			listDia = listTL->dsDia;
			while (listDia != NULL)
			{
				if (strcmp(ed, listDia->ten) == 0)
				{
					cout << setw(25) << left << "\t  Ma so dia: " << listDia->Maso << endl;
					cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
					cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
					cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
					cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;
					flap = true;
				}
				listDia = listDia->nextDia;
			}
			listTL = listTL->nextTL;
		}
		break;
	}
	case 2: {
		char ed[5];
		cout << "- Nhap maso dia can tim: ";
		cin.ignore();
		cin.getline(ed, 200);
		while (listTL != NULL)
		{
			listDia = listTL->dsDia;
			while (listDia != NULL)
			{
				if (strcmp(ed, listDia->Maso) == 0)
				{
					cout << setw(25) << left << "\t  Ma so dia: " << listDia->Maso << endl;
					cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
					cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
					cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
					cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;
					flap = true;
				}
				listDia = listDia->nextDia;
			}
			listTL = listTL->nextTL;
		}
		break;
	}
	case 3: {
		char ed[200];
		cout << "- Nhap ten dien vien can tim: ";
		cin.ignore();
		cin.getline(ed, 200);
		while (listTL != NULL)
		{
			listDia = listTL->dsDia;
			while (listDia != NULL)
			{
				if (strcmp(ed, listDia->dienVien) == 0)
				{
					cout << setw(25) << left << "\t  Ma so dia: " << listDia->Maso << endl;
					cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
					cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
					cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
					cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;
					flap = true;
				}
				listDia = listDia->nextDia;
			}
			listTL = listTL->nextTL;
		}
		break;
	}
	default:
		break;
	}
	if (!flap)
		cout << "              khong tim thay!!!"<<endl;
}
void Edit(cuaHang &CH) {
	NODETL listTL = CH.dstheloai;
	NODEDia listDia;
	char ed[5],tL[200];
	cout << "- Nhap ten the loai dia can sua: ";
	cin.ignore();
	cin.getline(tL, 200);
	cout << "    + Nhap ma so dia can sua: ";
	cin.getline(ed, 5);
	while (listTL!=NULL)
	{
		listDia = listTL->dsDia;
		if (strcmp(tL, listTL->ten) == 0)
		while (listDia!=NULL)
		{
			if (strcmp(ed, listDia->Maso) == 0)
			{
				cout << "\tMa so dia moi: ";
				cin.getline(listDia->Maso, 5);
				cout << "\tTen dia moi: ";
				cin.getline(listDia->ten, 200);
				cout << "\tNhap nam phat hanh moi: ";
				cin.getline(listDia->namphathanh, 5);
				cout << "\tNhap ten dao dien moi: ";
				cin.getline(listDia->daoDien, 200);
				cout << "\tNhap ten dien vien moi: ";
				cin.getline(listDia->dienVien, 200);
			}
			listDia = listDia->nextDia;
		}
		listTL = listTL->nextTL;
	}
}
void sort(cuaHang &CH) {
	NODETL i = CH.dstheloai;
	NODEDia j;
	int a;
	cout << "-----Nhap 1 de sap xep theo maso, nhap 2 sap xep theo ten-----" << endl << "CHON: ";
	cin >> a;
	switch (a)
	{
	case 1: {
		bool flap = true;
		for (i; i != NULL; i = i->nextTL) {
			for (j = i->dsDia; j != NULL; j = j->nextDia) {
				if (j->nextDia != NULL && flap && strcmp(j->Maso, j->nextDia->Maso) == 1) {
					NODEDia c = new bangDia;
					c = j->nextDia;
					j->nextDia = j->nextDia->nextDia;
					c->nextDia = j;
					i->dsDia = c;
				}
				if (j->nextDia != NULL && j->nextDia->nextDia != NULL && strcmp(j->nextDia->Maso, j->nextDia->nextDia->Maso) == 1) {
					NODEDia c = new bangDia;
					c = j->nextDia->nextDia;
					j->nextDia->nextDia = j->nextDia->nextDia->nextDia;
					if (c->nextDia != NULL)
						c->nextDia->nextDia = j;
					j->nextDia = c;
				}
				flap = false;
			}
			flap = true;
		}
		break;
	}
	case 2: {
		bool flap = true;
		for (i; i != NULL; i = i->nextTL) {
			for (j = i->dsDia; j != NULL; j = j->nextDia) {
				if (j->nextDia != NULL && flap && strcmp(j->ten, j->nextDia->ten) == 1) {
					NODEDia c = new bangDia;
					c = j->nextDia;
					j->nextDia = j->nextDia->nextDia;
					c->nextDia = j;
					i->dsDia = c;
				}
				if (j->nextDia != NULL && j->nextDia->nextDia != NULL && strcmp(j->nextDia->ten, j->nextDia->nextDia->ten) == 1) {
					NODEDia c = new bangDia;
					c = j->nextDia->nextDia;
					j->nextDia->nextDia = j->nextDia->nextDia->nextDia;
					if(c->nextDia!=NULL)
						c->nextDia->nextDia = j;
					j->nextDia = c;
				}
				flap = false;
			}
			flap = true;
		}
		break;
	}
	default:
		break;
	}
	
	cout << "Sap Xep Thanh Cong!!!"<<endl;
}
void outPutFile(cuaHang &CH) {
	NODETL listTL = CH.dstheloai, tamlistTL = CH.dstheloai;
	NODEDia listDia;

	fstream f;
	f.open("dSDia.txt");

	int x;//so luong the loai.
	f >> x;

	for (int i = 0; i < x; i++)
	{

		listTL = CH.dstheloai;
		if (listTL == NULL) {
			NODETL p = new theLoai;	
			f.ignore(); 
			f.getline(p->ten, 200);
			f >> p->sodia;
			p->dsDia = NULL;
			p->nextTL = NULL;
			CH.dstheloai = p;
			tamlistTL = CH.dstheloai;

		}
		else {
			while (listTL->nextTL != NULL )
				listTL = listTL->nextTL;
			NODETL p = new theLoai;			
			f.getline(p->ten, 200);
			f >> p->sodia;
			p->dsDia = NULL;
			p->nextTL = NULL;
			listTL->nextTL = p;
			tamlistTL = listTL->nextTL;
		}

		for (int j = 0; j < tamlistTL->sodia; j++)
		{
			listDia = tamlistTL->dsDia;
			if (tamlistTL->dsDia == NULL) {
				NODEDia p = new bangDia;
				f.ignore();
				f.getline(p->Maso, 5);
				f.getline(p->ten, 200);
				f.getline(p->namphathanh, 5);
				f.getline(p->daoDien, 200);
				f.getline(p->dienVien, 200);
				p->nextDia = NULL;
				tamlistTL->dsDia = p;
			}
			else {
				while (listDia->nextDia != NULL)
					listDia = listDia->nextDia;
				NODEDia p = new bangDia;
				
				f.getline(p->Maso, 5);
				f.getline(p->ten, 200);
				f.getline(p->namphathanh, 5);
				f.getline(p->daoDien, 200);
				f.getline(p->dienVien, 200);
				p->nextDia = NULL;
				listDia->nextDia = p;
			}
		}

	}
	cout << "\t\t\tNHAP DS DIA THANH CONG!!!"<<endl;
}
void MENU() {
	cuaHang CH;
	inIt(CH);
	int a; bool flat = false;
	cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t\t\t\t 0: Xuat Thong Tin Cua hang." << endl;
	cout << "\t\t\t\t\t 1: Nhap The Loai Va Danh Sach Dia." << endl;
	cout << "\t\t\t\t\t 2: Xuat Danh Sach Dia" << endl;
	cout << "\t\t\t\t\t 3: Them." << endl;
	cout << "\t\t\t\t\t 4: Xoa Dia" << endl;
	cout << "\t\t\t\t\t 5: Tim." << endl;
	cout << "\t\t\t\t\t 6: Sua Thong Tin Dia" << endl;
	cout << "\t\t\t\t\t 7: Sap Xep               " << endl;
	cout << "\t\t\t\t\t 8: Xoa Man Hinh" << endl;
	cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	do
	{
		if (flat) {
			cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
			cout << endl << "| 2: Xuat DS Dia  ";
			cout << "  3: Them.    ";
			cout << "  4: Xoa Dia" ;
			cout << "  5: Tim." ;
			cout << "  6: Sua Thong Tin Dia    " ;
			cout << "  7: Sap Xep      " ;
			cout << "  8: Xoa Man Hinh  |"<<endl;
			cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
		}
		flat = true;
		cout << "CHON Chuc Nang (Nhap -99 De Thoat): "; cin >> a;
		switch (a)
		{
		case 0: {
			nhapCuaHang(CH);
			xuatCuaHang(CH);
			break;
		}
		case 1: {
			/*nhapDSDia(CH);*/
			outPutFile(CH);
			break;
		}
		case 2: {
			xuatDSdia(CH);
			break;
		}
		case 3: {
			them(CH);
			break;
		}
		case 4: {
			xoaDia(CH);
			break;
		}
		case 5: {
			search(CH);
			break;
		}
		case 6: {
			Edit(CH);
			break;
		}
		case 7: {
			sort(CH);
			break;
		}
		case 8: {
			system("cls");
			cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~" << endl;
			cout << "\t\t\t\t\t 0: Xuat Thong Tin Cua hang." << endl;
			cout << "\t\t\t\t\t 1: Nhap The Loai Va Danh Sach Dia." << endl;
			cout << "\t\t\t\t\t 2: Xuat Danh Sach Dia" << endl;
			cout << "\t\t\t\t\t 3: Them." << endl;
			cout << "\t\t\t\t\t 4: Xoa Dia" << endl;
			cout << "\t\t\t\t\t 5: Tim." << endl;
			cout << "\t\t\t\t\t 6: Sua Thong Tin Dia" << endl;
			cout << "\t\t\t\t\t 7: Sap Xep               " << endl;
			cout << "\t\t\t\t\t 8: Xoa Man Hinh" << endl;
			cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			flat = false;
			break;
		}
		default: {
			if (a != -99)
				cout << "\t\t\tBan Nhap Sai!!! Vui Long Nhap Lai." << endl;
			break;
		}
			
		}
	} while (a != -99);

}