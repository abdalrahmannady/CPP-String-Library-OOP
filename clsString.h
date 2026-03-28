#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class clsString
{
private:
    std::string _Value;

public:

    // =========================
    // Constructors
    // =========================

    clsString()
    {
        _Value = "";
    }

    clsString(std::string Value)
    {
        _Value = Value;
    }

    // =========================
    // Properties
    // =========================

    void SetValue(std::string Value)
    {
        _Value = Value;
    }

    std::string GetValue()
    {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) std::string Value;

    // =========================
    // Static Functions (Core Logic)
    // =========================

    static std::string UpperString(std::string input)
    {
        for (int i = 0; i < input.length(); i++)
            input[i] = toupper(input[i]);

        return input;
    }

    static std::string LowerString(std::string input)
    {
        for (int i = 0; i < input.length(); i++)
            input[i] = tolower(input[i]);

        return input;
    }

    static std::string UpperFirstLetterOfEachWord(std::string text)
    {
        bool isFirst = true;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ' && isFirst)
                text[i] = toupper(text[i]);

            isFirst = (text[i] == ' ');
        }

        return text;
    }

    static bool IsVowel(char c)
    {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    static int CountVowels(std::string text)
    {
        int count = 0;

        for (int i = 0; i < text.length(); i++)
            if (IsVowel(text[i]))
                count++;

        return count;
    }

    static int CountCapitalLetters(std::string text)
    {
        int count = 0;

        for (int i = 0; i < text.length(); i++)
            if (isupper(text[i]))
                count++;

        return count;
    }

    static int CountSmallLetters(std::string text)
    {
        int count = 0;

        for (int i = 0; i < text.length(); i++)
            if (islower(text[i]))
                count++;

        return count;
    }

    static int CountLetter(std::string text, char letter)
    {
        int count = 0;

        for (int i = 0; i < text.length(); i++)
            if (text[i] == letter)
                count++;

        return count;
    }

    static std::vector<std::string> Split(std::string text, std::string delim = " ")
    {
        std::vector<std::string> words;
        int pos = 0;

        while ((pos = text.find(delim)) != std::string::npos)
        {
            std::string word = text.substr(0, pos);

            if (!word.empty())
                words.push_back(word);

            text.erase(0, pos + delim.length());
        }

        if (!text.empty())
            words.push_back(text);

        return words;
    }

    static std::string Join(const std::vector<std::string>& words, std::string delim = " ")
    {
        std::string result = "";

        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i != words.size() - 1)
                result += delim;
        }

        return result;
    }

    static std::string ReverseWords(std::string text)
    {
        std::vector<std::string> words = Split(text);
        std::string result = "";

        for (int i = words.size() - 1; i >= 0; i--)
        {
            result += words[i];
            if (i != 0)
                result += " ";
        }

        return result;
    }

    static std::string TrimLeft(std::string text)
    {
        int i = 0;

        while (i < text.length() && text[i] == ' ')
            i++;

        return text.substr(i);
    }

    static std::string TrimRight(std::string text)
    {
        if (text.empty()) return "";

        int i = text.length() - 1;

        while (i >= 0 && text[i] == ' ')
            i--;

        return text.substr(0, i + 1);
    }

    static std::string Trim(std::string text)
    {
        return TrimLeft(TrimRight(text));
    }

    static std::string Replace(std::string text, std::string oldWord, std::string newWord)
    {
        int pos = 0;

        while ((pos = text.find(oldWord, pos)) != std::string::npos)
        {
            text.replace(pos, oldWord.length(), newWord);
            pos += newWord.length();
        }

        return text;
    }

    static std::string RemovePunctuation(std::string text)
    {
        std::string result = "";

        for (int i = 0; i < text.length(); i++)
        {
            if (!ispunct(text[i]))
                result += text[i];
        }

        return result;
    }

    // =========================
    // Non-Static Wrappers
    // =========================

    std::string UpperString()
    {
        return UpperString(_Value);
    }

    std::string LowerString()
    {
        return LowerString(_Value);
    }

    std::string UpperFirstLetterOfEachWord()
    {
        return UpperFirstLetterOfEachWord(_Value);
    }

    int CountVowels()
    {
        return CountVowels(_Value);
    }

    int CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    int CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    int CountLetter(char letter)
    {
        return CountLetter(_Value, letter);
    }

    std::vector<std::string> Split(std::string delim = " ")
    {
        return Split(_Value, delim);
    }

    std::string Join(std::string delim = " ")
    {
        return Join(Split(_Value, delim), delim);
    }

    std::string ReverseWords()
    {
        return ReverseWords(_Value);
    }

    std::string TrimLeft()
    {
        return TrimLeft(_Value);
    }

    std::string TrimRight()
    {
        return TrimRight(_Value);
    }

    std::string Trim()
    {
        return Trim(_Value);
    }

    std::string Replace(std::string oldWord, std::string newWord)
    {
        return Replace(_Value, oldWord, newWord);
    }

    std::string RemovePunctuation()
    {
        return RemovePunctuation(_Value);
    }
};