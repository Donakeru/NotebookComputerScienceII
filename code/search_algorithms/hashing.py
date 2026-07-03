SLOTS = 10


class HashTable:

    def __init__(self):
        self.table = [[] for _ in range(SLOTS)]

    def hash_function(self, key):
        return key % SLOTS

    def insert(self, key):
        slot = self.hash_function(key)
        self.table[slot].append(key)

    def search(self, key):
        slot = self.hash_function(key)
        return key in self.table[slot]

    def print_table(self):
        for i, bucket in enumerate(self.table):
            print(f"[{i}] -> {bucket}")


ht = HashTable()

for value in [234, 543, 1, 11, 21, 31]:
    ht.insert(value)

ht.print_table()

print(ht.search(234))
print(ht.search(500))