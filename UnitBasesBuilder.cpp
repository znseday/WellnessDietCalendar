//---------------------------------------------------------------------------
#include <System.JSON.hpp>
#include <System.JSON.Writers.hpp>
#include <vcl.h>

#include <vector>
#include <algorithm>
#include <memory>

#pragma hdrstop

#include "UnitBasesBuilder.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//static struct {
//    bool operator()(const BasesPair &a, const BasesPair &b) const {
//        return a.second.B > b.second.B;
//    }
//} lambda_B;
//
//static struct {
//    bool operator()(const BasesPair &a, const BasesPair &b) const {
//        return a.second.J > b.second.J;
//    }
//} lambda_J;
//
//static struct {
//    bool operator()(const BasesPair &a, const BasesPair &b) const {
//        return a.second.U > b.second.U;
//    }
//} lambda_U;
//
//static struct {
//    bool operator()(const BasesPair &a, const BasesPair &b) const {
//        return a.second.K > b.second.K;
//    }
//} lambda_K;
//
//static struct {
//    bool operator()(const BasesPair &a, const BasesPair &b) const {
//        return a.second.Cost > b.second.Cost;
//    }
//} lambda_Cost;

void BasesBuilder::ClearTable(TStringGrid *grid) const
{
    //if (Data.size() > 1)
    //    grid->RowCount = Data.size() + 1;
    //else
        grid->RowCount = 2;

    grid->ColWidths[0] = 330;
    grid->ColWidths[4] = 96;
    grid->ColWidths[5] = 116;

    grid->Cells[0][0] = L"Название";
    grid->Cells[1][0] = L"Белки, г";
    grid->Cells[2][0] = L"Жиры, г";
    grid->Cells[3][0] = L"Углеводы, г";
    grid->Cells[4][0] = L"Калории, ккал";
    grid->Cells[5][0] = L"Стоимость, руб";

    for (int j = 0; j < 6; j++)
        grid->Cells[j][1] = L"";
}
//---------------------------------------------------------------------------

void BasesBuilder::PrintToTable(TStringGrid *grid, HowToSort _SortType,
                                 String _SearchString) const
{
    ClearTable(grid);

    int i = 1;

    String NameUpperCase;

    _SearchString = _SearchString.UpperCase();
    int SearchStringLength = _SearchString.Length();

    if (_SortType == HowToSort::Name)
    {
        for (auto it = Data.cbegin(); it != Data.cend(); ++it)
        {
            if (SearchStringLength > 0)
            {
                NameUpperCase = String(it->first.c_str()).UpperCase();

                int pos = NameUpperCase.Pos(_SearchString);

                if ( pos <= 0)
                    continue;
            }

            if (i > 1)
                grid->RowCount++;

            grid->Cells[0][i] = it->first.c_str();

            grid->Cells[1][i] = FloatToStrF(it->second.B, ffFixed, 12,1);
            grid->Cells[2][i] = FloatToStrF(it->second.J, ffFixed, 12,1);
            grid->Cells[3][i] = FloatToStrF(it->second.U, ffFixed, 12,1);
            grid->Cells[4][i] = FloatToStrF(it->second.K, ffFixed, 12,1);
            grid->Cells[5][i] = FloatToStrF(it->second.Cost, ffFixed, 12,1);

            ++i;
        }
    }
    else
    {
        std::vector<BasesPair> vectorData( Data.begin(), Data.end() );

        switch (_SortType)
        {
            case HowToSort::B:
                std::sort(vectorData.begin(), vectorData.end(), []
                (const BasesPair &a, const BasesPair &b)
                {
                        return a.second.B > b.second.B;
                });
            break;
            case HowToSort::J:
                std::sort(vectorData.begin(), vectorData.end(), []
                (const BasesPair &a, const BasesPair &b)
                {
                        return a.second.J > b.second.J;
                });
            break;
            case HowToSort::U:
                std::sort(vectorData.begin(), vectorData.end(), []
                (const BasesPair &a, const BasesPair &b)
                {
                        return a.second.U > b.second.U;
                });
            break;
            case HowToSort::K:
                std::sort(vectorData.begin(), vectorData.end(), []
                (const BasesPair &a, const BasesPair &b)
                {
                        return a.second.K > b.second.K;
                });
            break;
            case HowToSort::Cost:
                std::sort(vectorData.begin(), vectorData.end(), []
                (const BasesPair &a, const BasesPair &b)
                {
                        return a.second.Cost > b.second.Cost;
                });
            break;
            default:
            ;
        }

        for (auto it = vectorData.begin(); it != vectorData.end(); ++it)
        {
            if (SearchStringLength > 0)
            {
                NameUpperCase = String(it->first.c_str()).UpperCase();
                if ( NameUpperCase.Pos(_SearchString) <= 0)
                    continue;
            }

            if (i > 1)
                grid->RowCount++;

            grid->Cells[0][i] = it->first.c_str();

            grid->Cells[1][i] = FloatToStrF(it->second.B, ffFixed, 12,1);
            grid->Cells[2][i] = FloatToStrF(it->second.J, ffFixed, 12,1);
            grid->Cells[3][i] = FloatToStrF(it->second.U, ffFixed, 12,1);
            grid->Cells[4][i] = FloatToStrF(it->second.K, ffFixed, 12,1);
            grid->Cells[5][i] = FloatToStrF(it->second.Cost, ffFixed, 12,1);

            ++i;
        }
    }

}
//---------------------------------------------------------------------------

