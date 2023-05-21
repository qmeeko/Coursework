#include "other.h"
#include"include.h"
#include"strukt.h"
#include"Admin.h"
#include"User.h"


void whatch_info()
{
	ifstream in("info.txt", ios::app);
	vector<Info>inf;
	Info arr;
	while (in >> arr.number) {
		in >> arr.type;
		in >> arr.in;
		in >> arr.date;
		in >> arr.time_on;
		in >> arr.time_in;
		in >> arr.coast;
		in >> arr.tickets;
		in >> arr.buy_tic;
		inf.push_back(arr);
	}
	in.close();
	if (inf.empty()) {
		cout << "\n Файл пуст!\n";
	}
	else {
		loading_animation();
		cout << "________________________________________________________________________________________________________________________________________________________\n";
		cout << "|     Номер       |    Тип    |    Конечная точка    |     Дата     |  Время отправления |  Время прибытия |  Стоимость  |  Кол-во билетов |  Продано  |\n";
		for (int i = 0; i < inf.size(); i++) {
			printf("|%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|%*d|\n", 17, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets, 11, inf[i].buy_tic);
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
	}
}

bool switch_control() {
	system("cls");
	Admin admin;
	int ptr = 0; char r;
	while (true) {
		switch (ptr) {

		case 0:
			cout << "->1) Удалить рейс\n 2) Добавить рейсы\n 3) Выход" << endl;
			break;
		case 1:
			cout << " 1) Удалить рейс\n->2) Добавить рейсы\n 3) Выход" << endl;
			break;
		case 2:
			cout << " 1) Удалить рейс\n 2) Добавить рейсы\n->3) Выход" << endl;
			break;
		}
		r = _getch();
		system("cls");
		switch (r)
		{
		case 119:
			ptr--;
			break;
		case 115:
			ptr++;
			break;
		case 13:
			system("cls");
			switch (ptr)
			{
			case 0:
				admin.admin_delet_tic();
				system("pause");
				break;
			case 1:
				add_info();
				system("pause");
				break;
			case 2:
				return false;
				break;
			}
			system("cls");
			break;
		}
		if (ptr == -1) {
			ptr = 2;
		}
		else if (ptr == 3) {
			ptr = 0;
		}
	}
}






void add_info(){ 
	bool success = false;
	ofstream on("info.txt", ios::app);
	Info arr; char a;
	cout << "\nВведите номер автобуса\n";
	do {
		success = false;
		cin >> arr.number;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введен номер автобуса!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите тип поездки\n";
	do {
		success = false;
		cin >> arr.type;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введен тип автобуса!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите конечную точку поездки\n"; 
	do {
		success = false;
		cin >> arr.in;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введена конечная точка поездки!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите дату поездки\n";
	do {
		success = false;
		cin >> arr.date;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введена дата поездки!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите время отправления\n";
	do {
		success = false;
		cin >> arr.time_on;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введено время отправления!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите время прибытия\n";
	do {
		success = false;
		cin >> arr.time_in;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введено время прибытия!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите стоимость билета\n";
	do {
		success = false;
		cin >> arr.coast;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введена цена билета!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите количество билетов\n";
	do {
		success = false;
		cin >> arr.tickets;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введена количество билетов!" << endl;
		}
		else success = true;
	} while (success == false);
	cout << "\nВведите кол-во проданных билетов\n";
	do {
		success = false;
		cin >> arr.buy_tic;
		if (cin.fail()) {
			cin.clear();
			cin.seekg(cin.eof());

			cout << "Неправильно введена количество проданных билетов!" << endl;
		}
		else success = true;
	} while (success == false);

	on << endl << arr.number << " " << arr.type << " " << arr.in << " " << arr.date << " " << arr.time_on << " " << arr.time_in << " " << arr.coast << " " << arr.tickets << " " << arr.buy_tic;

	on.close();


}

void sign_up()
{
	ifstream inl("userlogin.txt", ios_base::app);
	ifstream inp("userpass.txt", ios_base::app);
	vector<users>arr;
	users arr1;
	int choise;
	while (inl >> arr1.login && inp >> arr1.pass) {
		arr.push_back(arr1);
	}

	inl.close();
	inp.close();
	bool flag;
	do {
	    flag = true;
		cout << "\nВведите логин\n";
		cin >> arr1.login;
		for (int i = 0; i < arr.size(); i++) {
			if (arr1.login == arr[i].login) {
				cout << "Такой логин уже существует!\n";
				flag = false;
				_getch();
				system("cls");
			}
		}
	} while (!flag);
	cout << "\nВведите пароль\n";
	cin >> arr1.pass;
	ofstream onl("userlogin.txt", ios_base::app);
	ofstream onp("userpass.txt", ios_base::app);
	onl << endl << arr1.login;
	onp << endl << arr1.pass;

	onl.close();
	onp.close();
	cout << "\nАккаунт успешно добавлен\n";
}

void found_location()
{
	ifstream in("info.txt", ios::app);
	vector<Info>inf;
	Info arr;
	while (in >> arr.number) {
		in >> arr.type;
		in >> arr.in;
		in >> arr.date;
		in >> arr.time_on;
		in >> arr.time_in;
		in >> arr.coast;
		in >> arr.tickets;
		in >> arr.buy_tic;
		inf.push_back(arr);
	}
	in.close();
	if (inf.empty()) {
		cout << "\n Файл пуст!\n";
	}
	else {
		string location;
		cout << "Введите конечную точку\n";
		cin >> location;
		loading_animation();
		bool a = false;
		for (int i = 0; i < inf.size(); i++) {
			if (location == inf[i].in) {
				cout << "________________________________________________________________________________________________________________________________________________________\n";
				cout << "|     Номер       |    Тип    |    Конечная точка    |     Дата     |  Время отправления |  Время прибытия |  Стоимость  |  Кол-во билетов |  Продано  |\n";
				
					printf("|%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|%*d|\n", 17, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets, 11, inf[i].buy_tic);
				
				cout << "________________________________________________________________________________________________________________________________________________________\n";
				a = true;
			}
		}
		if (!a) {
			cout << "\nНичего не найдено!\n";
		}
	}


}

void loading_animation()
{
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\tloading";
	cout << "\n\t\t\t\t\t\t[%    ]";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\tloading";
	cout << "\n\t\t\t\t\t\t[%%   ]";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\tloading";
	cout << "\n\t\t\t\t\t\t[%%%  ]";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\tloading";
	cout << "\n\t\t\t\t\t\t[%%%% ]";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\tloading";
	cout << "\n\t\t\t\t\t\t[%%%%%]";
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\tREADY";
	Sleep(1000);
	system("cls");

}

void sort_by_location()
{
	ifstream in("info.txt", ios::app);
	vector<Info>inf;
	Info arr;
	while (in >> arr.number) {
		in >> arr.type;
		in >> arr.in;
		in >> arr.date;
		in >> arr.time_on;
		in >> arr.time_in;
		in >> arr.coast;
		in >> arr.tickets;
		in >> arr.buy_tic;
		inf.push_back(arr);
	}
	in.close();
	if (inf.empty()) {
		cout << "\n Файл пуст!\n";
	}
	else {
		loading_animation();
		for (int i = 0; i < inf.size() - 1; ++i) {
			for (int j = 0; j < inf.size() - i - 1; ++j) {
				if (inf[j].in > inf[j + 1].in) {
					swap(inf[j], inf[j + 1]);
				}
			}
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
		cout << "|     Номер       |    Тип    |    Конечная точка    |     Дата     |  Время отправления |  Время прибытия |  Стоимость  |  Кол-во билетов |  Продано  |\n";
		for (int i = 0; i < inf.size(); i++) {
			printf("|%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|%*d|\n", 17, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets, 11, inf[i].buy_tic);
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
	}


}

void sort_by_tickets()
{
	ifstream in("info.txt", ios::app);
	vector<Info>inf;
	Info arr;
	while (in >> arr.number) {
		in >> arr.type;
		in >> arr.in;
		in >> arr.date;
		in >> arr.time_on;
		in >> arr.time_in;
		in >> arr.coast;
		in >> arr.tickets;
		in >> arr.buy_tic;
		inf.push_back(arr);
	}
	in.close();
	if (inf.empty()) {
		cout << "\n Файл пуст!\n";
	}
	else {
		loading_animation();
		for (int i = 0; i < inf.size() - 1; ++i) {
			for (int j = 0; j < inf.size() - i - 1; ++j) {
				if (inf[j].buy_tic < inf[j + 1].buy_tic) {
					swap(inf[j], inf[j + 1]);
				}
			}
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
		cout << "|     Номер       |    Тип    |    Конечная точка    |     Дата     |  Время отправления |  Время прибытия |  Стоимость  |  Кол-во билетов |  Продано  |\n";
		for (int i = 0; i < inf.size(); i++) {
			printf("|%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|%*d|\n", 17, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets, 11, inf[i].buy_tic);
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
	}


}

void sort_by_date()
{
	ifstream in("info.txt", ios::app);
	vector<Info>inf;
	Info arr;
	while (in >> arr.number) {
		in >> arr.type;
		in >> arr.in;
		in >> arr.date;
		in >> arr.time_on;
		in >> arr.time_in;
		in >> arr.coast;
		in >> arr.tickets;
		in >> arr.buy_tic;
		inf.push_back(arr);
	}
	in.close();
	if (inf.empty()) {
		cout << "\n Файл пуст!\n";
	}
	else {
		loading_animation();
		for (int i = 0; i < inf.size() - 1; ++i) {
			for (int j = 0; j < inf.size() - i - 1; ++j) {
				if (inf[j].date > inf[j + 1].date) {
					swap(inf[j], inf[j + 1]);
				}
			}
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
		cout << "|     Номер       |    Тип    |    Конечная точка    |     Дата     |  Время отправления |  Время прибытия |  Стоимость  |  Кол-во билетов |  Продано  |\n";
		for (int i = 0; i < inf.size(); i++) {
			printf("|%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|%*d|\n", 17, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets, 11, inf[i].buy_tic);
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
	}


}

void wheel_animation()
{
	for (int i = 0; i < 2; i++) {
		system("cls");
		cout << "\n\n\n\n\t\t\t\t\t **** ";
		Sleep(500);
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\t*\n\t\t\t\t\t*\n\t\t\t\t\t*";
		Sleep(500);
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t **** ";
		Sleep(500);
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\t     *\n\t\t\t\t\t     *\n\t\t\t\t\t     *";
		Sleep(500);

	}
}

int baned_log(string& login) {
	string a;
	vector<string>arr;
	ifstream in("baned.txt", ios_base::app);
	while (in >> a) {
		arr.push_back(a);
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == login) {
			in.close();
			return 1;

		}
	}
	in.close();
return 0;
}

bool admin_switch1(){
	Admin admin;
	int ptr = 0; char r;
	while (true) {
		
		switch (ptr) {

		case 0:
			cout << "->1) Управление данными о рейсах\n 2) Заблокировать покупку билетов\n 3) Отсортировать рейсы\n 4) Информация о конкретном рейсе\n 5) Все рейсы\n 6) Удалить пользователя\n 7) Заблокировать пользователя\n 8) Выход" << endl;
			break;
		case 1:
			cout << " 1) Управление данными о рейсах\n->2) Заблокировать покупку билетов\n 3) Отсортировать рейсы\n 4) Информация о конкретном рейсе\n 5) Все рейсы\n 6) Удалить пользователя\n 7) Заблокировать пользователя\n 8) Выход" << endl;
			break;
		case 2:
			cout << " 1) Управление данными о рейсах\n 2) Заблокировать покупку билетов\n->3) Отсортировать рейсы\n 4) Информация о конкретном рейсе\n 5) Все рейсы\n 6) Удалить пользователя\n 7) Заблокировать пользователя\n 8) Выход" << endl;
			break;
		case 3:
			cout << " 1) Управление данными о рейсах\n 2) Заблокировать покупку билетов\n 3) Отсортировать рейсы\n->4) Информация о конкретном рейсе\n 5) Все рейсы\n 6) Удалить пользователя\n 7) Заблокировать пользователя\n 8) Выход" << endl;
			break;
		case 4:
			cout << " 1) Управление данными о рейсах\n 2) Заблокировать покупку билетов\n 3) Отсортировать рейсы\n 4) Информация о конкретном рейсе\n->5) Все рейсы\n 6) Удалить пользователя\n 7) Заблокировать пользователя\n 8) Выход" << endl;
			break;
		case 5:
			cout << " 1) Управление данными о рейсах\n 2) Заблокировать покупку билетов\n 3) Отсортировать рейсы\n 4) Информация о конкретном рейсе\n 5) Все рейсы\n->6) Удалить пользователя\n 7) Заблокировать пользователя\n 8) Выход" << endl;
			break;
		case 6:
			cout << " 1) Управление данными о рейсах\n 2) Заблокировать покупку билетов\n 3) Отсортировать рейсы\n 4) Информация о конкретном рейсе\n 5) Все рейсы\n 6) Удалить пользователя\n->7) Заблокировать пользователя\n 8) Выход" << endl;
			break;
		case 7 :
			cout << " 1) Управление данными о рейсах\n 2) Заблокировать покупку билетов\n 3) Отсортировать рейсы\n 4) Информация о конкретном рейсе\n 5) Все рейсы\n 6) Удалить пользователя\n 7) Заблокировать пользователя\n->8) Выход" << endl;
			break;
		}
		r = _getch();
		system("cls");
		switch (r)
		{
		case 119:
			ptr--;
			break;
		case 115:
			ptr++;
			break;
		case 13:
			system("cls");
			switch (ptr)
			{
			case 0:
				switch_control();
				break;
			case 1:
				admin.ban_tickets();
				system("pause");
				break;
			case 2:
				switch_sort();
				system("pause");
				break;
			case 3:
				found_location();
				system("pause");
				break;
			case 4:
				whatch_info();
				system("pause");
				break;
			case 5:
				admin.admin_delete();
				system("pause");
				break;
			case 6:
				admin.admin_bann();
				system("pause");
				break;
			case 7:
				return false;
				break;
			}
			system("cls");
			break;
		}
		if (ptr == -1) {
			ptr = 7;
		}
		else if (ptr == 8) {
			ptr = 0;
		}
	}
	
}

bool user_switch() {

	User user;

	int ptr = 0; char r;
	while (true) {

		switch (ptr) {

		case 0:
			cout << "->1) Купить билет\n 2) Отсортировать рейсы\n 3) Информация о конкретном рейсе\n 4) Все рейсы\n 5) Выход" << endl;
			break;
		case 1:
			cout << " 1) Купить билет\n->2) Отсортировать рейсы\n 3) Информация о конкретном рейсе\n 4) Все рейсы\n 5) Выход" << endl;
			break;
		case 2:
			cout << " 1) Купить билет\n 2) Отсортировать рейсы\n->3) Информация о конкретном рейсе\n 4) Все рейсы\n 5) Выход" << endl;
			break;
		case 3:
			cout << " 1) Купить билет\n 2) Отсортировать рейсы\n 3) Информация о конкретном рейсе\n->4) Все рейсы\n 5) Выход" << endl;
			break;
		case 4:
			cout << " 1) Купить билет\n 2) Отсортировать рейсы\n 3) Информация о конкретном рейсе\n 4) Все рейсы\n->5) Выход" << endl;
			break;
		}
		r = _getch();
		system("cls");
		switch (r)
		{
		case 119:
			ptr--;
			break;
		case 115:
			ptr++;
			break;
		case 13:
			system("cls");
			switch (ptr)
			{
			case 0:
				user.buy_tickets();
				system("pause");
				break;
			case 1:
				switch_sort();
				break;
			case 2:
				found_location();
				system("pause");
				break;
			case 3:
				whatch_info();
				system("pause");
				break;
			case 4:
				return false;
				break;
			}
			system("cls");
			break;
		}
		if (ptr == -1) {
			ptr = 4;
		}
		else if (ptr == 5) {
			ptr = 0;
		}
	}
}

bool switch_sort() {
	system("cls");
	int ptr = 0; char r;
	while (true) {
		switch (ptr) {

		case 0:
			cout << "->1) Сортировка по пункту назначения\n 2) Сортировка по оставшимся билетам\n 3) Сортировка по дате отправления\n 4) Выход" << endl;
			break;
		case 1:
			cout << " 1) Сортировка по пункту назначения\n->2) Сортировка по оставшимся билетам\n 3) Сортировка по дате отправления\n 4) Выход" << endl;
			break;
		case 2:
			cout << " 1) Сортировка по пункту назначения\n 2) Сортировка по оставшимся билетам\n->3) Сортировка по дате отправления\n 4) Выход" << endl;
			break;
		case 3:
			cout << " 1) Сортировка по пункту назначения\n 2) Сортировка по оставшимся билетам\n 3) Сортировка по дате отправления\n->4) Выход" << endl;
			break;
		
		}
		r = _getch();
		system("cls");
		switch (r)
		{
		case 119:
			ptr--;
			break;
		case 115:
			ptr++;
			break;
		case 13:
			system("cls");
			switch (ptr)
			{
			case 0:
				sort_by_location();
				system("pause");
				break;
			case 1:
				sort_by_tickets();
				system("pause");
				break;
			case 2:
				sort_by_date();
				system("pause");
				break;
			case 3:
				return false;
				break;
			}
			system("cls");
			break;
		}
		if (ptr == -1) {
			ptr = 3;
		}
		else if (ptr == 4) {
			ptr = 0;
		}
	}
}


int log_in() {
	string pass, login; Admin admin; User user;
	cout << "\n\n\n\t\t\t\t\tлогин: ";
	cin >> login;
	cout << "\n\n\n\t\t\t\t\tпароль: ";
	cin >> pass;
	if (admin.admin_login(login, pass) == 1) {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t*************************************\n\t\t\t\t\t*    ВЫ ВОШЛИ КАК АМИНИСТРАТОР!      *\n\t\t\t\t\t*************************************";
		_getch();
		return 1;
	}
	if (user.user_login(login, pass) == 1) {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t*************************************\n\t\t\t\t\t*    ВЫ ВОШЛИ КАК ПОЛЬЗОВАТЕЛЬ!     *\n\t\t\t\t\t*************************************";
		_getch();
		return 2;
	}
	if (baned_log(login) == 1) {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t*************************************\n\t\t\t\t\t*    ВЫ БЫЛИ ЗАБЛОКИРОВАНЫ!     *\n\t\t\t\t\t*************************************";
		_getch();
		return 3;
	}
	system("cls");
	cout << "\a\n\n\n\n\n\n\t\t\t\t\t***************************\n\t\t\t\t\t*    !!ОШИБКА ВХОДА!!       *\n\t\t\t\t\t***************************";
	_getch();
	system("cls");
	return 0;
}
