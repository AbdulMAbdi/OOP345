/*
 ============================================================================
 Name        : DataTable.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 12th, 2019
 Workshop    : Workshop 7 - Lab
 ============================================================================
 */
 /*
  ============================================================================
  Class template for Data Table 
  ============================================================================
 */


#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <fstream>
#include <utility>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

extern int FW; // field width
extern int ND; // precision for numbers

namespace sict
{
	template <class T> 
	class DataTable
	{
		std::vector<std::pair<T, T>> dataPairs; 

	public: 
		//One argument contsructor - creates data pairs from file
		//
		DataTable(std::ifstream& file)
		{
			if (file)
			{
				T x, y; 
				while (file >> x >> y)
				{
					dataPairs.push_back(std::make_pair(x, y)); 
				}
			}
		}
		// calculates and returns mean 
		//
		double getMean() const
		{
			double mean = 0;

			for (auto& i : dataPairs)
			{
				mean += std::get<1>(i);
			}

			mean = mean / dataPairs.size(); 

			return mean;

		}
		//calculate and return standard deviation 
		//
		double getSigma() const
		{
			double sigma = 0; 

			for (auto &i : dataPairs)
			{
				sigma += pow(std::get<1>(i) - getMean(), 2); 
			}

			sigma = sqrt(sigma / (dataPairs.size() - 1)); 

			return sigma; 
		}

		//display function - displays x and y pairs 
	    // 
		void displayData(std::ostream& os) const
		{
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;
			for (auto &i : dataPairs)
			{
				os.setf(std::ios::fixed); 
				os << std::setw(FW) << std::setprecision(ND) << std::get<0>(i)
					<< std::setw(FW) << std::setprecision(ND) << std::get<1>(i) << std::endl;
			}

			os << std::endl; 
		}
		// display statistics - display y mean and y sigma (standard deviation) 
		void displayStatistics(std::ostream& os) const
		{
			os << "Statistics" << std::endl; 
			os << "----------" << std::endl; 
                        os.setf(std::ios::right); 
			os << std::setw(FW) << "  y mean    = " << std::setw(FW) << std::setprecision(ND) << getMean() << std::endl; 
			os << std::setw(FW) << "  y sigma   = " << std::setw(FW) << std::setprecision(ND) << getSigma() << std::endl;
		}
		
	};
}

#endif // !

