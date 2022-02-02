object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'Wellness'
  ClientHeight = 630
  ClientWidth = 1332
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object StatusBar1: TStatusBar
    Left = 0
    Top = 611
    Width = 1332
    Height = 19
    Panels = <>
  end
  object pcMain: TPageControl
    Left = 0
    Top = 0
    Width = 1332
    Height = 611
    ActivePage = tsCalendar
    Align = alClient
    TabOrder = 1
    object tsBases: TTabSheet
      Caption = #1041#1072#1079#1086#1074#1099#1077' '#1087#1088#1086#1076#1091#1082#1090#1099
      object Splitter1: TSplitter
        Left = 1091
        Top = 41
        Height = 539
        Align = alRight
        ExplicitLeft = 625
        ExplicitTop = 0
        ExplicitHeight = 499
      end
      object gridBases: TStringGrid
        Left = 0
        Top = 41
        Width = 1091
        Height = 539
        Align = alClient
        ColCount = 6
        DefaultColWidth = 80
        DrawingStyle = gdsGradient
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
        TabOrder = 0
      end
      object pnlBases: TPanel
        Left = 1094
        Top = 41
        Width = 230
        Height = 539
        Align = alRight
        TabOrder = 1
        object btnBasesAdd: TButton
          Left = 16
          Top = 16
          Width = 193
          Height = 41
          Action = ActionBasesAdd
          TabOrder = 0
        end
        object btnBasesEdit: TButton
          Left = 16
          Top = 72
          Width = 193
          Height = 41
          Action = ActionBasesEdit
          TabOrder = 1
        end
        object btnBasesDel: TButton
          Left = 16
          Top = 128
          Width = 193
          Height = 41
          Action = ActionBasesDel
          TabOrder = 2
        end
        object GroupBox1: TGroupBox
          Left = 24
          Top = 288
          Width = 177
          Height = 177
          Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
          TabOrder = 3
          object rbBasesSortName: TRadioButton
            Left = 24
            Top = 27
            Width = 113
            Height = 17
            Caption = #1053#1072#1079#1074#1072#1085#1080#1077
            Checked = True
            TabOrder = 0
            TabStop = True
            OnClick = PrintBases
          end
          object rbBasesSortB: TRadioButton
            Left = 24
            Top = 50
            Width = 113
            Height = 17
            Caption = #1041#1077#1083#1082#1080
            TabOrder = 1
            OnClick = PrintBases
          end
          object rbBasesSortJ: TRadioButton
            Left = 24
            Top = 73
            Width = 113
            Height = 17
            Caption = #1046#1080#1088#1099
            TabOrder = 2
            OnClick = PrintBases
          end
          object rbBasesSortU: TRadioButton
            Left = 24
            Top = 96
            Width = 113
            Height = 17
            Caption = #1059#1075#1083#1077#1074#1086#1076#1099
            TabOrder = 3
            OnClick = PrintBases
          end
          object rbBasesSortK: TRadioButton
            Left = 24
            Top = 119
            Width = 113
            Height = 17
            Caption = #1050#1072#1083#1086#1088#1080#1081#1085#1086#1089#1090#1100
            TabOrder = 4
            OnClick = PrintBases
          end
          object rbBasesSortCost: TRadioButton
            Left = 24
            Top = 142
            Width = 113
            Height = 17
            Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
            TabOrder = 5
            OnClick = PrintBases
          end
        end
        object btnBasesSave: TButton
          Left = 16
          Top = 192
          Width = 193
          Height = 41
          Action = ActionBasesSave
          TabOrder = 4
        end
      end
      object pnlBasesTop: TPanel
        Left = 0
        Top = 0
        Width = 1324
        Height = 41
        Align = alTop
        TabOrder = 2
        object Label1: TLabel
          Left = 16
          Top = 13
          Width = 34
          Height = 16
          Caption = #1055#1086#1080#1089#1082
        end
        object EditBasesSearch: TEdit
          Left = 72
          Top = 9
          Width = 481
          Height = 24
          MaxLength = 256
          TabOrder = 0
          OnChange = EditBasesSearchChange
        end
      end
    end
    object tsPrepared: TTabSheet
      Caption = #1041#1083#1102#1076#1072
      ImageIndex = 1
      object Splitter2: TSplitter
        Left = 1091
        Top = 41
        Height = 539
        Align = alRight
        ExplicitLeft = 560
        ExplicitTop = 256
        ExplicitHeight = 100
      end
      object Panel1: TPanel
        Left = 1094
        Top = 41
        Width = 230
        Height = 539
        Align = alRight
        TabOrder = 0
        object btnPreparedsAdd: TButton
          Left = 16
          Top = 16
          Width = 193
          Height = 41
          Action = ActionPreparedsAdd
          TabOrder = 0
        end
        object btnPreparedsEdit: TButton
          Left = 16
          Top = 72
          Width = 193
          Height = 41
          Action = ActionPreparedsEdit
          TabOrder = 1
        end
        object btnPreparedsDel: TButton
          Left = 16
          Top = 128
          Width = 193
          Height = 41
          Action = ActionPreparedsDel
          TabOrder = 2
        end
        object GroupBox2: TGroupBox
          Left = 24
          Top = 288
          Width = 177
          Height = 193
          Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
          TabOrder = 3
          object rbPreparedSortName: TRadioButton
            Left = 24
            Top = 27
            Width = 113
            Height = 17
            Caption = #1053#1072#1079#1074#1072#1085#1080#1077
            Checked = True
            TabOrder = 0
            TabStop = True
            OnClick = PrintPrepareds
          end
          object rbPreparedSortB: TRadioButton
            Left = 24
            Top = 50
            Width = 113
            Height = 17
            Caption = #1041#1077#1083#1082#1080
            TabOrder = 1
            OnClick = PrintPrepareds
          end
          object rbPreparedSortJ: TRadioButton
            Left = 24
            Top = 73
            Width = 113
            Height = 17
            Caption = #1046#1080#1088#1099
            TabOrder = 2
            OnClick = PrintPrepareds
          end
          object rbPreparedSortU: TRadioButton
            Left = 24
            Top = 96
            Width = 113
            Height = 17
            Caption = #1059#1075#1083#1077#1074#1086#1076#1099
            TabOrder = 3
            OnClick = PrintPrepareds
          end
          object rbPreparedSortK: TRadioButton
            Left = 24
            Top = 119
            Width = 113
            Height = 17
            Caption = #1050#1072#1083#1086#1088#1080#1081#1085#1086#1089#1090#1100
            TabOrder = 4
            OnClick = PrintPrepareds
          end
          object rbPreparedSortM: TRadioButton
            Left = 24
            Top = 142
            Width = 113
            Height = 17
            Caption = #1052#1072#1089#1089#1072
            TabOrder = 5
            OnClick = PrintPrepareds
          end
          object rbPreparedSortCost: TRadioButton
            Left = 24
            Top = 165
            Width = 113
            Height = 17
            Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
            TabOrder = 6
            OnClick = PrintPrepareds
          end
        end
        object btnPreparedsSave: TButton
          Left = 16
          Top = 192
          Width = 193
          Height = 41
          Action = ActionPreparedsSave
          TabOrder = 4
        end
        object Button1: TButton
          Left = 6
          Top = 248
          Width = 211
          Height = 25
          Caption = #1055#1077#1088#1077#1089#1095#1080#1090#1072#1090#1100' '#1074#1089#1077' '#1075#1086#1090#1086#1074#1099#1077' '#1073#1083#1102#1076#1072
          TabOrder = 5
        end
      end
      object gridPrepareds: TStringGrid
        Left = 0
        Top = 41
        Width = 1091
        Height = 539
        Align = alClient
        ColCount = 7
        DefaultColWidth = 80
        DrawingStyle = gdsGradient
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
        TabOrder = 1
        OnMouseDown = gridPreparedsMouseDown
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1324
        Height = 41
        Align = alTop
        TabOrder = 2
        object Label2: TLabel
          Left = 16
          Top = 13
          Width = 34
          Height = 16
          Caption = #1055#1086#1080#1089#1082
        end
        object EditPreparedsSearch: TEdit
          Left = 72
          Top = 9
          Width = 481
          Height = 24
          MaxLength = 256
          TabOrder = 0
          OnChange = EditPreparedsSearchChange
        end
      end
    end
    object tsCalendar: TTabSheet
      Caption = #1050#1072#1083#1077#1085#1076#1072#1088#1100
      ImageIndex = 2
      object pnlCalendarRight: TPanel
        Left = 923
        Top = 41
        Width = 401
        Height = 539
        Align = alRight
        TabOrder = 0
        object cvCalendar: TCalendarView
          Left = 1
          Top = 1
          Width = 399
          Height = 248
          Align = alTop
          Date = 43946.000000000000000000
          FirstDayOfWeek = dwMonday
          FocusedColor = clTeal
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = 'Segoe UI'
          Font.Style = []
          HeaderInfo.DaysOfWeekFont.Charset = DEFAULT_CHARSET
          HeaderInfo.DaysOfWeekFont.Color = clWindowText
          HeaderInfo.DaysOfWeekFont.Height = -13
          HeaderInfo.DaysOfWeekFont.Name = 'Segoe UI'
          HeaderInfo.DaysOfWeekFont.Style = []
          HeaderInfo.Font.Charset = DEFAULT_CHARSET
          HeaderInfo.Font.Color = clWindowText
          HeaderInfo.Font.Height = -20
          HeaderInfo.Font.Name = 'Segoe UI'
          HeaderInfo.Font.Style = []
          HeaderInfo.HighlightFontColor = clNavy
          HighlightColor = clNavy
          HighlightToday = False
          OnChange = cvCalendarChange
          OnDrawDayItem = cvCalendarDrawDayItem
          ParentFont = False
          ParentShowHint = False
          SelectionColor = clRed
          ShowHint = False
          TabOrder = 0
          TodayColor = clGreen
        end
        object EditCalendarPreparedSearch: TEdit
          Left = 6
          Top = 255
          Width = 385
          Height = 24
          MaxLength = 256
          TabOrder = 1
          OnChange = EditCalendarPreparedSearchChange
          OnKeyDown = EditCalendarPreparedSearchKeyDown
          OnKeyPress = EditCalendarPreparedSearchKeyPress
        end
        object lbCalendarPrepareds: TListBox
          Left = 6
          Top = 279
          Width = 385
          Height = 26
          TabOrder = 2
          Visible = False
          OnDblClick = lbCalendarPreparedsDblClick
          OnKeyDown = lbCalendarPreparedsKeyDown
        end
        object btnCalendarAdd: TButton
          Left = 6
          Top = 405
          Width = 385
          Height = 33
          Action = ActionCalendarAdd
          TabOrder = 3
        end
        object btnCalendarEdit: TButton
          Left = 6
          Top = 485
          Width = 385
          Height = 33
          Action = ActionCalendarEdit
          TabOrder = 4
        end
        object btnCalendarDelPrepared: TButton
          Left = 6
          Top = 446
          Width = 385
          Height = 33
          Action = ActionCalendarDel
          TabOrder = 5
        end
        object GroupBox3: TGroupBox
          Left = 6
          Top = 296
          Width = 267
          Height = 103
          Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
          TabOrder = 6
          object rbCalendarSortName: TRadioButton
            Left = 24
            Top = 27
            Width = 89
            Height = 17
            Caption = #1053#1072#1079#1074#1072#1085#1080#1077
            Checked = True
            TabOrder = 0
            TabStop = True
            OnClick = PrintCalendar
          end
          object rbCalendarSortB: TRadioButton
            Left = 24
            Top = 50
            Width = 89
            Height = 17
            Caption = #1041#1077#1083#1082#1080
            TabOrder = 1
            OnClick = PrintCalendar
          end
          object rbCalendarSortJ: TRadioButton
            Left = 24
            Top = 73
            Width = 89
            Height = 17
            Caption = #1046#1080#1088#1099
            TabOrder = 2
            OnClick = PrintCalendar
          end
          object rbCalendarSortU: TRadioButton
            Left = 127
            Top = 27
            Width = 113
            Height = 17
            Caption = #1059#1075#1083#1077#1074#1086#1076#1099
            TabOrder = 3
            OnClick = PrintCalendar
          end
          object rbCalendarSortK: TRadioButton
            Left = 128
            Top = 50
            Width = 113
            Height = 17
            Caption = #1050#1072#1083#1086#1088#1080#1081#1085#1086#1089#1090#1100
            TabOrder = 4
            OnClick = PrintCalendar
          end
          object rbCalendarSortCost: TRadioButton
            Left = 127
            Top = 73
            Width = 113
            Height = 17
            Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
            TabOrder = 5
            OnClick = PrintCalendar
          end
        end
      end
      object gridCalendar: TStringGrid
        Left = 0
        Top = 41
        Width = 923
        Height = 539
        Align = alClient
        ColCount = 8
        DefaultColWidth = 80
        DrawingStyle = gdsGradient
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
        TabOrder = 1
        OnMouseDown = gridPreparedsMouseDown
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 1324
        Height = 41
        Align = alTop
        TabOrder = 2
        object Label3: TLabel
          Left = 16
          Top = 13
          Width = 34
          Height = 16
          Caption = #1055#1086#1080#1089#1082
        end
        object lblDate: TLabel
          Left = 576
          Top = 9
          Width = 65
          Height = 25
          Caption = 'lblDate'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object EditCalendarSearch: TEdit
          Left = 72
          Top = 9
          Width = 481
          Height = 24
          MaxLength = 256
          TabOrder = 0
          OnChange = EditCalendarSearchChange
        end
      end
    end
  end
  object MainMenu: TMainMenu
    Left = 80
    Top = 168
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N3: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Action = ActionFileClose
      end
    end
    object N6: TMenuItem
      Caption = #1041#1072#1079#1086#1074#1099#1077' '#1087#1088#1086#1076#1091#1082#1090#1099
      object N4: TMenuItem
        Action = ActionBasesLoad
      end
      object N5: TMenuItem
        Action = ActionBasesSave
      end
      object N10: TMenuItem
        Action = ActionBasesSaveAs
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object N8: TMenuItem
        Action = ActionBasesAdd
      end
      object N7: TMenuItem
        Action = ActionBasesEdit
      end
      object N9: TMenuItem
        Action = ActionBasesDel
      end
    end
    object N12: TMenuItem
      Caption = #1043#1086#1090#1086#1074#1099#1077' '#1073#1083#1102#1076#1072
      object N13: TMenuItem
        Action = ActionPreparedsLoad
      end
      object N14: TMenuItem
        Action = ActionPreparedsSave
      end
      object N15: TMenuItem
        Action = ActionPreparedsSaveAs
      end
      object N16: TMenuItem
        Caption = '-'
      end
      object N17: TMenuItem
        Action = ActionPreparedsAdd
      end
      object N18: TMenuItem
        Action = ActionPreparedsEdit
      end
      object N19: TMenuItem
        Action = ActionPreparedsDel
      end
    end
    object N20: TMenuItem
      Caption = #1050#1072#1083#1077#1085#1076#1072#1088#1100
      object N21: TMenuItem
        Action = ActionCalendarLoad
      end
      object N22: TMenuItem
        Action = ActionCalendarSave
      end
      object N23: TMenuItem
        Action = ActionCalendarSaveAs
      end
      object N24: TMenuItem
        Caption = '-'
      end
    end
    object Y1: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      object N25: TMenuItem
        Action = ActionSettingsSettings
      end
    end
  end
  object ActionList: TActionList
    Left = 168
    Top = 168
    object ActionFileClose: TAction
      Caption = #1042#1099#1093#1086#1076
      OnExecute = ActionFileCloseExecute
    end
    object ActionBasesSaveAs: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1073#1072#1079#1086#1074#1099#1077' '#1087#1088#1086#1076#1091#1082#1090#1099' '#1082#1072#1082'...'
      OnExecute = ActionBasesSaveAsExecute
    end
    object ActionBasesSave: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1073#1072#1079#1086#1074#1099#1077' '#1087#1088#1086#1076#1091#1082#1090#1099
      OnExecute = ActionBasesSaveExecute
    end
    object ActionBasesLoad: TAction
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1073#1072#1079#1086#1074#1099#1077' '#1087#1088#1086#1076#1091#1082#1090#1099
      OnExecute = ActionBasesLoadExecute
    end
    object ActionBasesEdit: TAction
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      OnExecute = ActionBasesEditExecute
    end
    object ActionBasesAdd: TAction
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      OnExecute = ActionBasesAddExecute
    end
    object ActionBasesDel: TAction
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnExecute = ActionBasesDelExecute
    end
    object ActionPreparedsAdd: TAction
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      OnExecute = ActionPreparedsAddExecute
    end
    object ActionPreparedsEdit: TAction
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      OnExecute = ActionPreparedsEditExecute
    end
    object ActionPreparedsDel: TAction
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnExecute = ActionPreparedsDelExecute
    end
    object ActionPreparedsSave: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1075#1086#1090#1086#1074#1099#1077' '#1073#1083#1102#1076#1072
      OnExecute = ActionPreparedsSaveExecute
    end
    object ActionPreparedsSaveAs: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1075#1086#1090#1086#1074#1099#1077' '#1073#1083#1102#1076#1072' '#1082#1072#1082'..'
      OnExecute = ActionPreparedsSaveAsExecute
    end
    object ActionPreparedsLoad: TAction
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1075#1086#1090#1086#1074#1099#1077' '#1073#1083#1102#1076#1072
      OnExecute = ActionPreparedsLoadExecute
    end
    object ActionCalendarLoad: TAction
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1082#1072#1083#1077#1085#1076#1072#1088#1100
      OnExecute = ActionCalendarLoadExecute
    end
    object ActionCalendarSave: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1083#1077#1085#1076#1072#1088#1100
      OnExecute = ActionCalendarSaveExecute
    end
    object ActionCalendarSaveAs: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1083#1077#1085#1076#1072#1088#1100' '#1082#1072#1082'...'
      OnExecute = ActionCalendarSaveAsExecute
    end
    object ActionCalendarAdd: TAction
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1073#1083#1102#1076#1086
      OnExecute = ActionCalendarAddExecute
    end
    object ActionCalendarEdit: TAction
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1082#1086#1083'-'#1074#1086' '#1087#1086#1088#1094#1080#1081
      OnExecute = ActionCalendarEditExecute
    end
    object ActionCalendarDel: TAction
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1086#1077' '#1073#1083#1102#1076#1086
      OnExecute = ActionCalendarDelExecute
    end
    object ActionSettingsSettings: TAction
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080'...'
      OnExecute = ActionSettingsSettingsExecute
    end
    object ActionCalendarExport: TAction
      Caption = #1069#1082#1089#1087#1086#1088#1090'...'
      OnExecute = ActionCalendarExportExecute
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'json'
    Filter = 'Json files (*.json)|*.json'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 76
    Top = 248
  end
end
