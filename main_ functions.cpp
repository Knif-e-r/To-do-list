#include "functions.h"


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
	ifstream list_of_notes;
	list_of_notes.open("Notes.txt");
	if (!list_of_notes.is_open())
		cout << "Open file error!";
	else {
		
	}
	list_of_notes.close();
}


void add_note() {
	ofstream list_of_notes;
	list_of_notes.open("Notes.txt", ofstream::app);
	if (!list_of_notes.is_open())
		cout << "Open file error!";
	else {
		string note;
		getline(cin, note);
		if (note.size() > 0) {
			note += "\n";
			list_of_notes << note;
		}
	}
	list_of_notes.close();
}


void delete_note() {
	cout << "0) cancel\n\n";
	see_note();

	string note;
	vector <string> notes;
	ifstream from_list_of_notes;
	give_notes_arr(from_list_of_notes, notes, note);

	string action;
	if (!scan_note_number(action, notes))
		return;

	//Delete element
	vector <string>::iterator it = notes.begin();
	it += stoi(action) - 1;
	notes.erase(it);

	ofstream in_list_of_notes;
	send_notes_arr(in_list_of_notes, notes, note);
}


void change_note() {
	cout << "0) cancel\n\n";
	see_note();

	string note;
	vector <string> notes;
	ifstream from_list_of_notes;
	give_notes_arr(from_list_of_notes, notes, note);
	
	string action;
	if (!scan_note_number(action, notes))
		return;


	//Delete element
	vector <string>::iterator it = notes.begin();
	it += stoi(action) - 1;
	notes.erase(it);

	//Insert new element ("change" element)
	it = notes.begin() + (stoi(action) - 1);
	cout << "Write changed note: ";
	string changed_note; 
	getline(cin, changed_note);
	notes.insert(it, changed_note);
	cout << "Note has been changed!\n";

	ofstream in_list_of_notes;
	send_notes_arr(in_list_of_notes, notes, note);
}


void clear_to_do_list() {
		ofstream list_of_notes;
		list_of_notes.open("Notes.txt", ofstream::trunc);
		list_of_notes.close();
}