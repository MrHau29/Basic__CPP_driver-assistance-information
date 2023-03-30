#include<iostream>
#include<string>
#include<fstream>
#include <type_traits>
#include <sstream>
using namespace std;

class Car
{
private:
	int arrAuto[8];
	int arr[8];
	int safeDistance[3];
	int isDigit = 0;
	int speed = 0;
public:

	//cai dat mscn 
	void load();
	// nhap mscn tu file vao mang mac dinh
	void readFileArr();
	// ktra dl nhap vao co phai la so ko
	bool isNumber(string str);
	void ifNotInteger();
	//nhap mang mscn
	void inputArr(int* a, int n);
	//xuat mang
	void outArr(int* a, int n);
	// hoan vi
	void swap(int& a, int& b);
	// sao xep mang thep BubbleSort
	void bubbleSort(int* a, int n);
	// sap xep mang voi Selection Sort
	void selectionSort(int* a, int n);
	// check Pass
	void checkpass(int* arr);

	void resetPass();
	// cai dat khoang cach an toan
	void setSafeDistance();
	// canh bao toc do 
	void speedWaring(int vtoc2);
	//dieu khien toc do
	void controlSpeed(int input, int vtoc);
	// kiem tra toc do truoc khi chuyen so
	void checkSpeed(int input);
	// lua chon trang thai hop so
	void gearBoxMenu(int input1);


};

