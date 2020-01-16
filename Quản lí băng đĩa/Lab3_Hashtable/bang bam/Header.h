#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include<istream>
#include<conio.h>
#include<stdio.h>

using namespace std;
const int MAX = 100;

typedef struct bangDia *NODEDia;

struct cuaHang
{
	char ten[30];
	char diachi[60];
	char sdt[30];
	int i = 19;
	NODEDia hT[20];
};
struct bangDia
{
	char Maso[5];
	char ten[200];
	char namphathanh[5];
	char daoDien[200];
	char dienVien[200];
	char tenTL[200];
	NODEDia nextDia;
};
void inIt(cuaHang &CH) {
	for (int i = 0; i < 20; i++) {
		CH.hT[i] = NULL;
	}
}
int bam(char a[]) {
	int tong = 0;
	for (int i = 0; i < (int)strlen(a); i++) {
		tong += (int)a[i];
	}
	int z = tong % 20;
	return  z;
}
NODEDia create_Dia(int j) {
	NODEDia p = new bangDia;
	cin.ignore();
	cout << left << "  Lan " << j + 1 << ": " << endl;
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
	cout << setw(25) << left << "\tNhap ten the loai: ";
	cin.getline(p->tenTL, 200);
	cout << setw(25) << left << "        --------------" << endl;
	p->nextDia = NULL;

	return p;
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
void outPutFile(cuaHang &CH) {
	NODEDia listDia = CH.hT[0];

	fstream f;
	f.open("dSDia.txt");

	int x;//so luong dia.
	f >> x;
	int k = 0;
	for (int i = 0; i < x; i++)
	{
		NODEDia p = new bangDia;
		f.ignore();
		f.getline(p->tenTL, 200);
		f.getline(p->Maso, 5);
		f.getline(p->ten, 200);
		f.getline(p->namphathanh, 5);
		f.getline(p->daoDien, 200);
		f.getline(p->dienVien, 200);
		p->nextDia = NULL;
		for (int j = 0; j < CH.i; j++) {
			if (bam(p->Maso) == j) {
				listDia = CH.hT[j];
				if (listDia == NULL)
					CH.hT[j] = p;
				else {
					while (listDia->nextDia != NULL)
						listDia = listDia->nextDia;
					listDia->nextDia = p;

				}
			}
			
		}
		
	}
	cout << "\t\t\tNHAP DS DIA THANH CONG!!!" << endl;
}
void xuatDSdia(cuaHang CH)
{
	NODEDia listDia;
	int j = 1;
	for (int i = 0; i < 20; i++) {
		listDia = CH.hT[i];
		cout << "~~~~~" << i << "~~~~~"<<endl;
		while (listDia != NULL)
		{

			cout << "\t" << j++ << setw(23) << left << ".Ma so dia: " << listDia->Maso << endl;
			cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
			cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
			cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
			cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;


			listDia = listDia->nextDia;
		}
	}
}
void them(cuaHang &CH) {
	NODEDia listDia;
	cout << "nhap dia can them: " << endl;
	NODEDia p = new bangDia;
	int j = 0;
	p = create_Dia(j);
	j++;
	for (int j = 0; j < CH.i; j++) {
		if (bam(p->Maso) == j) {
			listDia = CH.hT[j];
			if (listDia == NULL)
				CH.hT[j] = p;
			else {
				while (listDia->nextDia != NULL)
					listDia = listDia->nextDia;
				listDia->nextDia = p;

			}
		}
	}
}
void xoaDia(cuaHang &CH) {
	NODEDia listDia;
	bool flap = true;

	char xoa[200];
	cout << " +Ten cua dia can xoa: ";
	cin.ignore();
	cin.getline(xoa, 200);
	for (int i = 0; i <= CH.i; i++) {
		listDia = CH.hT[i];
		if (listDia!=NULL && strcmp(listDia->ten, xoa) == 0) {
			NODEDia p = listDia;
			CH.hT[i] = listDia->nextDia;
			flap = false;
			delete p;
			listDia = CH.hT[i];
		}
		while (listDia != NULL )
		{
			if (listDia->nextDia!=NULL&&strcmp(listDia->nextDia->ten, xoa) == 0) {
				NODEDia p = listDia->nextDia;
				listDia->nextDia = listDia->nextDia->nextDia;
				delete p; flap = false;
			}
			listDia = listDia->nextDia;
		}
	}

	if (flap)
		cout << "\n~~~~~~~~~~~~~khong thanh cong!!!~~~~~~~~~~~~~~~~\n" << endl;
	else
		cout << "\n~~~~~~~~~~~~~xoa thanh cong!!!~~~~~~~~~~~~~~~~\n" << endl;
}
void search(cuaHang CH) {
	NODEDia listDia;

	int a;
	cout << "-----Nhap 1 de tim theo ten, nhap 2 de tin theo maso, nhap 3 de tim theo dien vien------" << endl << "CHON: ";
	cin >> a;
	switch (a)
	{
	case 1: {
		char ed[200];
		cout << "- Nhap ten dia can tim: ";
		cin.ignore();
		cin.getline(ed, 200);
		for (int i = 0; i < CH.i; i++) {
			listDia = CH.hT[i];
			while (listDia != NULL)
			{
				if (strcmp(ed, listDia->ten) == 0)
				{
					cout << setw(25) << left << "\t  Ma so dia: " << listDia->Maso << endl;
					cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
					cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
					cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
					cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;
					cout << setw(25) << left << "\t  Ten the loai: " << listDia->tenTL << endl;
				}
				listDia = listDia->nextDia;
			}
		}
		break;
	}
	case 2: {
		char ed[5];
		cout << "- Nhap maso dia can tim: ";
		cin.ignore();
		cin.getline(ed, 200);
		for (int i = 0; i < CH.i; i++) {
			listDia = CH.hT[i];
			while (listDia != NULL)
			{
				if (strcmp(ed, listDia->Maso) == 0)
				{
					cout << setw(25) << left << "\t  Ma so dia: " << listDia->Maso << endl;
					cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
					cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
					cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
					cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;
					cout << setw(25) << left << "\t  Ten the loai: " << listDia->tenTL << endl;
				}
				listDia = listDia->nextDia;
			}
		}
		break;
	}
	case 3: {
		char ed[200];
		cout << "- Nhap ten dien vien can tim: ";
		cin.ignore();
		cin.getline(ed, 200);
		for (int i = 0; i < CH.i; i++) {
			listDia = CH.hT[i];
			while (listDia != NULL)
			{
				if (strcmp(ed, listDia->dienVien) == 0)
				{
					cout << setw(25) << left << "\t  Ma so dia: " << listDia->Maso << endl;
					cout << setw(25) << left << "\t  Ten dia: " << listDia->ten << endl;
					cout << setw(25) << left << "\t  Nam phat hanh: " << listDia->namphathanh << endl;
					cout << setw(25) << left << "\t  Ten dao dien: " << listDia->daoDien << endl;
					cout << setw(25) << left << "\t  Ten dien vien: " << listDia->dienVien << endl;
					cout << setw(25) << left << "\t  Ten the loai: " << listDia->tenTL << endl;
				}
				listDia = listDia->nextDia;
			}
		}
		break;
	}
	default:
		break;
	}
}
void Edit(cuaHang &CH) {
	NODEDia listDia;
	char ed[5];
	cout << " - Nhap ma so dia can sua: ";
	cin.ignore();
	cin.getline(ed, 5);
	for (int i = 0; i < CH.i; i++) {
		listDia = CH.hT[i];
		while (listDia != NULL)
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
				cout << "\tNhap ten the loai moi: ";
				cin.getline(listDia->tenTL, 200);
			}
			listDia = listDia->nextDia;
		}
	}
}
void sort(cuaHang &CH) {
	/*NODETL i = CH.dstheloai;
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

	cout << "Sap Xep Thanh Cong!!!"<<endl;*/
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
	/*cout << "\t\t\t\t\t 7: Sap Xep               " << endl;*/
	cout << "\t\t\t\t\t 8: Xoa Man Hinh" << endl;
	cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	do
	{
		if (flat) {
			cout << endl << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
			cout << endl << "| 2: Xuat DS Dia  ";
			cout << "  3: Them.    ";
			cout << "  4: Xoa Dia";
			cout << "     5: Tim.";
			cout << "     6: Sua Thong Tin Dia    ";
			/*cout << "  7: Sap Xep      ";*/
			cout << setw(12) << "";
			cout << "  8: Xoa Man Hinh  |" << endl;
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
			/*cout << "\t\t\t\t\t 7: Sap Xep               " << endl;*/
			cout << "\t\t\t\t\t 8: Xoa Man Hinh" << endl;
			cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			flat = false;
			break;
		}
		default: {
			cout << "\t\t\tBan Nhap Sai!!! Vui Long Nhap Lai." << endl;
			break;
		}

		}
	} while (a != -99);

}