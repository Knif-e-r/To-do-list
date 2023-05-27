#include "functions.h"

void start_menu() {
	cout << "\n\n_____________________________\n"
		<< "\n\tMY TO-DO LIST\n"
		<< "_____________________________\n"
		<< "\nWhat do you want to do?\n\n"
		<< "1) See my notes\n"
		<< "2) Find note\n"
		<< "3) Add new note\n"
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
		<< "1) Ok\n"
		<< "\nYour choise: ";

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
				<< "1) Ok\n"
				<< "\nYour choise: ";
		}
	}
}


bool scan_note_number(string& action, vector <string>& notes) {
	cout << "\nYour answer: ";
	getline(cin, action);

	bool is_symbol = false;
	for (auto c : action) {
		if ('0' > c || c > '9') {
			is_symbol = true;
			break;
		}
	}

	if (!is_symbol) {
		if (stoi(action) > notes.size()) {
			while (stoi(action) > notes.size()) {
				cout << "\nThere no note with this number.\nPlease, try again.";
				cout << "\nYour answer: ";
				getline(cin, action);
				if (action[0] == CANCEL) {
					return false;
				}
			}
			return true;
		}
		if (action[0] == CANCEL) {
			return false;
		}
	}
	else {
		cout << "\nThis isn't a number.\nPlease, try again.";
		scan_note_number(action, notes);
	}
}


void get_notes_arr (ifstream &from_list_of_notes, vector <string> &notes) {
	
	from_list_of_notes.open("Notes.txt");
	if (!from_list_of_notes.is_open())
		cout << "Open file error!";
	else {
		while (!from_list_of_notes.eof())
		{
			string note;
			getline(from_list_of_notes, note);
			if (note.size() > 0)
				notes.push_back(note);
		}
	}
	from_list_of_notes.close();
}


void send_notes_arr(ofstream &in_list_of_notes, vector <string> &notes) {
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
			<< "\n     HERE ARE YOUR NOTES\n"
			<< "_____________________________\n\n";
		break;

	case FIND:
		cout << "\n\n_____________________________\n"
			<< "\n     SEARCH NEEDED NOTES\n"
			<< "_____________________________\n\n";
		break;

	case ADD:
		cout << "\n\n_____________________________\n"
			<< "\n\tADD NEW NOTE\n"
			<< "_____________________________\n\n";
		break;

	case DELETE:
		cout << "\n\n_____________________________\n"
			<< "\n\tDELETE NOTE\n"
			<< "_____________________________\n\n";
		break;

	case CHANGE:
		cout << "\n\n_____________________________\n"
			<< "\n\tCHANGE NOTE\n"
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
		cout << "\n\n_________________________________________\n"
			<< "\n  HERE IS NO ACTIONS WITH THIS NUMBER\n"
			<< "_________________________________________\n\n";
		break;
	};
}
