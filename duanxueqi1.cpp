#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
/*-------------------------------------------函数定义区----------------------------------------------*/
int menu();                                //菜单函数
void back();                               //返回函数
int search(int cin);                       //查询站点，线路编号最大值函数
void stationmax();                         //判断站点是否已满函数
void linemax();                            //判断线路是否已满函数
void read();                               //读取文件函数
void save();                               //保存内存数据到结构体函数
void stationmsg();                         //显示站点信息函数
void addstation();                         //添加站点函数
void deletestation();                      //删除站点函数
void changestation();                      //修改站点名字函数
void addline();                            //添加线路函数
void changeline();                         //修改线路函数
void searchline();                         //查找所有站点函数
int menu();                                //菜单函数
/*-------------------------------------------结构体定义区--------------------------------------------*/
char str[200];
struct Stations                            //创建站点结构体
{
    int num;
    char stname[20];
} station[500];

struct Lines                               //创建线路结构体
{
    int num;
    int endnum;
    char liname[20];
    char endname[20];
    struct Stations sta[500];
} line[100];
/*---------------------------------------------函数区------------------------------------------------*/
void back(){
        printf("\n\t\t\t\t\t\t  输入回车返回....\n\t\t\t\t\t\t");
        fflush(stdin);
        getchar();
        system("cls");
}
int search(int cin){                                                    //站点遍历函数
    int i=0;
    if(cin==1)
        for(i=0;i<500;i++)                                              //求站点最大编号i+1
            if(station[i].num==0)
                break;
    if(cin==2)
        for(i=0;i<100;i++)                                              //求线路最大编号i+1
            if(line[i].num==0&&*line[i].liname=='\0')
                break;
    return i;
}
void stationmax(){                                                      //站点达到最大值时提示
        if(station[499].num!=0){
            printf("\t\t\t\t\t\t  线路数量已经超出最大值\n");
            back();
            menu();
        }
}
void linemax(){
    if(line[100].num!=0){
        printf("\t\t\t\t\t\t  线路数量已经超出最大值\n");
        back();
        menu();
    }
}
void read(){
    int i;
    station[0].num=1;
    line[0].num=1;
    FILE *fp1,*fp2;
    printf("\t\t\t\t\t\t  正在尝试读取数据...\n\n");
    if((fp1=fopen("1.dat","r+"))==NULL){
        printf("\t\t\t\t\t\t  检测到未创建数据文件1，正在创建中...");
        fp1=fopen("1.dat","w+");
    }
    else{
        fp1=fopen("1.dat","r+");
    for(i=0;i<100;i++)
        if(fread(&station[i],sizeof(struct Stations),1,fp1)!=1)
            break;
    }
    if((fp2=fopen("2.dat","r+"))==NULL){
        printf("\t\t\t\t\t\t  检测到未创建数据文件2，正在创建中...");
        fp2=fopen("2.dat","w+");
    }
    else{
        fp2=fopen("2.dat","r+");
    for(i=0;i<500;i++)
        if(fread(&line[i],sizeof(struct Lines),1,fp2)!=1)
            break;
    }
    printf("\t\t\t\t\t\t  读取数据成功!");
    fclose(fp1);
    fclose(fp2);
    Sleep(500);
    system("cls");
    return;
}
void save(){
    int i;
    FILE *fp1=NULL,*fp2=NULL;
    printf("\t\t\t\t\t\t  正在保存数据...\n\n");
    if((fp1=fopen("1.dat","w+"))==NULL){
        printf("\t\t\t\t\t\t  检测到数据文件1丢失，正在创建中...");
        fp1=fopen("1.dat","w+");
    }
        fp1=fopen("1.dat","w+");
    for(i=0;station[i].num!=0&&i<100;i++)
        if(fwrite(&station[i],sizeof(struct Stations),1,fp1)!=1)
            break;

    if((fp2=fopen("2.dat","w+"))==NULL){
        printf("\t\t\t\t\t\t  检测到数据文件2丢失，正在创建中...");
        fp2=fopen("2.dat","w+");
    }
        fp2=fopen("2.dat","w+");
    for(i=0;line[i].num!=0&&i<500;i++)
        if(fwrite(&line[i],sizeof(struct Lines),1,fp2)!=1)
            break;
    printf("\t\t\t\t\t\t  保存数据成功!\n");
    fclose(fp1);
    fclose(fp2);
    return;
}
void stationmsg(){
    printf("\n\t\t\t\t\t\t  公交线路管理系统\n");
    printf("\n\t\t\t\t\t\t  显示全部站点信息\n");
    int i;
    for(i=0;i<500;i++){
        if(station[i].num!=0&&*station[i].stname!='\0'){
        printf("\t\t\t\t\t\t  %d\t%s\n",station[i].num,station[i].stname);
        }
    }
}
void addstation(){
    printf("\n\t\t\t\t\t\t  公交线路管理系统\n");
    printf("\t\t\t\t\t\t  新增公交站点\n");
    int i,flag=0;
    char name[1000];
    i=search(1);
    stationmax();
    printf("\t\t\t\t\t\t  请输入站点名称:");
    scanf("%s",&name);
    if(strlen(name)>20){
        printf("\t\t\t\t\t\t  站点名字过长！\n");
        return;
    }
    else{
    strcpy((station[i-1].stname),name);
    station[i].num=i+1;
    save();
    }
}
void deletestation(){
    printf("\n\t\t\t\t\t\t  公交线路管理系统\n\n");
    printf("\t\t\t\t\t\t  删除公交站点\n\n");
    for(int j=0;j<500;j++){
        if(station[j].num!=0&&*station[j].stname!='\0'){
        printf("\t\t\t\t\t\t  %d\t%s\n",station[j].num,station[j].stname);
        }
    }
    printf("\n\t\t\t\t\t\t  请输入站点编号:");
    char cin[1000];
    int i,flag,num;
    if(scanf("%d",&num)){
        for(i=0;i<500;i++){
            if(station[i].num==num&&*station[i].stname!='\0'){
                break;
            }
        }
        if(station[num-1].num==0||*station[num-1].stname=='\0'){
            printf("\n\t\t\t\t\t\t  找不到该站点\n");
            return;
        }
        else{
            printf("\n\t\t\t\t\t\t  确认要删除该站点吗?(Y/N)");
            scanf("%s",&cin);
            if(*cin=='y'||*cin=='Y'){
                for(int p=i;p<499;p++){
                    if(station[p+1].num>1)
                    station[p+1].num--;
                    station[p]=station[p+1];
                }
            }
            save();
            Sleep(500);
            system("cls");
            return;
        }
    }
    else{
        printf("\n\t\t\t\t\t\t  输入不合法\n");
        return;
    }
}
void changestation(){
    printf("\n\t\t\t\t\t\t  公交线路管理系统\n\n");
    printf("\t\t\t\t\t\t  修改公交站点\n");
    char name[1000];
    int i,num,flag=0;                                                   //创建输入临时变量
    printf("\t\t\t\t\t\t  请输入需要修改的站点编号:");
    if(scanf("%d",&num)){
        fflush(stdin);
        for(i=0;i<500;i++){
            if(station[i].num==num&&*station[i].stname!='\0'){
                flag++;                                                     //符合条件时进行标记
                break;
            }
        }
        if(flag==1){
            printf("\n\t\t\t\t\t\t  原站点名称为:%s\n\t\t\t\t\t\t  请输入修改后的站点名称:",station[i].stname);
            scanf("%s",&name);
            if(strlen(name)>20){                                            //判断输入字符长度
                printf("\t\t\t\t\t\t  站点名字过长！\n");
                return;
            }
            else{
                strcpy(station[i].stname,name);                             //复制临时输入站点名称到结构体中
                printf("\n\t\t\t\t\t\t  修改完毕！\n");
            }
        }
        else{
            printf("\t\t\t\t\t\t  找不到该编号所对应的站点\n");
            return;
        }
    }
    else{
        printf("\n\t\t\t\t\t\t  输入不合法\n");
        return;
    }
    save();
}
void addline(){
    printf("\n\t\t\t\t\t\t  公交线路管理系统\n\n");
    printf("\t\t\t\t\t\t  新增公交线路\n\n");
    char name[1000];                                                     //临时输入数据
    int i,j,flag1=0,flag2=0,start,end;                                   //定义临时变量和起点站终点站编号
    linemax();
    i=search(2);
    printf("\t\t\t\t\t\t  请输入线路名称:\n\t\t\t\t\t\t  ");
    scanf("%s",&name);
    if(strlen(name)>20){
        printf("\t\t\t\t\t\t  线路名字过长！\n");
        return;
    }
    else{
    strcpy(line[i-1].liname,name);
    line[i].num=i+1;
    }
    printf("\t\t\t\t\t\t  请输入起点站编号\n\t\t\t\t\t\t  ");
    if(scanf("%d",&start))
        for(j=0;j<500;j++){
            if(start!=0&&start==station[j].num) {
                line[i-1].sta[0].num=start;
                strcpy(line[i-1].sta[0].stname,station[start-1].stname);
                flag1++;
            }
        }
    else{
        printf("\n\t\t\t\t\t\t  输入不合法\n");
        return;
    }
    while(flag1==0){
        printf("\t\t\t\t\t\t  找不到该站点,请重新输入:");
        if(scanf("%d",&start))
            for(j=0;j<500;j++){
                if(start!=0&&start==station[j].num) {
                    line[i-1].sta[0].num=start;
                    strcpy(line[i-1].sta[0].stname,station[start].stname);
                    flag1++;
                }
            }
        else{
            printf("\n\t\t\t\t\t\t  输入不合法\n");
            return;
        }
    }
    printf("\t\t\t\t\t\t  请输入终点站编号\n\t\t\t\t\t\t  ");
    if(scanf("%d",&end))
        for(j=0;j<500;j++){
            if(end!=0&&end==station[j].num) {
                line[i-1].endnum=end;
                strcpy(line[i-1].endname,station[end-1].stname);
                flag2++;
            }
        }
    else{
        printf("\n\t\t\t\t\t\t  输入不合法\n");
        return;
    }
    while(flag2==0){
        printf("\t\t\t\t\t\t  找不到该站点,请重新输入:");
        if(scanf("%d",&end))
            for(j=0;j<500;j++){
                if(end!=0&&end==station[j].num) {
                    line[i].endnum=end;
                    strcpy(line[i].endname,station[end-1].stname);
                    flag2++;
                }
            }
        else{
            printf("\n\t\t\t\t\t\t  输入不合法\n");
            return;
        }
    }   
    save();
}
void changeline(){
    int num1=0;
    char cin[1000];                                                     //键盘输入的字符
    int i,j,num,flag=0,cin1,cin2,m,t;                                   //创建输入临时变量
    j=search(1);
    if(*line[0].liname=='\0'){
        printf("\t\t\t\t\t\t  请先添加线路\n");
        return;
    }
    printf("\t\t\t\t\t\t  请输入需要修改的线路编号:");
    if(scanf("%d",&num))
        for(i=0;i<100;i++){
            if(line[i].num==num&&*line[i].liname!='\0'){
                flag++;                                                     //符合条件时进行标记
                break;
            }
        }
        else{
            printf("\n\t\t\t\t\t\t  输入不合法\n");
            return;
        }
    while(1){
        if(flag==0){
            printf("\t\t\t\t\t\t  找不到该编号所对应的线路\n");
            back();
            printf("\t\t\t\t\t\t  请输入需要修改的线路编号:");
            if(scanf("%d",&num))
                for(i=0;i<100;i++){
                    if(line[i].num==num&&*line[i].liname!='\0'){
                        flag++;                                             //符合条件时进行标记
                        break;
                    }
                }
            else{
                printf("\n\t\t\t\t\t\t  输入不合法\n");
                return;
            }
            system("cls");
            continue;
        }
        system("cls");
        printf("\t\t\t\t\t\t  正在修改的线路为:\n\n");
        printf("\t\t\t\t  %d\t%s\t起点站：%d %s -> ",line[i].num,line[i].liname,line[i].sta[0].num,line[i].sta[0].stname);
        for(int j=1;j<500;j++){
            if(*line[i].sta[j].stname!='\0')
            printf("%d %s -> ",line[i].sta[j].num,line[i].sta[j].stname);
        }
        printf("终点站：%d %s\n\n",line[i].endnum,line[i].endname);
        printf("\t\t\t\t\t  *******************************\n");
        printf("\t\t\t\t\t  *       调整公交线路菜单      *\n");
        printf("\t\t\t\t\t  *                             *\n");
        printf("\t\t\t\t\t  *       1．调整线路名称       *\n");
        printf("\t\t\t\t\t  *       2．调整线路起点站     *\n");
        printf("\t\t\t\t\t  *       3．调整线路终点站     *\n");
        printf("\t\t\t\t\t  *       4．新增线路途径站     *\n");
        printf("\t\t\t\t\t  *       5．删除公交线路       *\n");
        printf("\t\t\t\t\t  *       6. 返回               *\n");
        printf("\t\t\t\t\t  *******************************\n");
        printf("\t\t\t\t\t          请输入操作编号：");
        fflush(stdin);
        num1=0;
        if(scanf("%d",&num1))
            while(num1<=0||num1>=7){
                printf("\t\t\t\t\t\t  请重新输入正确的数字:");
                if(!scanf("%d",&num1)){
                    printf("\n\t\t\t\t\t\t  输入不合法\n");
                    return;
                }
            }
        else{
            printf("\n\t\t\t\t\t\t  输入不合法\n");
            return;
        }
        switch(num1){
            case 1: {
                printf("\n\t\t\t\t\t\t  原线路名称为:%s\n\t\t\t\t\t\t  请输入修改后的线路名称:",line[i].liname);
                scanf("%s",&cin);
                if(strlen(cin)>20){                                             //判断输入字符长度
                    printf("\t\t\t\t\t\t  线路名字过长！\n");
                    back();
                    continue;
                }
                else{
                    strcpy(line[i].liname,cin);                                 //复制临时输入站点名称到结构体中
                    printf("\n\t\t\t\t\t\t  修改完毕！\n");
                }
            save();
            Sleep(500);
            system("cls");
            }break;
            case 2: {
                printf("\n\t\t\t\t\t\t  原线路起点站为:%d %s\n\t\t\t\t\t\t  请输入修改后的起点站编号:",line[i].sta[0].num,line[i].sta[0].stname);
                if(scanf("%d",&cin1)){
                    if(cin1>j||cin1<=0){
                        printf("\t\t\t\t\t\t  找不到对应站点！\n");
                        back();
                        continue;
                    }
                    else{
                        line[i].sta[0].num=cin1;                                    //复制临时输入站点名称到结构体中
                        strcpy(line[i].sta[0].stname,station[cin1].stname);
                        printf("\n\t\t\t\t\t\t  修改完毕！\n");
                    }
                save();
                Sleep(500);
                system("cls");
                }
                else{
                    printf("\n\t\t\t\t\t\t  输入不合法\n");
                    back();
                    continue;
                }
            }break;
            case 3: {
                printf("\n\t\t\t\t\t\t  原线路终点站为:%d %s\n\t\t\t\t\t\t  请输入修改后的终点站编号:",line[i].endnum,line[i].endname);
                if(scanf("%d",&cin1)){
                    if(cin1>j||cin1<=0){
                        printf("\t\t\t\t\t\t  找不到对应站点！\n");
                        back();
                        continue;
                    }
                    else{
                        line[i].endnum=cin1;                                        //复制临时输入站点名称到结构体中
                        strcpy(line[i].endname,station[cin1].stname);
                        printf("\n\t\t\t\t\t\t  修改完毕！\n");
                    }
                save();
                Sleep(500);
                system("cls");
                }
                else{
                    printf("\n\t\t\t\t\t\t  输入不合法\n");
                    back();
                    continue;
                }
            }break;
            case 4: {
                printf("\n\t\t\t\t\t\t  请输入途径站编号:");
                if(scanf("%d",&cin1)){
                    if(cin1>j||cin1<=0){
                        printf("\t\t\t\t\t\t  找不到对应站点！\n");
                        back();
                        continue;
                    }
                    else{
                        printf("\n\t\t\t\t\t\t  请输入途径站插入位置(起点站后为1,往后每一站加1)");
                        if(scanf("%d",&cin2))
                            for(m=0;m<500;m++){
                                if(line[i].sta[m].num==0){
                                break;
                                }
                            }
                        else{
                            printf("\n\t\t\t\t\t\t  输入不合法\n");
                            back();
                            continue;
                        }
                        if(cin2>m||cin2<1){
                            printf("\t\t\t\t\t\t  位置输入有误，请检查后再试");
                            back();
                            continue;
                        }
                        else{
                            for(int q=499;q>=cin2;q--){
                                line[i].sta[q+1].num=line[i].sta[q].num;
                                strcpy(line[i].sta[q+1].stname,line[i].sta[q].stname);
                            }
                            line[i].sta[cin2].num=cin1;
                            strcpy(line[i].sta[cin2].stname,station[cin1-1].stname);
                            printf("\n\t\t\t\t\t\t  修改完毕！\n");
                        }
                    }
                }
                else{
                    printf("\n\t\t\t\t\t\t  输入不合法\n");
                    back();
                    continue;
                }
            save();
            Sleep(500);
            system("cls");
            }break;
            case 5: {
                printf("\n\t\t\t\t\t\t  确认要删除该线路吗?(Y/N)");
                scanf("%s",&cin);
                if(*cin=='y'||*cin=='Y'){
                    for(int p=i;p<99;p++){
                        if(line[p+1].num>1)
                        line[p+1].num--;
                        line[p]=line[p+1];
                    }
                }
            save();
            Sleep(500);
            system("cls");
            return;
            }break;
            case 6: return;
        system("pause");
        }
    }
}
void searchline(){
    printf("\n\t\t\t\t\t\t  公交线路管理系统\n");
    printf("\n\t\t\t\t\t\t  查询公交线路\n");
    int i,cin;
    for(i=0;i<100;i++){
        if(line[i].num!=0&&*line[i].liname!='\0'){
        printf("\t\t\t\t  %d\t%s\t起点站：%d %s -> ",line[i].num,line[i].liname,line[i].sta[0].num,line[i].sta[0].stname);
        for(int j=1;j<500;j++){
            if(*line[i].sta[j].stname!='\0')
            printf("%d %s -> ",line[i].sta[j].num,line[i].sta[j].stname);
        }
        printf("终点站：%d %s\n\n",line[i].endnum,line[i].endname);
        }
    }
    printf("\n\t\t\t\t\t\t  请输入需要查询的线路编号:");
    if(scanf("%d",&cin))
        if(*line[cin-1].liname!='\0'){
            printf("\t\t\t\t  %d\t%s\t起点站：%d %s -> ",line[cin-1].num,line[cin-1].liname,line[cin-1].sta[0].num,line[cin-1].sta[0].stname);
            for(int j=1;j<500;j++){
                if(line[cin-1].sta[j].num!=0&&*line[cin-1].sta[j-1].stname!='\0')
                printf("%d %s -> ",line[cin-1].sta[j].num,line[cin-1].sta[j].stname);
            }
            printf("终点站：%d %s\n",line[cin-1].endnum,line[cin-1].endname);
        }
        else{
            printf("\n\t\t\t\t\t\t  查询不到该编号对应的线路");
        }
        else {
            printf("\n\t\t\t\t\t\t  输入不合法\n");
            return;
        }
}
int menu(){                                                                 //菜单函数
    int num1=0;
    printf("\t\t\t\t\t  *******************************\n");
    printf("\t\t\t\t\t  *       公交线路管理系统      *\n");
    printf("\t\t\t\t\t  *                             *\n");
    printf("\t\t\t\t\t  *      1. 显示全部站点信息    *\n");
    printf("\t\t\t\t\t  *      2．新增公交站点        *\n");
    printf("\t\t\t\t\t  *      3．删除公交站点        *\n");
    printf("\t\t\t\t\t  *      4．修改公交站点        *\n");
    printf("\t\t\t\t\t  *      5．新增公交线路        *\n");
    printf("\t\t\t\t\t  *      6．调整公交线路        *\n");
    printf("\t\t\t\t\t  *      7. 查询公交线路        *\n");
    printf("\t\t\t\t\t  *      8．退出                *\n");
    printf("\t\t\t\t\t  *******************************\n");
    printf("\t\t\t\t\t          请输入操作编号：");
    if(scanf("%d",&num1)){
        system("cls");
        switch(num1){
            case 1: stationmsg(); return 1; break;
            case 2: addstation(); return 1; break;
            case 3: deletestation(); return 1; break;
            case 4: changestation(); return 1; break;
            case 5: addline(); return 1; break;
            case 6: changeline(); return 1;break;
            case 7: searchline(); return 1; break;
            case 8: return 2; break;
            default: printf("\t\t\t\t\t\t请输入正确的数字。\n\t\t\t\t\t\t  输入回车返回....\n\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                    system("cls");
                    return 1;
                    break;
        }
    }
    else{
        printf("\n\t\t\t\t\t\t  输入不合法\n");
        return 1;
    }
    system("pause");
    return 0;
}

int main(){
    system("color F0");                                             //给终端调色为白底黑字便于操作
    read();
    fflush(stdin);
    int flag=1;
    flag=menu();                                                    //循环结构，使menu能够实现自动清屏返回上一级
    while(flag==1){
        back();
        flag=menu();
    }
    if(flag==2) return 0;                                           //退出程序
    system("pause");
    return 0;
}
