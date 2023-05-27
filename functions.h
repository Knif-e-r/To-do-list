#pragma once
#ifndef _FUNCTIONS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum CHOIСE {
	CANCEL = '0',
	OK
};

enum ACTIONS {
	SEE = '1',
	FIND,
	ADD,
	DELETE,
	CHANGE,
	CLEAR,
	EXIT
};

void start_menu();
bool sure();
void get_notes_arr(std::ifstream& from_list_of_notes, std::vector <std::string>& notes);
void send_notes_arr(std::ofstream& in_list_of_notes, std::vector <std::string>& notes);
bool scan_note_number(std::string& action, std::vector <std::string>& notes);

void print_info(int a);

void see_note();
void find_note();
void add_note();
void delete_note();
void change_note();
void clear_to_do_list();

#endif
