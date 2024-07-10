#include "Project.h"
#include <stdio.h>
#include <stdlib.h>
#include "2048.h"
#include "bmp.h"
#include "lcd.h"
#include "ts.h"

// 定义全局变量keysign，用于控制界面显示流程
int keysign = 1;

/**
 * @brief 控制主用户界面的函数
 * 
 * 该函数实现了主用户界面的各种功能按钮的控制逻辑，包括视频、音乐、游戏、相册和语音等按钮的响应处理。
 * 当用户在触摸屏上操作时，根据触摸的位置，执行相应的功能。
 */
void gamebegin(); // 声明gamebegin函数原型

int ControlMianUI() // 控制模块
{
    // 当keysign为1时，执行初始化界面显示和主循环
    if (keysign == 1)
    {
        // 初始化界面显示，逐步显示欢迎图片
        ShowBmp(0, 0, "./rec/ys0.bmp"); // 显示原神界面
        sleep(1);
        ShowBmp(0, 0, "./rec/ys1.bmp"); // 显示原神界面
        sleep(1);
        ShowBmp(0, 0, "./rec/ys2.bmp"); // 显示原神界面
        sleep(2);
        ShowBmp(0, 0, "./rec/main.bmp"); // 显示主界面

        // 主循环，等待用户触摸操作
        int key;
        while (1)
        {
            // 获取触摸屏位置
            Get_Xy();
            // 根据触摸位置判断用户操作了哪个按钮，并执行相应功能
            if (PI.Ts_x > 550 && PI.Ts_x < 700 && PI.Ts_y > 180 && PI.Ts_y < 300) // 视频按钮
            {
                printf("视频按钮!\n");
                StartVideo(); // 启动视频
            }

            if (PI.Ts_x > 100 && PI.Ts_x < 280 && PI.Ts_y > 5 && PI.Ts_y < 160) // 音乐按钮
            {
                printf("音乐按钮！\n");
                StartMusic(); // 启动音乐
            }

            if (PI.Ts_x > 350 && PI.Ts_x < 500 && PI.Ts_y > 5 && PI.Ts_y < 160) // 游戏按钮
            {
                printf("游戏按钮！\n");
                gamebegin(); // 启动游戏
            }

            if (PI.Ts_x > 100 && PI.Ts_x < 280 && PI.Ts_y > 180 && PI.Ts_y < 300) // 相册按钮
            {
                printf("相册!\n");
                StartAlbum(); // 启动相册
            }
            if (PI.Ts_x > 550 && PI.Ts_x < 770 && PI.Ts_y > 5 && PI.Ts_y < 160) // 语音按钮
            {
                printf("aitalk!\n");
                key = 1;
                aitalk_main(); // 启动AI对话
            }
            if (PI.Ts_x > 340 && PI.Ts_x < 500 && PI.Ts_y > 180 && PI.Ts_y < 300) // 退出按钮
            {
                printf("主界面退出按钮！\n");
                ShowBmp(0, 0, "./rec/exit.bmp"); // 显示退出界面
                break;
            }
            // 根据speaknum的值，执行相应的操作，作为对语音指令的响应
            switch(speaknum)
            {
                case 0: break;
                case 1: 
                {
                    printf("相册!\n");
                    StartAlbum(); //启动相册
                    break;
                }
                case 2: 
                {
                    printf("音乐按钮！\n");
                    StartMusic();//启动音乐
                    break;
                }
                case 3: 
                {
                    printf("游戏按钮！\n");
                    gamebegin(); //启动游戏
                    break;
                }
                case 4: 
                {
                    printf("视频按钮!\n");
                    StartVideo(); //启动视频
                    break;
                }
                case 5: 
                {
                    printf("主界面退出按钮！\n");
                    ShowBmp(0, 0, "./rec/exit.bmp"); //显示退出界面
                    break;
                }
            }
        }
    }
    else
    {
        // 当keysign不为1时，直接显示退出界面
        printf("主界面退出按钮！\n");
        ShowBmp(0, 0, "./rec/exit.bmp"); // 显示退出界面
    }
    return 0;
}

int main()
{
    // 初始化项目
    // 初始化
    int ProjectInit_ret = ProjectInit();
    if (ProjectInit_ret == -1)
    {
        printf("初始化失败！\n");
        return -1;
    }
    else
    {
        printf("初始化成功！\n");
    }

    // 控制主用户界面
    ControlMianUI(); // 启动程序

    // 释放项目资源
    // 释放资源
    int ProjectFree_ret = ProjectFree();
    if (ProjectFree_ret == -1)
    {
        printf("资源回收失败！\n");
        return -1;
    }
    else
    {
        printf("资源回收成功！\n");
    }
    return 0;
}