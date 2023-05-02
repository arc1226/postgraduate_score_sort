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
    char a[10][3] = { "��","��","��","��","��","֣","Ǯ","��","��","��"};
    char a1[10][6] = { "�B","һ","��","��","��","��","��","��","��","��"};
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
        printf("         ��ӭʹ���о����������Գɼ��������\n");
        printf("------------------------------------------------------\n\n\n\n");
        printf("                    >��ӭʹ��<\n\n\n\n\n");
        printf("******************************************************\n");
        system("pause");
        system("cls");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("���롰1���Բ�ѯѧ���ɼ�\n");
        printf("���롰2��������¼ȡ����[��Ŀ��ͷ֣�����ѧ��(��ͬ������������ǰ)]\n");
        printf("���롰3���Բ鿴¼ȡѧ��\n");
        printf("���롰4�����˳�����\n");
        printf("�������Ӧ�����֣�лл��\n\t");
        int num;
        cin >> num;
        switch (num)
        {
        case 1:readStudent(); break;
        case 2:ruleShow(); break;
        case 3:showStudent(); break;
        case 4:system("cls"); printf("\n\n\n\t\t\t ллʹ�ã�\n "); exit(0); break;
        default:printf("�������\n "); break;
        }
    }
}
void readStudent() {
    while (true)
    {
        system("cls");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("******************ѧ���ɼ���Ϣ************************\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("����      �ܷ�      ����      Ӣ��      ��ѧ     רҵ��\n");
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
        printf("�鿴�Ƿ���ɣ� Y/N\n");
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
        printf("******************����¼ȡ����************************\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("\n����Ҫ�������ܷ֣�\n");
        int numSum;
        cin >> numSum;
        printf("\n����Ҫ���������ͷ֣�\n");
        int numZZ;
        cin >> numZZ;
        printf("\n����Ҫ���Ӣ����ͷ֣�\n");
        int numEng;
        cin >> numEng;
        printf("\n����Ҫ�����ѧ��ͷ֣�\n");
        int numMath;
        cin >> numMath;
        printf("\n����Ҫ���רҵ����ͷ֣�\n");
        int numPro;
        cin >> numPro;
        printf("\n��������ѧ�ƣ�������/Ӣ��/��ѧ/רҵ�Σ�\n");
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
        if (strcmp(arr, "����")==0) {
            sort(s, s + i - 1, cmp);
        }else if (strcmp(arr, "Ӣ��") == 0) {
            sort(s, s + i - 1, cmp1);
        }else if (strcmp(arr, "��ѧ") == 0) {
            sort(s, s + i - 1, cmp2);
        }else if (strcmp(arr, "רҵ��") == 0) {
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
        printf("�Ƿ���ɣ� Y/N\n");
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
        printf("Ŀǰ����%d��ѧ������Ҫ��\n",i-1);
        printf("������Ҫ¼ȡ��ѧ��������\n");
        int num;
        cin >> num;
        system("cls");
        int temp = num > i - 1 ? i - 1 : num;
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("******************��¼ȡ%d��ѧ��**********************\n",temp);
        printf("******************¼ȡѧ����Ϣ************************\n");
        printf("******************************************************\n");
        printf("******************************************************\n");
        printf("����      �ܷ�      ����      Ӣ��      ��ѧ     רҵ��\n");
        for (int j = 0; j < temp; j++) {
            printf("%s     %d      %d       %d       %d       %d\t\n", s[j].name, s[j].sum, s[j].zz, s[j].eng, s[j].math, s[j].pro);
        }
        fclose(fp);
        printf("\n******************************************************\n");
        printf("******************************************************\n");
        printf("�鿴�Ƿ���ɣ� Y/N\n");
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