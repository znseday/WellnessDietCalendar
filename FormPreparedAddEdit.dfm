object frmPreparedsAddEdit: TfrmPreparedsAddEdit
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100'/'#1080#1079#1084#1077#1085#1080#1090#1100' '#1075#1086#1090#1086#1074#1086#1077' '#1073#1083#1102#1076#1086
  ClientHeight = 491
  ClientWidth = 888
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 192
    Top = 32
    Width = 56
    Height = 16
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
  end
  object Label2: TLabel
    Left = 210
    Top = 64
    Width = 35
    Height = 16
    Caption = #1041#1077#1083#1082#1080
  end
  object Label3: TLabel
    Left = 338
    Top = 64
    Width = 35
    Height = 16
    Caption = #1046#1080#1088#1099
  end
  object Label4: TLabel
    Left = 466
    Top = 64
    Width = 56
    Height = 16
    Caption = #1059#1075#1083#1077#1074#1086#1076#1099
  end
  object Label5: TLabel
    Left = 606
    Top = 64
    Width = 49
    Height = 16
    Caption = #1050#1072#1083#1086#1088#1080#1080
  end
  object Label6: TLabel
    Left = 763
    Top = 32
    Width = 36
    Height = 16
    Caption = #1052#1072#1089#1089#1072
  end
  object Label7: TLabel
    Left = 741
    Top = 64
    Width = 62
    Height = 16
    Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
  end
  object Label8: TLabel
    Left = 16
    Top = 102
    Width = 168
    Height = 13
    Caption = #1042#1089#1077' '#1074#1077#1083#1077#1095#1080#1085#1099' '#1074' '#1090#1072#1073#1083#1080#1094#1077' '#1085#1072' 100 '#1075
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbBases: TListBox
    Left = 19
    Top = 432
    Width = 334
    Height = 57
    TabOrder = 15
    Visible = False
    OnDblClick = lbBasesDblClick
    OnKeyDown = lbBasesKeyDown
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 161
    Height = 81
    Caption = #1058#1080#1087
    TabOrder = 0
    object rbFinished: TRadioButton
      Left = 16
      Top = 24
      Width = 113
      Height = 17
      Caption = #1043#1086#1090#1086#1074#1086#1077' '#1073#1083#1102#1076#1086
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = rbFinishedClick
    end
    object rbBuild: TRadioButton
      Left = 16
      Top = 47
      Width = 113
      Height = 17
      Caption = #1057#1086#1073#1088#1072#1090#1100
      TabOrder = 1
      OnClick = rbBuildClick
    end
  end
  object gridList: TStringGrid
    Left = 16
    Top = 120
    Width = 853
    Height = 265
    ColCount = 7
    DefaultColWidth = 100
    DrawingStyle = gdsGradient
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
    TabOrder = 1
  end
  object btnAddFromBases: TButton
    Left = 19
    Top = 447
    Width = 334
    Height = 33
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1079' '#1073#1072#1079#1086#1074#1099#1093
    TabOrder = 2
    OnClick = btnAddFromBasesClick
  end
  object btnCancel: TButton
    Left = 740
    Top = 399
    Width = 129
    Height = 33
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = btnCancelClick
  end
  object btnDone: TButton
    Left = 740
    Top = 447
    Width = 129
    Height = 33
    Caption = #1043#1086#1090#1086#1074#1086
    TabOrder = 4
    OnClick = btnDoneClick
  end
  object EditName: TEdit
    Left = 256
    Top = 29
    Width = 465
    Height = 24
    MaxLength = 256
    TabOrder = 5
  end
  object EditB: TEdit
    Left = 256
    Top = 61
    Width = 60
    Height = 24
    MaxLength = 10
    TabOrder = 6
  end
  object EditJ: TEdit
    Left = 384
    Top = 61
    Width = 60
    Height = 24
    MaxLength = 10
    TabOrder = 7
  end
  object EditU: TEdit
    Left = 528
    Top = 61
    Width = 60
    Height = 24
    MaxLength = 10
    TabOrder = 8
  end
  object EditK: TEdit
    Left = 661
    Top = 61
    Width = 60
    Height = 24
    MaxLength = 10
    TabOrder = 9
  end
  object EditM: TEdit
    Left = 809
    Top = 29
    Width = 60
    Height = 24
    MaxLength = 10
    TabOrder = 10
  end
  object EditCost: TEdit
    Left = 809
    Top = 59
    Width = 60
    Height = 24
    MaxLength = 10
    TabOrder = 11
  end
  object btnReCalc: TButton
    Left = 369
    Top = 399
    Width = 263
    Height = 33
    Caption = #1055#1077#1088#1077#1089#1095#1080#1090#1072#1090#1100' '#1041#1046#1059
    TabOrder = 12
    OnClick = btnReCalcClick
  end
  object btnEditM: TButton
    Left = 369
    Top = 447
    Width = 263
    Height = 33
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1084#1072#1089#1089#1091' '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1087#1088#1086#1076#1091#1082#1090#1072
    TabOrder = 13
    OnClick = btnEditMClick
  end
  object EditSearchBases: TEdit
    Left = 19
    Top = 408
    Width = 334
    Height = 24
    TabOrder = 14
    OnChange = EditSearchBasesChange
    OnKeyDown = EditSearchBasesKeyDown
    OnKeyPress = EditSearchBasesKeyPress
  end
end
