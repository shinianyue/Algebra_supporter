//----------------------------------------
//
// Written by Sny 09/19/2023
// Have fun Programing! :3
//
//----------------------------------------
#pragma once
#include <vector>
using std::vector;
namespace AlgebraSup
{
	struct Size_rect
	{
		int x;
		int y;
		bool operator==(Size_rect another_size) {
			if (another_size.x == this->x && another_size.y == this->y) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator!=(Size_rect another_size) {
			if (another_size == *this)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	};
	template<typename T>
	class Matrix
	{
	private: vector<vector<T>>_datas;
			 int _length;//resorved
			 Size_rect size_rect = {0,0};
			 void flush_size() {
				 size_rect.y = _datas.size();
				 if (size_rect.y == 0)
				 {
					 size_rect.x = 0;
				 }
				 else
				 {
					 size_rect.x = _datas[0].size();
				 }
			 }
	public: void append(vector<T> input)
			{
				_datas.push_back(input);
				flush_size();
			}
			int size_x()//return the lenth of the vector;
			{
				return(_datas.size());
			}
			Matrix<T> operator+(Matrix<T> _anotherMatrix)
			{
				if (this->size_rect != _anotherMatrix.size_rect)
				{
					Matrix<T> _tempMatrix;
					
					return _tempMatrix;
				}
				else
				{
					vector<T> _tempVector;
					vector<vector<T>> _temp2dVector;
					for (size_t _y = 0; _y < this->size_rect.y; _y++)
					{
						for (size_t _x = 0; _x < this->size_rect.x; _x++)
						{
							_tempVector.push_back(_datas[_x][_y] + _anotherMatrix._datas[_x][_y]);
						}
						_temp2dVector.push_back(_tempVector);
						_tempVector.clear();
					}
					Matrix<T> _tempMatrix;
					_tempMatrix._datas = _temp2dVector;
					_tempMatrix.flush_size();
					return _tempMatrix;
				}
			}
			
			Matrix<T> operator*(Matrix<T> _another) {
				if (this->size_rect != _another.size_rect)
				{
					Matrix<T> _tempMatrix;

					return _tempMatrix;
				}
				else 
				{
					vector<T> _tempVector;
					vector<vector<T>> _temp2dVector;
					//next_updata:3
					Matrix<T> _tempMatrix;
					_tempMatrix._datas = _temp2dVector;
					_tempMatrix.flush_size();
					return _tempMatrix;
				}
			}
			Matrix<T>() 
			{
				_length = 0;
			}

	};
}