#include <stdio.h>
#include <stdlib.h>
void FCFS(int t[], int n, int current)
{
    int seek_time = 0;
    for (int i = 0; i < n; i++)
    {
        int distance = abs(current - t[i]);
        seek_time += distance;
        current = t[i];
    }
    printf("Total seek time : %d\n", seek_time);
}
void SSTF(int t[], int n, int current)
{
    int seek_time = 0;
    int count = 0;
    int seek_sequence[n];
    int tmp = 999;
    int index;
    for (int i = 0; i < n; i++)
    {
        int dist = abs(current - t[i]);
        if (tmp > dist)
        {
            tmp = dist;
            index = i;
        }
    }
    seek_time += tmp;
    seek_sequence[count] = t[index];
    t[index] = -t[index];
    count++;
    while (count != n)
    {
        tmp = 999;
        int ind;
        int dist;
        for (int i = 0; i < n; i++)
        {
            dist = abs(abs(t[index]) - abs(t[i]));
            if (tmp > dist && t[i] > 0)
            {
                tmp = dist;
                ind = i;
            }
        }
        seek_time += tmp;
        index = ind;
        seek_sequence[count] = t[index];
        t[index] = -t[index];
        count++;
    }
    printf("Total seek time : %d\n", seek_time);
    printf("Seek Sequence : ");
    for (int i = 0; i < n; i++)
        printf("%d\t", seek_sequence[i]);
    printf("\n");
}
void SCAN(int t[], int n, int current)
{
    int direction;
    int additional_value = 199;
    int index_of_head;
    int seek_time = 0;
    int seek_sequence[n + 1];
    int count = 0;
    printf("Enter direction of the scan :\n");
    printf("1.Right to Left\n");
    printf("2.Left to Right\n");
    printf("Choice: ");
    scanf("%d", &direction);
    if (direction == 1)
        additional_value = 0;
    t[n] = additional_value;
    t[n + 1] = current;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = i; j < n + 2; j++)
        {
            if (t[i] > t[j])
            {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
    for (int i = 0; i < n + 2; i++)
    {
        if (t[i] == current)
        {
            index_of_head = i;
            break;
        }
    }
    if (direction == 1)
    {
        for (int i = index_of_head - 1; i >= 0; i--)
        {
            int dist = abs(current - t[i]);
            seek_time += dist;
            current = t[i];
            seek_sequence[count] = t[i];
            count++;
        }
        for (int i = index_of_head + 1; i < n + 2; i++)
        {
            int dist = abs(current - t[i]);
            seek_time += dist;
            current = t[i];
            seek_sequence[count] = t[i];
            count++;
        }
    }
    else
    {
        for (int i = index_of_head + 1; i < n + 2; i++)
        {
            int dist = abs(current - t[i]);
            seek_time += dist;
            current = t[i];
            seek_sequence[count] = t[i];
            count++;
        }
        for (int i = index_of_head - 1; i >= 0; i--)
        {
            int dist = abs(current - t[i]);
            seek_time += dist;
            current = t[i];
            seek_sequence[count] = t[i];
            count++;
        }
    }
    printf("Seek time : %d\n", seek_time);
    printf("Seek Sequence : ");
    for (int i = 0; i < n + 1; i++)
        printf("%d\t", seek_sequence[i]);
    printf("\n");
}
void CSCAN(int t[], int n, int current)
{
    int direction;
    int index_of_head;
    int seek_time = 0;
    int seek_sequence[n + 3];
    int count = 0;
    printf("Enter Direction : \n");
    printf("1. Left to Right\n");
    printf("2. Right to Left\n");
    printf("Choice: ");
    scanf("%d", &direction);
    t[n] = 0;
    t[n + 1] = 199;
    t[n + 2] = current;
    for (int i = 0; i < n + 3; i++)
    {
        for (int j = i; j < n + 3; j++)
        {
            if (t[i] > t[j])
            {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
    for (int i = 0; i < n + 3; i++)
    {
        if (t[i] == current)
        {
            index_of_head = i;
            break;
        }
    }
    if (direction == 1)
    {
        for (int i = index_of_head + 1; i < n + 3; i++)
        {
            int dist = abs(current - t[i]);
            seek_time += dist;
            current = t[i];
            seek_sequence[count] = t[i];
            count++;
        }
        seek_time += abs(199 - 0);
        current = 0;
        seek_sequence[count] = 0;
        count++;
        for (int i = 1; i < index_of_head; i++)
        {
            int dist = abs(current - t[i]);
            seek_time += dist;
            current = t[i];
            seek_sequence[count] = t[i];
            count++;
        }
    }
    else
    {
        seek_time += abs(current - 0);
        current = 0;
        seek_sequence[count] = 0;
        count++;
        for (int i = 1; i < n + 3; i++)
        {
            if (i == index_of_head)
                continue;
            int dist = abs(current - t[i]);
            seek_time += dist;
            current = t[i];
            seek_sequence[count] = t[i];
            count++;
        }
    }
    printf("Seek time : %d\n", seek_time);
    printf("Seek Sequence : ");
    for (int i = 0; i < count; i++)
        printf("%d\t", seek_sequence[i]);
    printf("\n");
}
int main()
{
    int n, current_pos;
    printf("\nEnter number of disck tracks : ");
    scanf("%d", &n);
    int tracks[n + 3];
    printf("\nEnter %d disk track numbers : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
    printf("\nEnter current position of head : ");
    scanf("%d", &current_pos);
    // FCFS(tracks,n,current_pos);
    // SSTF(tracks,n,current_pos);
    //  SCAN(tracks,n,current_pos);
    CSCAN(tracks, n, current_pos);
    return 0;
}


