import ctypes
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import random

LIB_ARR = "./lib/libarr.so"
FUNCS = ["Массив простых", "Фильтрация массива_1", "Фильтрация массива_2"]
libc = ctypes.CDLL(LIB_ARR)

#int fill_prime(int *arr, int n)
def import_library_func():
    fill_prime = libc.fill_prime
    fill_prime.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
    fill_prime.restype = ctypes.c_int

    form_arr_user_size= libc.form_arr_user_size
    form_arr_user_size.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.c_int)
    form_arr_user_size.restype = ctypes.c_int

    form_arr_my_size = libc.form_arr_my_size
    form_arr_my_size.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
    form_arr_my_size.restype = ctypes.c_int

    return (fill_prime, form_arr_user_size, form_arr_my_size)



def show_help():
    new_window = tk.Toplevel()
    new_window.title("Справка")
    text = [["---------------","Программа для работы с библиотекой libarr.so", "---------------"],
        ["Си-функции","Python-функции","Описание"],
        ["int fill_prime(int *arr, int n)","fill_prime(arr)","Заполнение массива простыми числами"],
        ["int form_arr_user_size(int *src, int src_n, int *dst, int dst_n)","form_arr_user(src)","Копирование из массива src в dst чисел,находящихся"
        "после четных в src.\nРазмер dst на вызывающей стороне"],
        ["int form_arr_my_size(int *src, int src_n, int *dst, int *dst_n)","form_arr_my(src)","Копирование из массива src в dst чисел,находящихся"
        "после четных в src.\nРазмер dst_n в случае нехватки исходного обновляется требуемым"]
    ]
    for i in range (len(text)):
        new_window.columnconfigure(i, weight=1, minsize=75)
        new_window.rowconfigure(i, weight=1, minsize=50)

        for j in range(len(text[i])):

            frame = tk.Frame(
            master=new_window,
            relief=tk.RAISED,
            borderwidth=1
        )
            mes = text[i][j]
            frame.grid(row=i, column=j, padx=5, pady=5, sticky = tk.W+tk.E+tk.S+tk.N)
 
            label = tk.Label(master=frame, text=str(mes), wraplen = 300, anchor = tk.W)
            label.pack(padx=5, pady=5)

    tk.Label(new_window, text = "Количество данных на вызывающей стороне,"
    "при вводе больших значений возможны задержки выполнения").grid(row = len(text), column = 0, columnspan = 3)
    
    

def form_menu(main_menu : tk.Menu):
    main_menu.add_command(label = "Справка", command = show_help)


def fill_prime(n):
    arr = (ctypes.c_int * n)()

    rc = _fill_prime(arr, n)

    return list(arr)
    
def form_arr_by_even(src):
    src_len = len(src)
    if (not src_len):
        return []
    dst_len = src_len
    
    src_c = (ctypes.c_int * src_len)(*src)
    dst_c = (ctypes.c_int * dst_len)()

    dst_len = _form_arr_user(src_c, src_len, dst_c, dst_len)

    return list(dst_c[:dst_len])

def form_arr_by_even_eco(src):
    src_len = len(src)
    if (not src_len):
        return []

    dst_len = (ctypes.c_int)(0)
    src_c = (ctypes.c_int * src_len)(*src)

    rc = _form_arr_my(src_c, src_len, None, dst_len)
    if rc:
        dst_c = (ctypes.c_int * dst_len.value)()

        _form_arr_my(src_c, src_len, dst_c, dst_len)

        return list(dst_c)

    return []

def change_func():
    func_list["values"] = [i for i in FUNCS]

def exit_app():
    msg = tk.messagebox.askquestion ('Уходите?','Выйти?',icon = 'error')    
    if msg == 'yes':
        window.destroy()
    else:
        tk.messagebox.showinfo('Благодарим за использование','Продолжаем')
def random_fill():
    my_entry.delete(1.0, tk.END)
    func = func_list.get()
    if (func not in FUNCS):
        tk.messagebox.showinfo("Ошибочка", "Нужно выбрать функцию в поле \"Функция\"")
    elif (func == FUNCS[0]):
        my_entry.insert(1.0,str(random.randint(1, 50)))
        return
    else:
        my_entry.insert(1.0," ".join(str(i) for i in [random.randint(1,50) for j in range(10)]))


