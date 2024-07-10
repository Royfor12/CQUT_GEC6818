#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int recorder_main(char *filename);
int asr_main(const char *filename, char *str_result);

char str_result[1024];
int speaknum;
int aitalk_main()
{
    //录音
    char *filename = "test.wav";

    recorder_main(filename);

    //定义一个字符串存放识别结果
    // char str_result[1024] = {"NULL"};

    asr_main(filename, str_result);
    printf("!!!!");
    if(strcmp(str_result, "NULL")!=0)
    {
    printf("识别结果\n");
    printf("%s\n", str_result);
    if (strstr(str_result, "音乐") != NULL)
    {
        printf("好的，已打开音乐！\n");
        speaknum=2;
    }
    if (strstr(str_result, "相册") != NULL)
    {
        //播放之前录的声音
        speaknum=1;
        printf("好的，已打开相册\n");
    }
    if (strstr(str_result, "游戏") != NULL)
    {
        //播放之前录的声音
        speaknum=3;
        printf("好的，已打开游戏\n");
    }
    if (strstr(str_result, "视频") != NULL)
    {
        //播放之前录的声音
        speaknum=4;
        printf("好的，已打开视频\n");
    }
    if (strstr(str_result, "关机") != NULL)
    {
        //播放之前录的声音
        speaknum=5;
        printf("好的，已关机\n");
    }
    }

    return 0;
}