void BasesBuilder::PrintToListBox(TListBox *lb, String _SearchString) const
{
    String SearchStringUpCase = _SearchString.UpperCase();
    int SearchStringLength = SearchStringUpCase.Length();

    lb->Clear();

    String NameUpperCase;

    for (auto it = Data.cbegin(); it != Data.cend(); ++it)
    {
        if (SearchStringLength > 0)
        {
            NameUpperCase = String(it->first.c_str()).UpperCase();
            if ( NameUpperCase.Pos(SearchStringUpCase) <= 0)
                continue;
        }

        lb->Items->Add(it->first.c_str());
    }

    if (SearchStringUpCase.Length() > 0 && lb->Items->Count > 0)
    {
        lb->Visible = true;
        //lb->SetFocus();
        lb->ItemIndex = 0;
        lb->BringToFront();
    }
    else
    {
        lb->Visible = false;
    }

}
//---------------------------------------------------------------------------

void BasesBuilder::PrintToComboBox(TComboBox *cb, String _SearchString) const
{
    //String SearchString = cb->Text;
    String SearchStringUpCase = _SearchString.UpperCase();
    int SearchStringLength = SearchStringUpCase.Length();

    cb->Clear();

    //size_t pos;

    String NameUpperCase;

    for (auto it = Data.cbegin(); it != Data.cend(); ++it)
    {
        if (SearchStringLength > 0)
        {
            NameUpperCase = String(it->first.c_str()).UpperCase();
            if ( NameUpperCase.Pos(SearchStringUpCase) <= 0)
                continue;
        }

        cb->Items->Add(it->first.c_str());
    }

    Application->ProcessMessages();

    //cb->SetFocus();
    cb->DroppedDown = true;
    //cb->Invalidate();

    cb->ItemIndex = 0;

    cb->Text = _SearchString;

    //if (cb->Text.Length() > 0 && cb->Items->Count > 0)
    //    cb->SetFocus();

    cb->SelStart = _SearchString.Length();

    if (cb->Text.Length() > 0 && cb->Items->Count > 0)
        cb->SetFocus();
}
//---------------------------------------------------------------------------