def calculate():
    cur_value = func_list.get()
    if (cur_value == FUNCS[0]):
        user_input = my_entry.get(1.0, tk.END).split()
        if (len(user_input) != 1 or not user_input[0].isdecimal()):
            messagebox.showinfo("Вас заметили", "Ввод некорректен")
            return
        n = int(user_input[0])
        res = fill_prime(n)
        my_result.configure(state=tk.NORMAL)
        my_result.delete(1.0, tk.END)
        my_result.insert(1.0, str(res))
        my_result.configure(state=tk.DISABLED)

    elif (cur_value == FUNCS[1] or cur_value == FUNCS[2]):
        user_input = my_entry.get(1.0, tk.END).split()
        for i in user_input:
            if (not i.isdecimal()):
                messagebox.showinfo("Вас заметили", "Ввод некорректен")
                return
        src = [int(num) for num in user_input]
        print(src)
        if (cur_value == FUNCS[1]):
            res = form_arr_by_even(src)
        else:
            res = form_arr_by_even_eco(src)
        # res = " ".join(i for i in form_arr_by_even(src))
        my_result.configure(state=tk.NORMAL)
        my_result.delete(1.0, tk.END)
        my_result.insert(1.0, str(res))
        my_result.configure(state=tk.DISABLED)
    else:
        messagebox.showinfo("Вас заметили", "Ввод некорректен")
        
window = tk.Tk()
window.resizable(width = False, height = False)
tk.Label(text="Функция").grid(row=0, column=0, sticky=tk.W, pady=10, padx=10)
func_list = ttk.Combobox(values=["Массив простых",
                            "Фильтрация массива_1",
                            "Фильтрация массива_2",
                            ],
                            postcommand=change_func)


func_list.grid(row=0, column=1,columnspan=3,sticky=tk.W+tk.E, padx=10)
 
tk.Label(text="Входные").grid(row = 1, column = 0, rowspan = 2, columnspan = 1,  sticky=tk.W, pady=10, padx=10)

my_entry = tk.Text(width = 60, height = 4)
my_entry.grid(row = 1, column = 1, rowspan = 2, columnspan = 3, sticky = tk.W + tk.E, padx=10)


tk.Button(text = "Запуск", command = calculate).grid(row = 3, column = 2, sticky = tk.W + tk.E)
tk.Label(text="Выходные").grid(row=4, column=0, rowspan = 2, sticky = tk.W, pady = 10, padx = 10)
my_result = tk.Text(width = 60, height = 4, state = tk.DISABLED)
my_result.grid(row = 4, column = 1, columnspan = 3) #перед добавлением state = "normal"

scroll_y = tk.Scrollbar(command=my_result.yview)
scroll_x = tk.Scrollbar(orient='horizontal')

scroll_y.grid(row = 4, column = 4)
scroll_x.grid(row = 5, column = 2)

my_result.config(yscrollcommand=scroll_y.set)
my_result.config(xscrollcommand=scroll_x.set)


tk.Button(text="Справка", command = show_help).grid(row=6, column=0, pady=10, padx=10)
tk.Button(text="Случайное заполнение", command = random_fill).grid(row=6, column=2)
tk.Button(text="Выход", command = exit_app).grid(row=6, column=3)

main_menu = tk.Menu(window)
form_menu(main_menu)

_fill_prime, _form_arr_user, _form_arr_my = import_library_func()

print(_fill_prime, _form_arr_my, _form_arr_user)

print(fill_prime(5))
print(form_arr_by_even([2,3,4,5,6,7]))
print(form_arr_by_even([]))
print(form_arr_by_even([1,1,1,1,1]))

print(form_arr_by_even_eco([2,3,4,5,6,7]))
print(form_arr_by_even_eco([]))
print(form_arr_by_even_eco([1,1,2,1,1]))
print(form_arr_by_even_eco([2,2,2,2,22]))




window.config(menu=main_menu)


window.mainloop()