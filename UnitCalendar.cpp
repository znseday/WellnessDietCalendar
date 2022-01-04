//---------------------------------------------------------------------------
#include <vector>
#include <algorithm>

#include <System.JSON.hpp>
#include <System.JSON.Writers.hpp>
#include <vcl.h>

#pragma hdrstop

#include "UnitCalendar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

//---------------------------------------------------------------------------

bool CalendarClass::Add(TDate _Date, const OnePreparedPair &_OnePreparedPair)
{
	auto it = Calendar.find(_Date);

	if (it == Calendar.end())
	{
		auto res = Calendar.insert( make_pair(_Date, OneDayMap()) );

		if (!res.second)
			return false;

		it = res.first;
	}

	auto res_add = it->second.insert( _OnePreparedPair );

	if (res_add.second)
		IsSaved = false;

	return res_add.second;
}
//---------------------------------------------------------------------------

bool CalendarClass::Edit(TDate _Date, const OnePreparedPair &_OnePreparedPair)
{
	auto it_date = Calendar.find(_Date);

	if (it_date == Calendar.end())
		return false;

	auto it = it_date->second.find(_OnePreparedPair.first);

	if (it == it_date->second.end())
		return false;

	it->second = _OnePreparedPair.second;

	IsSaved = false;

	return true;

}
//---------------------------------------------------------------------------

bool CalendarClass::Del(TDate _Date, const std::wstring &_name)
{
	auto it_date = Calendar.find(_Date);

	if (it_date == Calendar.end())
		return false;

	auto it = it_date->second.find(_name);

    if (it == it_date->second.end())
        return false;

	it_date->second.erase(it);

    IsSaved = false;

	return true;
}
//---------------------------------------------------------------------------

void CalendarClass::ClearTable(TStringGrid *grid) const
{
//    if (Data.size() > 1)
//		grid->RowCount = Data.size() + 1;
//	else
		grid->RowCount = 2;

	grid->ColWidths[0] = 260;
	grid->ColWidths[4] = 96;
	grid->ColWidths[7] = 116;

	grid->Cells[0][0] = L"Название";
	grid->Cells[1][0] = L"Белки, г";
	grid->Cells[2][0] = L"Жиры, г";
	grid->Cells[3][0] = L"Углеводы, г";
	grid->Cells[4][0] = L"Калории, ккал";
	grid->Cells[5][0] = L"Порции, шт";
	grid->Cells[6][0] = L"Масса, г";
	grid->Cells[7][0] = L"Стоимость, руб";

	for (int j = 0; j < 8; j++)
		grid->Cells[j][1] = L"";
}
//---------------------------------------------------------------------------

void CalendarClass::PrintOneDayToTable(TDate _Date, TStringGrid *grid,
								 HowToSort _SortType, String _SearchString,
								 PreparedsBuilder *pPrepareds) const
{
	ClearTable(grid);

	auto it_date = Calendar.find(_Date);

	if (it_date == Calendar.end())
		return;

    int i = 1;

	String NameUpperCase;

	_SearchString = _SearchString.UpperCase();
	int SearchStringLength = _SearchString.Length();

    BJUKM_Struct BJUKM_summ;

	if (_SortType == HowToSort::Name)
    {
		for (auto it = it_date->second.cbegin(); it != it_date->second.cend(); ++it)
		{
			BJUKM_Struct BJUKM = pPrepareds->GetBJUKM(it->first.c_str());

			BJUKM_summ.B += BJUKM.B * it->second;
			BJUKM_summ.J += BJUKM.J * it->second;
			BJUKM_summ.U += BJUKM.U * it->second;
			BJUKM_summ.K += BJUKM.K * it->second;
			BJUKM_summ.M += BJUKM.M * it->second;
			BJUKM_summ.Cost += BJUKM.Cost * it->second;


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

//            BJUKM.B * it->second;

			grid->Cells[1][i] = FloatToStrF(BJUKM.B * it->second, ffFixed, 12, 1);
			grid->Cells[2][i] = FloatToStrF(BJUKM.J * it->second, ffFixed, 12, 1);
			grid->Cells[3][i] = FloatToStrF(BJUKM.U * it->second, ffFixed, 12, 1);
			grid->Cells[4][i] = FloatToStrF(BJUKM.K * it->second, ffFixed, 12, 1);
			grid->Cells[5][i] = FloatToStrF(it->second, ffFixed, 12, 2);
			grid->Cells[6][i] = FloatToStrF(BJUKM.M * it->second, ffFixed, 12, 1);
			grid->Cells[7][i] = FloatToStrF(BJUKM.Cost * it->second, ffFixed, 12, 1);

			++i;
		}
	}

	for (int j = 0; j < 8; j++)
		grid->Cells[j][i] = L"";

	++i;
	if (i <= 2)
	{
		grid->RowCount = 3;
	}
	else
		grid->RowCount += 2;

	grid->Cells[0][i] = L"Итого:";
	grid->Cells[1][i] = FloatToStrF(BJUKM_summ.B, ffFixed, 12, 1);
	grid->Cells[2][i] = FloatToStrF(BJUKM_summ.J, ffFixed, 12, 1);
	grid->Cells[3][i] = FloatToStrF(BJUKM_summ.U, ffFixed, 12, 1);
	grid->Cells[4][i] = FloatToStrF(BJUKM_summ.K, ffFixed, 12, 1);
	grid->Cells[5][i] = L"";
	grid->Cells[6][i] = FloatToStrF(BJUKM_summ.M, ffFixed, 12, 1);
	grid->Cells[7][i] = FloatToStrF(BJUKM_summ.Cost, ffFixed, 12, 1);

}
//---------------------------------------------------------------------------