bool BasesBuilder::SaveToJSON(String _FullFileName)
{
    std::unique_ptr<TStreamWriter> DestFileStream(new TStreamWriter(_FullFileName, false, TEncoding::UTF8, 64*1024));
    //std::auto_ptr<TFileStream> DestFileStream(new TFileStream(_FullFileName, fmCreate));

    //TStringWriter *StringWriter = new TStringWriter;
    std::auto_ptr<TJsonTextWriter> Writer( new TJsonTextWriter( DestFileStream.get()) );
//    TJsonTextWriter *Writer = new TJsonTextWriter(StringWriter);

      __try
    {

        Writer->Formatting = TJsonFormatting::Indented;
        Writer->WriteStartObject();
        Writer->WritePropertyName(L"Products");
        Writer->WriteStartArray();

        for (auto it = Data.cbegin(); it != Data.cend(); ++it)
        {
            Writer->WriteStartObject();
            Writer->WritePropertyName(L"name");

            //ShowMessage( String(it->first.c_str()) );

            Writer->WriteValue( String(it->first.c_str()) );

            Writer->WritePropertyName(L"B");
            Writer->WriteValue( it->second.B );
            Writer->WritePropertyName(L"J");
            Writer->WriteValue( it->second.J );
            Writer->WritePropertyName(L"U");
            Writer->WriteValue( it->second.U );
            Writer->WritePropertyName(L"K");
            Writer->WriteValue( it->second.K );
            Writer->WritePropertyName(L"Cost");
            Writer->WriteValue( it->second.Cost );

            Writer->WriteEndObject();

//            TJSONObject *entry = new TJSONObject();
//            ShowMessage(String(it->first.c_str()));
//            entry->AddPair( new TJSONPair(L"name", String(it->first.c_str())) );
//            entry->AddPair( new TJSONPair(L"B", it->second.B) );
//            entry->AddPair( new TJSONPair(L"J", it->second.J) );
//            entry->AddPair( new TJSONPair(L"U", it->second.U) );
//            entry->AddPair( new TJSONPair(L"K", it->second.K) );
//
//            a->AddElement(entry);
        }

        Writer->WriteEndArray();
        Writer->WriteEndObject();
    }
    //catch(...)
    //{
    //    ShowMessage(L"Что-то пошло не так при записи");
    //}
    __finally
    {
        //ShowMessage ( StringWriter->ToString() );
    }

    IsSaved = true;
    return true;
}
//---------------------------------------------------------------------------

bool BasesBuilder::LoadFromJSON(String _FullFileName)
{
    if ( !FileExists(_FullFileName) )
        return false;

    try
    {
        std::unique_ptr<TStreamReader> SrcFileStream(new TStreamReader(_FullFileName, TEncoding::UTF8, false, 64*1024));

    // std::auto_ptr<TFileStream> SrcFileStream(new TFileStream(_FullFileName, fmOpenRead));

        std::auto_ptr<TJsonTextReader> Reader( new TJsonTextReader( SrcFileStream.get()) );

        Data.clear();

        while (Reader->Read())
        {
            if (Reader->TokenType == TJsonToken::StartObject)
            {
                 String Name;
                float b, j, u, k, cost;
                b = j = u = k = cost = -1;

                while (Reader->Read())
                {
                    if (Reader->TokenType == TJsonToken::PropertyName)
                    {
                        String Value = Reader->Value.ToString();

                        if (Value == L"name")
                            Name = Reader->ReadAsString();
                        else if (Value == L"B")
                            b = (float)Reader->ReadAsDouble();
                        else if (Value == L"J")
                            j = (float)Reader->ReadAsDouble();
                        else if (Value == L"U")
                            u = (float)Reader->ReadAsDouble();
                        else if (Value == L"K")
                            k = (float)Reader->ReadAsDouble();
                        else if (Value == L"Cost")
                            cost = (float)Reader->ReadAsDouble();

                    }
                    else if (Reader->TokenType == TJsonToken::EndObject)
                    {
                        Add(Name.c_str(), b, j, u, k, cost);
                        break;
                    }
                }
            }
        }

//        Writer->Formatting = TJsonFormatting::Indented;
//        Writer->WriteStartObject();
//        Writer->WritePropertyName(L"Products");
//        Writer->WriteStartArray();
//
//        for (BasesMap::iterator it = Data.begin(); it != Data.end(); ++it)
//        {
//            Writer->WriteStartObject();
//            Writer->WritePropertyName(L"Name");
//
//            ShowMessage( String(it->first.c_str()) );
//
//            Writer->WriteValue( String(it->first.c_str()) );
//
//            Writer->WritePropertyName(L"B");
//            Writer->WriteValue( it->second.B );
//            Writer->WritePropertyName(L"J");
//            Writer->WriteValue( it->second.J );
//            Writer->WritePropertyName(L"U");
//            Writer->WriteValue( it->second.U );
//            Writer->WritePropertyName(L"K");
//            Writer->WriteValue( it->second.K );
//
//            Writer->WriteEndObject();
//        }
//
//        Writer->WriteEndArray();
//        Writer->WriteEndObject();
    }
    catch(...)
    {
         ShowMessage(L"Что-то пошло не так при чтении");
    }


    IsSaved = true;
    return true;
}
//---------------------------------------------------------------------------
