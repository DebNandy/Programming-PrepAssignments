//  Programming Prep, Fall 2018
//  Homework 1.1
//  File:  hw1.1.cpp
//  Authors:  DEBAJYOTI NANDY and PALLAV RAJ
//  Description:  The program parses through CME SPAN file information and
//			      extracts expiration date and price related information
//				  for Crude Oil and Natural Gas Futures and Options listed
//				  under CME Globex, and stores it in a separate file.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() 
{
	//Declare the location and lengths of data in interest from SPAN files
	const int record_id_start = 1;
	const int record_id_length = 2;
	const int B_commodity_code_start = 6;
	const int B_commodity_code_length = 10;
	const int B_product_type_code_start = 16;
	const int B_product_type_code_length = 3;
	const int B_contract_month_start = 19;
	const int B_contract_month_length = 6;
	const int B_settlement_date_start = 92;
	const int B_settlement_date_length = 8;
	const int B_underlying_commod_code_start = 100;
	const int B_underlying_commod_code_length = 10;
	
	const int Eight_commodity_code_start = 6;
	const int Eight_commodity_code_length = 10;
	const int Eight_option_type_start = 29;
	const int Eight_option_type_length = 1;
	const int Eight_contract_month_start = 30;
	const int Eight_contract_month_length = 6;
	const int Eight_underlying_commod_code_start = 16;
	const int Eight_underlying_commod_code_length = 10;
	const int Eight_options_strike_price_start = 48;
	const int Eight_options_strike_price_length = 7;
	const int Eight_one_settlement_price_start = 109;
	const int Eight_one_settlement_price_length = 14;
	const int Eight_two_settlement_price_start = 111;
	const int Eight_two_settlement_price_length = 7;
	ifstream infile;
	ofstream outfile;
	outfile.open("CL_and_NG_expirations_and_settlements.txt ");
	infile.open("cme.20180727.c.pa2");
	string data, record_id, commodity_code, product_type_code, short_code, contract_month, settlement_date;
	string contract_type, underlying_commod_code, empty_date, option_type, option_strike_price, settlement_price;
	int contract_month_number;
	double price_factor, settlement_price_value, option_strike_price_value;
	while (!infile.eof())
	{
		std::getline(infile, data);
		if (size(data))
		{
			record_id = data.substr(record_id_start - 1, record_id_length);
			if(record_id == "B ")
			{
				commodity_code = data.substr(B_commodity_code_start - 1, B_commodity_code_length);
				short_code = commodity_code.substr(0, 3);
				if (short_code == "CL " || short_code == "LO " || short_code == "NG " || short_code == "ON ")
				{
					contract_month = data.substr(B_contract_month_start - 1, B_contract_month_length);
					//Converting to integer as I can filter the desired range of contract month
					contract_month_number = stoi(contract_month);
					if (contract_month_number >= 201810 && contract_month_number <= 202012)
					{
						contract_month = contract_month.substr(0, 4) + '-' + contract_month.substr(4, 2);
						product_type_code = data.substr(B_product_type_code_start - 1, B_product_type_code_length);
						settlement_date = data.substr(B_settlement_date_start - 1, B_settlement_date_length);
						settlement_date = settlement_date.substr(0, 4) + '-' + settlement_date.substr(4, 2) + '-' + settlement_date.substr(6,2);
						string empty_date(settlement_date.size(), ' ');
						if (short_code == "LO " || short_code == "ON ")
						{
							underlying_commod_code = data.substr(B_underlying_commod_code_start-1, B_underlying_commod_code_length);
							contract_type = "Opt";
							outfile << underlying_commod_code << " " << contract_month << " " << contract_type << " "
									<< empty_date << " " << commodity_code<< " " << settlement_date << " " << "\n";
						}
						else
						{
							contract_type = "Fut";
							string empty_commodity_code(commodity_code.size(), ' ');
							outfile << commodity_code << " " << contract_month << " " << contract_type << " " 	
									<< settlement_date << " " << empty_commodity_code << " "<< empty_date << "\n";
						};
					}		
				}
			}
			else if (record_id[0] == '8')
			{
				commodity_code = data.substr(Eight_commodity_code_start - 1, Eight_commodity_code_length);
				short_code = commodity_code.substr(0, 3);
				if (short_code == "CL " || short_code == "LO " || short_code == "NG " || short_code == "ON ")
				{
					contract_month = data.substr(Eight_contract_month_start - 1, Eight_contract_month_length);
					//Converting to integer as I can filter the desired range of contract month
					contract_month_number = stoi(contract_month);
					if (contract_month_number >= 201810 && contract_month_number <= 202012)
					{
						contract_month = contract_month.substr(0, 4) + '-' + contract_month.substr(4, 2);
						//Price adjustment factors based on online documentation and min. fluctuation info
						if (short_code == "CL " || short_code == "LO ")
							price_factor = 0.01;
						else if (short_code == "NG ")
							price_factor = 0.00001;
						else if (short_code == "ON ")
							price_factor = 0.0001;
						option_strike_price = data.substr(Eight_options_strike_price_start - 1, Eight_options_strike_price_length);
						unsigned int option_strike_price_size = option_strike_price.size();
						if (short_code == "ON ")
							option_strike_price_value = stof(option_strike_price) * 0.001;
						else option_strike_price_value = stof(option_strike_price) * price_factor;
						option_strike_price = to_string(option_strike_price_value);
						if(record_id[1] == '1')
							settlement_price = data.substr(Eight_one_settlement_price_start - 1, Eight_one_settlement_price_length);
						else settlement_price = data.substr(Eight_two_settlement_price_start - 1, Eight_two_settlement_price_length);
						unsigned int settlement_price_size = settlement_price.size();
						settlement_price_value = stof(settlement_price) * price_factor;
						string empty_option_strike_price(option_strike_price_size, ' ');
						if (short_code == "LO " || short_code == "ON ")
						{
							option_type = data.substr(Eight_option_type_start - 1, Eight_option_type_length);
							underlying_commod_code = data.substr(Eight_underlying_commod_code_start - 1, Eight_underlying_commod_code_length);
							if(option_type[0] == 'P')
								 option_type = "Put ";
							else option_type = "Call";

							outfile << underlying_commod_code << " " << contract_month << " " << option_type << " "
									<< setw(option_strike_price_size) << option_strike_price_value <<  " " 
									<< setw(7)<< settlement_price_value << "\n";
						}
						else
						{
							contract_type = "Fut ";
							outfile << commodity_code << " " << contract_month << " " << contract_type << " " 
									<< empty_option_strike_price << " " << setw(7) << settlement_price_value << "\n";
						};
					}
				}
			}
		}
	}
	infile.close();
	outfile.close();

/*
Snapshot of output
	    Futures   Contract   Contract   Futures     Options   Options
		Code      Month      Type       Exp Date    Code      Exp Date
		------ - --------   --------   --------    ------ - --------
		CL        2018 - 10    Fut        2018 - 09 - 20
		CL        2018 - 11    Fut        2018 - 10 - 20
		CL        2018 - 10    Opt                    LO        2018 - 09 - 17
		CL        2018 - 11    Opt                    LO        2018 - 10 - 17

		Futures   Contract   Contract   Strike   Settlement
		Code      Month      Type       Price    Price
		-------   --------   --------   ------   ----------
		CL        2018-10    Fut                   67.73
		CL        2018-11    Fut                   67.36
		… and so forth, through contract month 2020-12 …
		CL        2018-10    Call       5.50       62.48
		CL        2018-10    Put        5.50        0.01

*/
}
