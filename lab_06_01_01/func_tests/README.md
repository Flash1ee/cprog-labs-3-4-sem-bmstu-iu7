# Тесты к лабораторной работе №61

*входные данные* : app.exe FILE FIELD [KEY]  
где FILE — имя файла, FIELD — анализируемое поле, KEY — значение ключа;  
*выходные данные* : 
- Если значение ключа не указано, выводит упорядоченный массив.
- Если значение ключа указано, выполняет двоичный поиск по полю и значению  
ключа. Если кинофильм с искомым значением ключа найден, программа выводит  
информацию о нём на экран, иначе программа выводит сообщение «Not found». 

## Негативные:  
- 001 Неверное количество ключей;  
- 002 Неверное имя поля (аргумент 3);  
- 003 Несуществующий файл;  
- 004 Число символов в строковых полях превышает N;    
- 005 Ошибка 4, но не в первой структуре;  
- 006 Числовое поле структуры - не число;  
- 007 При поиске по ключу year значение - не число;
- 008 Структур в файле больше чем MAX;  
- 009 Во второй структуре превышение кол-ва символов в поле *title*;  
- 0010 Пустой файл;  
- 0011 Длина аргумента *key* > (**N - 1**);  
- 0012 Аргумент *field* = *year* и **year** не число или число < 0;  
- 0013 Поле *name* не в первой структуре файла занимает больше, чем N символов;  
- 0014 Поле *year* не в первой структуре файла <= 0;  



## Позитивные:  
- 01 Файл с неравными полями *year*, по которым сортируются структуры;  
- 02 Файл с равными полями в ключе *name*, по которым происходит сортировка;  
- 03 Поиск по полю, которого нет ни в одной структуре;  
- 04 Поиск по полю, которое есть в структуре;  
- 06 Файл с поиском по полю *title*;  
- 07 Бинарным поиском по полю *title* возвращается элемент, находящийся в середине массива структур;  
- 08 Бинарным поиском по полю *name* ищется элемент, находящийся в второй половине массива структур;  



