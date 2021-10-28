#include "./shell/shell.h"
// #include "./std/datetime.h"

void main(void)
{
	update_dir("MAIN");
	shell_init();

	while(1);
}

// int main(){
// 	printf("intro\n");
// 	char date_str[11] = "12/10/2021";
// 	std_date d1 = MMDDYYYY_to_date(date_str);
// 	print_date(d1);
// 	return 0;
// }