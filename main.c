#include <stdio.h>
#include <stdlib.h>

#include "./linked-list/linked_list.h"
//#include "./queue/queue.h"
//#include "./stack/stack.h"

int main(int argc, char const *argv[])
{
    linked_list list = list_new();

    if (list == NULL)
    {
        exit(1);
    }

    list_insert_end(list, 1);
    list_insert_end(list, 2);
    list_insert_end(list, 3);
    list_insert_end(list, 4);
    list_print(list);
    list_remove_at_position(list, 0);
    list_remove_at_position(list, 1);
    list_print(list);
    list_destroy(list);

    return 0;
}

/*valgrind --leak-check=full ./main
==10136== Memcheck, a memory error detector
==10136== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10136== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10136== Command: ./main
==10136== 
[2 ]
[2 1 3 ]
list is empty 0
list size 3
[2 3 ]
list is empty 0
list size 2
[2 3 ]
list is empty 0
list size 2
==10136== 
==10136== HEAP SUMMARY:
==10136==     in use at exit: 96 bytes in 4 blocks
==10136==   total heap usage: 6 allocs, 2 frees, 1,144 bytes allocated
==10136== 
==10136== 96 (24 direct, 72 indirect) bytes in 1 blocks are definitely lost in loss record 4 of 4
==10136==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10136==    by 0x108811: list_new (in /home/daloyce/Documents/Programação/c-algorithm-and-data-structures-master/linked-list/main)
==10136==    by 0x108D56: main (in /home/daloyce/Documents/Programação/c-algorithm-and-data-structures-master/linked-list/main)
==10136== 
==10136== LEAK SUMMARY:
==10136==    definitely lost: 24 bytes in 1 blocks
==10136==    indirectly lost: 72 bytes in 3 blocks
==10136==      possibly lost: 0 bytes in 0 blocks
==10136==    still reachable: 0 bytes in 0 blocks
==10136==         suppressed: 0 bytes in 0 blocks
==10136== 
==10136== For counts of detected and suppressed errors, rerun with: -v
==10136== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/