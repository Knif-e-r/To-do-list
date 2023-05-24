#pragma once
#ifndef _FUNCTIONS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum ACTIONS {
	OK = '1',
	CANCEL = '0',
	
	SEE,
	FIND,
	ADD,
	DELETE,
	CHANGE,
	CLEAR,
	EXIT
};

void start_menu();
bool sure();
void get_notes_arr(ifstream &from_list_of_notes, vector <string> &notes);
void send_notes_arr(ofstream &in_list_of_notes, vector <string> &notes);
bool scan_note_number(string &action, vector <string>& notes);

void print_info(int a);

void see_note();
void find_note();
void add_note();
void delete_note();
void change_note();
void clear_to_do_list();

#endif