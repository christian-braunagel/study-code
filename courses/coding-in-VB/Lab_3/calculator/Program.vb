Imports System

Module Program
    Sub Main(args As String())

        Dim operant1 As Double
        Dim operant2 As Double
        Dim operation As Char
        Dim result As Double

        Console.WriteLine("Starting Calculator")
        Console.WriteLine("This calculator can perform the operations '+', '-', '*', '/' with two digits.")
        
        Console.WriteLine("Please enter your first number: ")
        operant1 = Console.ReadLine()

        Console.WriteLine("Please enter your second number: ")
        operant2 = Console.ReadLine()

        Console.WriteLine("Please enter the operation ('+', '-', '*', '/') you want to perform: ")
        operation = Console.ReadLine()(0)

        If operation = "+"c Then
            result = operant1 + operant2
        
        ElseIf operation = "-"c Then
            result = operant1 - operant2
        
        Elseif operation = "*"c Then
            result = operant1 * operant2

        ElseIf operation = "/"c Then
            If operant2 = 0 Then
                Console.WriteLine("Division by zero. Program stopped.")
                return
            Else
                result = operant1 / operant2
            End If
        Else
            Console.WriteLine($"You provided an unknown operation: {operation}")
            return
        End If

        Console.WriteLine($"The result of {operant1:F2} {operation} {operant2:F2} = {result:F2}")

    End Sub
End Module