int CalendarClass::GetCountForDay(TDate _Date) const
{
	auto it_date = Calendar.find(_Date);

	if (it_date == Calendar.end())
		return 0;

    return it_date->second.size();
}
//---------------------------------------------------------------------------

bool CalendarClass::SaveToJSON(String _FullFileName)
{
	std::unique_ptr<TStreamWriter> DestFileStream(new
								   TStreamWriter(_FullFileName, false, TEncoding::UTF8, 64*1024));

	std::unique_ptr<TJsonTextWriter> Writer( new TJsonTextWriter( DestFileStream.get()) );

	try
	{
		Writer->Formatting = TJsonFormatting::Indented;
		Writer->WriteStartObject();
		Writer->WritePropertyName(L"Calendar");
		Writer->WriteStartArray();

		for (auto it = Calendar.cbegin(); it != Calendar.cend(); ++it)
		{
			Writer->WriteStartObject();

			Writer->WritePropertyName(L"date");
			Writer->WriteValue( it->first );

			//Writer->WriteEndObject();

			//Writer->WriteStartObject();
			Writer->WritePropertyName(L"Prepareds");
			Writer->WriteStartArray();

			for (auto itList = it->second.cbegin();
									 itList != it->second.cend(); ++itList)
			{
				Writer->WriteStartObject();
				Writer->WritePropertyName(L"name");
				Writer->WriteValue( String(itList->first.c_str()) );
				Writer->WritePropertyName(L"amount");
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
		ShowMessage(L"Что-то пошло не так при записи файла календаря.");
	}

	IsSaved = true;
	return true;
}
//---------------------------------------------------------------------------

//void CalendarClass::ProcessOneDay(OneDayMap &OneDay, std::auto_ptr<TJsonTextReader> &Reader)
void CalendarClass::ProcessOneDay(TDate _Date, std::unique_ptr<TJsonTextReader> &Reader)
{
	while (Reader->Read())
	{
		if (Reader->TokenType == TJsonToken::StartObject)
		{
			String Name;
			float amount = 0;

			while (Reader->Read())
			{
				if (Reader->TokenType == TJsonToken::PropertyName)
				{
					String Value = Reader->Value.ToString();

					if (Value == L"name")
						Name = Reader->ReadAsString();
					else if (Value == L"amount")
						amount = (float)Reader->ReadAsDouble();

				}
				else if (Reader->TokenType == TJsonToken::EndObject)
				{
					//OneDay.insert( std::make_pair(Name.c_str(), amount) );
					Add(_Date, std::make_pair(Name.c_str(), amount) );
					break;
				}
			}
		}
		else if (Reader->TokenType == TJsonToken::EndArray)
            return;
	}
}
//---------------------------------------------------------------------------

bool CalendarClass::LoadFromJSON(String _FullFileName)
{
	if ( !FileExists(_FullFileName) )
		return false;

	try
	{
		std::unique_ptr<TStreamReader> SrcFileStream(new
					   TStreamReader(_FullFileName, TEncoding::UTF8, false, 64*1024));

		std::unique_ptr<TJsonTextReader> Reader( new TJsonTextReader( SrcFileStream.get()) );

		Calendar.clear();

		while (Reader->Read())
		{
			if (Reader->TokenType == TJsonToken::StartObject)
			{
				TDate Date;

				//OnePreparedPair Prepared;
				//OneDayMap OneDay;

				while (Reader->Read())
				{
					if (Reader->TokenType == TJsonToken::PropertyName)
					{
						String Value = Reader->Value.ToString();

						if (Value == L"date")
							Date = Reader->ReadAsDateTime();
						else if (Value == L"Prepareds")
							ProcessOneDay(Date, Reader);

					}
					else if (Reader->TokenType == TJsonToken::EndObject)
					{
						//Add(Name.c_str(), Prepared);
						break;
					}
				}
            }
		}

	}
	catch(...)
	{
		 ShowMessage(L"Что-то пошло не так при чтении файла календаря");
	}

    IsSaved = true;
	return true;
}
//---------------------------------------------------------------------------
