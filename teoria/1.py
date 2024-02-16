if __name__ == "__main__":
    with open('text.txt', 'r', encoding='utf-8') as file:
        text = file.read()
    text = text.lower()
    abc = " оеаинтсрвлкмдпуяызъбгчйхжюшцщэф"
    C = 0
    for char in abc:
        c = text.count(char)
        print(f"{char}  {c}")
        C = c+C
    print("Всего: ",C)