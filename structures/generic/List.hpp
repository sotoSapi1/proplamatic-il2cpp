#pragma once
#include <memory>
#include <cstring>
#include "Array.hpp"

namespace IL2CPP
{
	template <typename T>
	struct List : private Object
	{
		private:
		Array<T>* items;
		int32_t size;
		int32_t version;
		IMPORT::Il2CppObject* syncRoot;

		public:	
		int32_t GetSize()
		{
			return this->size;
		}

		T Get(int index)
		{	
			if(index >= GetSize())
			{
				throw Exception::IndexOutOfBounds(
					index,
					GetSize()
				);
			}
			
			return items->vector[index];
		}

		void Set(int index, T value)
		{
			if(index >= GetSize())
			{
				throw Exception::IndexOutOfBounds(
					index,
					GetSize()
				);
			}
			
			items->vector[index] = value;
		}

		void ForEach(std::function<void(T)> func)
		{
			for (int i = 0; i < size; ++i)
			{
				func(items->vector[i]);
			}
		}

		void ForEach(std::function<void(T, int)> func)
		{
			for (int i = 0; i < size; ++i)
			{
				func(items->m_Ivectortems[i], i);
			}
		}
	};

}

