#include "sys_props.h"

void set_SYS_DATE(unsigned char str_date[12]){
	SYS_DATE = MMDDYYYY_to_date(str_date);
}