//Dao Thanh Manh - 20211014
#include<iostream>
#include<string>
using namespace std;

struct sanpham {
	string Tensp, Donvi;
	int Soluong;
	double Dongia, TienVanChuyen, Thanhtien;
}; 

struct phieuxuat {
	string TenKho;
    string MaPhieuXuat;
	int ngay, thang, nam, Sosp;
	double Sotiendatt, Sotienphaitt, TongVanChuyen;
	sanpham *Dssanpham;
};

struct dsphieuxuat {
	int Soluongphieu;
	phieuxuat *Dsphieuxuat;
};

void nhapSanPham(sanpham &sp) {
	cout<<"\t\tTen mat hang: "; cin.ignore(); getline(cin, sp.Tensp); cout<<endl;
    cout<<"\t\tDon vi tinh: "; cin>>sp.Donvi; cout<<endl;
	cout<<"\t\tSo luong: "; cin>>sp.Soluong; cout<<endl;
	cout<<"\t\tDon gia: "; cin>>sp.Dongia; cout<<endl;
	
	sp.Thanhtien = sp.Soluong*sp.Dongia;

    if(sp.Donvi == "Thung"){
    if(sp.Soluong < 20) sp.TienVanChuyen = 75;
    else if(sp.Soluong >20 && sp.Soluong < 35) sp.TienVanChuyen = 105;
    else if(sp.Soluong >35 && sp.Soluong < 50) sp.TienVanChuyen = 125;
    else if(sp.Soluong >=50) sp.TienVanChuyen= 170;
} else{
if(sp.Soluong <= 50) sp.TienVanChuyen = 50;
    else if(sp.Soluong >50) sp.TienVanChuyen = 125;
}
}

void nhapPhieuXuat(phieuxuat &pn) {
	cout<<"\tTen Kho Hang: "; cin.ignore(); getline(cin, pn.TenKho); cout<<endl;
    cout<<"\tMa Phieu Xuat: "; cin.ignore(); getline(cin, pn.MaPhieuXuat); cout<<endl;
    cout<<"Ngay Lap Phieu Xuat\n";
	cout<<"\tNgay: "; cin>>pn.ngay; cout<<endl;
	cout<<"\tThang: "; cin>>pn.thang; cout<<endl;
	cout<<"\tNam: "; cin>>pn.nam; cout<<endl;
	cout<<"\tSo mat hang: "; cin>>pn.Sosp; cout<<endl;
	cout<<"\tNhap ds cac mat hang: "<<endl;
	pn.Dssanpham = new sanpham[pn.Sosp];
	pn.Sotienphaitt = 0;
	pn.TongVanChuyen = 0;
	for(int i=0; i<pn.Sosp; i++) {
		cout<<"\tMat hang thu "<<i+1<<endl;
		nhapSanPham(pn.Dssanpham[i]);
		pn.Sotienphaitt += pn.Dssanpham[i].Thanhtien;
		pn.TongVanChuyen += pn.Dssanpham[i].TienVanChuyen;
	}
	cout<<"\tSo tien da thanh toan: ";cin>>pn.Sotiendatt; cout<<endl;
}

void nhapDsPhieuXuat(dsphieuxuat &ds) {
	ds.Dsphieuxuat = new phieuxuat[ds.Soluongphieu];
	for(int i=0; i<ds.Soluongphieu; i++) {
		cout<<"Nhap thong tin Phieu Xuat "<<i+1<<":"<<endl;
		nhapPhieuXuat(ds.Dsphieuxuat[i]);
	}
	cout<<endl;
}

