mainProgram.c - главный файл, в котором происходит обработка данных от пользователя
sorting.c - файл, в котором реализована функция сортировки
sorting.s - файл, в котором содержится ассемблерный код sorting.c
sorting.h - библиотека

Инструкция по сборке:


С использованием уже готового ассемблерного кода:

gcc -O3 -Wall -Wextra -pedantic -o sort mainProgram.c sorting.s
./sort

Для генерации кода ассемблера из С-шника + запуск приложения:

gcc -O3 -Wall -Wextra -pedantic -S sorting.c -o sorting.s
gcc -O3 -Wall -Wextra -pedantic -o sort mainProgram.c sorting.s
./sort

