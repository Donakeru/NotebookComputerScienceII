slots = 10

hash_table = []

def init():
    for i in range(slots):
        hash_table.append([])

def hash_function_module(key: int) -> int:
    return key % slots

def hash_function_middle_square(key: int) -> str:
    remove = 1
    slot = str(key ** 2)
    slot = slot[remove:-remove] # slicing
    return slot

def truncate(key: int) -> str:
    positions = (3, 4, 8)
    key_str = str(key)
    slot = ''
    for p in positions:
        slot += key_str[p]
    return slot

def insert(key: int):
    slot = hash_function_module(key)
    hash_table[slot].append(key)
    
def search(key: int) -> int:
    slot = hash_function_module(key)
    value = -1
    
    for i, key_i in enumerate(hash_table[slot]):
        if key_i == key:
            value = slot, i
    return value
    
init()
insert(234)
insert(546)
insert(20212020109)

print(search(234))
