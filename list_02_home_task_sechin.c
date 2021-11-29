/* ������ ������� ��������� ������ � ���������������� ������� �������.
���� ��������� � ����������� ��������� � ������� �������� ������.
� ��������� ����������� ���� ����� ������������ ��� ������������
�������� � ����������.*/

/* ��
�������� ���������:
1. ������� fgets() �������� �� �����������, ����� ������ \n � ������.
2. ������� ��� ����� ����� ������ �������� � ���� ������ �������� �����.
���������: ��� ����� ���� ��������� ��� ������� system("").
3. �������� ��� ���, ��� ����������� ���������� ������ ���� �� � �����
������, � � ������������ ��� �����. � ����������� ���� �������.
4. �������� ����� ������� � ���� - Help. ����� ���� ��� �������� � ���,
��� �������� ��������� � ��� �� ������������.
5. ������� ��������������� #define ����� ������� ��������� �����*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#define curr_next current->next

// ������ ����
struct cpu
{
    char model[15];
    char freq[11]; // ����� ���� unsigned freq
    struct cpu * next;
};

// ��������� ��� ������ �� �������
struct cpu * first;
struct cpu * newNode;
struct cpu * current;

// ��������� �������
struct cpu * makeNode(void); // �������� ������ ��� ����
struct cpu * getNode(unsigned );// �������� ������ �� ������� �� ������ ������
void addNode(void); // ��������� ���� � ������
void deleteNode(void); // ������� ���� �� ������
void showList(void); // ����� �� ����� ����� ������
int menu(void); // ���� ������ �������� ���������
void addAfter(); // ��������� ������� ����� ��������� ����������
void getManual(void); // �������� ������ ���������

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    int choice  = 0;
    first = NULL; // ��� ������� ��������� ������ �� ����� ��� ���
                  // � ��� ���� ���� ����������

    while(1)
    {

        choice = menu(); // ������������ ������ ����� ������ ����
        system("cls");
        switch(choice)
        {
        case 'S':
            showList();
            break;
        case 'A':
            addNode();
            break;
        case 'D':
            deleteNode();
            break;
        case 'N':
            addAfter();
            break;
        case 'Q':
            puts("����� �������!");
            exit(EXIT_SUCCESS);
            break;
        case 'M':
            getManual();
            break;
        default:
            puts("������������ ����.");
            break;
        }
    }
    return 0;
}

// �-��� �������� ������ ��� ����� ������� ������ � ���������� ���������
// �� ���� �������, ����� �� ������������ � �-��� addNode()
struct cpu * makeNode(void)
{
    struct cpu * tempCpu;
    tempCpu = (struct cpu *) malloc(sizeof (struct cpu));
    if(tempCpu == NULL)
    {
        puts("���������� �������� ������ ��� ����� ������� ������!\n");
        system("pause");
        exit(1);
    }
    return tempCpu;
}

// ������� �������� �������� ������������
int menu(void)
{
    int ch = 0;
    printf("S - �������� ������\nA - �������� �������\n\
D - ������� �������\nN - �������� ������� ������ �� ���������\n\
M - ����������� ������\nQ - �����\n");
    ch = getch();
    putchar(ch); putch('\n');
    ch = toupper(ch); // ����� ������� ���� ��� ������ ��������� ����
    return ch;
}

void addNode(void)
{
    if(first == NULL) // ������ �������� ���� �� ���� 1 �������
    {
        first = makeNode(); // ������� ������ �������
        current = first; // ������� ��� �������
    }
    else // ���� � ������ ��� ���� ��������
    {
        current = first; // ������� ������ �������
        while(curr_next != NULL) // ���� ��������� ������� ������
            current = curr_next; // � ������ ��� �������
        newNode = makeNode(); // ������� ����� �������
        curr_next = newNode; // ��������� ��� � ����� ������
        current = newNode; // ������ ��� �������
    }
    fflush(stdin);
    printf("������� �������� ������ ���������� (�� ����� 14 ��������): ");
    fgets(current->model, 15, stdin);
    strcpy(strstr(current->model, "\n"), "\0");
    fflush(stdin);
    printf("������� �������� ������� ���������� � �� (�� ����� 10 ��������): ");
    fgets(current->freq, 11, stdin);
    strcpy(strstr(current->freq, "\n"), "\0");
    fflush(stdin);
    curr_next = NULL; // ����� �� ������, ������� ����� ����������
                          // �� ������������� �������� (������� ������)
}

// ������� ���� ������ �� �����
void showList(void)
{
    int count = 1; // ����� ���������� ��������

    if(first == NULL) // ���� ������ ������
    {
        printf("������ ����! ������ �������� � ���� ��������.\n");
        return;
    }
    puts("������:");
    current = first; //�������� ����� ������ � ������� ��������
    while(current != NULL) // ���� �������� ����������
    {
        printf("������ �%d: %s %s\n", count, current->model, current->freq);
        current = curr_next; // ������ ��������� ���� �������
        count++;
    }
}

// ������� ���� �� ������
void deleteNode(void)
{
    struct cpu * previous; // ����� ���������������� �������� ����������
    unsigned delNum; // ����� ���������� ��������
    unsigned num = 1; // ������� �� ������� �������

    if(first == NULL) // �������� ���� �� ���� �� 1 �������
    {
        puts("������ ������ - ������� ������!");
        return;
    }
    puts("����������, �������� ���� ��� ��������:");
    showList(); // ������� ������
    printf("������� ����: ");
    scanf("%u", &delNum);
    fflush(stdin);
    current = first; // ������ ������ ���� �������
    previous = NULL; // � ������� �������� ��� �����������
    while(num != delNum) // � ����� �������� ���� �� ����� �������
    {
        previous = current; // ��������� ������� ��������
        current = curr_next; // ������� ������ �� �������
        num++;
        if(current == NULL) // �������� ����� ������
        {
            puts("����� ������ � ������ ���.");
            return;
        }
    }
    if(previous == NULL) // ���� ������� ������ �������
        first = curr_next; // ������� ������ ��������� �������
    else // ���������� ������ ������ ��������� �� ���������
         // ��� �� ������������ �������
        previous->next = curr_next;

    printf("������ �%u �������\n", delNum);
    free(current); // ������������ ������ �� ��������� ����
    return;
}

void addAfter(void)
{
    unsigned record_number = 1;
    //������� ���������� ��������� � ������
    unsigned count_of_records = 0;
    current = first;
    for(;current; ++count_of_records)
    {
        current = curr_next;
    }

    //���� ���������� ������� = 0, �� ������ �������� ������� addNode()
    if(count_of_records == 0)
    {
        addNode();
        return;
    }

    //���������� ����� ����������� �������� ������ ��������, ����� �������� �������� ������� ������
    while(1)
    {
        printf("������� ����� ������, \
����� ������� ���������� ��������� ����� ������� [1..%u]: ", count_of_records);
        scanf("%u", &record_number);
        if(record_number <= count_of_records && record_number > 0)
        {
            break;
        }
    }

    //�������� ������ �� ������� �� ��� ������, ����� ����� ���� ��������� �����
    current = getNode(record_number);

    //��������� ������ �� next �� ��������� ��������� temp_next
    struct cpu * temp_next = curr_next;
    //������ ����� ������� ��� �������
    curr_next = makeNode();
    //������ ����� ������� �������
    current = curr_next;
    fflush(stdin);// �� ������ ������
    printf("������� �������� ������ ���������� (�� ����� 14 ��������): ");
    fgets(current->model, 15, stdin);
    strcpy(strstr(current->model, "\n"), "\0");//������� ������� �� ������
    fflush(stdin);
    printf("������� �������� ������� ���������� � �� (�� ����� 10 ��������): ");
    fgets(current->freq, 11, stdin);
    strcpy(strstr(current->freq, "\n"), "\0");//������� ������� �� ������
    fflush(stdin);
    // ������ ������ ��������� ������� ��������� ��� ����� ������������
    curr_next = temp_next;
}

struct cpu * getNode(unsigned number)
{
    current = first;
    for(unsigned i = 0; i < number-1; ++i)
    {
        if(!current)
            return NULL;
        else
        {
            current = curr_next;
        }
    }
    return current;
}

// �������� ������ ���������
void getManual(void)
{
    printf("������������ ������������ ���� ��� ������������ ��������� ������ � ������������ ��������.\
����� ������ �� ������� ���� ��������� ����������� ���� ���������, ����������� ��������������� ��������.\
������ ����� ���������, ��������� � ������� ��������, ��������� � ��������� ����� � ������������� ������ ���� ���������.\n");
    return;
}
