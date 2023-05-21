#include"include.h"
#include"Admin.h"
#include"strukt.h"
#include"other.h"

Admin::Admin() {  
	ifstream in_login("adminlog.txt", ios::app);
	ifstream in_password("adminpassword.txt", ios::app);
	int i = 0;
	while (getline(in_login, login) && getline(in_password, pass)) {
		logins.push_back(login);
		passwords.push_back(pass);
	}
	in_login.close();
	in_password.close();
}
Admin::~Admin() {};
int Admin::admin_login(string& login, string& password) {
	for (int i = 0; i < logins.size(); i++) {
		if ((logins[i] == login) && (passwords[i] == password)) {
			return 1;
		}
	}
	return 0;
}

void Admin::admin_bann()
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

	if (arr.empty()) {

		cout << "\nНет пользователей\n";
	}
	else {

		cout << "\n---------------------------\n";
		cout << "|   ЛОГИН    |   ПАРОЛЬ   |\n";
		for (int i = 0; i < arr.size(); i++) {
			printf("|%d%*s|%*s|\n", i + 1, 11, arr[i].login.c_str(), 12, arr[i].pass.c_str());
		}

		cout << "Какой аккаунт Вы хотите заблокировать\n";
		cin >> choise;

		arr1 = arr[choise - 1];
		arr.erase(arr.begin() + (choise - 1));

		ofstream onl("userlogin.txt");
		ofstream onp("userpass.txt");

		for (int i = 0; i < arr.size(); i++) {
			onl << endl << arr[i].login;
			onp << endl << arr[i].pass;
		}
		onl.close();
		onp.close();

		ofstream onb("baned.txt", ios_base::app);

		onb << endl << arr1.login;

		onb.close();
		
	}

	

}

void Admin::admin_delete()
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

	if (arr.empty()) {

		cout << "\nНет пользователей\n";
	}
	else {

		cout << "\n---------------------------\n";
		cout << "|   ЛОГИН    |   ПАРОЛЬ   |\n";
		for (int i = 0; i < arr.size(); i++) {
			printf("|%d%*s|%*s|\n", i + 1, 11, arr[i].login.c_str(), 12, arr[i].pass.c_str());
		}

		cout << "Какой аккаунт Вы хотите удалить\n";
		cin >> choise;

		arr.erase(arr.begin() + (choise - 1));

		ofstream onl("userlogin.txt");
		ofstream onp("userpass.txt");

		for (int i = 0; i < arr.size(); i++) {
			onl << endl << arr[i].login;
			onp << endl << arr[i].pass;
		}

		cout << "\nАккаунт успешно удален!\n";

		onl.close();
		onp.close();
	}
}

void Admin::admin_delet_tic()
{

	ifstream in("info.txt", ios::app);
	vector<Info>inf;
	Info arr; int choise;
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
			printf("|%*d%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|%*d|\n", 3, i + 1, 14, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets, 11, inf[i].buy_tic);
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
		cout << "Какой рейс Вы хотите удалить?\n";
		cin >> choise;
		inf.erase(inf.begin() + choise - 1);
		ofstream on("info.txt");
		for (int i = 0; i < inf.size(); i++) {
			on << endl << inf[i].number << " " << inf[i].type << " " << inf[i].in << " " << inf[i].date << " " << inf[i].time_on << " " << inf[i].time_in << " " << inf[i].coast << " " << inf[i].tickets << " " << inf[i].buy_tic;
		}
		on.close();
	}

}

void Admin::ban_tickets()
{
	ifstream in("info.txt", ios::app);
	vector<Info>inf;
	Info arr; int choise;
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
			printf("|%*d%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|%*d|\n",3,i+1, 14, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets, 11, inf[i].buy_tic);
		}
		cout << "________________________________________________________________________________________________________________________________________________________\n";
		cout << "Продажу какого Вы хотите заблокировать?\n";
		cin >> choise;
		arr.number = inf[choise - 1].number;
		ofstream on("ban_tic.txt", ios::app);
		on << endl << arr.number;
		on.close();
	}
}

void Admin::watch_akks()
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

	if (arr.empty()) {

		cout << "\nНет пользователей\n";
	}
	else {

		cout << "\n---------------------------\n";
		cout << "|   ЛОГИН    |   ПАРОЛЬ   |\n";
		for (int i = 0; i < arr.size(); i++) {
			printf("|%d%*s|%*s|\n", i + 1, 11, arr[i].login.c_str(), 12, arr[i].pass.c_str());
		}
	}
}





