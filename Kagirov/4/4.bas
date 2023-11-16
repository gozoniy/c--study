Private Sub CommandButton_Click()
For i = 1 To 8
    Cells(i, 1).RowHeight = 30
    Cells(1, i).ColumnWidth = 5


Next i

For i = 1 To 8
    For j = 1 To 8
        Cells(i, j) = ""
        Cells(i, j).Font.ColorIndex = 3
        If (i + j) Mod 2 = 1 Then
            Cells(i, j).Interior.ColorIndex = 40
        Else
            Cells(i, j).Interior.ColorIndex = 53
        End If
        
    Next j
Next i

Shah = False
Mat = True

kr_x = Cells(1, 11)
kr_y = Cells(1, 12)
Cells(kr_x, kr_y) = "??"

l_x = Cells(2, 11)
l_y = Cells(2, 12)
Cells(l_x, l_y) = "?"

s_x = Cells(3, 11)
s_y = Cells(3, 12)
Cells(s_x, s_y) = "?"

k_x = Cells(4, 11)
k_y = Cells(4, 12)
Cells(k_x, k_y) = "?"

f_x = Cells(5, 11)
f_y = Cells(5, 12)
Cells(f_x, f_y) = "?"



For i = kr_x - 1 To kr_x + 1
    For j = kr_y - 1 To kr_y + 1
        If (i < 9 And j < 9) Then
            flag = False
            If ((i = l_x) Or (j = l_y)) Then
                If (Cells(i, j) = "") Then
                    Cells(i, j).Font.ColorIndex = 22
                    Cells(i, j) = ChrW(&H25CF)
                End If
                flag = True
            End If
            
            If (Abs(i - s_x) = Abs(j - s_y)) Then
                If (Cells(i, j) = "") Then
                    Cells(i, j).Font.ColorIndex = 22
                    Cells(i, j) = ChrW(&H25CF)
                End If
                flag = True
            End If
            
            If (Abs(i - k_x) = 2 Or Abs(j - k_y) = 2) Then
                If (Abs(i - k_x) = 1 Or Abs(j - k_y) = 1) Then
                    If (Cells(i, j) = "") Then
                        Cells(i, j).Font.ColorIndex = 22
                        Cells(i, j) = ChrW(&H25CF)
                    End If
                    flag = True
                End If
            End If
            
            If (((i = f_x) Or (j = f_y)) Or (Abs(i - f_x) = Abs(j - f_y))) Then
                If (Cells(i, j) = "") Then
                    Cells(i, j).Font.ColorIndex = 22
                    Cells(i, j) = ChrW(&H25CF)
                End If
                flag = True
            End If
            
            If (flag = False) Then
                Mat = False
            End If
        End If
        
    Next j
Next i
  
If ((kr_x = l_x) Or (kr_y = l_y)) Then
    Shah = True
End If

If (Abs(kr_x - s_x) = Abs(kr_y - s_y)) Then
    Shah = True
End If

If (Abs(kr_x - k_x) = 2 Or Abs(kr_y - k_y) = 2) Then
    If (Abs(kr_x - k_x) = 1 Or Abs(kr_y - k_y) = 1) Then
        Shah = True
    End If
End If

If (((kr_x = f_x) Or (kr_y = f_y)) Or (Abs(kr_x - f_x) = Abs(kr_y - f_y))) Then
    Shah = True
End If


If (Shah = True) Then
    If (Mat = True) Then
        Response = MsgBox("??? ? ???", 0, "????????? ????")
    Else
        Response = MsgBox("???", 0, "????????? ????")
    End If
End If

End Sub
