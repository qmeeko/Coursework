#include"include.h"
#include"other.h"
#include "Admin.h"
#include"User.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Admin admin; User user;
    int ptr = 0; char r;
    while (true) {

        switch (ptr) {

        case 0:
            cout << "->1 Вход\n 2 Регистрация\n 3 Выход" << endl;
            break;
        case 1:
            cout << " 1 Вход\n->2 Регистрация\n 3 Выход" << endl;
            break;
        case 2:
            cout << " 1 Вход\n 2 Регистрация\n->3 Выход\n" << endl;
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
                int i;
                i = log_in();
                system("cls");
                switch (i) {
                case 1:
                wheel_animation();
                system("cls");
               admin_switch1();
                break;
                case 2:
                wheel_animation();
                system("cls");
                user_switch();
                break;
                }
                break;
            case 1:
                sign_up();
                system("cls");
                wheel_animation();
                break;
            case 2:
                return 0;
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