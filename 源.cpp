#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;

struct student {
    char name[20];
    int sum;
    int zz;
    int eng;
    int math;
    int pro;
    int flag;
};



void Begin();
void readStudent();
void ruleShow();
void showStudent();
bool cmp(struct student A ,struct student B);
bool cmp1(struct student A, struct student B);
bool cmp2(struct student A, struct student B);
bool cmp3(struct student A, struct student B);

int main() {
	Begin();
    /*FILE* fp;
    fp = fopen("1.txt","w");
    srand(time(NULL));
    char a[10][3] = { "张","李","赵","周","吴","郑","钱","齐","秦","郭"};
    char a1[10][6] = { "锽","一","六","七","八","久","三","二","四","五"};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int zz = rand() % 99 + 1;
            int eng = rand() % 99 + 1;
            int math = rand() % 149 + 1;
            int pro = rand() % 149 + 1;
            int sum = zz + eng + math + pro;
            fprintf(fp,"%s%s %d %d %d %d %d\n",a[i],a1[j],sum,zz,eng,math,pro);
        }
    }*/
	return 0;
}

void Begin() {
    while (true) {
        system("cls");
        char ch;
        printf("******************************************************\n");
        printf("         欢迎使用研究生招生考试成绩排序程序\n");
        printf("------------------------------------------------------\n\n\n\n");
        printf("                    >欢迎使用<\n\n\n\n\n");
        printf("******************************************************\n");
        system("pause");
        system("cls");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("输入“1”以查询学生成绩\n");
        printf("输入“2”以输入录取规则[科目最低分，优先学科(相同分数，排名靠前)]\n");
        printf("输入“3”以查看录取学生\n");
        printf("输入“4”以退出程序\n");
        printf("请输入对应的数字，谢谢：\n\t");
        int num;
        cin >> num;
        switch (num)
        {
        case 1:readStudent(); break;
        case 2:ruleShow(); break;
        case 3:showStudent(); break;
        case 4:system("cls"); printf("\n\n\n\t\t\t 谢谢使用！\n "); exit(0); break;
        default:printf("输入错误\n "); break;
        }
    }
}
void readStudent() {
    while (true)
    {
        system("cls");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("******************学生成绩信息************************\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("姓名      总分      政治      英语      数学     专业课\n");
        struct student s[1000];
        FILE* fp;
        fp = fopen("1.txt", "r");
        int i;
        for (i = 0; !feof(fp); i++) {
            fscanf(fp, "%s %d %d %d %d %d", s[i].name, &s[i].sum, &s[i].zz, &s[i].eng, &s[i].math, &s[i].pro);
        }
        for (int j = 0; j < i - 1; j++) {
            printf("%s     %d      %d       %d       %d       %d\t\n", s[j].name, s[j].sum, s[j].zz, s[j].eng, s[j].math, s[j].pro);
        }
        fclose(fp);
        printf("\n******************************************************\n");
        printf("******************************************************\n");
        printf("查看是否完成？ Y/N\n");
        char ch;
        cin >> ch;
        if (ch == 'Y') {
            Begin();
        }
        else {
            readStudent();
        }
    }
}
void ruleShow() {
    while (true)
    {
        system("cls");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("******************输入录取规则************************\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("\n输入要求的最低总分：\n");
        int numSum;
        cin >> numSum;
        printf("\n输入要求的政治最低分：\n");
        int numZZ;
        cin >> numZZ;
        printf("\n输入要求的英语最低分：\n");
        int numEng;
        cin >> numEng;
        printf("\n输入要求的数学最低分：\n");
        int numMath;
        cin >> numMath;
        printf("\n输入要求的专业课最低分：\n");
        int numPro;
        cin >> numPro;
        printf("\n输入优先学科：（政治/英语/数学/专业课）\n");
        char arr[100];
        cin >> arr;
        struct student s[1000];
        FILE* fp;
        fp = fopen("1.txt", "r");
        int i;
        for (i = 0; !feof(fp); i++) {
            fscanf(fp, "%s %d %d %d %d %d", s[i].name, &s[i].sum, &s[i].zz, &s[i].eng, &s[i].math, &s[i].pro);
            s[i].flag = 1;
        }
        fclose(fp); 

        FILE* fp1;
        fp1 = fopen("2.txt", "w");
        for (int j = 0; j < i - 1; j++) {
            if (s[j].sum < numSum || s[j].zz < numZZ || s[j].eng < numEng || s[j].math < numMath || s[j].pro < numPro) {
                s[j].flag = 0;
            }
        }
        if (strcmp(arr, "政治")==0) {
            sort(s, s + i - 1, cmp);
        }else if (strcmp(arr, "英语") == 0) {
            sort(s, s + i - 1, cmp1);
        }else if (strcmp(arr, "数学") == 0) {
            sort(s, s + i - 1, cmp2);
        }else if (strcmp(arr, "专业课") == 0) {
            sort(s, s + i - 1, cmp3);
        }
        for (int j = 0; j < i - 1; j++) {
            if (s[j].flag == 1) {
                fprintf(fp1,"%s %d %d %d %d %d\n", s[j].name, s[j].sum, s[j].zz, s[j].eng, s[j].math, s[j].pro);
            }
        }
        fclose(fp1);
        printf("\n******************************************************\n");
        printf("******************************************************\n");
        printf("是否完成？ Y/N\n");
        char ch;
        cin >> ch;
        if (ch == 'Y') {
            Begin();
        }
        else {
            ruleShow();
        }
    }
}
void showStudent() {
    while (true)
    {
        FILE* fp;
        struct student s[1000];
        fp = fopen("2.txt", "r");
        int i;
        for (i = 0; !feof(fp); i++) {
            fscanf(fp, "%s %d %d %d %d %d", s[i].name, &s[i].sum, &s[i].zz, &s[i].eng, &s[i].math, &s[i].pro);
        }
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("目前已有%d名学生满足要求！\n",i-1);
        printf("请输入要录取的学生个数：\n");
        int num;
        cin >> num;
        system("cls");
        int temp = num > i - 1 ? i - 1 : num;
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("******************共录取%d名学生**********************\n",temp);
        printf("******************录取学生信息************************\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("姓名      总分      政治      英语      数学     专业课\n");
        for (int j = 0; j < temp; j++) {
            printf("%s     %d      %d       %d       %d       %d\t\n", s[j].name, s[j].sum, s[j].zz, s[j].eng, s[j].math, s[j].pro);
        }
        fclose(fp);
        printf("\n******************************************************\n");
        printf("******************************************************\n");
        printf("查看是否完成？ Y/N\n");
        char ch;
        cin >> ch;
        if (ch == 'Y') {
            Begin();
        }
        else {
            showStudent();
        }
    }
}

bool cmp(struct student A, struct student B) {
    if (A.sum != B.sum) {
        return A.sum > B.sum;
    }
    else if (A.sum == B.sum) {
        return A.zz > B.zz;
    }
}
bool cmp1(struct student A, struct student B) {
    if (A.sum != B.sum) {
        return A.sum > B.sum;
    }
    else if (A.sum == B.sum) {
        return A.eng > B.eng;
    }
}
bool cmp2(struct student A, struct student B) {
    if (A.sum != B.sum) {
        return A.sum > B.sum;
    }
    else if (A.sum == B.sum) {
        return A.math > B.math;
    }
}
bool cmp3(struct student A, struct student B) {
    if (A.sum != B.sum) {
        return A.sum > B.sum;
    }
    else if (A.sum == B.sum) {
        return A.pro > B.pro;
    }
}