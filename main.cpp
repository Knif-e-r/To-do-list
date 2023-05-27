#include "functions.h"

int main() {
	bool exit_program = false;
	while (!exit_program) {

		system("cls");
		start_menu();

		std::ofstream list_of_notes;
		list_of_notes.open("Notes.txt", std::ofstream::app);
		if (!list_of_notes.is_open())
			std::cout << "(Open file error! File doesn't exist!)\n";
		list_of_notes.close();

		std::string num_of_act;
		getline(std::cin, num_of_act);

		if (num_of_act.size() > 1)
			num_of_act = '0';

		switch (num_of_act[0]) {
		case SEE:
			system("cls");
			print_info(num_of_act[0]);
			see_note();
			system("pause");
			break;

		case FIND:
			system("cls");
			print_info(num_of_act[0]);
			find_note();
			system("pause");
			break;

		case ADD:
			system("cls");
			print_info(num_of_act[0]);
			add_note();
			break;

		case DELETE:
			system("cls");
			print_info(num_of_act[0]);
			delete_note();
			break;

		case CHANGE:
			system("cls");
			print_info(num_of_act[0]);
			change_note();
			system("pause");
			break;

		case CLEAR:
			if (sure()) {
				system("cls");
				print_info(num_of_act[0]);
				clear_to_do_list();
			};
			system("pause");
			break;

		case EXIT:
			if (sure()) {
				system("cls");
				exit_program = true;
			}
			break;

		default:
			system("cls");
			print_info(num_of_act[0]);
			system("pause");
			break;
		};
	}

	return 0;
}
