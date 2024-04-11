from collections import defaultdict
import heapq
def read_probabilities(file_name):
    probabilities = {}
    with open(file_name, 'r', encoding='utf-8') as file:
        for line in file:
            symbol, probability = line.strip().split()
            probabilities[symbol] = float(probability)
    return probabilities
#Шеннон-Фано
def shannon_fano(probabilities):
    sorted_probabilities = sorted(probabilities.items(), key=lambda x: x[1], reverse=True)
    codes = defaultdict(str)
    def build_code(symbols, start, end):
        if start == end:
            return
        if start + 1 == end:
            codes[symbols[start]] += '0'
            codes[symbols[end]] += '1'
            return
        total_probability = sum(probabilities[symbol] for symbol in symbols[start:end+1])
        cumulative_probability = 0
        split_index = start

        for i in range(start, end+1):
            cumulative_probability += probabilities[symbols[i]]
            if cumulative_probability >= total_probability / 2:
                split_index = i
                break
        for i in range(start, split_index+1):
            codes[symbols[i]] += '0'
        for i in range(split_index+1, end+1):
            codes[symbols[i]] += '1'
        build_code(symbols, start, split_index)
        build_code(symbols, split_index+1, end)
    symbols = [symbol for symbol, _ in sorted_probabilities]
    build_code(symbols, 0, len(symbols)-1)
    return dict(codes)
#Хаффман
def huffman(probabilities):
    heap = [[weight, [symbol, ""]] for symbol, weight in probabilities.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        lo = heapq.heappop(heap)
        hi = heapq.heappop(heap)
        for pair in lo[1:]:
            pair[1] = '0' + pair[1]
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    huffman_codes = dict(heapq.heappop(heap)[1:])
    return huffman_codes

# Закодировать текст
def encode_text(text, codes):
    encoded_text = ''
    for char in text:
        # Добавляем код символа в закодированный текст, используя метод get(),
        # чтобы обрабатывать случай отсутствия символа в словаре
        encoded_text += codes.get(char, '')  
    return encoded_text

# Прочитать вероятности символов из файла
probabilities = read_probabilities('probabilities.txt')

#Вызов функций метода Шеннона-фано
codes = shannon_fano(probabilities)
# Закодировать текст с использованием построенных кодов
input_text = open("text.txt", encoding='utf-8').read()
encoded_text = encode_text(input_text, codes)
# Сохранить закодированный текст и коды в файл
with open('encoded_text.txt', 'w', encoding='utf-8') as file:
    file.write(encoded_text + '\n')
    for symbol, code in codes.items():
        file.write(f"{symbol} {code} {probabilities[symbol]} {len(code)}\n") 
        
#Вызов функций метода Хаффмана
codes_huffman = huffman(probabilities)
# Закодировать текст с использованием построенных кодов
input_text = open("text.txt", encoding='utf-8').read()

encoded_text_huffman = encode_text(input_text, codes_huffman)
# Сохранить закодированный текст и коды в файл
with open('encoded_text_huffman.txt', 'w', encoding='utf-8') as file:
    file.write(encoded_text_huffman + '\n')
    for symbol, code in codes_huffman.items():
        file.write(f"{symbol} {code} {probabilities[symbol]} {len(code)}\n")

