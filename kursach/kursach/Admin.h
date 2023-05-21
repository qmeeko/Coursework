#pragma once
#include"include.h"
class Admin
{
private:
	vector<string>logins;
	vector<string>passwords;
	string login;
	string pass;
public:
	Admin();
	~Admin();
	int admin_login(string& login, string& password);
	void admin_bann();
	void admin_delete();
	void admin_delet_tic();
	void ban_tickets();
	void watch_akks();
};

