#ifndef _GORGON_BINARY_
#define _GORGON_BINARY_

#define _0b00000001 1
#define _0b00000010 2
#define _0b00000100 4
#define _0b00001111 15
#define _0b00011111 31
#define _0b00111111 63
#define _0b01111111 127
#define _0b11111111 255


namespace Gorgon
{
	class Binary
	{
		private:
			long value;
			int size;
		public:
			Binary(const char& value)
			{
				this->value=0;
				this->value=value;
				size=8*sizeof(char);
			}

			Binary(const short& value)
			{
				this->value=0;
				this->value=value;
				size=8*sizeof(short);
			}

			Binary(const int& value)
			{
				this->value=0;
				this->value=value;
				size=8*sizeof(int);
			}

			void describe() const
			{
				for(int i=0; i<size; ++i)
				{
					printf("%d ",((value >> size-i) & 1));
				}
			}

			int	getValue(const int& pos) const
			{
				return (value >> (size - pos)) & 1;
			}

			long getValue(const int& init=0, const int& end=8)
			{
				value= this->value;
				for( int i=0; i<size; ++i)
				{
				
				}
			}
	};
}
#endif

