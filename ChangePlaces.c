/*“огда така€ задача есть массив целых чисел из 10 элементов.
«адача помен€ть местами первый и второй элемент с 9 и 10, 3 и 4 с 7 и 8.
“.е допустим были элементы
1 2 3 4 5 6 7 8 9 10 а стало
9 10 7 8 5 6 3 4 1 2

ѕрограмма мен€ет местами значени€ соответствующих элементов массива размера size в соответствии с постановкой задачи.
в цикле с начала массива до середины массива half_size(= size / 2 ) обмениваем пары  значений следующим образом:
элемент с индексом index обмениваетс€ значением с элементом с индексом size - index - 2,
а элемент с индексом index + 1 обмениваетс€ с элементом с индексом size - index - 1
*/
//srv 03/05/2021
//ver 3.0

#include <stdio.h>

void print_array(int array[], int size)
{
    for(int index = 0; index < size; ++index)
        printf("%d ", array[index]);
    printf("\n\n");
}
int main()
{
    int size = 300;//размер массива
    if(size <= 3 )
    {
        printf("There are nothing to swap!\n");
        return 0;
    }
    int half_size = size / 2;//цела€ половина размера массива
    int temp = 0; //временна€ переменна€ дл€ реализации swap
    int * array = malloc(size * sizeof(int));//пример массива
    for(int index = 0; index < size; ++index)
    {
        array[index] = index;
    }
    print_array(array, size);//печать массива в консоль
    for(int index = 0; index < half_size; index += 2)
    {
        temp = array[index];
        array[index] = array[size - index - 2];
        array[size - index - 2] = temp;

        temp = array[index + 1];
        array[index + 1] = array[size - index - 1];
        array[size - index - 1] = temp;
    }
    print_array(array, size);
    free(array);
    return 0;
}
