#pragma once
#include <format>
#include "../Main.hpp"

namespace IL2CPP
{
	namespace Exception
	{
		class UnexpectedError : public ExceptionBase
		{
			public:
			explicit UnexpectedError() : ExceptionBase()
			{
				InitializeException(
					IL2CPP_NAMEOF(UnexpectedError),
					"Unexpected error occurred during runtime."
				);
			}
		};
	}
}