Attribute VB_Name = "NewMacros"
Sub tv_programm()
    Dim Rang As Range
    Dim Template As String
    Dim Expression As Object
    Dim matches As Object
    Dim match As Object
    Dim timeValue As String
    pr = InputBox("������� ������� ���� ���������� UTC +_")
    curr = InputBox("������� ��� ������� ���� UTC +_")
    offs = curr - pr
    Dim timeOffset As Double
    timeOffset = offs / 24
    Template = "([0-9]{2}:[0-9]{2})"
    Set Rang = ActiveDocument.Content
    Set Expression = CreateObject("VBScript.RegExp")
    With Expression
        .Global = True
        .Pattern = Template
        Set matches = .Execute(Rang.Text) '������� ���������� �� ���������
        For Each match In matches
            timeValue = match.Value
            Rang.Text = Replace(Rang.Text, timeValue, Format(CDate(timeValue) + timeOffset, "HH:MM") & vbTab) '������ ������� � ���������
        Next match
    End With
End Sub
