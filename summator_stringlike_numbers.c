/*
    ��������� ��������� ������� sum_of_strings(), ������������ ��� �����, �������������� ��������.
    ������� � �������� �������, ������������ �����, � ���� �� ����� (summ_number) ��������� 10,
    �� ���������� dozen ���������� ����� �������, � summ_number ����������� �� 10.
    � ������ �������������� ������ (result_string) ��������� �������� summ_number + dozen.
    dozen ��� �������� ������� ����� ����, � ��� ��������� �������� ����������� ������ �� ����� ���������� ��������.

    ����� ����� ����� ����� ���� �������, ������� ���������� ������� �� ��� �����.
    � ������ ����� ��������� ����� ���� �� ����� �� �������� ������� �� ����� ������� ������ (min_len),
    � �� ������ - �� min_len �� ����� ������� ������ (max_len), �� ��� ����� �������� ������� ������,
	��������� ��� ����������� � ������ �����.
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
//������� ���������, �������� �� ��� ������� �������
int check_digits(char * str_number);
//������� ������� ����, ������������ �����
char * remove_prevent_zeros(char * number_string);


int main()
{
    //����� ����� � ���� �����
    char * str1 = "-00090";
    char * str2 = "-0002";
    char * result;
    //��������� �����, �������������� � ���� �����
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
    //� ������ ������������� ����� - ����������� �� � ������ ��� ������� '-' � ��������� ��������������
    //�� ����� minus

    //��������� ������ ��� �����
    char *temp_str1;
    char *temp_str2;
    int need_to_free_memory;//���� ������ ����� ������ ��� ������������� ������ - �� ����� ����������
    int minus = 0;//���� ��������������� �������� ����� - ���������� � ����� ���� �������
    if(inner_temp_str1[0] == '-' && inner_temp_str2[0] == '-')//���� ����� �������������
    {
        minus = 1;//���� ��������������� - � �������
        //�������� ������ ��� ����� � ������, ������� �� ������� �������� ����� � ������������� ������
        temp_str1 = (char *)malloc((strlen(inner_temp_str1)-1) * sizeof(char));
        temp_str2 = (char *)malloc((strlen(inner_temp_str2)-1) * sizeof(char));
        need_to_free_memory = 1;
        //�������� � temp_str1 � temp_str2 ����� ����� ��� ����� �����
        memcpy(temp_str1, inner_temp_str1 + 1, strlen(inner_temp_str1));
        memcpy(temp_str2, inner_temp_str2 + 1, strlen(inner_temp_str2));
    }
    else//����� �������� ������ � ��������� ������
    {
        temp_str1 = inner_temp_str1;
        temp_str2 = inner_temp_str2;
    }
    //������� ����� ������� �����
    int temp_str1_length = strlen(temp_str1);
    int temp_str2_length = strlen(temp_str2);
    //��������� � ������ ������ ���������� �������. ���� ������� - �������� �� ���� � ������� �� ���������
    for(int index = 0; index < temp_str1_length; ++index)
        if(!isdigit(temp_str1[index]))
        {
            printf("'%c' (position %d in a string \"%s\") is not a digit!\n", temp_str1[index], index, temp_str1);
            return "";
        }
    //��������� �� ������ ������ ���������� �������. ���� ������� - �������� �� ���� � ������� �� ���������
    for(int index = 0; index < temp_str2_length; ++index)
        if(!isdigit(temp_str2[index]))
        {
            printf("'%c' (position %d in a string \"%s\") is not a digit!\n", temp_str2[index], index, temp_str2);
            return "";
        }

    int zero_count1 = 0;//������� ����� ����� ������ ������
    int zero_count2 = 0;//������� ����� ����� ������ ������
    //������� ���������� ����� ����� ������ � ������ ������
    for(int index = 0; ; ++index)
    {
        if(temp_str1[index] == '0') ++zero_count1;
        else break;
    }
    //������ ������ ��� ������� ����� ��� ������������ ����� ���� ����� ��� ������������� �������
    char str1[strlen(temp_str1) - zero_count1 + 1];
    //�������� � str1 ����� ��� ������������ �����
    memmove(str1, temp_str1 + zero_count1, strlen(temp_str1) - zero_count1);
    //������������� ������������ ������ ������
    str1[strlen(temp_str1) - zero_count1] = '\0';

    //������� ���������� ����� ����� ������ �� ������ ������
    for(int index = 0; ; ++index)
    {
        if(temp_str2[index] == '0') ++zero_count2;
        else break;
    }
    //������ ������ ��� ������ ����� ��� ������������ ����� ���� ����� ��� ������������� �������
    char str2[strlen(temp_str2) - zero_count2 + 1];
    //�������� � str2 ����� ��� ������������ �����
    memmove(str2, temp_str2 + zero_count2, strlen(temp_str2) - zero_count2);
    //������������� ������������ ������ ������
    str2[strlen(temp_str2) - zero_count2] = '\0';


    int strlen1 = strlen(str1);//����� ������ ������
    int strlen2 = strlen(str2);//����� ������ ������

    int max_len = (strlen1 >= strlen2) ? strlen1 : strlen2;//������� ������� �� ���� �����
    int min_len = (strlen1 <  strlen2) ? strlen1 : strlen2;//������� ������� �� ���� �����
    char * max_str = (strlen1 >= strlen2) ? str1 : str2;   //������ ��������� �� ������� ������

    //���� ������ ������ ������ ��� ������� �� ����, �� ���������� ������ ������
    if(strcmp(str1, "") == 0 || strcmp(str1, "0") == 0)
    {
        int length = strlen(str2);
        char * result_string = (char *)malloc(length * sizeof(char));//������ ������ ��� ���������� ����������
        strcpy(result_string, str2);
        return result_string;
    }
    //���� ������ ������ ������ ��� ������� �� ����, �� ���������� ������ ������
    if(strcmp(str2, "") == 0 || strcmp(str2, "0") == 0)
    {
        int length = strlen(str1);
        char * result_string = (char *)malloc(length * sizeof(char));//������ ������ ��� ���������� ����������
        strcpy(result_string, str1);
        return result_string;
    }

    char * result_string = (char *)malloc((max_len + 2)  * sizeof(char));//������ ������ ��� ���������� ����������
    if(result_string == NULL)//���������, ���������� �� ������ ��� �������������� ������
    {
        printf("Can't allocate memory!\n");
        return 0;
    }
    result_string[max_len + 1] = '\0';//������������ ������� ������ � ����� ������
    int index = 0;
    int number1 = 0;//�����, ����������� �������� ����� �� ������� ������ ������
    int number2 = 0;//�����, ����������� �������� ����� �� ������� ������ ������
    char summ_number = 0;//�����, ����������� �������� ����� number1 � number2
    int dozen = 0;  //�������

    //��������� ����� �� �������� ������ �������� �������
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
        result_string[max_len - index] = (char)(summ_number + '0');//��������� ������������ ��������������� ��������
    }
    // ��������� ����� �� �������� ������ �� �������� ������� �� ���������� �������� ������ �������� �������
    for(index = min_len; index < max_len; ++index)
    {
        summ_number = max_str[max_len - 1 - index] - '0' + dozen;
        if(summ_number >= 10)//���� ����� ������ ������, �� ����������� ���������� ��������, � ����� ��������� �� 10
        {
            dozen = 1;
            summ_number -= 10;
        }
        else dozen = 0;
        result_string[max_len - index] = (char)(summ_number + '0');
    }

    if(dozen)//���� �������� �������, �� ������� �������� ��������������� ������ ������ ��������� ���������� ��������
        result_string[max_len - index] = dozen + '0';

    else//����� ������ �������� ������ ����� �� �������
        for(unsigned i = 0; i < strlen(result_string); ++i)
            result_string[i] = result_string[i + 1];
    //���� ����� �������������, �� �������� ������ ������ �� �������, � ������� ������ - '-'
    if(minus == 1)
    {
        result_string = add_minus_before_number(result_string);
    }
    //���� ���������� - ����������� ������ ��� ��������� �����
    if(need_to_free_memory)
    {
        free(temp_str1);
        free(temp_str2);
    }
    return result_string;
}

//������� ��������� ���� ����� ����� �������� �������
char * add_minus_before_number(char * str)
{
    int length = strlen(str);
    char * temp = (char *)malloc(length + 2);
    memcpy(temp + 1, str, length + 1);
    temp[0] = '-';
    return temp;
}
//������� ���������, �������� �� ��� ������� �������
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
//������� ������� ����, ������������ �����
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

//������� �������� ������ �������� �� �������
char * substraction_of_strings(char * temp_str1, char * temp_str2)
{
    //������� ���������, ��� �� ������� � ������ �������� �������
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
    //������� ������������ ����� ����, ���� ��� ����
    char * str1 = remove_prevent_zeros(temp_str1);
    char * str2 = remove_prevent_zeros(temp_str2);

    //��������� ����� ������������ �����
    int strlen1 = strlen(str1);
    int strlen2 = strlen(str2);
    //���������� ������������ � ����������� ������ � ����� ������ �����
    char * max_string = (strlen1 > strlen2) ? str1 : str2;
    char * min_string = (strlen1 < strlen2 ) ? str1 : str2;
    int index = 0;
    int debt  = 0;//���� ��� �������� ������� ��� ���������� � �������
    int number1 = 0;//�����������
    int number2 = 0;//����������
    int diff_of_numbers = 0;//��������

    //����� ������������ � ����������� ������ � ����� ������ ��������� �������� � ������ ������ ���� �����
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

    int length_of_max_string = strlen(max_string);//����� ������������ ������
    int length_of_min_string = strlen(min_string);//����� ����������� ������
    int result_string_length = length_of_max_string + 1;//����� �������������� ������
    //������ �������������� ������
    char * result_string = (char *)malloc(result_string_length * sizeof(char));
    //������������� ������������ ������
    result_string[result_string_length - 1] = '\0';
    //��� � ����� �� ������, ��������� �� ������� � ���������� � result_string, ��������� ���� �������� �������
    //������ �� ����� ������� ������
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
//���������� ����������, � ��� ���� ��������, ��� ������� ����� ������� ������ ����, ������ �� ����� ������� ������
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
    //������� �� ���������� ������������ ����
    result_string = remove_prevent_zeros(result_string);

    //������ ����� ����������� ���� �����, ���� ���������� ������ ������������, �.�. ������ �������� ������� ��������
    //������������ �� ����������
    if(max_string == str2)
    {
       result_string = add_minus_before_number(result_string);
    }
    //���� ��������� ������� �� ����� ����� � ����� ������ - ���������� ����.
    if((result_string[0] == '-') && (result_string[1] == '\0' || result_string[1] == '\n' || result_string[1] == '\0'))
        return "0";

    return result_string;
}
