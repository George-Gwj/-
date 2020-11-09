/****************************************************************************
**程序描述:学生成绩管理系统
**日期：2020/11/8
****************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 30
#define M 6
#define P 60
#define Q 15
void ReadName_Number_ScoreOfCourses(int score[][Q],char Name_Number[][Q],char Course[][Q],int n,int m);
void Print_Number_Name_Score_Total_Average(int score[][Q],int sum_1[],char Name_Number[][Q],char Course[][Q],int n,int m);
void Total_and_Average_Score_Of_Courses(int score[][Q],int sum_2[],char Course[][Q],int n,int m);
void Total_and_Average_Score_Of_Students(int sum_1[],char Name_Number[][Q],int n,int m);
void SelectionSort_Total(int sum[],char Name_Number[][Q],int n,int (*compare)(int a,int b));
void Print(int sum[],char Name_Number[][Q],int n);
int Ascending(int a,int b);
int Descending(int a,int b);
void AscendingNumber(int sum[],char Name_Number[][Q],int n);
void SortString(int score[][Q],int sum[],char Name_Number[][Q],int n,int m);
void Grade(int score[][Q],char Course[][Q],int n,int m);
int main()
{
    printf("1.Input record\n");
    printf("2.List record\n");
    printf("3.Calculate total and average score of every course\n");
    printf("4.Calculate total and average score of every student\n");
    printf("5.Sort in descending order by total score of every student\n");
    printf("6.Sort in ascending order by total score of every student\n");
    printf("7.Sort in ascending order by studentID\n");
    printf("8.Sort in dictionary order by name\n");
    printf("9.Search by studentID\n");
    printf("10.Search by name\n");
    printf("11.Statistic analysis for every course\n");
    printf("0.Exit\n");
    int score[N][Q],n,m,sum_1[N]= {0},sum_2[N]= {0},i,j,k;
    /**score[N][Q]:行指的是学生；列指的是各科成绩
      对sun_1[],sum_2[]初始化为0
      k用于输入指令0-11**/
    char Name_Number[P][Q],Course[M][Q],xname[Q],xnumber[Q];
    /**Name_Number[][]前三十行存储姓名；后三十行存储学号
      Course[][]每一行存储不同的学科；
      xname[]存储输入查找的名字，xnumber[]存储输入查找的学号**/
    printf("How many students?\n");
    scanf("%d",&n);
    printf("How many courses?\n");
    scanf("%d",&m);
    printf("Input courses:\n");
    for(j=0; j<m; j++)
    {
        scanf("%s",Course[j]);
    }
    do
    {
        printf("Please enter your choice:");
        scanf("%d",&k);
        if(k!=1)
        {
            printf("请先录入学生的信息!\n");
        }
        else
            ///录入每个学生的学号、姓名和各科考试成绩
        {
            ReadName_Number_ScoreOfCourses(score,Name_Number,Course,n,m);
            printf("录入完成!\n");
        }
    }
    while(k!=1);
    do
    {
        do
        {
            printf("Input a number from 0 to 10:");
            scanf("%d",&k);
            if(k<0||k>10)
                printf("Input error!Please try it again!\n");
        }
        while(k<0||k>10);
        switch(k)
        {
        case 1:
            ///录入每个学生的学号、姓名和各科考试成绩
            ReadName_Number_ScoreOfCourses(score,Name_Number,Course,n,m);
            printf("录入完成!\n");
            break;
        case 2:
            ///输出每个学生的学号、姓名、各科考试成绩、总分、平均分（按输入顺序输出）
            Print_Number_Name_Score_Total_Average(score,sum_1,Name_Number,Course,n,m);
            break;
        case 3:
            ///计算每门课程的总分和平均分
            Total_and_Average_Score_Of_Courses(score,sum_2,Course,n,m);
            break;
        case 4:
            ///计算每个学生的总分和平均分
            Total_and_Average_Score_Of_Students(sum_1,Name_Number,n,m);
            break;
        case 5:
            ///按每个学生的总分由高到低排出名次表
            SelectionSort_Total(sum_1,Name_Number,n,Descending);
            Print(sum_1,Name_Number,n);
            break;
        case 6:
            ///按每个学生的总分由低到高排出名次表
            SelectionSort_Total(sum_1,Name_Number,n,Ascending);
            Print(sum_1,Name_Number,n);
            break;
        case 7:
            ///按学号由小到大排出成绩表
            AscendingNumber(sum_1,Name_Number,n);
            Print_Number_Name_Score_Total_Average(score,sum_1,Name_Number,Course,n,m);
            break;
        case 8:
            ///按姓名的字典顺序排出成绩表
            SortString(score,sum_1,Name_Number,n,m);
            Print_Number_Name_Score_Total_Average(score,sum_1,Name_Number,Course,n,m);
            break;
        case 9:
            ///按学号查询学生排名及其各科考试成绩
            printf("请输入需要查询的学号:");
            scanf("%s",xnumber);
            for(i=0; i<n; i++)
            {
                if(strcmp(Name_Number[i+N],xnumber)==0)
                {
                    printf("Rank\tName\t");
                    for(j=0; j<m; j++)
                    {
                        printf("%s\t",Course[j]);
                    }
                    printf("\n");
                    printf("%d\t%s\t",i+1,Name_Number[i]);
                    for(j=0; j<m; j++)
                    {
                        printf("%d\t",score[i][j]);
                    }
                    printf("\n");

                }
            }
            break;
        case 10:
            ///按姓名查询学生排名及其各科考试成绩
            printf("请输入需要查询的姓名:");
            scanf("%s",xname);
            int i,j;
            for(i=0; i<n; i++)
            {
                if(strcmp(Name_Number[i],xname)==0)
                {
                    printf("Rank\tName\t");
                    for(j=0; j<m; j++)
                    {
                        printf("%s\t",Course[j]);
                    }
                    printf("\n");
                    printf("%d\t%s\t",i+1,Name_Number[i]);
                    for(j=0; j<m; j++)
                    {
                        printf("%d\t",score[i][j]);
                    }
                    printf("\n");

                }
            }
            break;
        case 11:
            ///按优秀（90-100分）、良好（80-89分）、中等（70-79分）、及格（60 -69分）、不及格(0-59分)5个类别，对每门课程分别统计每个类别的人数以及所占的百分比
            Grade(score,Course,n,m);
            break;
        }
    }
    while(i!=0);
}
/**函数功能:录入每个学生的学号、姓名和各科考试成绩
**i表示学生
**j表示学科
**日期：2020/11/8
**/
void ReadName_Number_ScoreOfCourses(int score[][Q],char Name_Number[][Q],char Course[][Q],int n,int m)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("Input name:");
        scanf("%s",Name_Number[i]);
        printf("Input number:");
        scanf("%s",Name_Number[i+N]);
        for(j=0; j<m; j++)
        {
            printf("Input scores:\n");
            printf("%s:",Course[j]);
            scanf("%d",&score[i][j]);
        }
    }
}
/**函数功能:输出每个学生的学号、姓名、各科考试成绩、总分、平均分（按输入顺序输出）
**i表示学科
**j表示学生
**average每个学生所有学科的平均分
**日期：2020/11/8
**/
void Print_Number_Name_Score_Total_Average(int score[][Q],int sum_1[],char Name_Number[][Q],char Course[][Q],int n,int m)
{
    int i,j;
    memset(sum_1,0,N);///每次打印前将sum[]数组初始化为0,防止sum[]被多次赋值
    double average;
    printf("**********************************************************************************************************************\n");
    printf("学号\t姓名\t");
    for(i=0; i<m; i++)
    {
        printf("%s\t",Course[i]);
    }
    printf("总分\t平均分\n");
    for(i=0; i<n; i++)
    {
        printf("%s\t%s\t",Name_Number[i+N],Name_Number[i]);
        for(j=0; j<m; j++)
        {
            printf("%d\t",score[i][j]);
        }
        for(j=0; j<m; j++)
        {
            sum_1[i]+=score[i][j];
        }
        average = (double)sum_1[i]/m;
        printf("%d\t%.2lf\t",sum_1[i],average);
        printf("\n");
    }
    printf("**********************************************************************************************************************\n");
}
/**函数功能:计算每门课程的总分和平均分
**i表示学科
**j表示学生
**average表示每个学科的平均分
**日期：2020/11/8
**/
void Total_and_Average_Score_Of_Courses(int score[][Q],int sum_2[],char Course[][Q],int n,int m)
{
    int i,j;
    double average;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            sum_2[i]+=score[j][i];
        }
        average = (double)sum_2[i]/n;
        printf("%s学科的总分是:%d\t平均分是:%.2lf\t\n",Course[i],sum_2[i],average);
    }

}
/**函数功能:计算每个学生的总分和平均分
**i表示学生
**average表示每个学生所有学科的平均分
**日期：2020/11/8
**/
void Total_and_Average_Score_Of_Students(int sum_1[],char Name_Number[][Q],int n,int m)
{
    int i;
    double average;
    for(i=0; i<n; i++)
    {
        average=(double)sum_1[i]/m;
        printf("%s\t学生的学科总分是:%d\t平均分是:%.2lf\n",Name_Number[i],sum_1[i],average);
    }
}
/**函数功能:按每个学生的总分 /由高到低/ 由低到高/ 排出名次表
**调用模块:Ascending 和 Descending函数
**i,j表示学生人数
**temp_x[]用于作为字符串交换的中间变量
**日期：2020/11/8
**/
void SelectionSort_Total(int sum_1[],char Name_Number[][Q],int n,int(*compare)(int a,int b))
{
    int i,j,temp;
    char temp_x[Q];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if((*compare)(sum_1[j],sum_1[i]))
            {
                temp=sum_1[i];
                sum_1[i]=sum_1[j];
                sum_1[j]=temp;
                strcpy(temp_x,Name_Number[i]);
                strcpy(Name_Number[i],Name_Number[j]);
                strcpy(Name_Number[j],temp_x);
            }
        }
    }
}
///函数功能:打印学生排名和总成绩

