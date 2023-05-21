#include "User.h"
#include"strukt.h"

int User::user_login(string& login, string& password)
{
	string current_login, current_password;
	ifstream inl("userlogin.txt", ios_base::app);
	ifstream inp("userpass.txt", ios_base::app);
	while (!inl.eof()) {
		inl >> current_login;
		inp >> current_password;
		if (current_login == login && current_password == password) {
			return 1;
			inl.close();
			inp.close();
		}
	}
	return 0;
	inl.close();
	inp.close();
}

void User::buy_tickets()
{
	ifstream in("info.txt", ios::app);
	ifstream inn("ban_tic.txt", ios::app);
	vector<Info>inf; vector<int> arr1;
	Info arr; int choise,k,count=0;
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
	while (inn >> arr.number) {
		arr1.push_back(arr.number);
	}
	inn.close();
	if (inf.empty()) {
		cout << "\nПока нет рейсов!\n";
	}
	else {
		bool flag;
		cout << "Доступные рейсы\n";
		cout << "\n____________________________________________________________________________________________________________________________________________\n";
		cout << "|     Номер       |    Тип    |    Конечная точка    |     Дата     |  Время отправления |  Время прибытия |  Стоимость  |  Кол-во билетов |\n";
		for (int i = 0; i < inf.size(); i++) {
			flag = true;
			for (int j = 0; j < arr1.size();j++) {
				if (inf[i].number == arr1[j]) {
					flag = false;
					break;
				}
			}
			if (inf[i].tickets - inf[i].buy_tic == 0 || !flag) {
				continue;
			}else
			printf("|%*d%*d|%*s|%*s|%*s|%*s|%*s|%*f|%*d|\n",3,i+1, 14, inf[i].number, 11, inf[i].type.c_str(), 22, inf[i].in.c_str(), 14, inf[i].date.c_str(), 20, inf[i].time_on.c_str(), 17, inf[i].time_in.c_str(), 13, inf[i].coast, 17, inf[i].tickets-inf[i].buy_tic);
			count++;
		}
		cout << "____________________________________________________________________________________________________________________________________________\n";
		if (count == 0) {
			system("cls");
			cout << "\nПока нет рейсов!\n";
			return;
		}
		else
		cout << "\nВыберите рейс для покупки белетов\n";
		cin >> choise;
		cout << "\nВыберите кол-во белетов белетов\n";
		cin >> k;
		inf[choise - 1].buy_tic += k;
		ofstream on("info.txt");
		for (int i = 0;i < inf.size(); i++) {
			on << endl << inf[i].number << " " << inf[i].type << " " << inf[i].in << " " << inf[i].date << " " << inf[i].time_on << " " << inf[i].time_in << " " << inf[i].coast << " " << inf[i].tickets << " " << inf[i].buy_tic;
		}
		cout << "\nУспешная покупка!\n";
	}

}
