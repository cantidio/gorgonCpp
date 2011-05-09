#ifndef _GORGON_KEYBOARD_KEY_
#define _GORGON_KEYBOARD_KEY_
#include <gorgon++/core/gorgon_string.hpp>
namespace Gorgon{
namespace Input
{
	/**
	 * Class that represents a Key
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/05/2011
	 * @version	07/05/2011
	 */
	class Key
	{
		protected:
			int mValue;		/**<< var that holds the value of this key*/
			bool mPressed;	/**<< var that holds if the key is being pressed*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @param	const int& pKeyValue		, the value of the key
			 * @param	const bool& pPressedAscii	, if the key is being pressed
			 */
			inline Key(const int& pKeyValue = 0,const bool& pPressed=false)
			{
				mValue	= pKeyValue;
				mPressed= pPressed;
			}
			/**
			 * Method that returns true if the key is being pressed
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			inline bool isPressed() const
			{
				return  mPressed;
			}
			/**
			 * Method that returns if the key is a number
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			inline bool isNumber() const
			{
				return (mValue >= NUM_1 && mValue <= PAD_0);
			}
			/**
			 * Method that returns if the key is a letter
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			inline bool isLetter() const
			{
				return (mValue >= A && mValue <= Z);
			}
			/**
			 * Method that returns the value of the key
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			inline  int getValue() const
			{
				return mValue;
			}
			/**
			 * Method that returns the name of the key
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	Core::String
			 */
			Core::String getName() const;
			/**
			 * Method that returns if the 2 keys are equal
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			inline bool operator==(const Key& pKey) const
			{
				return (mValue == pKey.mValue);
			}
			/**
			 * Operator that returns if the 2 keys are different
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			inline bool operator!=(const Key& pKey) const
			{
				return (mValue != pKey.mValue);
			}

			enum
			{
				A,
				B,
				C,
				D,
				E,
				F,
				G,
				H,
				I,
				J,
				K,
				L,
				M,
				N,
				O,
				P,
				Q,
				R,
				S,
				T,
				U,
				V,
				W,
				X,
				Y,
				Z,
				NUM_1,
				NUM_2,
				NUM_3,
				NUM_4,
				NUM_5,
				NUM_6,
				NUM_7,
				NUM_8,
				NUM_9,
				NUM_0,
				PAD_1,
				PAD_2,
				PAD_3,
				PAD_4,
				PAD_5,
				PAD_6,
				PAD_7,
				PAD_8,
				PAD_9,
				PAD_0,
				F1,
				F2,
				F3,
				F4,
				F5,
				F6,
				F7,
				F8,
				F9,
				F10,
				F11,
				F12,
				ESCAPE,
				MINUS,
				EQUALS,
				BACKSPACE,
				TAB,
				OPENBRACE,
				CLOSEBRACE,
				ENTER,
				SEMICOLON,
				QUOTE,
				BACKSLASH,
				COMMA,
				SLASH,
				SPACE,
				PRINT_SCREEN,
				PAUSE,
				INSERT,
				DELETE,
				HOME,
				END,
				PAGE_UP,
				PAGE_DOWN,
				LEFT,
				RIGHT,
				UP,
				DOWN,
				PAD_SLASH,
				PAD_MINUS,
				PAD_PLUS,
				PAD_ASTERISK,
				PAD_EQUALS,
				PAD_DELETE,
				PAD_ENTER,
				LEFT_CONTROL,
				RIGHT_CONTROL,
				LEFT_SHIFT,
				RIGHT_SHIFT,
				LEFT_ALT,
				RIGHT_ALT,
				LEFT_WIN,
				RIGHT_WIN,
				MENU,
				SCROOL_LOCK,
				NUM_LOCK,
				CAPS_LOCK,
				KEY_LAST
			};/**<< ENUM with all key values*/
	};
}}
#endif
