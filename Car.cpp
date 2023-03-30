#include"Car.h"
bool Car::isNumber(string str)
{
	bool check = true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str.at(i)) == false)
		{
			check = false;
		}
	}
	return check;
}

void Car::ifNotInteger()
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}
void Car::checkpass(int* arr) {

	for (int i = 0; i < 8; i++) {
		if (*(arr + i) == this->arr[i]);
		else {
			cout << "MA SO KHONG GIONG NHAU" << endl;
			cout << " TAM BIET!!!!!" << endl;
			exit(0);
		}
	}
}


void Car::inputArr(int* a, int n) {
	cout << "NHAP MA SO CA NHAN, MANG 08 SO" << '\n';
	for (int i = 0; i < n; i++) {
		string str = "";
		do {
			cout << "So Thu " << i + 1 << ": ";
			cin >> str;
		} while (!isNumber(str));
		//(*(a + i)) = sscanf(str.c_str(), "%d");
		istringstream(str) >> (*(a + i));
	}
}

//cai dat mscn 

void Car::load() {

	ifstream  inFile("AMS04.dat", ios::in | ios::binary);

	//kiểm tra file có trống ko
	// nếu trống thì yc nhập dữ liệu
	inFile.seekg(0, ios::end);
	if (inFile.tellg() == 0)
	{
		inFile.close();

		cout << "CHUA CAI MSCN" << endl;
		cout << "VUI LONG CAI DAT MSCN GOM 8 CHU SO:" << endl;

		ofstream outFile("AMS04.dat", ios::out | ios::binary);
		this->inputArr(this->arrAuto, 8);
		outFile.write((char*)&this->arrAuto, sizeof(this->arrAuto));
		outFile.close();
	}
	readFileArr();
}

void Car::resetPass() {

	Car C;
	int number;
	do
	{
		cout << "BAN CO MUON CAI DAT LAI MSCN KHONG ?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. NO" << endl;
		cin >> number;
		ifNotInteger();
		system("cls");
		cout << "Ban da chon : " << number << endl;
		switch (number)
		{
		case 1: {
			ofstream outFile("AMS04.dat", ios::out | ios::binary);
			this->inputArr(this->arrAuto, 8);
			outFile.write((char*)&this->arrAuto, sizeof(this->arrAuto));
			outFile.close();
			cout << "DA CAI LAI MSCN ";
			break;
		}
		case 2:
			cout << "MA SO CA NHAN CUA BAN VAN DUOC GIU NGUYEN!!!" << endl;
			break;
		default:
			cout << "YEU CAU BAN NHAP 1 OR 2" << endl;
			break;
		}
	} while (number != 2);



}


void Car::readFileArr() {
	Car c;
	ifstream  inFile("AMS04.dat", ios::in | ios::binary);
	inFile.read((char*)&c, sizeof(Car));
	inFile.close();
	this->inputArr(arr, 8);
	cout << "MANG NHAP VAO TRUOC KHI SAP XEP: ";
	this->outArr(arr, 8);
	this->bubbleSort(arr, 8);
	cout << "MANG NHAP VAO SAU KHI SAP XEP: ";
	this->outArr(arr, 8);
	cout << "Ma so ca nhan truoc khi sap xep: ";
	this->outArr(c.arrAuto, 8);
	this->selectionSort(c.arrAuto, 8);
	cout << "Ma so ca nhan sau khi sap xep: ";
	this->outArr(c.arrAuto, 8);
	this->checkpass(c.arrAuto);
	this->resetPass();
	this->setSafeDistance();
	this->gearBoxMenu(isDigit);
}

// xuat manng
void Car::outArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(a + i) << " ";;
	}
	cout << endl;
}
void Car::swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
// sap xep mang voi BubbleSort
void Car::bubbleSort(int* a, int n) {
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (*(a + i) > *(a + j)) {
				swap(*(a + j), *(a + i));
				count++;
			}
		}
	}
	cout << "BubbleSort: " << count << endl;
}
//  sap xep mang voi Selection Sort
void Car::selectionSort(int* a, int n) {
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (*(a + j) < *(a + min)) {
				min = j;
			}
		}
		swap(*(a + min), *(a + i));
		count++;
	}
	cout << "Selection Sort: " << count << endl;

}
//cat dat khoang cach an toan
void Car::setSafeDistance() {
	int set;
	do
	{
		cout << "BAN CO MUON CAI LAI KHOANG CACH AN TOAN THEO TOC DO KHONG ?" << "\n";
		cout << "1. Yes" << '\n';
		cout << "2. No" << '\n';
		cin >> set;
		ifNotInteger();
		system("cls");
		cout << "Ban da chon : " << set << endl;
		switch (set)
		{

		case 1: {
			cout << "CAI DAT KHOANG CACH AN TOAN VOI 3 MUC VAN TOC: " << endl;
			//ghi du lieu vao file
			for (int i = 0; i < 3; i++) {
				cin >> this->safeDistance[i];
			}
			ofstream outputfile("SafeDistance.dat", ios::out | ios::binary);
			outputfile.write((char*)&this->safeDistance, sizeof(this->safeDistance));
			outputfile.close();
			this->bubbleSort(this->safeDistance, 3);
			break;
		}
		case 2: {
			cout << "KHOANG CACH AN TOAN THEO TOC DO VAN DUOC GIU NGUYEN !!!" << endl;
			ifstream inFile("SafeDistance.dat", ios::out | ios::binary);
			inFile.read((char*)&this->safeDistance, sizeof(this->safeDistance));

			break;
		}
		default:
			cout << "YEU CAU BAN NHAP 1 OR 2" << endl;
			break;
		}
	} while (set != 2);


}
// canh bao toc do
void Car::speedWaring(int vtoc2) {
	if (vtoc2 < safeDistance[0])
	{
		cout << "!!!!CHU Y PHAI GIU KHOANG CACH TOI THIEU 20M!!!!" << '\n';
	}
	if (vtoc2 >= safeDistance[0] && vtoc2 < safeDistance[1])
	{
		cout << "!!!!CHU Y KHOANG CACH AN TOAN TOI THIEU LA 55M!!!!" << '\n';
	}
	if (vtoc2 >= safeDistance[1] && vtoc2 < safeDistance[2])
	{
		cout << "!!!!CHU Y KHOANG CACH AN TOAN TOI THIEU LA 70M!!!!" << '\n';
	}
	if (vtoc2 >= safeDistance[2])
	{
		cout << "!!!!CHU Y KHOANG CACH AN TOAN TOI THIEU LA 100M!!!!" << '\n';
	}
};

