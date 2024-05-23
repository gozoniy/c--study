from collections import defaultdict
import heapq

# чтение веро€тностей символов из файла
def read_probs(file_name):
    probs = {}
    with open(file_name, 'r', encoding='utf-8') as file:
        for line in file:
            sym, prob = line.strip().split()
            probs[sym] = float(prob)
    return probs

# кодировкатекста
def encode_text(text, codes):
    encoded_text = ''
    for char in text:
        encoded_text += codes.get(char, '')  
    return encoded_text

# построениекодов’аффмана
def huffman_method(probs):
    heap = [[weight, [sym, ""]] for sym, weight in probs.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        lo = heapq.heappop(heap)
        hi = heapq.heappop(heap)
        for p in lo[1:]:
            p[1] = '0' + p[1]
        for p in hi[1:]:
            p[1] = '1' + p[1]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    huffman_codes = dict(heapq.heappop(heap)[1:])
    return huffman_codes

# построение кодов Ўеннона-‘ано
def sf_method(probs):
    sorted_probs = sorted(probs.items(), key=lambda x: x[1], reverse=True)
    codes = defaultdict(str)

    def build_code(syms, start, end):
        if start == end:
            return
        if start + 1 == end:
            codes[syms[start]] += '0'
            codes[syms[end]] += '1'
            return

        total_prob = sum(probs[sym] for sym in syms[start:end+1])
        cumulative_prob = 0
        index = start

        for i in range(start, end+1):
            cumulative_prob += probs[syms[i]]
            if cumulative_prob >= total_prob / 2:
                index = i
                break

        for i in range(start, index+1):
            codes[syms[i]] += '0'

        for i in range(index+1, end+1):
            codes[syms[i]] += '1'

        build_code(syms, start, index)
        build_code(syms, index+1, end)

    syms = [sym for sym, _ in sorted_probs]
    build_code(syms, 0, len(syms)-1)

    return dict(codes)

# декодирование текста с использованием кодов Ўеннона-‘ано
def decode_text_shannon_fano(encoded_text, codes):
    reversed_codes = {code: sym for sym, code in codes.items()}
    decoded_text = ''
    code_buffer = ''
    for bit in encoded_text:
        code_buffer += bit
        if code_buffer in reversed_codes:
            decoded_text += reversed_codes[code_buffer]
            code_buffer = ''
    return decoded_text

# декодирование текста с использованием кодов ’аффмана
def decode_text_huffman(encoded_text, codes):
    reversed_codes = {code: sym for sym, code in codes.items()}
    decoded_text = ''
    code_buffer = ''
    for bit in encoded_text:
        code_buffer += bit
        if code_buffer in reversed_codes:
            decoded_text += reversed_codes[code_buffer]
            code_buffer = ''
    return decoded_text



# чтение веро€тностей символов из файла
probs = read_probs('probs.txt')

# построение кодов Ўеннона-‘ано
codes = sf_method(probs)

# кодировка текста с использованием построенных кодов
input_text = open("text.txt", encoding='utf-8').read()
encoded_text = encode_text(input_text, codes)

# сохранение закодированного текста и кодов в файл
with open('encoded_text.txt', 'w', encoding='utf-8') as file:
    file.write(encoded_text + '\n')

with open('codes_fano.txt', 'w', encoding='utf-8') as file:
    for sym, code in codes.items():
        file.write(sym + ": " + code + '\n')

# построениекодов’аффмана
codes_huffman = huffman_method(probs)

# кодировка текста с использованием построенных кодов
input_text = open("text.txt", encoding='utf-8').read()
encoded_text_huffman = encode_text(input_text, codes_huffman)

with open('encoded_text_huffman.txt', 'w', encoding='utf-8') as file:
    file.write(encoded_text_huffman + '\n')

with open('codes_huffman.txt', 'w', encoding='utf-8') as file:
    for sym, code in codes.items():
        file.write(sym + ": " + code + '\n')

# декодированиезакодированноготекстаЎеннона-‘ано
encoded_text_sf = open("encoded_text.txt", encoding='utf-8').readline().strip()
decoded_text_sf = decode_text_shannon_fano(encoded_text_sf, codes)

with open('decoded_text_sf.txt', 'w', encoding='utf-8') as file:
    file.write(decoded_text_sf + '\n')

# декодированиезакодированноготекста’аффмана
encoded_text_huffman = open("encoded_text_huffman.txt", encoding='utf-8').readline().strip()
decoded_text_huffman = decode_text_huffman(encoded_text_huffman, codes_huffman)

with open('decoded_text_huffman.txt', 'w', encoding='utf-8') as file:
    file.write(decoded_text_huffman + '\n')
