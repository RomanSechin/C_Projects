//��������� ���������� ������� id ����� ���������� ������ �������� union ��� �������������
//��������� �������� ������ (��������� 1.1) ��� ������� ������ ��������� ��� ������������������
//0-2, 1-4, 2-5, 3-6, 0-4, 1-3
//������� ����� ���������� ��������� ��������� � ������� id ��� ������ �������� ����

#include <stdio.h>
#define N 1000

int main()
{
    int i, t, p, q, id[N];
    int count_of_query = 0;

    for(i = 0; i < N; ++i)
        id[i] = i;

    while(scanf("%d %d", &p, &q) == 2)
    {
        if(id[p] == id[q])
            continue;

        t = id[p];

        for(i = 0; i < N; ++i)
            if(id[i] == t)
            {
                 id[i] = q;
                 ++count_of_query;
            }


        printf("\t%d %d count_of_query = %d\n", p, q, count_of_query);
        count_of_query = 0;
    }

    return 0;
}
