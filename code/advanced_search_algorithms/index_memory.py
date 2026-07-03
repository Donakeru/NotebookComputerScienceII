import json

# Lista con información de estudiantes y añadirle una adicional
lista_estudiantes = []
index_table = []

def create_list():
    global lista_estudiantes
    with open('students.json', 'r', encoding='UTF') as file:
        lista_estudiantes = json.load(file)

def print_students():
    for student in lista_estudiantes:
        print(f'codigo: {student["codigo"]}, nombre: {student["nombre"]}, edad: {student["edad"]}\n')

def create_index():
    global index_table
    for i, student in enumerate(lista_estudiantes):
        print(student)
        index_table.append((student['codigo'], i))
    index_table = sorted(index_table, key=lambda x: x[0])
    print("---------")
    print(index_table)
    
def binary_search(code: int):
    
    lower = 0
    upper = len(index_table)
    
    while lower <= upper:
        middle = (upper + lower) // 2

        if index_table[middle][0] == code:
            return index_table[middle][1]
        if index_table[middle][0] < code:
            lower = middle + 1
        if index_table[middle][0] > code:
            upper = middle -1

    return -1

def search(code: int):
    student_i = binary_search(code)
    print('---- resultado ----')
    if student_i != -1:
        print(lista_estudiantes[student_i])
    else:
        print("student not found")
        
create_list()
print_students()
create_index()
search(20212020089)



