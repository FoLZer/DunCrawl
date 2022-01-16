object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Buttle frame'
  ClientHeight = 192
  ClientWidth = 320
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
    Width = 320
    Height = 192
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 256
    Top = 72
  end
end
