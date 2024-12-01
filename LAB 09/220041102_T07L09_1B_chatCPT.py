def is_abbreviation_in_list(word_list, abbreviation):
    for word in word_list:
        index = 0  # Index to track position in the abbreviation
        for char in word:
            if index < len(abbreviation) and char == abbreviation[index]:
                index += 1
        # If all characters of abbreviation are found in sequence
        if index == len(abbreviation):
            return "YES"
    return "NO"

# Example usage
words = [str(i) for i in input().split() if i!="-1"]
abbr = input()
print(is_abbreviation_in_list(words, abbr))