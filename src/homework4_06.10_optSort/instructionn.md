# ИНСТРУКЦИЯ ПО СБОРКЕ
------------------------------------------------------------
# Генерация ассемблерного кода
gcc -S -O2 optSort.c -o optSort.s

# Компиляция и линковка
gcc -c main.c -o main.o
gcc -c optSort.s -o optSort.o
gcc -o NumberSorter main.o optSort.o

# Тестирование
echo "5 2 8 1 9" | ./NumberSorter
