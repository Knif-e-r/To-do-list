#include "functions.h"

using namespace std;

void start_menu() {
	cout << "\n\n_____________________________________\n"
		<< "\n\t    MY TO-DO LIST\n"
		<< "_____________________________________\n"
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
	system("cls");
	cout << "\n\n_____________________________________\n"
		<< "\n\t    ARE YOU SURE?\n"
		<< "_____________________________________\n\n"
		<< "0) Cancel\n"
		<< "1) Ok\n"
		<< "\nYour choise: ";

	while (true) {
		string action; getline(cin, action);
		if (action.size() > 1 || action.size() == 0)
			action = "9";
		switch (action[0]) {
		case OK:
			return true;
			break;
		case CANCEL:
			return false;
			break;
		default:
			cout << "There is no action with this number.\nPlease, try again.\n";
			system("pause"); system("cls");
			cout << "\n\n_____________________________________\n"
				<< "\n\t    ARE YOU SURE?\n"
				<< "_____________________________________\n\n"
				<< "0) Cancel\n"
				<< "1) Ok\n"
				<< "\nYour choise: ";
			break;
		};
	}
}


bool scan_note_number(string& action, vector <string>& notes) {
	cout << "\nYour answer: ";
	getline(cin, action);

	if (action.size() == 0)
		action += "N";

	bool is_symbol = false;
	for (auto c : action) {
		if ('0' > c || c > '9') {
			is_symbol = true;
			break;
		}
	}

	if (!is_symbol && stoi(action) <= notes.size()) {
		if (action[0] == CANCEL) {
			return false;
		}
		return true;
	}
	else {
		cout << "\nThere no note with this number.\nPlease, try again.";
		scan_note_number(action, notes);
	}
}


void get_notes_arr(ifstream& from_list_of_notes, vector <string>& notes) {

	from_list_of_notes.open("Notes.txt");
	if (!from_list_of_notes.is_open())
		cout << "(Open file error! File doesn't exist!)\n";
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


void send_notes_arr(ofstream& in_list_of_notes, vector <string>& notes) {
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
		cout << "\n\n_____________________________________\n"
			<< "\n\tHERE ARE YOUR NOTES\n"
			<< "_____________________________________\n\n";
		break;

	case FIND:
		cout << "\n\n_____________________________________\n"
			<< "\n\tSEARCH NEEDED NOTES\n"
			<< "_____________________________________\n\n";
		break;

	case ADD:
		cout << "\n\n_____________________________________\n"
			<< "\n\t    ADD NEW NOTE\n"
			<< "_____________________________________\n\n";
		break;

	case DELETE:
		cout << "\n\n_____________________________________\n"
			<< "\n\t    DELETE NOTE\n"
			<< "_____________________________________\n\n";
		break;

	case CHANGE:
		cout << "\n\n_____________________________________\n"
			<< "\n\t    CHANGE NOTE\n"
			<< "_____________________________________\n\n";
		break;

	case CLEAR:
		cout << "\n\n_____________________________________\n"
			<< "\n  YOUR TO-DO LIST HAS BEEN CLEARED\n"
			<< "_____________________________________\n\n";
		break;

	default:
		cout << "\n\n_____________________________________\n"
			<< "\n HERE IS NO ACTIONS WITH THIS NUMBER\n"
			<< "_____________________________________\n\n";
		break;
	};
}
