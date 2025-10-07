mainProgram.c - главный файл, в котором происходит обработка данных от пользователя
sort.c - файл, в котором реализована функция сортировки
sort.s - файл, в котором содержится ассемблерный код sort.c

Инструкция по сборке:


gcc -O0 -S sort.c -o sort.s

gcc -no-pie -o sort mainProgram.c sort.s
 
./sort
