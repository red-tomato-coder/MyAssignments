object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnMouseDown = Image1MouseDown
  OnMouseUp = Image1MouseUp
  TextHeight = 15
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 608
    Height = 425
    OnClick = FormPaint
    OnMouseDown = Image1MouseDown
    OnMouseUp = Image1MouseUp
  end
end
