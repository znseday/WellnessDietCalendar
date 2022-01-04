object frmBasesAddEdit: TfrmBasesAddEdit
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100'/'#1048#1079#1084#1077#1085#1080#1090#1100
  ClientHeight = 340
  ClientWidth = 421
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 18
    Top = 40
    Width = 56
    Height = 16
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
  end
  object Label2: TLabel
    Left = 18
    Top = 80
    Width = 35
    Height = 16
    Caption = #1041#1077#1083#1082#1080
  end
  object Label3: TLabel
    Left = 18
    Top = 120
    Width = 35
    Height = 16
    Caption = #1046#1080#1088#1099
  end
  object Label4: TLabel
    Left = 18
    Top = 160
    Width = 56
    Height = 16
    Caption = #1059#1075#1083#1077#1074#1086#1076#1099
  end
  object Label5: TLabel
    Left = 18
    Top = 200
    Width = 27
    Height = 16
    Caption = #1050#1082#1072#1083
  end
  object Label6: TLabel
    Left = 18
    Top = 245
    Width = 62
    Height = 16
    Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
  end
  object EditName: TEdit
    Left = 88
    Top = 37
    Width = 313
    Height = 24
    MaxLength = 256
    TabOrder = 0
  end
  object EditB: TEdit
    Left = 88
    Top = 77
    Width = 121
    Height = 24
    MaxLength = 10
    TabOrder = 1
  end
  object EditJ: TEdit
    Left = 88
    Top = 117
    Width = 121
    Height = 24
    MaxLength = 10
    TabOrder = 2
  end
  object EditU: TEdit
    Left = 88
    Top = 157
    Width = 121
    Height = 24
    MaxLength = 10
    TabOrder = 3
  end
  object EditK: TEdit
    Left = 88
    Top = 197
    Width = 121
    Height = 24
    MaxLength = 10
    TabOrder = 4
  end
  object btnCancel: TButton
    Left = 176
    Top = 294
    Width = 105
    Height = 33
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 5
    OnClick = btnCancelClick
  end
  object btnOk: TButton
    Left = 296
    Top = 294
    Width = 105
    Height = 33
    Caption = #1054#1082
    Default = True
    TabOrder = 6
    OnClick = btnOkClick
  end
  object EditCost: TEdit
    Left = 88
    Top = 242
    Width = 121
    Height = 24
    MaxLength = 10
    TabOrder = 7
  end
end
