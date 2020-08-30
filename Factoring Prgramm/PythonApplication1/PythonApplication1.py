import math
def inserter(value):
    output.delete("0.0","end")
    output.insert("0.0",value)
def handler():
    try:
        a_val = float(a.get())
        inserter(math.factorial(a_val))
    except ValueError:
        inserter("It isn't number!")
 
from tkinter import *
root = Tk()
root.title("Factoring program by IZOBRETATEL777")

fra = Frame(root,width=500,height=250)
but2 = Button(root,text="Exit", command=root.destroy)
but1 = Button(fra, text="Factoring this!", command=handler).grid(row=1, column=7, padx=(10,0))


output = Text(fra, bg="lightgreen", font="Arial 14", width=40, height=1)
output.grid(row=2, columnspan=8)

inf = Text(fra, bg="lightblue", font="Arial 14", width=40, height=10)
inf.grid(row=3, columnspan=10)
inf.insert("0.0","\nIn mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n.\n\nFor example, 5!=5*4*3*2*1=120.\n\nThe value of 0! is 1, according to the convention for an empty product.")

a = Entry(fra, width=60)
a.grid(row=1,column=1,padx=(10,0))
a.focus_set()
root.bind("<Return>", output.insert("0.0","Hello!"))
fra.pack()
but2.pack()

 
root.mainloop()
