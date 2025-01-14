#pragma once
#include "../Main.hpp"

namespace IL2CPP
{
	namespace Wrapper
	{
		template <typename T>
		class Field
		{
			private:
			Object* obj;
			FieldInfo* info;

			public:
			Field(Object* obj, const std::string& name, int indexOffset = 0)
			{
				if (obj == nullptr)
				{
					throw Exception::NullArgument(IL2CPP_NAMEOF(obj));
				}

				this->obj = obj;
				
				for (size_t i = 0; i < obj->GetClass()->FieldCount(); i++)
				{
					FieldInfo* currentInfo = obj->GetClass()->GetField(i);

					if (currentInfo->GetName() == name)
					{
						this->info = obj->GetClass()->GetField(i + indexOffset);
					}
				}
			}

			Field(Object* obj, int index)
			{
				if (obj == nullptr)
				{
					throw Exception::NullArgument(IL2CPP_NAMEOF(obj));
				}

				this->obj = obj;
				this->info = obj->GetClass()->GetField(index);
			}

			inline T Get()
			{
				return info->GetValue(obj);
			}

			inline void operator=(T value)
			{
				info->SetValue(obj, value);
			}
		};
	}
}