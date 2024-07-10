#include "Project.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lcd.h"
#include "2048.h"
#include "bmp.h"
#include "ts.h"

int gamebegin()
{
	int game_flag = 1;
	int game_over = 1;
	srandom(time(NULL));

	// 1. 打开屏幕
	lcd_open();
restart:
	lcd_clear_screen(0x555555);
	// 关闭屏幕
	game_over = game_2048(game_flag);
	if(game_over == 0)
	{
		goto over;
	}
	int mv = get_user_input();
	printf("mvgame = %d",mv);
	if (mv && game_over)
	{
		goto restart;
	}

over:

	lcd_close();

	return 0;
}
