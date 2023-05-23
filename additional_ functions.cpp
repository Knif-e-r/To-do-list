#include "functions.h"

using namespace std;


void start_menu() {
	cout << "\n\n_____________________________\n"
		<< "\n\tMY TO-DO LIST\n"
		<< "_____________________________\n"
		<< "\nWhat do you want to do?\n\n"
		<< "1) See my notes\n"
		<< "2) Find note\n"
		<< "3) Write new note\n"
		<< "4) Delete note\n"
		<< "5) Change note\n"
		<< "6) Clear my to-do list\n"
		<< "7) Exit\n"
		<< "\nPlease, choose a number of action: ";
}


bool sure() {
	cout << "\n\n_____________________________\n"
		<< "\n\tARE YOU SURE?\n"
		<< "_____________________________\n\n"
		<< "0) Cancel\n"
		<< "1) Ok\n";

	bool just_for_cycle = true;

	while (just_for_cycle) {

		string action; getline(cin, action);
		if (action.size() > 1 || action.size() == 0)
			action = "9";
		if (action[0] == OK) {
			return true;
		}
		else if (action[0] == CANCEL) {
			return false;
		}
		else {
			cout << "There is no action with this number.\nPlease, try again.\n";
			system("pause");
			system("cls");
			cout << "\n\n_____________________________\n"
				<< "\n\tARE YOU SURE?\n"
				<< "_____________________________\n\n"
				<< "0) Cancel\n"
				<< "1) Ok\n";
		}
	}
}


void give_notes_arr (ifstream from_list_of_notes, vector <string> notes, string note, string action) {
	
	from_list_of_notes.open("Notes.txt");
	if (!from_list_of_notes.is_open())
		cout << "Open file error!";
	else {
		while (!from_list_of_notes.eof())
		{
			getline(from_list_of_notes, note);
			if (note.size() > 0)
				notes.push_back(note);
		}

		getline(cin, action);
		if (stoi(action) > notes.size())
			while (stoi(action) > notes.size()) {
				cout << "There no note with this number.\nPlease, try again: ";
				getline(cin, action);
				cout << endl;
			}
		if (action[0] == CANCEL) {
			return;
		}
	}
	from_list_of_notes.close();
}


void send_notes_arr(ofstream in_list_of_notes, vector <string> notes, string note) {
	in_list_of_notes.open("Notes.txt");
	if (!in_list_of_notes.is_open())
		cout << "Open file error!";
	else {
		for (int i = 0; i < notes.size(); i++)
			in_list_of_notes << notes[i] << '\n';
	}
	in_list_of_notes.close();
}


void print_info(int a) {

	switch (a) {
	case SEE:
		cout << "\n\n_____________________________\n"
			<< "\n\tHERE ARE YOUR NOTES\n"
			<< "_____________________________\n\n";
		break;

	case FIND:
		std::cout << "\nNotes you looked for:\n";
		break;

	case ADD:
		cout << "\n\n_____________________________\n"
			<< "\n\tWRITE NEW NOTE\n"
			<< "_____________________________\n\n";
		break;

	case DELETE:
		cout << "\n\n_____________________________\n"
			<< "\n\tWRITE NUMBER OF NOTE YOU WANT TO DELETE\n"
			<< "_____________________________\n\n";
		break;

	case CHANGE:
		cout << "\n\n_____________________________\n"
			<< "\n\tWRITE NUMBER OF NOTE YOU WANT TO CHANGE\n"
			<< "_____________________________\n\n";
		break;

	case CLEAR:
		cout << "\n\n_____________________________\n"
			<< "\n\tYOUR TO-DO LIST HAS BEEN CLEARED\n"
			<< "_____________________________\n\n";
		break;

	case EXIT:
		cout << "\n\n_____________________________\n"
			<< "\n\tGOOD BYE\n"
			<< "_____________________________\n\n";
		break;

	default:
		cout << "\n\n_____________________________\n"
			<< "\n\tTHERE IS NOT ACTIONS WITH THIS NUMBER\n"
			<< "_____________________________\n\n";
		break;
	};
}