void Print(int sum_1[],char Name_Number[][Q],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Rank %d:\t%s\tTotal is %d\n",i+1,Name_Number[i],sum_1[i]);
    }
}
///函数功能:传递由高到低的信息到SelectionSort函数
int Ascending(int a,int b)
{
    return a<b;
}
///函数功能:传递由低到高的信息到SelectionSort函数
int Descending(int a,int b)
{
    return a>b;
}
//函数功能:按学号由小到大排出成绩表
void AscendingNumber(int sum_1[],char Name_Number[][Q],int n)
{
    int i,j,temp;
    char temp_x[Q];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(Name_Number[j+N]<Name_Number[i+N])
            {
                temp=sum_1[i];
                sum_1[i]=sum_1[j];
                sum_1[j]=temp;
                strcpy(temp_x,Name_Number[i]);
                strcpy(Name_Number[i],Name_Number[j]);
                strcpy(Name_Number[j],temp_x);
                strcpy(temp_x,Name_Number[i+N]);
                strcpy(Name_Number[i+N],Name_Number[j+N]);
                strcpy(Name_Number[j+N],temp_x);
            }
        }
    }
}
/**函数功能:按姓名的字典顺序排出成绩表
**i,j表示学生
**k表示学科
**temp_x[]作为字符串交换的中间变量
**temp_y[]作为整型二维数组中一整行交换的中间变量
**日期：2020/11/8
**/
void SortString(int score[][Q],int sum_1[],char Name_Number[][Q],int n,int m)
{
    int i,j,k,temp;
    char temp_x[Q];
    int temp_y[Q];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(Name_Number[j],Name_Number[i])<0)
            {
                strcpy(temp_x,Name_Number[i]);
                strcpy(Name_Number[i],Name_Number[j]);
                strcpy(Name_Number[j],temp_x);
                strcpy(temp_x,Name_Number[i+N]);
                strcpy(Name_Number[i+N],Name_Number[j+N]);
                strcpy(Name_Number[j+N],temp_x);
                temp=sum_1[i];
                sum_1[i]=sum_1[j];
                sum_1[j]=temp;
                for(k=0; k<m; k++)
                {
                    temp_y[k]=score[i][k];
                    score[i][k]=score[j][k];
                    score[j][k]=temp_y[k];
                }
            }
        }
    }
}
/**函数功能:按优秀（90-100分）、良好（80-89分）、中等（70-79分）、及格（60 -69分）、不及格(0-59分)5个类别，对每门课程分别统计每个类别的人数以及所占的百分比
**one,two,three,four,five分别表示优秀，良好，中等，及格，不及格五个等级
**j表示学科
**k表示学生
**日期2020/11/8
**/
void Grade(int score[][Q],char Course[][Q],int n,int m)
{
    int j,k;
    for(j=0; j<m; j++)
    {
        int one=0,two=0,three=0,four=0,five=0;
        for(k=0; k<n; k++)
        {
            if(score[j][k]>=0&&score[j][k]<=60)
                five++;
            else if(score[j][k]>=60&&score[j][k]<=69)
                four++;
            else if(score[j][k]>=70&&score[j][k]<=79)
                three++;
            else if(score[j][k]>=80&&score[j][k]<=89)
                two++;
            else
                one++;
        }
        printf("*********************************************************************************\n");
        printf("%s\n",Course[j]);
        printf("优秀的人有%d人，所占百分比是%.2f:\n",one,(double)one/n);
        printf("良好的人有%d人，所占百分比是%.2f:\n",two,(double)two/n);
        printf("中等的人有%d人，所占百分比是%.2f:\n",three,(double)three/n);
        printf("及格的人有%d人，所占百分比是%.2f:\n",four,(double)four/n);
        printf("不及格的人有%d人，所占百分比是%.2f:\n",five,(double)five/n);
        printf("*********************************************************************************\n");
    }
}
