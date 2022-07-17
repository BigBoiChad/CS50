from cs50 import get_string


def main():
    text = get_string("TEXT: ")
    coleman_liau(text)


def coleman_liau(text):
    letters = 0
    words = 0
    sentences = 0

    for l in text:
        # ord() can show the ASCII number of a character (string in the context of python)
        if ord(l[0].lower()) >= 96 and ord(l[0].lower()) <= 123:
            letters += 1

    for w in text:
        # here we just use the in list function [" "]
        if w in [" "]:
            words += 1
    words += 1

    for s in text:
        if s in [".", "!", "?"]:
            sentences += 1

    # 0.0588 * L - 0.296 * S - 15.8;
    index = 0.0588 * (letters/words) * 100 - 0.296 * (sentences/words) * 100 - 15.8

    if index < 1:
        print("Before Grade 1")
    else:
        # we round it up
        # we convert the index into a integer
        index = int(round(index))
        if index >= 16:
            print("Grade 16+")
        else:
            print(f"Grade {index}")


main()