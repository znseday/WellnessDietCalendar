object frmSettings: TfrmSettings
  Left = 0
  Top = 0
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 161
  ClientWidth = 406
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
    Left = 32
    Top = 39
    Width = 197
    Height = 13
    Caption = #1042' '#1082#1072#1082#1086#1077' '#1074#1088#1077#1084#1103' '#1085#1072#1095#1080#1085#1072#1077#1090#1089#1103' '#1085#1086#1074#1099#1081' '#1076#1077#1085#1100
  end
  object dtpStartDayTime: TDateTimePicker
    Left = 235
    Top = 36
    Width = 81
    Height = 21
    Date = 44585.000000000000000000
    Format = 'HH:mm'
    Time = 0.107822002311877400
    Kind = dtkTime
    TabOrder = 0
  end
  object btnCancel: TButton
    Left = 192
    Top = 128
    Width = 91
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object btnOk: TButton
    Left = 304
    Top = 128
    Width = 94
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 2
    OnClick = btnOkClick
  end
end
