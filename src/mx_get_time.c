#include "uls.h"

char* mx_get_time(time_t st_time) {
	const time_t SIX_MONTH_IN_SECONDS = 15768000;
	time_t current_time = time(NULL);
	time_t diff = (current_time - st_time) > 0 ? current_time - st_time : st_time - current_time;

	char* time = ctime(&st_time);
	char* res = "";

	if (diff > SIX_MONTH_IN_SECONDS) {
		res = mx_strnew(mx_strlen(time));
		mx_strncpy(res, time + 4, 7);
		mx_strcat(res, time + 19);
		res[mx_strlen(res) - 1] = '\0';
	} else {
		res = mx_strndup(time + 4, 12);
	}

	return res;
}

