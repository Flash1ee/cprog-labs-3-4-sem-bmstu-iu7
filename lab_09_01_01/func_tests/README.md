# Тесты к лабораторной работе №91

*входные данные* : app.exe FILE FIELD [KEY]  
где FILE — имя файла, FIELD — анализируемое поле, KEY — значение ключа;  
*выходные данные* : 
- Если значение ключа не указано, выводит упорядоченный массив.
- Если значение ключа указано, выполняет двоичный поиск по полю и значению  
ключа. Если кинофильм с искомым значением ключа найден, программа выводит  
информацию о нём на экран, иначе программа выводит сообщение «Not found». 

## Негативные:  
- 01 Неверное количество ключей;  
- 02 Неверное имя поля (аргумент 3);  
- 03 Несуществующий файл;  
- 04 Числовое поле структуры - не число;  
- 05 При поиске по ключу year значение - не число;
- 06 Структур в файле больше чем MAX;  
- 07 Пустой файл;  
- 08 Длина аргумента *key* > (**N - 1**);  
- 09 Аргумент *field* = *year* и **year** не число или число < 0;  
- 010 Поле *year* не в первой структуре файла <= 0;  



## Позитивные:  
- 01 Файл с неравными полями *year*, по которым сортируются структуры;  
- 02 Файл с равными полями в ключе *name*, по которым происходит сортировка;  
- 03 Поиск по полю, которого нет ни в одной структуре;  
- 04 Поиск по полю, которое есть в структуре;  
- 06 Файл с поиском по полю *title*;  
- 07 Бинарным поиском по полю *title* возвращается элемент, находящийся в середине массива структур;  
- 08 Бинарным поиском по полю *name* ищется элемент, находящийся в второй половине массива структур;  



