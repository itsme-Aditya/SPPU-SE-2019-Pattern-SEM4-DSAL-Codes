def probe(keys, n):
    table = [None] * 10
    chain = [-1] * 10
    t = 0

    for i in range(n):
        x = keys[i]
        hkey = (x % 10)
        
        if (table[hkey] is None):
            table[hkey] = x
        else:
            p = hkey

            while (table[hkey] is not None):
                hkey += 1
                t += 1
                if (hkey > 9):
                    hkey = 0

            table[hkey] = x

            if (chain[p] != -1):
                p = chain[p]
            chain[p] = hkey
        
        t += 1

    for j in range(10):
        print(table[j], "\t", chain[j])

    return t


def double(keys, n):
    table = [None] * 11
    t = 0
    for x in keys:
        i = 0
        h1 = x % 11
        h2 = 7 - (x % 7)
        hkey = (h1 + i * h2) % 11

        while (table[hkey] is not None):
            i += 1
            hkey = (h1 + i * h2) % 11
            t += 1

        table[hkey] = x
        t += 1
    
    for i in range(11):
        print(table[i])
    

    return t


sample = [12, 44, 13, 88, 23, 94]
a = probe(sample, len(sample))
b = double(sample, len(sample))
print("Comparisons for probe: ", a)
print("Comparisons for double: ", b)
