object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 305
  ClientWidth = 520
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object RandomLabel1: TRandomLabel
    Left = 24
    Top = 72
    Width = 79
    Height = 15
    Caption = 'RandomLabel1'
    Max = 4
  end
  object Button1: TButton
    Left = 24
    Top = 104
    Width = 79
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
end
