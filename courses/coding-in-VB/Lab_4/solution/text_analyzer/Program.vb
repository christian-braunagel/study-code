Imports System

Module Program
    Sub Main(args As String())
        Dim sentence As String
        Dim words() As String

        Console.WriteLine("Hello from Text-Analyzer")
        Console.WriteLine("Please enter your sentence: ")
        sentence = Console.ReadLine()

        words = sentence.Split(" ")


        PrintResults(sentence, words)

    End Sub

    ''' ----------------------------------------------------------
    ''' <summary>
    ''' Count words in the arrays of strings
    ''' </summary>
    ''' <param name="words"> Array of strings </param>
    ''' <returns> number of strings/words as integer </returns>
    Function CountWords(words() As String) As Integer

        Return words.Length
    End Function

    ''' ----------------------------------------------------------
    ''' <summary>
    ''' Counts vowels within the string
    ''' </summary>
    ''' <param name="text"> string with text to analyse </param>
    ''' <returns> number of vowels as integer </returns>
    Function CountVowels(text As String) As Integer
        Dim vowels As Integer = 0
        text = text.ToLower()   ' enable case-insensitivity
        For i As Integer = 0 To text.Length - 1
            If text(i) = "a"c Or text(i) = "e"c Or text(i) = "i"c Or text(i) = "o"c Or text(i) = "u"c Then
                vowels += 1
            End If
        Next
        Return vowels
    End Function
    ''' ----------------------------------------------------------
    ''' <summary>
    ''' Counts sum of characters of all words in the array
    ''' </summary>
    ''' <param name="words"> Array of strings </param>
    ''' <returns> number of characters as integer </returns>
    Function CountChars(words() As String) As Integer
        Dim numCharacters As Integer = 0
        For i As Integer = 0 To words.Length - 1
            numCharacters += words(i).Length
        Next
        Return numCharacters
    End Function

    ''' ----------------------------------------------------------
    ''' <summary>
    ''' Prints the output for the user
    ''' </summary>
    ''' <param name="sentence"> string to analyze </param>
    ''' <param name="words"> Array of strings </param>
    Sub PrintResults(sentence As String, words() As String)

        Console.WriteLine($"Characters (without spaces): {CountChars(words)}")
        Console.WriteLine($"Words: {CountWords(words)}")
        Console.WriteLine($"Vowels: {CountVowels(sentence)}")
    End Sub

End Module
