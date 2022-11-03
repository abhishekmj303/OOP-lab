import tkinter as tk
from tkinter import messagebox

def create_label(text: str, row: int, column: int, inplace=False):
    label = tk.Label(main, text=text)
    label.grid(row=row, column=column)

    if inplace:
        main_ui[text] = label
    else:
        return label

def create_entry(row: int, column: int):
    entry = tk.Entry(main)
    entry.grid(row=row, column=column)
    return entry

def create_button(text: str, cmd: object, row: int, column: int, inplace=False):
    button = tk.Button(main, text=text, command=cmd, bg="lightgreen")
    button.grid(row=row, column=column)

    if inplace:
        main_ui[text] = button
    else:
        return button

def create_frame(text: str, row: int, column: int, inplace=False):
    label = create_label(text, row, column)
    entry = create_entry(row, column+1)

    frame_ui = {'label': label, 'entry': entry}
    if inplace:
        main_ui[text] = frame_ui
    else:
        return frame_ui

def create_table(table: dict, row: int, column: int, inplace=False):
    table_ui = {}
    for key, value in table.items():
        if isinstance(key, str):
            label = create_label(key, row, column)
            value_labels = []
            r, c = row+1, column
            for v in value:
                value_labels.append(create_label(v, r, c))
                r += 1
            table_ui[key] = {"attr": label, "val": value_labels}
            column += 1
        elif isinstance(key, tuple):
            label = [create_label(key[i], row, column+i) for i in (0,1)]
            frames = []
            r, c = row+1, column
            for v in value:
                frames.append(create_frame(v, r, c))
                frames[-1]['entry'].configure(validate='key', validatecommand=(main.register(validate_grade), "%P"))
                r += 1
            table_ui[key] = {"atrr": label, "val": frames}
            column += 2
    
    if inplace:
        main_ui['table'] = table_ui
    else:
        return table_ui

def check_info():
    info_labels = ['Name', 'Roll.No', 'Reg.No']
    info_frames = [main_ui[label] for label in info_labels]
    for frame in info_frames:
        if frame['entry'].get() == "":
            messagebox.showerror("Error", "Missing information: " + frame['label']['text'])
            return False
    return True

def calc_result():
    if not check_info():
        return
    
    grades_obt = main_ui["table"][("Subject", "Grade")]["val"]
    sub_credits = marks_table["Sub Credit"]
    credits_obt = main_ui["table"]["Credit Obtained"]["val"]

    total_cred = 0
    total_sub_cred = 0
    for g, s, c in zip(grades_obt, sub_credits, credits_obt):
        g_pnt = grades.get(g["entry"].get().upper(), -1)
        if g_pnt == -1:
            messagebox.showerror("Error", "Missing grade for subject: " + g["label"]["text"])
            return
        cred = g_pnt*int(s)
        c.configure(text=cred)
        total_cred += cred
        total_sub_cred += int(s)
    
    sgpa = round(total_cred / total_sub_cred, 2)
    main_ui["result"]["Total Credit"]["val"].configure(text=total_cred)
    main_ui["result"]["SGPA"]["val"].configure(text=sgpa)

def validate_grade(inp: str):
    valid_grades = ["S", "A", "B", "C", "D", "U", "W", "I", ""]
    if inp.upper() in valid_grades:
        return True
    else:
        return False

main = tk.Tk()
main.title("Marksheet")

main_ui = {}

stud_info = [("Name", 0, 0), ("Roll.No", 1, 0), ("Reg.No", 0, 3)]

marks_table = {
    "Srl.No": ["1", "2", "3", "4"],
    ("Subject", "Grade"): ["CS 201", "CS 202", "MA 201", "EC 201"],
    "Sub Credit": ["4", "4", "3", "4"],
    "Credit Obtained": [""]*4,
}

result = {
    "Total Credit": (7, 3),
    "SGPA": (8, 3)
}

grades = {"S": 10, "A": 9, "B": 8, "C": 7, "D": 6, "E": 5, "U": 0, "I": 0, "W": 0}

for s in stud_info:
    create_frame(s[0], s[1], s[2], inplace=True)

create_table(marks_table, 2, 0, inplace=True)

result_ui = {}
for key, value in result.items():
    label = create_label(key, value[0], value[1])
    value = create_label("", value[0], value[1]+1)
    result_ui[key] = {"label": label, "val": value}

main_ui["result"] = result_ui

create_button("Submit", calc_result, 8, 1, inplace=True)

main.mainloop()