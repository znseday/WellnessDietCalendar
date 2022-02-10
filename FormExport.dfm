object frmExport: TfrmExport
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1069#1082#1089#1087#1086#1088#1090
  ClientHeight = 59
  ClientWidth = 372
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 7
    Height = 13
    Caption = #1057
  end
  object Label2: TLabel
    Left = 146
    Top = 24
    Width = 13
    Height = 13
    Caption = #1055#1086
  end
  object btnExport: TButton
    Left = 280
    Top = 19
    Width = 75
    Height = 25
    Caption = #1069#1082#1089#1087#1086#1088#1090'...'
    TabOrder = 0
    OnClick = btnExportClick
  end
  object dtpFrom: TDateTimePicker
    Left = 29
    Top = 21
    Width = 97
    Height = 21
    Date = 44594.000000000000000000
    Time = 0.154225092592241700
    TabOrder = 1
  end
  object dtpTo: TDateTimePicker
    Left = 167
    Top = 20
    Width = 97
    Height = 21
    Date = 44594.000000000000000000
    Time = 0.154225092592241700
    TabOrder = 2
  end
  object dlgSave: TSaveDialog
    DefaultExt = 'txt'
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1081' '#1086#1090#1095#1077#1090' (*.txt)|*.txt'
    FilterIndex = 0
    Options = [ofReadOnly, ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 120
    Top = 16
  end
end
