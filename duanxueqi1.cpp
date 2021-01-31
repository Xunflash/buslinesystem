#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
/*-------------------------------------------����������----------------------------------------------*/
int menu();                                //�˵�����
void back();                               //���غ���
int search(int cin);                       //��ѯվ�㣬��·������ֵ����
void stationmax();                         //�ж�վ���Ƿ���������
void linemax();                            //�ж���·�Ƿ���������
void read();                               //��ȡ�ļ�����
void save();                               //�����ڴ����ݵ��ṹ�庯��
void stationmsg();                         //��ʾվ����Ϣ����
void addstation();                         //���վ�㺯��
void deletestation();                      //ɾ��վ�㺯��
void changestation();                      //�޸�վ�����ֺ���
void addline();                            //�����·����
void changeline();                         //�޸���·����
void searchline();                         //��������վ�㺯��
int menu();                                //�˵�����
/*-------------------------------------------�ṹ�嶨����--------------------------------------------*/
char str[200];
struct Stations                            //����վ��ṹ��
{
    int num;
    char stname[20];
} station[500];

struct Lines                               //������·�ṹ��
{
    int num;
    int endnum;
    char liname[20];
    char endname[20];
    struct Stations sta[500];
} line[100];
/*---------------------------------------------������------------------------------------------------*/
void back(){
        printf("\n\t\t\t\t\t\t  ����س�����....\n\t\t\t\t\t\t");
        fflush(stdin);
        getchar();
        system("cls");
}
int search(int cin){                                                    //վ���������
    int i=0;
    if(cin==1)
        for(i=0;i<500;i++)                                              //��վ�������i+1
            if(station[i].num==0)
                break;
    if(cin==2)
        for(i=0;i<100;i++)                                              //����·�����i+1
            if(line[i].num==0&&*line[i].liname=='\0')
                break;
    return i;
}
void stationmax(){                                                      //վ��ﵽ���ֵʱ��ʾ
        if(station[499].num!=0){
            printf("\t\t\t\t\t\t  ��·�����Ѿ��������ֵ\n");
            back();
            menu();
        }
}
void linemax(){
    if(line[100].num!=0){
        printf("\t\t\t\t\t\t  ��·�����Ѿ��������ֵ\n");
        back();
        menu();
    }
}
void read(){
    int i;
    station[0].num=1;
    line[0].num=1;
    FILE *fp1,*fp2;
    printf("\t\t\t\t\t\t  ���ڳ��Զ�ȡ����...\n\n");
    if((fp1=fopen("1.dat","r+"))==NULL){
        printf("\t\t\t\t\t\t  ��⵽δ���������ļ�1�����ڴ�����...");
        fp1=fopen("1.dat","w+");
    }
    else{
        fp1=fopen("1.dat","r+");
    for(i=0;i<100;i++)
        if(fread(&station[i],sizeof(struct Stations),1,fp1)!=1)
            break;
    }
    if((fp2=fopen("2.dat","r+"))==NULL){
        printf("\t\t\t\t\t\t  ��⵽δ���������ļ�2�����ڴ�����...");
        fp2=fopen("2.dat","w+");
    }
    else{
        fp2=fopen("2.dat","r+");
    for(i=0;i<500;i++)
        if(fread(&line[i],sizeof(struct Lines),1,fp2)!=1)
            break;
    }
    printf("\t\t\t\t\t\t  ��ȡ���ݳɹ�!");
    fclose(fp1);
    fclose(fp2);
    Sleep(500);
    system("cls");
    return;
}
void save(){
    int i;
    FILE *fp1=NULL,*fp2=NULL;
    printf("\t\t\t\t\t\t  ���ڱ�������...\n\n");
    if((fp1=fopen("1.dat","w+"))==NULL){
        printf("\t\t\t\t\t\t  ��⵽�����ļ�1��ʧ�����ڴ�����...");
        fp1=fopen("1.dat","w+");
    }
        fp1=fopen("1.dat","w+");
    for(i=0;station[i].num!=0&&i<100;i++)
        if(fwrite(&station[i],sizeof(struct Stations),1,fp1)!=1)
            break;

    if((fp2=fopen("2.dat","w+"))==NULL){
        printf("\t\t\t\t\t\t  ��⵽�����ļ�2��ʧ�����ڴ�����...");
        fp2=fopen("2.dat","w+");
    }
        fp2=fopen("2.dat","w+");
    for(i=0;line[i].num!=0&&i<500;i++)
        if(fwrite(&line[i],sizeof(struct Lines),1,fp2)!=1)
            break;
    printf("\t\t\t\t\t\t  �������ݳɹ�!\n");
    fclose(fp1);
    fclose(fp2);
    return;
}
void stationmsg(){
    printf("\n\t\t\t\t\t\t  ������·����ϵͳ\n");
    printf("\n\t\t\t\t\t\t  ��ʾȫ��վ����Ϣ\n");
    int i;
    for(i=0;i<500;i++){
        if(station[i].num!=0&&*station[i].stname!='\0'){
        printf("\t\t\t\t\t\t  %d\t%s\n",station[i].num,station[i].stname);
        }
    }
}
void addstation(){
    printf("\n\t\t\t\t\t\t  ������·����ϵͳ\n");
    printf("\t\t\t\t\t\t  ��������վ��\n");
    int i,flag=0;
    char name[1000];
    i=search(1);
    stationmax();
    printf("\t\t\t\t\t\t  ������վ������:");
    scanf("%s",&name);
    if(strlen(name)>20){
        printf("\t\t\t\t\t\t  վ�����ֹ�����\n");
        return;
    }
    else{
    strcpy((station[i-1].stname),name);
    station[i].num=i+1;
    save();
    }
}
void deletestation(){
    printf("\n\t\t\t\t\t\t  ������·����ϵͳ\n\n");
    printf("\t\t\t\t\t\t  ɾ������վ��\n\n");
    for(int j=0;j<500;j++){
        if(station[j].num!=0&&*station[j].stname!='\0'){
        printf("\t\t\t\t\t\t  %d\t%s\n",station[j].num,station[j].stname);
        }
    }
    printf("\n\t\t\t\t\t\t  ������վ����:");
    char cin[1000];
    int i,flag,num;
    if(scanf("%d",&num)){
        for(i=0;i<500;i++){
            if(station[i].num==num&&*station[i].stname!='\0'){
                break;
            }
        }
        if(station[num-1].num==0||*station[num-1].stname=='\0'){
            printf("\n\t\t\t\t\t\t  �Ҳ�����վ��\n");
            return;
        }
        else{
            printf("\n\t\t\t\t\t\t  ȷ��Ҫɾ����վ����?(Y/N)");
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
        printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
        return;
    }
}
void changestation(){
    printf("\n\t\t\t\t\t\t  ������·����ϵͳ\n\n");
    printf("\t\t\t\t\t\t  �޸Ĺ���վ��\n");
    char name[1000];
    int i,num,flag=0;                                                   //����������ʱ����
    printf("\t\t\t\t\t\t  ��������Ҫ�޸ĵ�վ����:");
    if(scanf("%d",&num)){
        fflush(stdin);
        for(i=0;i<500;i++){
            if(station[i].num==num&&*station[i].stname!='\0'){
                flag++;                                                     //��������ʱ���б��
                break;
            }
        }
        if(flag==1){
            printf("\n\t\t\t\t\t\t  ԭվ������Ϊ:%s\n\t\t\t\t\t\t  �������޸ĺ��վ������:",station[i].stname);
            scanf("%s",&name);
            if(strlen(name)>20){                                            //�ж������ַ�����
                printf("\t\t\t\t\t\t  վ�����ֹ�����\n");
                return;
            }
            else{
                strcpy(station[i].stname,name);                             //������ʱ����վ�����Ƶ��ṹ����
                printf("\n\t\t\t\t\t\t  �޸���ϣ�\n");
            }
        }
        else{
            printf("\t\t\t\t\t\t  �Ҳ����ñ������Ӧ��վ��\n");
            return;
        }
    }
    else{
        printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
        return;
    }
    save();
}
void addline(){
    printf("\n\t\t\t\t\t\t  ������·����ϵͳ\n\n");
    printf("\t\t\t\t\t\t  ����������·\n\n");
    char name[1000];                                                     //��ʱ��������
    int i,j,flag1=0,flag2=0,start,end;                                   //������ʱ���������վ�յ�վ���
    linemax();
    i=search(2);
    printf("\t\t\t\t\t\t  ��������·����:\n\t\t\t\t\t\t  ");
    scanf("%s",&name);
    if(strlen(name)>20){
        printf("\t\t\t\t\t\t  ��·���ֹ�����\n");
        return;
    }
    else{
    strcpy(line[i-1].liname,name);
    line[i].num=i+1;
    }
    printf("\t\t\t\t\t\t  ���������վ���\n\t\t\t\t\t\t  ");
    if(scanf("%d",&start))
        for(j=0;j<500;j++){
            if(start!=0&&start==station[j].num) {
                line[i-1].sta[0].num=start;
                strcpy(line[i-1].sta[0].stname,station[start-1].stname);
                flag1++;
            }
        }
    else{
        printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
        return;
    }
    while(flag1==0){
        printf("\t\t\t\t\t\t  �Ҳ�����վ��,����������:");
        if(scanf("%d",&start))
            for(j=0;j<500;j++){
                if(start!=0&&start==station[j].num) {
                    line[i-1].sta[0].num=start;
                    strcpy(line[i-1].sta[0].stname,station[start].stname);
                    flag1++;
                }
            }
        else{
            printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
            return;
        }
    }
    printf("\t\t\t\t\t\t  �������յ�վ���\n\t\t\t\t\t\t  ");
    if(scanf("%d",&end))
        for(j=0;j<500;j++){
            if(end!=0&&end==station[j].num) {
                line[i-1].endnum=end;
                strcpy(line[i-1].endname,station[end-1].stname);
                flag2++;
            }
        }
    else{
        printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
        return;
    }
    while(flag2==0){
        printf("\t\t\t\t\t\t  �Ҳ�����վ��,����������:");
        if(scanf("%d",&end))
            for(j=0;j<500;j++){
                if(end!=0&&end==station[j].num) {
                    line[i].endnum=end;
                    strcpy(line[i].endname,station[end-1].stname);
                    flag2++;
                }
            }
        else{
            printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
            return;
        }
    }   
    save();
}
void changeline(){
    int num1=0;
    char cin[1000];                                                     //����������ַ�
    int i,j,num,flag=0,cin1,cin2,m,t;                                   //����������ʱ����
    j=search(1);
    if(*line[0].liname=='\0'){
        printf("\t\t\t\t\t\t  ���������·\n");
        return;
    }
    printf("\t\t\t\t\t\t  ��������Ҫ�޸ĵ���·���:");
    if(scanf("%d",&num))
        for(i=0;i<100;i++){
            if(line[i].num==num&&*line[i].liname!='\0'){
                flag++;                                                     //��������ʱ���б��
                break;
            }
        }
        else{
            printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
            return;
        }
    while(1){
        if(flag==0){
            printf("\t\t\t\t\t\t  �Ҳ����ñ������Ӧ����·\n");
            back();
            printf("\t\t\t\t\t\t  ��������Ҫ�޸ĵ���·���:");
            if(scanf("%d",&num))
                for(i=0;i<100;i++){
                    if(line[i].num==num&&*line[i].liname!='\0'){
                        flag++;                                             //��������ʱ���б��
                        break;
                    }
                }
            else{
                printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
                return;
            }
            system("cls");
            continue;
        }
        system("cls");
        printf("\t\t\t\t\t\t  �����޸ĵ���·Ϊ:\n\n");
        printf("\t\t\t\t  %d\t%s\t���վ��%d %s -> ",line[i].num,line[i].liname,line[i].sta[0].num,line[i].sta[0].stname);
        for(int j=1;j<500;j++){
            if(*line[i].sta[j].stname!='\0')
            printf("%d %s -> ",line[i].sta[j].num,line[i].sta[j].stname);
        }
        printf("�յ�վ��%d %s\n\n",line[i].endnum,line[i].endname);
        printf("\t\t\t\t\t  *******************************\n");
        printf("\t\t\t\t\t  *       ����������·�˵�      *\n");
        printf("\t\t\t\t\t  *                             *\n");
        printf("\t\t\t\t\t  *       1��������·����       *\n");
        printf("\t\t\t\t\t  *       2��������·���վ     *\n");
        printf("\t\t\t\t\t  *       3��������·�յ�վ     *\n");
        printf("\t\t\t\t\t  *       4��������·;��վ     *\n");
        printf("\t\t\t\t\t  *       5��ɾ��������·       *\n");
        printf("\t\t\t\t\t  *       6. ����               *\n");
        printf("\t\t\t\t\t  *******************************\n");
        printf("\t\t\t\t\t          �����������ţ�");
        fflush(stdin);
        num1=0;
        if(scanf("%d",&num1))
            while(num1<=0||num1>=7){
                printf("\t\t\t\t\t\t  ������������ȷ������:");
                if(!scanf("%d",&num1)){
                    printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
                    return;
                }
            }
        else{
            printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
            return;
        }
        switch(num1){
            case 1: {
                printf("\n\t\t\t\t\t\t  ԭ��·����Ϊ:%s\n\t\t\t\t\t\t  �������޸ĺ����·����:",line[i].liname);
                scanf("%s",&cin);
                if(strlen(cin)>20){                                             //�ж������ַ�����
                    printf("\t\t\t\t\t\t  ��·���ֹ�����\n");
                    back();
                    continue;
                }
                else{
                    strcpy(line[i].liname,cin);                                 //������ʱ����վ�����Ƶ��ṹ����
                    printf("\n\t\t\t\t\t\t  �޸���ϣ�\n");
                }
            save();
            Sleep(500);
            system("cls");
            }break;
            case 2: {
                printf("\n\t\t\t\t\t\t  ԭ��·���վΪ:%d %s\n\t\t\t\t\t\t  �������޸ĺ�����վ���:",line[i].sta[0].num,line[i].sta[0].stname);
                if(scanf("%d",&cin1)){
                    if(cin1>j||cin1<=0){
                        printf("\t\t\t\t\t\t  �Ҳ�����Ӧվ�㣡\n");
                        back();
                        continue;
                    }
                    else{
                        line[i].sta[0].num=cin1;                                    //������ʱ����վ�����Ƶ��ṹ����
                        strcpy(line[i].sta[0].stname,station[cin1].stname);
                        printf("\n\t\t\t\t\t\t  �޸���ϣ�\n");
                    }
                save();
                Sleep(500);
                system("cls");
                }
                else{
                    printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
                    back();
                    continue;
                }
            }break;
            case 3: {
                printf("\n\t\t\t\t\t\t  ԭ��·�յ�վΪ:%d %s\n\t\t\t\t\t\t  �������޸ĺ���յ�վ���:",line[i].endnum,line[i].endname);
                if(scanf("%d",&cin1)){
                    if(cin1>j||cin1<=0){
                        printf("\t\t\t\t\t\t  �Ҳ�����Ӧվ�㣡\n");
                        back();
                        continue;
                    }
                    else{
                        line[i].endnum=cin1;                                        //������ʱ����վ�����Ƶ��ṹ����
                        strcpy(line[i].endname,station[cin1].stname);
                        printf("\n\t\t\t\t\t\t  �޸���ϣ�\n");
                    }
                save();
                Sleep(500);
                system("cls");
                }
                else{
                    printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
                    back();
                    continue;
                }
            }break;
            case 4: {
                printf("\n\t\t\t\t\t\t  ������;��վ���:");
                if(scanf("%d",&cin1)){
                    if(cin1>j||cin1<=0){
                        printf("\t\t\t\t\t\t  �Ҳ�����Ӧվ�㣡\n");
                        back();
                        continue;
                    }
                    else{
                        printf("\n\t\t\t\t\t\t  ������;��վ����λ��(���վ��Ϊ1,����ÿһվ��1)");
                        if(scanf("%d",&cin2))
                            for(m=0;m<500;m++){
                                if(line[i].sta[m].num==0){
                                break;
                                }
                            }
                        else{
                            printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
                            back();
                            continue;
                        }
                        if(cin2>m||cin2<1){
                            printf("\t\t\t\t\t\t  λ�������������������");
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
                            printf("\n\t\t\t\t\t\t  �޸���ϣ�\n");
                        }
                    }
                }
                else{
                    printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
                    back();
                    continue;
                }
            save();
            Sleep(500);
            system("cls");
            }break;
            case 5: {
                printf("\n\t\t\t\t\t\t  ȷ��Ҫɾ������·��?(Y/N)");
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
    printf("\n\t\t\t\t\t\t  ������·����ϵͳ\n");
    printf("\n\t\t\t\t\t\t  ��ѯ������·\n");
    int i,cin;
    for(i=0;i<100;i++){
        if(line[i].num!=0&&*line[i].liname!='\0'){
        printf("\t\t\t\t  %d\t%s\t���վ��%d %s -> ",line[i].num,line[i].liname,line[i].sta[0].num,line[i].sta[0].stname);
        for(int j=1;j<500;j++){
            if(*line[i].sta[j].stname!='\0')
            printf("%d %s -> ",line[i].sta[j].num,line[i].sta[j].stname);
        }
        printf("�յ�վ��%d %s\n\n",line[i].endnum,line[i].endname);
        }
    }
    printf("\n\t\t\t\t\t\t  ��������Ҫ��ѯ����·���:");
    if(scanf("%d",&cin))
        if(*line[cin-1].liname!='\0'){
            printf("\t\t\t\t  %d\t%s\t���վ��%d %s -> ",line[cin-1].num,line[cin-1].liname,line[cin-1].sta[0].num,line[cin-1].sta[0].stname);
            for(int j=1;j<500;j++){
                if(line[cin-1].sta[j].num!=0&&*line[cin-1].sta[j-1].stname!='\0')
                printf("%d %s -> ",line[cin-1].sta[j].num,line[cin-1].sta[j].stname);
            }
            printf("�յ�վ��%d %s\n",line[cin-1].endnum,line[cin-1].endname);
        }
        else{
            printf("\n\t\t\t\t\t\t  ��ѯ�����ñ�Ŷ�Ӧ����·");
        }
        else {
            printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
            return;
        }
}
int menu(){                                                                 //�˵�����
    int num1=0;
    printf("\t\t\t\t\t  *******************************\n");
    printf("\t\t\t\t\t  *       ������·����ϵͳ      *\n");
    printf("\t\t\t\t\t  *                             *\n");
    printf("\t\t\t\t\t  *      1. ��ʾȫ��վ����Ϣ    *\n");
    printf("\t\t\t\t\t  *      2����������վ��        *\n");
    printf("\t\t\t\t\t  *      3��ɾ������վ��        *\n");
    printf("\t\t\t\t\t  *      4���޸Ĺ���վ��        *\n");
    printf("\t\t\t\t\t  *      5������������·        *\n");
    printf("\t\t\t\t\t  *      6������������·        *\n");
    printf("\t\t\t\t\t  *      7. ��ѯ������·        *\n");
    printf("\t\t\t\t\t  *      8���˳�                *\n");
    printf("\t\t\t\t\t  *******************************\n");
    printf("\t\t\t\t\t          �����������ţ�");
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
            default: printf("\t\t\t\t\t\t��������ȷ�����֡�\n\t\t\t\t\t\t  ����س�����....\n\t\t\t\t\t\t");
                    fflush(stdin);
                    getchar();
                    system("cls");
                    return 1;
                    break;
        }
    }
    else{
        printf("\n\t\t\t\t\t\t  ���벻�Ϸ�\n");
        return 1;
    }
    system("pause");
    return 0;
}

int main(){
    system("color F0");                                             //���ն˵�ɫΪ�׵׺��ֱ��ڲ���
    read();
    fflush(stdin);
    int flag=1;
    flag=menu();                                                    //ѭ���ṹ��ʹmenu�ܹ�ʵ���Զ�����������һ��
    while(flag==1){
        back();
        flag=menu();
    }
    if(flag==2) return 0;                                           //�˳�����
    system("pause");
    return 0;
}
