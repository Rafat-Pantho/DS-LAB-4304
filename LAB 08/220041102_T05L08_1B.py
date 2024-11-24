def morse_trnsformation(s):
    morse_map = {
        'a': '.-', 'b': '-...', 'c': '-.-.', 'd': '-..', 'e': '.', 'f': '..-.',
        'g': '--.', 'h': '....', 'i': '..', 'j': '.---', 'k': '-.-', 'l': '.-..',
        'm': '--', 'n': '-.', 'o': '---', 'p': '.--.', 'q': '--.-', 'r': '.-.',
        's': '...', 't': '-', 'u': '..-', 'v': '...-', 'w': '.--', 'x': '-..-',
        'y': '-.--', 'z': '--..'
    }
    
    t = {"".join(morse_map[c] for c in a)for a in s}
    return len(t),t

n=int(input())
s=[]
for i in range(n):s.append(input())
res = morse_trnsformation(s)
print(res[0])
print('\n'.join(res[1]))