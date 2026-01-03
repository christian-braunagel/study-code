Imports System

Module Program
    Sub Main(args As String())

        Dim columns as String = "ABCDEFGH"
        For row as Integer = 8 to 1 Step -1
            For column as Integer = 0 to 7
                Console.Write(columns(column) & row & " ")
            Next
            Console.WriteLine()
        Next

        ''''''''' Idiomatic Solution with For each ''''''''' 
        ' Dim columns as String = "ABCDEFGH"
        ' For row as Integer = 8 to 1 Step -1
        '     For Each column as char in columns
        '         Console.Write(column & row & " ")
        '     Next
        '     Console.WriteLine()
        ' Next
    End Sub
End Module