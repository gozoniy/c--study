
if __name__ == "__main__":
    A = []
    s = input().lower().split()
    for i in range(len(s)):
        c = 0
        
        for j in range(len(s)):
            if s[i] == s[j]:
                c+=1
        if c>1:
            A.append((c,s[i]))
    
    answ = list(set(A))
    answ.sort()
    answ.reverse()
    for i in answ:
        pr = "Слово '" + i[1] + "' встречается " + str(i[0]) + " раз."
        print(pr)
    