/*
 ============================================================================
 Name        : DataTable.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 12th, 2019
 Workshop    : Workshop 7 - Home
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
#include <cmath>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>

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

			mean = getSum(false) / dataPairs.size(); 

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
		// calculate and return sum - if first is true return sum of first number in pair(X) and second number (Y) if false 
		//
		double getSum(bool first) const
		{
			std::pair<T, T> data;

			data = std::accumulate(dataPairs.begin(), dataPairs.end(), std::make_pair((T)0, (T)0), [](auto& begin, auto& end) 
			{return std::make_pair(begin.first + end.first, begin.second + end.second); });

			if (first)
			{
				return data.first; 
			}
			else
			{
				return data.second; 
			}
		}

		//calculate and return slope 
		//
		double getSlope() const
		{
			double sumXY = 0.0;
			double sumXSquared = 0.0;
			double slope = 0.0;
			double size = dataPairs.size();

			for (auto &i : dataPairs)
			{
				sumXY += std::get<0>(i) * std::get<1>(i);
				sumXSquared += pow(std::get<0>(i), 2); 
			}

			slope = ((size * sumXY) - ((getSum(true) * getSum(false)))) / ((size * sumXSquared) - (pow(getSum(true), 2)));

			return slope;

		}
		//calculate and return intercept 
		//
		double getIntercept() const
		{
			double intercept = 0; 

			intercept = (getSum(false) - getSlope() * getSum(true)) / dataPairs.size(); 

			return intercept; 
		}
		// calculate and return median 
		//
		T getMedian() const 
		{
			std::vector<std::pair<T, T>> sortedDataPairs(dataPairs.begin(), dataPairs.end()); 

			std::sort(sortedDataPairs.begin(), sortedDataPairs.end(), [](auto  &x, auto &y)
			{
				return x.second < y.second;
			});

			size_t index = sortedDataPairs.size() / 2;

			T median = sortedDataPairs[index].second;

			return median; 
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

		
		// display statistics - display y mean and y sigma (standard deviation) , y median, slope and intercept 
		//
		void displayStatistics(std::ostream& os) const
		{
			os << "Statistics" << std::endl; 
			os << "----------" << std::endl; 

			os << std::setw(FW) << "  y mean    = " << std::setw(FW) << std::setprecision(ND) << getMean() << std::endl; 
			os << std::setw(FW) << "  y sigma   = " << std::setw(FW) << std::setprecision(ND) << getSigma() << std::endl;
			os << std::setw(FW) << "  y median  = " << std::setw(FW) << std::setprecision(ND) << getMedian() << std::endl;
			os << std::setw(FW) << "  slope     = " << std::setw(FW) << std::setprecision(ND) << getSlope() << std::endl;
			os << std::setw(FW) << "  intercept = " << std::setw(FW) << std::setprecision(ND) << getIntercept() << std::endl;
		}
		
	};
}

#endif // !

