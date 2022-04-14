/*
    Программа тестирует функцию sum_of_strings(), складывающую два числа, представленных строками.
    Начиная с младшего разряда, складываются цифры, и если их сумма (summ_number) превышает 10,
    то переменная dozen становится равна единице, а summ_number уменьшается на 10.
    В разряд результирующей строки (result_string) заносится значение summ_number + dozen.
    dozen для младшего разряда равен нулю, а для следующих разрядов вычисляется исходя из суммы предыдущих разрядов.

    Длины строк чисел могут быть разными, поэтому вычисление разбито на два цикла.
    В первом цикле считаются суммы цифр из строк от нулевого разряда до длины меньшей строки (min_len),
    а во втором - от min_len до длины большей строки (max_len), но без учёта разрядов меньшей строки,
	поскольку они закончились в первом цикле.
    srv 22.05.2021
    ver 7.0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * summ_of_strings(char *, char * );
char * substraction_of_strings(char * temp_str1, char * temp_str2);
char * add_minus_before_number(char * str);
//функция проверяет, являются ли все символы числами
int check_digits(char * str_number);
//функция удаляет нули, предваряющие число
char * remove_prevent_zeros(char * number_string);


int main()
{
    //задаём числа в виде строк
    char * str1 = "-00090";
    char * str2 = "-0002";
    char * result;
    //суммируем числа, представленные в виде строк
    if(str1[0] == '-' && str2[0] == '-')
        result = summ_of_strings(str1, str2);
    else if(isdigit(str1[0]) && isdigit((str2[0])))
        result = summ_of_strings(str1, str2);
    else if(str1[0] == '-' && isdigit(str2[0]))
        result = substraction_of_strings(str2, str1 + 1);
    else if(str2[0] == '-' && isdigit(str1[0]))
        result = substraction_of_strings(str1, str2 + 1);

    printf("%s", result );

    free(result);

    return 0;
}

char * summ_of_strings(char * inner_temp_str1, char * inner_temp_str2)
{
    //в случае отрицательных чисел - преобразуем их в строки без символа '-' и фиксируем преобразование
    //во флаге minus

    //локальные строки для чисел
    char *temp_str1;
    char *temp_str2;
    int need_to_free_memory;//если создаём новые строки при отрицательных числах - их нужно освободить
    int minus = 0;//флаг отрицательности числовых строк - используем в конце тела функции
    if(inner_temp_str1[0] == '-' && inner_temp_str2[0] == '-')//если числа отрицательные
    {
        minus = 1;//флаг отрицательности - в единицу
        //выделяем память для строк с длиной, меньшей на единицу исходных строк с отрицательным числом
        temp_str1 = (char *)malloc((strlen(inner_temp_str1)-1) * sizeof(char));
        temp_str2 = (char *)malloc((strlen(inner_temp_str2)-1) * sizeof(char));
        need_to_free_memory = 1;
        //копируем в temp_str1 и temp_str2 части строк без знака минус
        memcpy(temp_str1, inner_temp_str1 + 1, strlen(inner_temp_str1));
        memcpy(temp_str2, inner_temp_str2 + 1, strlen(inner_temp_str2));
    }
    else//иначе копируем адреса в локальные строки
    {
        temp_str1 = inner_temp_str1;
        temp_str2 = inner_temp_str2;
    }
    //находим длины входных строк
    int temp_str1_length = strlen(temp_str1);
    int temp_str2_length = strlen(temp_str2);
    //проверяем в первой строке нечисловые символы. Если находим - сообщаем об этом и выходим из программы
    for(int index = 0; index < temp_str1_length; ++index)
        if(!isdigit(temp_str1[index]))
        {
            printf("'%c' (position %d in a string \"%s\") is not a digit!\n", temp_str1[index], index, temp_str1);
            return "";
        }
    //проверяем во второй строке нечисловые символы. Если находим - сообщаем об этом и выходим из программы
    for(int index = 0; index < temp_str2_length; ++index)
        if(!isdigit(temp_str2[index]))
        {
            printf("'%c' (position %d in a string \"%s\") is not a digit!\n", temp_str2[index], index, temp_str2);
            return "";
        }

    int zero_count1 = 0;//счётчик нулей перед первым числом
    int zero_count2 = 0;//счётчик нулей перед вторым числом
    //считаем количество нулей перед числом в первой строке
    for(int index = 0; ; ++index)
    {
        if(temp_str1[index] == '0') ++zero_count1;
        else break;
    }
    //создаём строку для первого числа без предваряющих нулей плюс место для терминального символа
    char str1[strlen(temp_str1) - zero_count1 + 1];
    //копируем в str1 число без предваряющих нулей
    memmove(str1, temp_str1 + zero_count1, strlen(temp_str1) - zero_count1);
    //устанавливаем терминальный символ строки
    str1[strlen(temp_str1) - zero_count1] = '\0';

    //считаем количество нулей перед числом во второй строке
    for(int index = 0; ; ++index)
    {
        if(temp_str2[index] == '0') ++zero_count2;
        else break;
    }
    //создаём строку для вторго числа без предваряющих нулей плюс место для терминального символа
    char str2[strlen(temp_str2) - zero_count2 + 1];
    //копируем в str2 число без предваряющих нулей
    memmove(str2, temp_str2 + zero_count2, strlen(temp_str2) - zero_count2);
    //устанавливаем терминальный символ строки
    str2[strlen(temp_str2) - zero_count2] = '\0';


    int strlen1 = strlen(str1);//длина первой строки
    int strlen2 = strlen(str2);//длина второй строки

    int max_len = (strlen1 >= strlen2) ? strlen1 : strlen2;//находим бОльшую из длин строк
    int min_len = (strlen1 <  strlen2) ? strlen1 : strlen2;//находим мЕньшую из длин строк
    char * max_str = (strlen1 >= strlen2) ? str1 : str2;   //создаём указатель на бОльшую строку

    //Если первая строка пустая или состоит из нуля, то возвращаем другую строку
    if(strcmp(str1, "") == 0 || strcmp(str1, "0") == 0)
    {
        int length = strlen(str2);
        char * result_string = (char *)malloc(length * sizeof(char));//создаём строку для результата вычислений
        strcpy(result_string, str2);
        return result_string;
    }
    //Если вторая строка пустая или состоит из нуля, то возвращаем другую строку
    if(strcmp(str2, "") == 0 || strcmp(str2, "0") == 0)
    {
        int length = strlen(str1);
        char * result_string = (char *)malloc(length * sizeof(char));//создаём строку для результата вычислений
        strcpy(result_string, str1);
        return result_string;
    }

    char * result_string = (char *)malloc((max_len + 2)  * sizeof(char));//создаём строку для результата вычислений
    if(result_string == NULL)//проверяем, выделилась ли память под результирующую строку
    {
        printf("Can't allocate memory!\n");
        return 0;
    }
    result_string[max_len + 1] = '\0';//терминальный элемент ставим в конец строки
    int index = 0;
    int number1 = 0;//число, принимающее значение цифры из разряда первой строки
    int number2 = 0;//число, принимающее значение цифры из разряда второй строки
    char summ_number = 0;//число, принимающее значение суммы number1 и number2
    int dozen = 0;  //десятки

    //вычисляем сумму по разрядам строки меньшего размера
    for(index = 0; index < min_len; ++index)
    {
        number1 = str1[strlen1 - index - 1] - '0';
        number2 = str2[strlen2 - index - 1] - '0';
        summ_number = number1 + number2 + dozen;
        if(summ_number >= 10)
        {
            dozen = 1;
            summ_number -= 10;
        }
        else dozen = 0;
        result_string[max_len - index] = (char)(summ_number + '0');//результат суммирования соответствующих разрядов
    }
    // вычисляем сумму по разрядам строки от меньшего размера до количества разрядов строки большего размера
    for(index = min_len; index < max_len; ++index)
    {
        summ_number = max_str[max_len - 1 - index] - '0' + dozen;
        if(summ_number >= 10)//если число больше десяти, то увеличиваем количество десятков, а число уменьшаем на 10
        {
            dozen = 1;
            summ_number -= 10;
        }
        else dozen = 0;
        result_string[max_len - index] = (char)(summ_number + '0');
    }

    if(dozen)//Если остались десятки, то нулевым символом результироующей строки ставим колчество оставшихся десятков
        result_string[max_len - index] = dozen + '0';

    else//Иначе просто сдвигаем строку влево на единицу
        for(unsigned i = 0; i < strlen(result_string); ++i)
            result_string[i] = result_string[i + 1];
    //Если числа отрицательные, то сдвигаем строку вправо на единицу, а нулевой символ - '-'
    if(minus == 1)
    {
        result_string = add_minus_before_number(result_string);
    }
    //Если необходимо - освобождаем память при ненулевом флаге
    if(need_to_free_memory)
    {
        free(temp_str1);
        free(temp_str2);
    }
    return result_string;
}

//функция добавляет знак минус перед числовой строкой
char * add_minus_before_number(char * str)
{
    int length = strlen(str);
    char * temp = (char *)malloc(length + 2);
    memcpy(temp + 1, str, length + 1);
    temp[0] = '-';
    return temp;
}
//функция проверяет, являются ли все символы числами
int check_digits(char * str_number)
{
    int length = strlen(str_number);
    for(int index = 0; index < length; ++index)
    {
        if(!isdigit(str_number[index]))
        return index;
    }
    return -1;
}
//функция удаляет нули, предваряющие число
char * remove_prevent_zeros(char * number_string)
{
    int string_length = strlen(number_string);
    int zero_count = 0;
    char * return_string;

    for(int index = 0; index < string_length; ++index)
    {
        if(number_string[index] == '0')
            ++zero_count;
        else
            index = string_length;
    }

    if(zero_count)
    {
        return_string = (char *)malloc((string_length - zero_count));
        memcpy(return_string, number_string + zero_count, string_length - zero_count + 1);
        return return_string;
    }
    else
    return number_string;
}

//функция вычитает второй аргумент из первого
char * substraction_of_strings(char * temp_str1, char * temp_str2)
{
    //Сначала проверяем, все ли символы в строке являются цифрами
    int check_digits_result_1 = check_digits(temp_str1);
    int check_digits_result_2 = check_digits(temp_str2);
    if( check_digits_result_1 != -1)
    {
        printf("There is not digit at the position %d of string: %s\n", check_digits_result_1, temp_str1);
        return NULL;
    }
    if( check_digits_result_2 != -1)
    {
        printf("There is not digit at the position %d of string: %s\n", check_digits_result_2, temp_str2);
        return NULL;
    }
    //удаляем предваряющие число нули, если они есть
    char * str1 = remove_prevent_zeros(temp_str1);
    char * str2 = remove_prevent_zeros(temp_str2);

    //вычисляем длины получившихся строк
    int strlen1 = strlen(str1);
    int strlen2 = strlen(str2);
    //Определяем максимальную и минимальную строки с точки зрения длины
    char * max_string = (strlen1 > strlen2) ? str1 : str2;
    char * min_string = (strlen1 < strlen2 ) ? str1 : str2;
    int index = 0;
    int debt  = 0;//долг для старшего разряда при вычислении в столбец
    int number1 = 0;//уменьшаемое
    int number2 = 0;//вычитаемое
    int diff_of_numbers = 0;//разность

    //поиск максимальной и минимальной строки с точки зрения хранимого значения в случае равных длин строк
    if(strlen1 == strlen2)
    {
        for(index = 0; index < strlen1; ++index)
        {
            if(str1[index] > str2[index])
            {
                max_string = str1;
                min_string = str2;
                break;
            }
            else if(str1[index] < str2[index])
            {
                max_string = str2;
                min_string = str1;
                break;
            }
            else
                continue;
        }
    }
    else if(strlen1 > strlen2)
    {
        max_string = str1;
        min_string = str2;
    }
    else
    {
        max_string = str2;
        min_string = str1;
    }

    int length_of_max_string = strlen(max_string);//длина максимальной строки
    int length_of_min_string = strlen(min_string);//длина минимальной строки
    int result_string_length = length_of_max_string + 1;//длина результирующей строки
    //создаём результирующую строку
    char * result_string = (char *)malloc(result_string_length * sizeof(char));
    //устанавливаем терминальный символ
    result_string[result_string_length - 1] = '\0';
    //идём с конца по цифрам, вычисляем их разницу и записываем в result_string, запоминая долг старшего разряда
    //вплоть до длины меньшей строки
    for(index = 0; index < length_of_min_string; ++index)
    {
        number1 = max_string[length_of_max_string - index - 1] - '0' - debt;
        number2 = min_string[length_of_min_string - index - 1] - '0';
        if(number1 < number2)
        {
            number1 += 10;
            debt = 1;
        }
        else debt = 0;

        diff_of_numbers = number1 - number2;
        result_string[result_string_length - index - 2] = (char)(diff_of_numbers + '0');
    }
//продолжаем вычисление, с той лишь разницей, что мешьшее число считаем равным нулю, вплоть до длины большей строки
    for(; index < length_of_max_string; ++index)
    {
        if((number1 = max_string[length_of_max_string - index - 1] - '0') < debt)
        {
            number1 += 10;
            number1 -= debt;
        }
        else
        {
            number1 = max_string[length_of_max_string - index - 1] - '0' - debt;
            debt = 0;
        }
        number2 = 0;
        if(number1 < number2)
        {
            number1 += 10;
            debt = 1;
        }

        diff_of_numbers = number1 - number2;
        result_string[result_string_length - index - 2] = (char)(diff_of_numbers + '0');
   }
    //убираем из результата предваряющие нули
    result_string = remove_prevent_zeros(result_string);

    //ставим перед результатом знак минус, если вычитаемое больше уменьшаемого, т.е. второй аргумент функции ясляется
    //максимальным из аргументов
    if(max_string == str2)
    {
       result_string = add_minus_before_number(result_string);
    }
    //если результат состоит из знака минус и конца строки - возвращаем ноль.
    if((result_string[0] == '-') && (result_string[1] == '\0' || result_string[1] == '\n' || result_string[1] == '\0'))
        return "0";

    return result_string;
}
