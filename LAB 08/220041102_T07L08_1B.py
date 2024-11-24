def find_repeated_dna_sequences(s: str) -> list[str]:
    repeated_sequences = []
    hash_counts = {}
    
    n = len(s)
    window_size = 10
    hash_value = 0
    base = 4
    power = 1
    char_to_int = {'A': 0, 'C': 1, 'G': 2, 'T': 3}

    for i in range(window_size):
        hash_value = hash_value * base + char_to_int[s[i]]
        power *= base

    hash_counts[hash_value] = 1

    for i in range(1, n - window_size + 1):
        hash_value = ( hash_value * base - char_to_int[s[i - 1]] * power + char_to_int[s[i + window_size - 1]] )
        hash_counts[hash_value] = hash_counts.get(hash_value, 0) + 1
        if hash_counts[hash_value] == 2:repeated_sequences.append(s[i : i + window_size])

    return repeated_sequences

        
s=input().strip()

result = find_repeated_dna_sequences(s)
print(', '.join(str(i) for i in result)if result else "No repeat sequence")