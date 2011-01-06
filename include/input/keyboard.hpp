namespace Gorgon{
namespace Input
{
	class Key
	{
		std::vector<bool>
	};
	enum key
	{
		A,
		B
	};
	class Keyboard
	{
		private:
			Keyboard* mSingleton;
			Keyboard();
			~Keyboard();
		public:
			
			bool isKeyPressed() const;
	};
}}
