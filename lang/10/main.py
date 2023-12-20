
if __name__ == "__main__":
    A = []
    s = input("Введите строку: ").lower().split()
    for i in range(len(s)):
        c = s.count(s[i])
        if c>1:
            A.append((c,s[i]))
    answ = list(set(A))
    answ.sort()
    answ.reverse()
    for i in answ:
        print(f"|{i[1]:^10}|{str(i[0]):^10}|")
        
    
    #""", table
    