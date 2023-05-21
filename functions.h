#pragma once

enum ACTIONS {
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

void print_info(int a);

void see_note();
void find_note();
void add_note();
void delete_note();
void clear_to_do_list();