void inThongTinPN(phieuxuat pn) {
	// cout<<"\tTen Nha Cung cap: "<<pn.TenKho<<endl;
	// cout<<"\tNgay thu: Ngay "<<pn.ngay<<" thang "<<pn.thang<<" nam "<<pn.nam<<endl;
	// cout<<"\tSo Mat Hang: "<<pn.Sosp<<endl;
	// cout<<"\tDa thanh toan: "<<pn.Sotiendatt<<endl;
	// cout<<"\tTong thanh tien: "<<pn.Sotienphaitt<<endl;
	// cout<<"\tTong van chuyen: "<<pn.TongVanChuyen<<endl;
	// cout<<"Tong phai thanh toan: "<<-pn.Sotiendatt+pn.Sotienphaitt+pn.TongVanChuyen<<endl;
	// cout << "Tinh trang thanh toan: \t";
	// cout<<"\tChi tiet cac san pham: "<<endl;
	// cout<<"\tTenMatHang"<<"\tDonVT"<<"\tSoL"<<"\tdongia"<<"\t\tThanhtien"<<"\tVanchuyen"<<"Cong"<<endl;
	cout<<"\tTen Kho Hang: "<<pn.TenKho<<endl;
    cout<<"\tNgay thu: Ngay "<<pn.ngay<<" thang "<<pn.thang<<" nam "<<pn.nam<<endl;
    cout<<"\tSo Mat Hang: "<<pn.Sosp<<endl;
    cout<<"\tDa thanh toan: "<<pn.Sotiendatt<<endl;
    cout<<"\tTong thanh tien: "<<pn.Sotienphaitt<<endl;
    cout<<"\tTong van chuyen: "<<pn.TongVanChuyen<<endl;
    cout<<"Tong phai thanh toan: "<<pn.Sotienphaitt+pn.TongVanChuyen<<endl;
    cout<<"Tinh trang thanh toan: \t";
    cout<<"Thanh toan thieu so tien"<<(pn.Sotiendatt-pn.Sotienphaitt+pn.TongVanChuyen)-pn.Sotiendatt << endl;
    cout<<"\tChi tiet cac mat hang: "<<endl;
    cout<<"\tTenMatHang"<<"\tDongia"<<"\tSoluong"<<"\t\tThanhtien"<<"\tTienvanchuyen" <<"\tCong"<<endl;
	for(int i=0; i<pn.Sosp; i++) {
		cout<<"\t"<<pn.Dssanpham[i].Tensp<<"\t"
		<<pn.Dssanpham[i].Donvi<<"\t\t"
        <<pn.Dssanpham[i].Soluong<<"\t\t"
		<<pn.Dssanpham[i].Dongia<<"\t"
		<<pn.Dssanpham[i].Thanhtien<<"\t\t"
		<<pn.Dssanpham[i].TienVanChuyen
        <<pn.Dssanpham[i].TienVanChuyen + pn.Dssanpham[i].Thanhtien<<endl;
	}
	cout<<endl;
}

void inDsPhieuXuat(dsphieuxuat ds) {
	for(int i=0; i<ds.Soluongphieu; i++) {
		inThongTinPN(ds.Dsphieuxuat[i]);
	}
}

int main() {
	int luachon;
	dsphieuxuat ds;
    cout << endl;
	cout<<"Dao Thanh Manh - 20211014 - 727641 - IT3040 - 2022.2"<<endl;
	cout<<"Nhap so Phieu Xuat: "; cin>>ds.Soluongphieu; cout<<endl;
	do {
		cout<<"Dao Thanh Manh - 20211014 - 727641 - IT3040 - 2022.2"<<endl;
		cout<<"**   CHUONG TRINH QUAN LY PHIEU XUAT   **"<<endl;
		cout<<"**1. Nhap CAC PHIEU XUAT, MAT HANG        **"<<endl;
		cout<<"**2. IN KET QUA PHIEU XUAT VA MAT HANG**"<<endl;
		cout<<"**0. Thoat                         **"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"**      Nhap lua chon cua ban      **"<<endl;
		cin>>luachon;
		switch(luachon) {
			case 1: {
				cout<<"Ban da chon nhap ds Phieu Xuat SP!"<<endl;
				nhapDsPhieuXuat(ds);
				cout<<"Ban da nhap thanh cong!"<<endl;
				cout<<endl;
				break;
			}
			case 2: {
				cout<<"Ban da chon IN RA PHIEU XUAT!"<<endl;
				inDsPhieuXuat(ds);
				break;
			}
			case 0: {
                cout<<"Dao Thanh Manh - 20211014 - 727641 - IT3040 - 2022.2"<<endl;
                cout<<"Ban da chon thoat chuong trinh!"<<endl;
				break;
            }
			default: {
				cout<<"Nhan phim bat ki de tiep tuc!"<<endl;
				break;
			}
		}
	}
	while(luachon != 0);
	return 0;
}
//Dao Thanh Manh - 20211014