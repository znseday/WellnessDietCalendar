//---------------------------------------------------------------------------
#include <System.JSON.hpp>
#include <System.JSON.Writers.hpp>
#include <vcl.h>

#include <vector>
#include <algorithm>
#include <memory>

#pragma hdrstop

#include "UnitPreparedsBuilder.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void PreparedsBuilder::ClearTable(TStringGrid *grid) const
{
//    if (Data.size() > 1)
//		grid->RowCount = Data.size() + 1;
//	else
		grid->RowCount = 2;

	grid->ColWidths[0] = 330;
    grid->ColWidths[4] = 96;
	grid->ColWidths[6] = 116;

	grid->Cells[0][0] = L"Название";
	grid->Cells[1][0] = L"Белки, г";
	grid->Cells[2][0] = L"Жиры, г";
	grid->Cells[3][0] = L"Углеводы, г";
	grid->Cells[4][0] = L"Калории, ккал";
	grid->Cells[5][0] = L"Масса, г";
	grid->Cells[6][0] = L"Стоимость, руб";


	for (int j = 0; j < 7; j++)
		grid->Cells[j][1] = L"";

}
//---------------------------------------------------------------------------

void PreparedsBuilder::PrintAllToTable(TStringGrid *grid, HowToSort _SortType,
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

			grid->Cells[1][i] = FloatToStrF(it->second.Finished.B, ffFixed, 12,1);
			grid->Cells[2][i] = FloatToStrF(it->second.Finished.J, ffFixed, 12,1);
			grid->Cells[3][i] = FloatToStrF(it->second.Finished.U, ffFixed, 12,1);
			grid->Cells[4][i] = FloatToStrF(it->second.Finished.K, ffFixed, 12,1);
			grid->Cells[5][i] = FloatToStrF(it->second.Finished.M, ffFixed, 12,1);
			grid->Cells[6][i] = FloatToStrF(it->second.Finished.Cost, ffFixed, 12,1);

			++i;
        }
	}
	else
    {
        std::vector<PreparedsPair> vectorData( Data.begin(), Data.end() );

        switch (_SortType)
        {
			case HowToSort::B:
				std::sort(vectorData.begin(), vectorData.end(), []
					(const PreparedsPair &a, const PreparedsPair &b)
					{
						return a.second.Finished.B > b.second.Finished.B;
					}
				);
			break;
			case HowToSort::J:
				std::sort(vectorData.begin(), vectorData.end(), []
					(const PreparedsPair &a, const PreparedsPair &b)
					{
						return a.second.Finished.J > b.second.Finished.J;
					}
				);
            break;
			case HowToSort::U:
				std::sort(vectorData.begin(), vectorData.end(), []
					(const PreparedsPair &a, const PreparedsPair &b)
					{
						return a.second.Finished.U > b.second.Finished.U;
					}
				);
            break;
			case HowToSort::K:
                std::sort(vectorData.begin(), vectorData.end(), []
					(const PreparedsPair &a, const PreparedsPair &b)
					{
						return a.second.Finished.K > b.second.Finished.K;
					}
				);
            break;
			case HowToSort::M:
                std::sort(vectorData.begin(), vectorData.end(), []
					(const PreparedsPair &a, const PreparedsPair &b)
					{
						return a.second.Finished.M > b.second.Finished.M;
					}
				);
            break;
			case HowToSort::Cost:
				std::sort(vectorData.begin(), vectorData.end(), []
					(const PreparedsPair &a, const PreparedsPair &b)
					{
						return a.second.Finished.Cost > b.second.Finished.Cost;
					}
				);
			break;
			default:
			;
		}


		for (auto it = vectorData.begin(); it != vectorData.end(); ++it)
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

			grid->Cells[1][i] = FloatToStrF(it->second.Finished.B, ffFixed, 12,1);
			grid->Cells[2][i] = FloatToStrF(it->second.Finished.J, ffFixed, 12,1);
			grid->Cells[3][i] = FloatToStrF(it->second.Finished.U, ffFixed, 12,1);
			grid->Cells[4][i] = FloatToStrF(it->second.Finished.K, ffFixed, 12,1);
			grid->Cells[5][i] = FloatToStrF(it->second.Finished.M, ffFixed, 12,1);
			grid->Cells[6][i] = FloatToStrF(it->second.Finished.Cost, ffFixed, 12,1);

            ++i;
		}
	}
}
//---------------------------------------------------------------------------

void PreparedsBuilder::PrintToListBox(TListBox *lb, String _SearchString) const
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

	//Application->ProcessMessages();

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

	//lb->DroppedDown = true;
	//lb->Invalidate();

	//lb->Text = _SearchString;

	//if (cb->Text.Length() > 0 && cb->Items->Count > 0)
	//	cb->SetFocus();

	//cb->SelStart = _SearchString.Length();

//	if (cb->Text.Length() > 0 && cb->Items->Count > 0)
//		cb->SetFocus();

	//cb->OnDropDown(cb);
	//cb->AutoDropDown = true;
}
//---------------------------------------------------------------------------

