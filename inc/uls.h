#pragma once

#include "libmx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <errno.h>

char** mx_arg_definition(char* argv[], int argc, int argumentsCount);
char* mx_flag_definition(char* argv[], int argc, int* countArgs, int* countFlags);
void mx_print_files(int dir_len, t_list* file_list);
void mx_print_dir(t_list** dir_list, int dir_list_len);
t_list** mx_filling_arr(char** file_arr, int count_args, t_list** file_list, int* dir_len);
bool mx_list_cmp(void* a, void* b);
int mx_find_max_name_len(t_list* list);
t_list* mx_get_elem_in_list(t_list* list, int index);