// dieu khien toc do
void Car::controlSpeed(int input, int vtoc)
{
	switch (input)
	{
	case 1:
		speed += 5;
		speedWaring(speed);
		break;
	case 2:
		cout << "GIAM TOC" << endl;
		speed -= 5;
		speedWaring(speed);
		break;
	case 3:
		cout << "PHANH" << endl;
		speed = 0;
		break;
	case 4:
		cout << "TRO VE" << endl;
		break;

	default:
		cout << "NHAP SAI CU PHAP" << endl;
		break;
	}
}

// kiem tra toc do trc khi ve so 
void Car::checkSpeed(int input)
{
	int userInput4;

	switch (input)
	{
	case 1:
		// kiểm tra tốc độ trước khi về số P
		if (speed == 0)
		{
			cout << "DA VE SO P." << '\n';
			cout << "CHU Y DUNG PHANH TAY DE DAM BAO AN TOAN" << '\n';
		}
		else
		{
			cout << "HAY CHAC CHAN XE DA DUNG, VA VAN TOC LA 0 KM/H" << endl;
		}
		// break thoat khoi vong lap coi nhu la thoat khoi ham luon
		break;
	case 2:
		if (speed != 0 && isDigit != 2)
		{
			cout << "KIEM TRA LAI VAN TOC, XE VAN DANG CHAY" << endl;
			return;
		}
		if (speed <= 0)
		{
			speed = 7;
		}
		isDigit = 2;
		do
		{
			cout << "DA VE SO R." << '\n';
			cout << "------ TOC DO HIEN TAI:" << speed << "km/h" << '\n';
			if (speed > 20)
			{
				cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
			}
			cout << "MOI LUA CHON: " << '\n';
			cout << "1: TANG TOC" << '\n';
			cout << "2: GIAM TOC" << '\n';
			cout << "3: PHANH" << '\n';
			cout << "4: TRO VE" << '\n';
			cin >> userInput4;
			ifNotInteger();
			system("cls");
			cout << "USE CHON: " << userInput4 << endl;
			controlSpeed(userInput4, speed);

		} while (userInput4 != 4);
		break;
	case 3:
		// kiểm tra tốc độ trước khi về số N
		if (speed <= 0)
		{
			cout << "DA VE SO N." << '\n';
			cout << "CHU Y DUNG PHANH TAY DE DAM BAO AN TOAN" << '\n';
		}
		else
		{
			cout << "HAY CHAC CHAN XE DA DUNG, VA VAN TOC LA 0 KM/H" << endl;
		}
		break;
	case 4:
		// kiểm tra tốc độ = 0, để được phép vào số R hoặc D
		if (isDigit != 4 && speed != 0)
		{
			cout << "KIEM TRA LAI VAN TOC, XE VAN DANG CHAY" << endl;
			return;
		}
		// khi vận tốc bằng 0 giá trị mặc định khi vào số bằng 7
		if (speed <= 0)
		{
			speed = 7;
		}

		isDigit = 4;
		do
		{
			cout << "DA VE SO D." << '\n';
			cout << "------ TOC DO HIEN TAI:" << speed << "km/h" << '\n';
			if (speed > 60)
			{
				cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
			}
			cout << "MOI LUA CHON: " << '\n';
			cout << "1: TANG TOC" << '\n';
			cout << "2: GIAM TOC" << '\n';
			cout << "3: PHANH" << '\n';
			cout << "4: TRO VE" << '\n';
			cin >> userInput4;
			ifNotInteger();
			system("cls");
			cout << "USE CHON: " << userInput4 << endl;
			controlSpeed(userInput4, speed);
		} while (userInput4 != 4);
		break;
	case 5:
		cout << " XE DA TAT MAY!!!" << endl;
		cout << " GOOD BYE" << endl;
		break;
	default:
		cout << " KHONG CO DU LIEU" << endl;
		break;
	}
}
// Menu
void Car::gearBoxMenu(int input1)
{
	do
	{
		cout << "Xin moi lua chon" << endl;
		cout << "1. P" << endl;
		cout << "2. R" << endl;
		cout << "3. N" << endl;
		cout << "4. D" << endl;
		cout << "5. Power OFF" << endl;
		cin >> input1;
		ifNotInteger();
		system("cls");
		cout << "Ban da chon so " << input1 << endl;
		checkSpeed(input1);

	} while (input1 != 5);
}