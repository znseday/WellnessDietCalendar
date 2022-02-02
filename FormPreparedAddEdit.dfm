object frmPreparedsAddEdit: TfrmPreparedsAddEdit
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100'/'#1080#1079#1084#1077#1085#1080#1090#1100' '#1075#1086#1090#1086#1074#1086#1077' '#1073#1083#1102#1076#1086
  ClientHeight = 624
  ClientWidth = 882
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
  object pnlBottom: TPanel
    Left = 0
    Top = 525
    Width = 882
    Height = 99
    Align = alBottom
    TabOrder = 0
    ExplicitTop = 510
    object lbBases: TListBox
      Left = 17
      Top = 11
      Width = 334
      Height = 86
      TabOrder = 0
      Visible = False
      OnDblClick = lbBasesDblClick
      OnKeyDown = lbBasesKeyDown
    end
    object btnAddFromBases: TButton
      Left = 17
      Top = 53
      Width = 334
      Height = 33
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1079' '#1073#1072#1079#1086#1074#1099#1093
      TabOrder = 1
      OnClick = btnAddFromBasesClick
    end
    object btnCancel: TButton
      Left = 716
      Top = 13
      Width = 129
      Height = 33
      Cancel = True
      Caption = #1054#1090#1084#1077#1085#1072
      TabOrder = 2
      OnClick = btnCancelClick
    end
    object btnDone: TButton
      Left = 716
      Top = 52
      Width = 129
      Height = 33
      Caption = #1043#1086#1090#1086#1074#1086
      TabOrder = 3
      OnClick = btnDoneClick
    end
    object btnReCalc: TButton
      Left = 369
      Top = 13
      Width = 263
      Height = 33
      Caption = #1055#1077#1088#1077#1089#1095#1080#1090#1072#1090#1100' '#1041#1046#1059
      TabOrder = 4
      OnClick = btnReCalcClick
    end
    object btnEditM: TButton
      Left = 369
      Top = 52
      Width = 263
      Height = 33
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1084#1072#1089#1089#1091' '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1087#1088#1086#1076#1091#1082#1090#1072
      TabOrder = 5
      OnClick = btnEditMClick
    end
    object EditSearchBases: TEdit
      Left = 17
      Top = 17
      Width = 334
      Height = 24
      TabOrder = 6
      OnChange = EditSearchBasesChange
      OnKeyDown = EditSearchBasesKeyDown
      OnKeyPress = EditSearchBasesKeyPress
    end
  end
  object pnlTop: TPanel
    Left = 0
    Top = 0
    Width = 882
    Height = 97
    Align = alTop
    TabOrder = 1
    object Label1: TLabel
      Left = 193
      Top = 18
      Width = 56
      Height = 16
      Caption = #1053#1072#1079#1074#1072#1085#1080#1077
    end
    object Label2: TLabel
      Left = 214
      Top = 55
      Width = 35
      Height = 16
      Caption = #1041#1077#1083#1082#1080
    end
    object Label3: TLabel
      Left = 334
      Top = 55
      Width = 35
      Height = 16
      Caption = #1046#1080#1088#1099
    end
    object Label4: TLabel
      Left = 457
      Top = 55
      Width = 56
      Height = 16
      Caption = #1059#1075#1083#1077#1074#1086#1076#1099
    end
    object Label5: TLabel
      Left = 597
      Top = 55
      Width = 49
      Height = 16
      Caption = #1050#1072#1083#1086#1088#1080#1080
    end
    object Label6: TLabel
      Left = 758
      Top = 18
      Width = 36
      Height = 16
      Caption = #1052#1072#1089#1089#1072
    end
    object Label7: TLabel
      Left = 732
      Top = 55
      Width = 62
      Height = 16
      Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
    end
    object GroupBox1: TGroupBox
      Left = 14
      Top = 9
      Width = 161
      Height = 77
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
    object EditName: TEdit
      Left = 255
      Top = 15
      Width = 457
      Height = 24
      MaxLength = 256
      TabOrder = 1
    end
    object EditB: TEdit
      Left = 255
      Top = 52
      Width = 60
      Height = 24
      MaxLength = 10
      TabOrder = 2
    end
    object EditJ: TEdit
      Left = 375
      Top = 52
      Width = 60
      Height = 24
      MaxLength = 10
      TabOrder = 3
    end
    object EditU: TEdit
      Left = 519
      Top = 52
      Width = 60
      Height = 24
      MaxLength = 10
      TabOrder = 4
    end
    object EditK: TEdit
      Left = 652
      Top = 52
      Width = 60
      Height = 24
      MaxLength = 10
      TabOrder = 5
    end
    object EditM: TEdit
      Left = 800
      Top = 15
      Width = 60
      Height = 24
      MaxLength = 10
      TabOrder = 6
    end
    object EditCost: TEdit
      Left = 800
      Top = 52
      Width = 60
      Height = 24
      MaxLength = 10
      TabOrder = 7
    end
  end
  object pnlCentral: TPanel
    Left = 0
    Top = 97
    Width = 882
    Height = 428
    Align = alClient
    TabOrder = 2
    ExplicitLeft = 304
    ExplicitTop = 152
    ExplicitWidth = 553
    ExplicitHeight = 361
    object gridList: TStringGrid
      Left = 1
      Top = 26
      Width = 880
      Height = 401
      Align = alClient
      ColCount = 7
      DefaultColWidth = 100
      DrawingStyle = gdsGradient
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
      TabOrder = 0
      ExplicitLeft = 52
      ExplicitTop = 104
      ExplicitWidth = 674
      ExplicitHeight = 232
    end
    object pnlCentralTop: TPanel
      Left = 1
      Top = 1
      Width = 880
      Height = 25
      Align = alTop
      TabOrder = 1
      ExplicitLeft = 248
      ExplicitTop = 24
      ExplicitWidth = 441
      object Label8: TLabel
        Left = 13
        Top = 6
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
    end
  end
end
