object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'DunCrawl'
  ClientHeight = 600
  ClientWidth = 600
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Screen: TImage
    Left = 0
    Top = 0
    Width = 600
    Height = 600
  end
  object MainMenu1: TMainMenu
    Left = 568
    Top = 568
    object File1: TMenuItem
      Caption = 'File'
    end
  end
end
