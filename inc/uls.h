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

char** mx_arg_definition(char* argv[], int argc, int* argumentsCount);
char* mx_flag_definition(char* argv[], int argc, int* countArgs, int* countFlags);
void mx_print_files(t_list* file_list, struct winsize ws);
void mx_print_dir(t_list** dir_list, int dir_list_len, char* flags, int flags_count, struct winsize ws);
t_list** mx_filling_arr(char** file_arr, int count_args, t_list** file_list, int* dir_len);
bool mx_list_cmp(void* a, void* b);
int mx_find_max_name_len(t_list* list);
t_list* mx_get_elem_in_list(t_list* list, int index);
void mx_error_check(char* flags, int flag_count);
void mx_check_flag(char* flags);
void mx_arg_error(char* file);
bool mx_is_flag(char* flags, int n, char flag);
int mx_count_cols(int width, int max_len);
void mx_base_ls(t_list* current, struct winsize ws);
void mx_ls_l(t_list* current);
void mx_print_permission(mode_t mode);
// char mx_check_permission_mode(mode_t mode);

