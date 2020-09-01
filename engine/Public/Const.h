#pragma once
#include <string>   
using namespace std;

const string c_red_head = "\033[31m";
const string c_red_tail = "\033[0m";

const string c_green_head = "\033[32m";
const string c_green_tail = "\033[0m";

const string c_yellow_head = "\033[33m";
const string c_yellow_tail = "\033[0m";

const string c_blue_head = "\033[34m";
const string c_blue_tail = "\033[0m";

const string c_purple_head = "\033[35m";
const string c_purple_tail = "\033[0m";

static string c_map_color_head = c_red_head;
static string c_map_color_tail = c_red_tail;
static int c_map_cell_size = 3;
static string c_map_cell = "|_____";