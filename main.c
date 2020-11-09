/****************************************************************************
**��������:ѧ���ɼ�����ϵͳ
**���ڣ�2020/11/8
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
    /**score[N][Q]:��ָ����ѧ������ָ���Ǹ��Ƴɼ�
      ��sun_1[],sum_2[]��ʼ��Ϊ0
      k��������ָ��0-11**/
    char Name_Number[P][Q],Course[M][Q],xname[Q],xnumber[Q];
    /**Name_Number[][]ǰ��ʮ�д洢����������ʮ�д洢ѧ��
      Course[][]ÿһ�д洢��ͬ��ѧ�ƣ�
      xname[]�洢������ҵ����֣�xnumber[]�洢������ҵ�ѧ��**/
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
            printf("����¼��ѧ������Ϣ!\n");
        }
        else
            ///¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
        {
            ReadName_Number_ScoreOfCourses(score,Name_Number,Course,n,m);
            printf("¼�����!\n");
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
            ///¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
            ReadName_Number_ScoreOfCourses(score,Name_Number,Course,n,m);
            printf("¼�����!\n");
            break;
        case 2:
            ///���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֡�ƽ���֣�������˳�������
            Print_Number_Name_Score_Total_Average(score,sum_1,Name_Number,Course,n,m);
            break;
        case 3:
            ///����ÿ�ſγ̵��ֺܷ�ƽ����
            Total_and_Average_Score_Of_Courses(score,sum_2,Course,n,m);
            break;
        case 4:
            ///����ÿ��ѧ�����ֺܷ�ƽ����
            Total_and_Average_Score_Of_Students(sum_1,Name_Number,n,m);
            break;
        case 5:
            ///��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
            SelectionSort_Total(sum_1,Name_Number,n,Descending);
            Print(sum_1,Name_Number,n);
            break;
        case 6:
            ///��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
            SelectionSort_Total(sum_1,Name_Number,n,Ascending);
            Print(sum_1,Name_Number,n);
            break;
        case 7:
            ///��ѧ����С�����ų��ɼ���
            AscendingNumber(sum_1,Name_Number,n);
            Print_Number_Name_Score_Total_Average(score,sum_1,Name_Number,Course,n,m);
            break;
        case 8:
            ///���������ֵ�˳���ų��ɼ���
            SortString(score,sum_1,Name_Number,n,m);
            Print_Number_Name_Score_Total_Average(score,sum_1,Name_Number,Course,n,m);
            break;
        case 9:
            ///��ѧ�Ų�ѯѧ������������ƿ��Գɼ�
            printf("��������Ҫ��ѯ��ѧ��:");
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
            ///��������ѯѧ������������ƿ��Գɼ�
            printf("��������Ҫ��ѯ������:");
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
            ///�����㣨90-100�֣������ã�80-89�֣����еȣ�70-79�֣�������60 -69�֣���������(0-59��)5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
            Grade(score,Course,n,m);
            break;
        }
    }
    while(i!=0);
}
/**��������:¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
**i��ʾѧ��
**j��ʾѧ��
**���ڣ�2020/11/8
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
/**��������:���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֡�ƽ���֣�������˳�������
**i��ʾѧ��
**j��ʾѧ��
**averageÿ��ѧ������ѧ�Ƶ�ƽ����
**���ڣ�2020/11/8
**/
void Print_Number_Name_Score_Total_Average(int score[][Q],int sum_1[],char Name_Number[][Q],char Course[][Q],int n,int m)
{
    int i,j;
    memset(sum_1,0,N);///ÿ�δ�ӡǰ��sum[]�����ʼ��Ϊ0,��ֹsum[]����θ�ֵ
    double average;
    printf("**********************************************************************************************************************\n");
    printf("ѧ��\t����\t");
    for(i=0; i<m; i++)
    {
        printf("%s\t",Course[i]);
    }
    printf("�ܷ�\tƽ����\n");
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
/**��������:����ÿ�ſγ̵��ֺܷ�ƽ����
**i��ʾѧ��
**j��ʾѧ��
**average��ʾÿ��ѧ�Ƶ�ƽ����
**���ڣ�2020/11/8
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
        printf("%sѧ�Ƶ��ܷ���:%d\tƽ������:%.2lf\t\n",Course[i],sum_2[i],average);
    }

}
/**��������:����ÿ��ѧ�����ֺܷ�ƽ����
**i��ʾѧ��
**average��ʾÿ��ѧ������ѧ�Ƶ�ƽ����
**���ڣ�2020/11/8
**/
void Total_and_Average_Score_Of_Students(int sum_1[],char Name_Number[][Q],int n,int m)
{
    int i;
    double average;
    for(i=0; i<n; i++)
    {
        average=(double)sum_1[i]/m;
        printf("%s\tѧ����ѧ���ܷ���:%d\tƽ������:%.2lf\n",Name_Number[i],sum_1[i],average);
    }
}
/**��������:��ÿ��ѧ�����ܷ� /�ɸߵ���/ �ɵ͵���/ �ų����α�
**����ģ��:Ascending �� Descending����
**i,j��ʾѧ������
**temp_x[]������Ϊ�ַ����������м����
**���ڣ�2020/11/8
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
///��������:��ӡѧ���������ܳɼ�

void Print(int sum_1[],char Name_Number[][Q],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Rank %d:\t%s\tTotal is %d\n",i+1,Name_Number[i],sum_1[i]);
    }
}
///��������:�����ɸߵ��͵���Ϣ��SelectionSort����
int Ascending(int a,int b)
{
    return a<b;
}
///��������:�����ɵ͵��ߵ���Ϣ��SelectionSort����
int Descending(int a,int b)
{
    return a>b;
}
//��������:��ѧ����С�����ų��ɼ���
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
/**��������:���������ֵ�˳���ų��ɼ���
**i,j��ʾѧ��
**k��ʾѧ��
**temp_x[]��Ϊ�ַ����������м����
**temp_y[]��Ϊ���Ͷ�ά������һ���н������м����
**���ڣ�2020/11/8
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
/**��������:�����㣨90-100�֣������ã�80-89�֣����еȣ�70-79�֣�������60 -69�֣���������(0-59��)5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
**one,two,three,four,five�ֱ��ʾ���㣬���ã��еȣ����񣬲���������ȼ�
**j��ʾѧ��
**k��ʾѧ��
**����2020/11/8
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
        printf("���������%d�ˣ���ռ�ٷֱ���%.2f:\n",one,(double)one/n);
        printf("���õ�����%d�ˣ���ռ�ٷֱ���%.2f:\n",two,(double)two/n);
        printf("�еȵ�����%d�ˣ���ռ�ٷֱ���%.2f:\n",three,(double)three/n);
        printf("���������%d�ˣ���ռ�ٷֱ���%.2f:\n",four,(double)four/n);
        printf("�����������%d�ˣ���ռ�ٷֱ���%.2f:\n",five,(double)five/n);
        printf("*********************************************************************************\n");
    }
}