bool PreparedsBuilder::SaveToJSON(String _FullFileName)
{
	std::unique_ptr<TStreamWriter> DestFileStream(new
                                   TStreamWriter(_FullFileName, false, TEncoding::UTF8, 64*1024));

	std::unique_ptr<TJsonTextWriter> Writer( new TJsonTextWriter( DestFileStream.get()) );

  	try
	{
		Writer->Formatting = TJsonFormatting::Indented;
		Writer->WriteStartObject();
		Writer->WritePropertyName(L"Prepareds");
		Writer->WriteStartArray();

		for (PreparedsMap::iterator it = Data.begin(); it != Data.end(); ++it)
    	{
			Writer->WriteStartObject();

				Writer->WritePropertyName(L"name");
				Writer->WriteValue( String(it->first.c_str()) );

				Writer->WritePropertyName(L"B");
				Writer->WriteValue( it->second.Finished.B );
				Writer->WritePropertyName(L"J");
				Writer->WriteValue( it->second.Finished.J );
				Writer->WritePropertyName(L"U");
				Writer->WriteValue( it->second.Finished.U );
				Writer->WritePropertyName(L"K");
				Writer->WriteValue( it->second.Finished.K );
				Writer->WritePropertyName(L"M");
				Writer->WriteValue( it->second.Finished.M );
				Writer->WritePropertyName(L"Cost");
				Writer->WriteValue( it->second.Finished.Cost );

			//Writer->WriteEndObject();


            //Writer->WriteStartObject();
			Writer->WritePropertyName(L"Products");
			Writer->WriteStartArray();

			for (PreparedsList::iterator itList = it->second.List.begin();
										itList != it->second.List.end(); ++itList)
			{
				Writer->WriteStartObject();
				Writer->WritePropertyName(L"name");
				Writer->WriteValue( String(itList->first.c_str()) );
				Writer->WritePropertyName(L"m");
				Writer->WriteValue( itList->second );
				Writer->WriteEndObject();
			}

			Writer->WriteEndArray();
			Writer->WriteEndObject();
        }

		Writer->WriteEndArray();
		Writer->WriteEndObject();
	}
    catch(...)
    {
        ShowMessage(L"Что-то пошло не так при записи файла готовых блюд.");
    }

	IsSaved = true;
	return true;
}
//---------------------------------------------------------------------------

void ProcessProduct(PreparedStruct &Prepared, std::auto_ptr<TJsonTextReader> &Reader)
{
	while (Reader->Read())
	{
		if (Reader->TokenType == TJsonToken::StartObject)
		{
			String Name;
			float m = 0;

			while (Reader->Read())
			{
				if (Reader->TokenType == TJsonToken::PropertyName)
				{
					String Value = Reader->Value.ToString();

					if (Value == L"name")
						Name = Reader->ReadAsString();
					else if (Value == L"m")
						m = (float)Reader->ReadAsDouble();

				}
				else if (Reader->TokenType == TJsonToken::EndObject)
				{
					Prepared.List.push_back( std::make_pair(Name.c_str(), m) );
					break;
				}
			}
		}
		else if (Reader->TokenType == TJsonToken::EndArray)
            return;
	}
}
//---------------------------------------------------------------------------

bool PreparedsBuilder::LoadFromJSON(String _FullFileName)
{
	if ( !FileExists(_FullFileName) )
		return false;

	try
	{
		std::auto_ptr<TStreamReader> SrcFileStream(new
					   TStreamReader(_FullFileName, TEncoding::UTF8, false, 64*1024));

		std::auto_ptr<TJsonTextReader> Reader( new TJsonTextReader( SrcFileStream.get()) );

        Data.clear();

		while (Reader->Read())
		{
			if (Reader->TokenType == TJsonToken::StartObject)
			{
				String Name;
				//float b, j, u, k, m, cost;
				//b = j = u = k = m = cost = -1;
				PreparedStruct Prepared;

				while (Reader->Read())
				{
					if (Reader->TokenType == TJsonToken::PropertyName)
					{
						String Value = Reader->Value.ToString();

						if (Value == L"name")
							Name = Reader->ReadAsString();
						else if (Value == L"B")
							Prepared.Finished.B = (float)Reader->ReadAsDouble();
						else if (Value == L"J")
							Prepared.Finished.J = (float)Reader->ReadAsDouble();
						else if (Value == L"U")
							Prepared.Finished.U = (float)Reader->ReadAsDouble();
						else if (Value == L"K")
							Prepared.Finished.K = (float)Reader->ReadAsDouble();
						else if (Value == L"M")
							Prepared.Finished.M = (float)Reader->ReadAsDouble();
						else if (Value == L"Cost")
							Prepared.Finished.Cost = (float)Reader->ReadAsDouble();
						else if (Value == L"Products")
							ProcessProduct(Prepared, Reader);

					}
					else if (Reader->TokenType == TJsonToken::EndObject)
					{
						Add(Name.c_str(), Prepared);
						break;
					}
				}
            }
		}

	}
	catch(...)
	{
		 ShowMessage(L"Что-то пошло не так при чтении файла готовых блюд");
	}

    IsSaved = true;
    return true;
}
//---------------------------------------------------------------------------
