# Lab 4: Text Analyser

## Introduction
In this lab, you will develop a VB.NET console application that analyzes a given text. The goal is to practice the use of **Subs and Functions** as well as working with **Strings** and **Arrays**.

## Section I

### Task Description

The program shall analyze a text entered by the user.

The analysis must include the following aspects:

- Number of characters (excluding spaces)
- Number of words
- Number of vowels (`A, E, I, O, U` – case-insensitive)

The input text must first be split into individual words and stored in an array. All calculations must be performed using **Functions and Subs**, not directly inside `Main`.

Example output (depending on input):

Enter text:

> Programming is key

Analysis:

- Characters (without spaces): 16
- Words: 3
- Vowels: 5

### Requirements

Your program must:

- read a text from the console
- split the text into words using string methods
- store the words in an **array**
- use at least **two Functions** (e.g. for word or vowel analysis)
- use at least **one Sub** for structured output
- not hard-code any example texts or results

Suggested structure:

- `Function CountWords(words() As String) As Integer`
- `Function CountVowels(text As String) As Integer`
- `Sub PrintResults(...)`

