import tkinter as tk
from tkinter import ttk

main = tk.Tk()
main.title("BMI Calculator")
main.configure(bg="#D2DAFF")
main.option_add( "*font", "Comfortaa 12 bold" )

style = ttk.Style()
style.theme_use("clam")

def validate_entry(inp):
    valid_char = ["", "."]
    if inp in valid_char:
        return True
    try:
        float(inp)
    except:
        return False
    return True

h_label = tk.Label(main, text="Height (in meter)", bg="#D2DAFF")
h_label.grid(row=0, column=0)

h_entry = tk.Entry(main, bg="#B1B2FF", validate='key', validatecommand=(main.register(validate_entry), "%P"))
h_entry.grid(row=0, column=1)

w_label = tk.Label(main, text="Weight (in kg)", bg="#D2DAFF")
w_label.grid(row=1, column=0)

w_entry = tk.Entry(main, bg="#B1B2FF", validate='key', validatecommand=(main.register(validate_entry), "%P"))
w_entry.grid(row=1, column=1)

bmi_label = tk.Label(main, text="Your BMI", bg="#D2DAFF")
bmi_label.grid(row=2, column=0)

bmi_entry = tk.Entry(main, bg="#B1B2FF")
bmi_entry.grid(row=2, column=1)

res_label = tk.Label(main, text="", bg="#D2DAFF")
res_label.grid(row=3, column=1)

def calculate_bmi():
    try:
        height = float(h_entry.get())
        weight = float(w_entry.get())
    except ValueError:
        bmi_entry.delete(0, tk.END)
        bmi_entry.insert(0, "NaN")
        return
    
    try:
        bmi = round(weight / (height * height), 2)
    except ZeroDivisionError:
        bmi_entry.delete(0, tk.END)
        bmi_entry.insert(0, "NaN")
        return

    bmi_entry.delete(0, tk.END)
    bmi_entry.insert(0, bmi)
    bmi_category()

def bmi_category():
    try:
        bmi = float(bmi_entry.get())
    except ValueError:
        res_label.configure(text="")
        return

    if bmi < 18.5:
        res_label.configure(text="You are Underweight 😔,\n eat more!", fg="#B32C50")
    elif bmi < 25:
        res_label.configure(text="You are Healthy 😊,\n keep it up!", fg="#594057")
    elif bmi < 30:
        res_label.configure(text="You are Overweight 😔,\n exercise more!", fg="#B32C50")
    else:
        res_label.configure(text="You are Obese 😔,\n exercise more and more!", fg="red")

calculate_button = tk.Button(main, text="Calculate", command=calculate_bmi, bg="#AAC4FF", activebackground="#D2DAFF")
calculate_button.grid(row=3, column=0)

main.mainloop()
