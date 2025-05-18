#include <iostream>
using namespace std;

const float luong = 14000000;
const float hoc_bong = 85000000;

float so_tien_phai_tiet_kiem(int so_thang) {
	return (float) (hoc_bong) / so_thang  - (float)(hoc_bong)/24;
}


int main() {
	
	for(int i = 1; i <= 24; ++i) {
		int so_thang = i;
		float so_tien_tiet_kiem_moi_thang = so_tien_phai_tiet_kiem(so_thang);
		float so_tien_con_lai_de_tieu = luong - so_tien_tiet_kiem_moi_thang;

		cout<<so_thang<<" ";
		cout<<fixed;
		cout.precision(3);
		cout<<so_tien_tiet_kiem_moi_thang<<" ";
		cout<<so_tien_con_lai_de_tieu<<" ";
		cout<<"\n";
	
	}
}