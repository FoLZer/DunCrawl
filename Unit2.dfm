object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Buttle frame'
  ClientHeight = 246
  ClientWidth = 376
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 80
    Height = 64
    OnMouseDown = Image1MouseDown
  end
  object Label1: TLabel
    Left = 232
    Top = 24
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 152
    Top = 112
    Width = 3
    Height = 13
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 256
    Top = 72
  end
end
