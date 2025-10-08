# Компиляция C-файла
gcc -c sort.c -o sort.o

# Ассемблирование asm-файла  
as bubbleSortAsm.s -o bubbleSortAsm.o

# Линковка
gcc sort.o bubbleSortAsm.o -o sorter

# Запуск
echo "5 2 8 1 9" | ./sorter
echo "Количество элементов, изменивших свое положение: $?"
