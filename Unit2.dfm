object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Buttle frame'
  ClientHeight = 200
  ClientWidth = 250
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 250
    Height = 200
    OnMouseDown = Image1MouseDown
  end
  object Timer2: TTimer
    Enabled = False
    Left = 208
    Top = 88
  end
end
