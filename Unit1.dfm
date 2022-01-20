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
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
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
      object N1: TMenuItem
        Caption = 'New game'
        OnClick = FormCreate
      end
      object Downloadprogress2: TMenuItem
        Caption = 'Leaderbords'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Settings1: TMenuItem
      Caption = 'Settings'
      object LandSize1: TMenuItem
        Caption = 'LandSize'
        object N150x1501: TMenuItem
          Caption = '150 x 150'
          RadioItem = True
          OnClick = N150x1501Click
        end
        object N200x2001: TMenuItem
          Caption = '200 x 200'
          RadioItem = True
          OnClick = N200x2001Click
        end
        object N300x3001: TMenuItem
          Caption = '300 x 300'
          RadioItem = True
          OnClick = N300x3001Click
        end
      end
      object PoVskin1: TMenuItem
        Caption = 'PoV skin'
        object Rogue1: TMenuItem
          Caption = 'Elf'
          OnClick = Rogue1Click
        end
        object Rogue2: TMenuItem
          Caption = 'Mario'
          OnClick = Rogue2Click
        end
        object Knight1: TMenuItem
          Caption = 'Knight'
          OnClick = Knight1Click
        end
        object Wizard1: TMenuItem
          Caption = 'Wizard'
          OnClick = Wizard1Click
        end
      end
      object Sound: TMenuItem
        Caption = 'Turn off sound'
        OnClick = SoundClick
      end
    end
  end
  object Timer1: TTimer
    Interval = 15
    OnTimer = Timer1Timer
    Left = 288
    Top = 312
  end
end
