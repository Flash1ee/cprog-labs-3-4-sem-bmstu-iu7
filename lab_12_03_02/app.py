import ctypes
import tkinter as tk

LIB_ARR = "./lib/libarr.so"

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




text = [[["---------------"],["Программа для работы с библиотекой libarr.so"], ["---------------"]],
        [["Си-функции"],["Python-функции"],["Описание"]],
        [["int fill_prime(int *arr, int n)"],["fill_prime(arr, n)"],["Заполнение массива простыми числами"]],
        [["int form_arr_user_size(int *src, int src_n, int *dst, int dst_n)"],["form arr_user(src, src_n, dst, dst_n)"],["Копирование из массива src в dst чисел,\n находящихся"
        "после четных в src.\n Размер dst на вызывающей стороне"]],
        [["int form_arr_my_size(int *src, int src_n, int *dst, int *dst_n)"],["form_arr_my_size(src, src_n, dst, dst_n)"],["Копирование из массива src в dst чисел,находящихся\n"
        "после четных в src.\nРазмер dst_n в случае нехватки исходного значения\n обновляется требуемым"]]
]

def show_help():
    new_window = tk.Toplevel()
    new_window.title("Справка")

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
            frame.grid(row=i, column=j, padx=5, pady=5, sticky = "w")
 
            label = tk.Label(master=frame, text=mes)
            label.pack(padx=5, pady=5)

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

window = tk.Tk()
label = tk.Label(text="Добро пожаловать в программу для работы с библиотекой, написанной на языке СИ")

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



label.pack(side = tk.LEFT)
 
window.mainloop()