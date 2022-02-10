object frmSettings: TfrmSettings
  Left = 0
  Top = 0
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 287
  ClientWidth = 376
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
    Top = 15
    Width = 197
    Height = 13
    Caption = #1042' '#1082#1072#1082#1086#1077' '#1074#1088#1077#1084#1103' '#1085#1072#1095#1080#1085#1072#1077#1090#1089#1103' '#1085#1086#1074#1099#1081' '#1076#1077#1085#1100
  end
  object Label2: TLabel
    Left = 16
    Top = 50
    Width = 99
    Height = 13
    Caption = #1052#1072#1089#1089#1072' '#1095#1077#1083#1086#1074#1077#1082#1072', '#1082#1075
  end
  object Label3: TLabel
    Left = 16
    Top = 77
    Width = 97
    Height = 13
    Caption = #1053#1086#1088#1084#1072' '#1073#1077#1083#1082#1086#1074', '#1075'/'#1082#1075
  end
  object Label4: TLabel
    Left = 16
    Top = 104
    Width = 93
    Height = 13
    Caption = #1053#1086#1088#1084#1072' '#1078#1080#1088#1086#1074', '#1075'/'#1082#1075
  end
  object Label5: TLabel
    Left = 16
    Top = 131
    Width = 115
    Height = 13
    Caption = #1053#1086#1088#1084#1072' '#1091#1075#1083#1077#1074#1086#1076#1086#1074', '#1075'/'#1082#1075
  end
  object Label6: TLabel
    Left = 16
    Top = 174
    Width = 155
    Height = 13
    Caption = #1062#1077#1083#1077#1074#1072#1103' '#1082#1072#1083#1083#1086#1088#1080#1081#1085#1086#1089#1090#1100', '#1082#1082#1072#1083
  end
  object dtpStartDayTime: TDateTimePicker
    Left = 219
    Top = 12
    Width = 81
    Height = 21
    Date = 44585.000000000000000000
    Format = 'HH:mm'
    Time = 0.107822002311877400
    Kind = dtkTime
    TabOrder = 0
  end
  object btnCancel: TButton
    Left = 160
    Top = 255
    Width = 91
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnOk: TButton
    Left = 272
    Top = 255
    Width = 94
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 2
    OnClick = btnOkClick
  end
  object EditM: TEdit
    Left = 136
    Top = 47
    Width = 77
    Height = 21
    TabOrder = 3
    Text = '80'
  end
  object EditK: TEdit
    Left = 191
    Top = 171
    Width = 77
    Height = 21
    TabOrder = 4
    Text = '0'
  end
  object EditB: TEdit
    Left = 136
    Top = 74
    Width = 77
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object EditJ: TEdit
    Left = 136
    Top = 101
    Width = 77
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object EditU: TEdit
    Left = 136
    Top = 128
    Width = 77
    Height = 21
    TabOrder = 7
    Text = '0'
  end
end
