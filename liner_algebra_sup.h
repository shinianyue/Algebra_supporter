//----------------------------------------
//
// Written by Sny 09/19/2023
// Have fun Programing! :3
//
//----------------------------------------
#pragma once
#include <vector>
namespace AlgebraSup
{
	template<typename T>
	class Vec
	{
	private: std::vector<T>_datas;
			 int _length;//resorved
	public: void append(T input)//inset a new data;
	{
		_datas.push_back(input);
	}
			int length()//return the lenth of the vector;
	{
		return(_datas.size());
	}
			Vec<T> operator+(Vec<T> _another)
			{
				if (this->length() != _another.length())
				{
					return Vec<T>(-1);
				}
				else
				{
					std::vector<T> temp;
					for (int Po = 0; Po < this->length(); Po++)
					{
						temp.push_back(this->_datas[Po] + _another._datas[Po]);
					}
					Vec<T> result(temp);
					return result;
				}
			}
			Vec<T>(int error_num) 
			{
				_datas = { error_num };
			}
			Vec<T>(std::vector<T> _numbers) 
			{
				_datas = _numbers;
			}
			Vec<T>() 
			{
				_length = 0;
			}

	};
}