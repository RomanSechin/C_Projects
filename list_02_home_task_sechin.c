/* Третий вариант программы работы с однонаправленным связным списком.
Суть изменений в возможности добавлять и удалять элементы списка.
В программе реализовано меню чтобы пользователь мог интерактивно
работать с программой.*/

/* ДЗ
Улучшить программу:
1. Функцию fgets() заменить на собственную, убрав лишний \n в выводе.
2. Сделать так чтобы после выбора действия в меню сперва очищался экран.
Подсказка: для этого надо вспомнить про функцию system("").
3. Подумать над тем, как реализовать добавление нового узла не в конец
списка, а в произвольную его часть. И реализовать если сможете.
4. Добавить новый элемент в меню - Help. Чтобы юзер мог почитать о том,
как работает программа и как ей пользоваться.
5. Сделать макропостановки #define чтобы сделать программу проще*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#define curr_next current->next

// Шаблон узла
struct cpu
{
    char model[15];
    char freq[11]; // ранее было unsigned freq
    struct cpu * next;
};

// Указатели для работы со списком
struct cpu * first;
struct cpu * newNode;
struct cpu * current;

// Прототипы функций
struct cpu * makeNode(void); // выделяем память под узел
struct cpu * getNode(unsigned );// получаем ссылку на элемент по номеру записи
void addNode(void); // добавляем узел в список
void deleteNode(void); // удаляем узел из списка
void showList(void); // вывод на экран ВСЕГО списка
int menu(void); // меню выбора действий программы
void addAfter(); // добавляем элемент после заданного аргументом
void getManual(void); // описание работы программы

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    int choice  = 0;
    first = NULL; // при запуске программы списка по факту ещё нет
                  // и это надо явно обозначить

    while(1)
    {

        choice = menu(); // пользователь делает выбор пункта меню
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
            puts("Всего доброго!");
            exit(EXIT_SUCCESS);
            break;
        case 'M':
            getManual();
            break;
        default:
            puts("Некорректный ввод.");
            break;
        }
    }
    return 0;
}

// Ф-ция выделяет память под новый элемент списка и возвращает указатель
// на этот элемент, потом он используется в ф-ции addNode()
struct cpu * makeNode(void)
{
    struct cpu * tempCpu;
    tempCpu = (struct cpu *) malloc(sizeof (struct cpu));
    if(tempCpu == NULL)
    {
        puts("Невозможно выделить память под новый элемент списка!\n");
        system("pause");
        exit(1);
    }
    return tempCpu;
}

// Выводит варианты действий пользователя
int menu(void)
{
    int ch = 0;
    printf("S - показать список\nA - добавить элемент\n\
D - удалить элемент\nN - добавить элемент следом за выбранным\n\
M - распечатать мануал\nQ - выход\n");
    ch = getch();
    putchar(ch); putch('\n');
    ch = toupper(ch); // чтобы работал ввод для разных регистров букв
    return ch;
}

void addNode(void)
{
    if(first == NULL) // сперва проверка есть ли хоть 1 элемент
    {
        first = makeNode(); // создать первый элемент
        current = first; // сделать его текущим
    }
    else // если в списке уже есть элементы
    {
        current = first; // сделать первый текущим
        while(curr_next != NULL) // ищем последний элемент списка
            current = curr_next; // и делаем его текущим
        newNode = makeNode(); // создали новый элемент
        curr_next = newNode; // поставили его в конец списка
        current = newNode; // сделал его текущим
    }
    fflush(stdin);
    printf("Введите название модели процессора (не более 14 символов): ");
    fgets(current->model, 15, stdin);
    strcpy(strstr(current->model, "\n"), "\0");
    fflush(stdin);
    printf("Введите тактовую частоту процессора в Гц (не более 10 символов): ");
    fgets(current->freq, 11, stdin);
    strcpy(strstr(current->freq, "\n"), "\0");
    fflush(stdin);
    curr_next = NULL; // нужно не забыть, указать адрес следующего
                          // не существующего элемента (закрыть список)
}

// Выводим весь список на экран
void showList(void)
{
    int count = 1; // номер выводимого элемента

    if(first == NULL) // если список пустой
    {
        printf("Список пуст! Сперва добавьте в него элементы.\n");
        return;
    }
    puts("Список:");
    current = first; //начинаем обход списка с первого элемента
    while(current != NULL) // пока элементы существуют
    {
        printf("Запись №%d: %s %s\n", count, current->model, current->freq);
        current = curr_next; // делаем следующий узел текущим
        count++;
    }
}

// Удаляем узел из списка
void deleteNode(void)
{
    struct cpu * previous; // адрес предшевствующего элемента удаляемому
    unsigned delNum; // номер удаляемого элемента
    unsigned num = 1; // текущий по порядку элемент

    if(first == NULL) // проверка есть ли хотя бы 1 элемент
    {
        puts("Список пустой - удалять нечего!");
        return;
    }
    puts("Пожалуйста, выберите узел для удаления:");
    showList(); // выводим список
    printf("Удалить узел: ");
    scanf("%u", &delNum);
    fflush(stdin);
    current = first; // Делаем первый узел текущим
    previous = NULL; // У первого элемента нет предыдущего
    while(num != delNum) // в цикле проверим есть ли такой элемент
    {
        previous = current; // сохраняем текущее значение
        current = curr_next; // обходим список по порядку
        num++;
        if(current == NULL) // достигли конца списка
        {
            puts("Такой записи в списке нет.");
            return;
        }
    }
    if(previous == NULL) // если удаляем первый элемент
        first = curr_next; // сделать первым следующий элемент
    else // предыдущая запись должна указывать на следующую
         // как бы перескакивая текущую
        previous->next = curr_next;

    printf("Запись №%u удалена\n", delNum);
    free(current); // высвобождаем память от удалённого узла
    return;
}

void addAfter(void)
{
    unsigned record_number = 1;
    //Считаем количество элементов в списке
    unsigned count_of_records = 0;
    current = first;
    for(;current; ++count_of_records)
    {
        current = curr_next;
    }

    //Если количество записей = 0, то просто вызываем функцию addNode()
    if(count_of_records == 0)
    {
        addNode();
        return;
    }

    //Добиваемся ввода корректного значения номера элемента, после которого возможна вставка нового
    while(1)
    {
        printf("Введите номер записи, \
после которой необходимо поместить новый элемент [1..%u]: ", count_of_records);
        scanf("%u", &record_number);
        if(record_number <= count_of_records && record_number > 0)
        {
            break;
        }
    }

    //Получаем ссылку на элемент по его номеру, чтобы после него вставлять новый
    current = getNode(record_number);

    //Сохраняем ссылку на next во временный указатель temp_next
    struct cpu * temp_next = curr_next;
    //создаём новый элемент для вставки
    curr_next = makeNode();
    //делаем новый элемент текущим
    current = curr_next;
    fflush(stdin);// на всякий случай
    printf("Введите название модели процессора (не более 14 символов): ");
    fgets(current->model, 15, stdin);
    strcpy(strstr(current->model, "\n"), "\0");//убираем перенос из строки
    fflush(stdin);
    printf("Введите тактовую частоту процессора в Гц (не более 10 символов): ");
    fgets(current->freq, 11, stdin);
    strcpy(strstr(current->freq, "\n"), "\0");//убираем перенос из строки
    fflush(stdin);
    // делаем старый следующий элемент следующим для вновь вставленного
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

// описание работы программы
void getManual(void)
{
    printf("Пользователю предлагается меню для тестирования программы работы с односвязными списками.\
Выбор одного из пунктов меню запускает определённый блок программы, выполняющий соответствующее действие.\
Список можно создавать, добавлять и удалять элементы, добавлять в выбранное место и просматривать список всех элементов.\n");
    return;
}
