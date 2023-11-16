Sub ??????1_??????()
For i = 1 To 8
    Cells(i, 1).RowHeight = 60
    Cells(1, i).ColumnWidth = 10
    

Next i

Range("A1:H8").HorizontalAlignment = xlCenter
Range("A1:H8").VerticalAlignment = xlCenter
Range("A1:H8").Font.Size = 18
For i = 1 To 8
    For j = 1 To 8
        Cells(i, j) = ""
        Cells(i, j).Font.ColorIndex = 1
        If (i + j) Mod 2 = 1 Then
            Cells(i, j).Interior.ColorIndex = 43
        Else
            Cells(i, j).Interior.ColorIndex = 19
        End If
        
    Next j
Next i

Cells(1, 18) = "??????"
Cells(2, 18) = "?????"
Cells(3, 18) = "????"
Cells(4, 18) = "????"
Cells(5, 18) = "?????"
kr_x = Cells(1, 19)
kr_y = Cells(1, 20)
Cells(kr_x, kr_y) = "?"
Cells(kr_x, kr_y).Font.ColorIndex = 48


l_x = Cells(2, 19)
l_y = Cells(2, 20)
Cells(l_x, l_y) = "?"
Range(Cells(1, l_y), Cells(8, l_y)).Interior.ColorIndex = 22
Range(Cells(l_x, 1), Cells(l_x, 8)).Interior.ColorIndex = 22



s_x = Cells(3, 19)
s_y = Cells(3, 20)
Cells(s_x, s_y) = "?"
For i = l To 8
    For j = l To 8
        x = i + (s_x - 4)
        y = j + (s_y - 4)
        x1 = x
        y1 = 8 - y + 6
        If (i = j) Then
            If (x <= 8 And x > 0) And (y <= 8 And y > 0) And (x1 <= 8 And x1 > 0) And (y1 <= 8 And y1 > 0) Then
                Cells(x, y).Interior.ColorIndex = 2
                Cells(x1, y1).Interior.ColorIndex = 2
            End If
        End If
    Next j
Next i



k_x = Cells(4, 19)
k_y = Cells(4, 20)
Cells(k_x, k_y) = "?"


f_x = Cells(5, 19)
f_y = Cells(5, 20)
Cells(f_x, f_y) = "?"


'??????
'For i = l To 8
 '   For j = l To 8
  '      If (Cells(i, j) = "?") Then
   '         Cells(20, 20) = "???"
    '    End If
    'Next j
'Next i

        


End Sub

