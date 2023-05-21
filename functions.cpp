#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

	string action; getline(cin, action);

	if (stoi(action) == 1) { //Ok
		return true;
	}
	else if (action[0] == CANCEL) {
		return false;
	}
}

void see_note() {
	ifstream list_of_notes;
	list_of_notes.open("Notes.txt");
	if (!list_of_notes.is_open())
		cout << "Open file error!";
	else {
		int note_number = 1;
		while (!list_of_notes.eof())
		{
			string note;
			getline(list_of_notes, note);

			if (note.size() != 0)
				cout << note_number++ << ") " << note << "\n";
		}
	}
	list_of_notes.close();
}


void find_note() {

}


void add_note() {
	ofstream list_of_notes;
	list_of_notes.open("Notes.txt", ofstream::app);
	if (!list_of_notes.is_open())
		cout << "Open file error!";
	else {
		string note;
		getline(cin, note);
		note += "\n";
		list_of_notes << note;
		
	}
	list_of_notes.close();
}


void delete_note() {
	cout << "0) cancel\n\n";
	see_note();

	ifstream from_list_of_notes;
	string note;
	vector <string> notes;

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

		string action; getline(cin, action);
		if (stoi(action) > notes.size())
			while (stoi(action) > notes.size()) {
				cout << "There no note with this number.\nPlease, try again: ";
				getline(cin, action);
				cout << endl;
			}
		if (action[0] == CANCEL) {
			return;
		}
		
		vector <string>::iterator it = notes.begin();
		it += stoi(action) - 1;
		notes.erase(it);
	}
	from_list_of_notes.close();

	ofstream in_list_of_notes;
	in_list_of_notes.open("Notes.txt");
	if (!in_list_of_notes.is_open())
		cout << "Open file error!";
	else {
		for (int i = 0; i < notes.size(); i++)
			in_list_of_notes << notes[i] << '\n';
	}
	in_list_of_notes.close();
}

void change_note() {

}

void clear_to_do_list() {
		ofstream list_of_notes;
		list_of_notes.open("Notes.txt", ofstream::trunc);
		list_of_notes.close();
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
			<< "\n\tWRITE NOTE NUMBER YOU WANT TO DELETE\n"
			<< "_____________________________\n\n";
		break;
	
	case CHANGE:
		cout << "\n\n_____________________________\n"
			<< "\n\tWRITE NOTE NUMBER YOU WANT TO CHANGE\n"
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
