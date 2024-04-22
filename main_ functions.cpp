#include "functions.h"

using namespace std;

void see_note() {
	ifstream list_of_notes;
	list_of_notes.open("Notes.txt");
	if (!list_of_notes.is_open())
		cout << "You haven't created your to-do list yet!\nPlease, create a few notes.\n";
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
	vector <string> notes;
	get_notes_arr(list_of_notes, notes);

	cout << "Enter search keyword: ";
	string search_keyword;
	getline(cin, search_keyword);

	bool no_notes = true;
	for (int i = 0; i < notes.size(); i++) {
		if (notes[i].find(search_keyword) != string::npos) {
			cout << i + 1 << ") " << notes[i] << endl;
			no_notes = false;
		}
	}
	if (no_notes)
		cout << "Notes not found!\n";
}


void add_note() {
	ofstream list_of_notes;
	list_of_notes.open("Notes.txt", ofstream::app);
	if (!list_of_notes.is_open())
		cout << "(Open file error! File doesn't exist!)\n";
	else {
		cout << "0) cancel\n\n"
			<< "Enter new note: ";
		string note;
		getline(cin, note);

		if (note.size() == 1 && note[0] == CANCEL)
			return;
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

	vector <string> notes;
	ifstream from_list_of_notes;
	get_notes_arr(from_list_of_notes, notes);

	string note_number;
	if (!scan_note_number(note_number, notes))
		return;

	vector <string>::iterator it = notes.begin();
	it += stoi(note_number) - 1;
	notes.erase(it);
	cout << "Note has been deleted!\n";
	system("pause");

	ofstream in_list_of_notes;
	send_notes_arr(in_list_of_notes, notes);
}


void change_note() {
	cout << "0) cancel\n\n";
	see_note();

	vector <string> notes;
	ifstream from_list_of_notes;
	get_notes_arr(from_list_of_notes, notes);

	string note_number;
	if (!scan_note_number(note_number, notes))
		return;

	//Copy element that will be deleted (1st step of "changing" element)
	string note_copy = notes[stoi(note_number) - 1];

	//Delete element (2nd step of "changing" element)
	vector <string>::iterator it = notes.begin();
	it += stoi(note_number) - 1;
	notes.erase(it);

	//Insert new element (3rd step of "changing" element)
	it = notes.begin() + (stoi(note_number) - 1);
	cout << "Write changes: ";
	string changed_note; 
	getline(cin, changed_note);
	if (changed_note.size() != 0) {
		notes.insert(it, changed_note);
		cout << "Note has been changed!\n";
	}
	else {
		notes.insert(it, note_copy);
		cout << "\nNote hasn's been changed!\nEmpty string has been entered!\n";
	}

	ofstream in_list_of_notes;
	send_notes_arr(in_list_of_notes, notes);
}


void clear_to_do_list() {
	ofstream list_of_notes;
	list_of_notes.open("Notes.txt", ofstream::trunc);
	list_of_notes.close();
}
