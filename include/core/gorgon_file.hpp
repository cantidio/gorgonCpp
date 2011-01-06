/*
 *
 *    __     ___   _ __    __     ___     ___
 *  /'_ `\  / __`\/\`'__\/'_ `\  / __`\ /' _ `\
 * /\ \L\ \/\ \L\ \ \ \//\ \L\ \/\ \L\ \/\ \/\ \
 * \ \____ \ \____/\ \_\\ \____ \ \____/\ \_\ \_\
 *  \/___L\ \/___/  \/_/ \/___L\ \/___/  \/_/\/_/
 *    /\____/              /\____/
 *    \_/__/               \_/__/
 *
 *  Copyright (C) 2008-2010  Cantidio Oliveira Fontes
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#ifndef _GORGON_FILE_
#define	_GORGON_FILE_
#include <fstream>
#include <string>
/*
#ifdef __BYTE_ORDER
   # if __BYTE_ORDER == __LITTLE_ENDIAN
   #  define I_AM_LITTLE_ENDIAN
   # else
   #  if __BYTE_ORDER == __BIG_ENDIAN
   #   define I_AM_BIG_ENDIAN
   #  else
       Error: unknown byte order!
   #  endif
   # endif
   #endif

   int am_big_endian()
  {
     long one= 1;
     return !(*((char *)(&one)));
  }

Or an alternate version using unions (based on Harbison & Steele):

  int am_big_endian()
  {
      union { long l; char c[sizeof (long)]; } u;
      u.l = 1;
      return (u.c[sizeof (long) - 1] == 1);
  }
 */

namespace Gorgon{
namespace Core
{
	/**
	 * Classe responsável por lidar com arquivos em suma binários
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	21/06/2009
	 * @version	05/08/2009
	 */
	class File : public std::fstream
	{
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 */
			File();
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const std::string&		pFileName	, nome do arquivo a ser aberto
			 * @param	std::ios_base::openmode	pMode		, modo de abertura do arquivo
			 */
			File(const std::string& pFileName,std::ios_base::openmode pMode);
			/**
			 * Método Destrutor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 */
			virtual ~File();
			/**
			 * Método para retornar o tamanho do arquivo em bytes
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	21/06/2009
			 * @return	long
			 */
			long getSize();
			/**
			 * Método para escrever um inteiro de 8 bits no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const char& pInt8 , valor a ser escrito
			 */
			void writeInt8(const char& pInt8);
			/**
			 * Método para escrever um inteiro de 16 bits no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const char& pInt16 , valor a ser escrito
			 */
			void writeInt16(const short& pInt16);
			/**
			 * Método para escrever um inteiro de 32 bits no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const char& pInt32 , valor a ser escrito
			 */
			void writeInt32(const int& pInt32);
			/**
			 * Método para escrever um inteiro de 64 bits no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const char& pInt64 , valor a ser escrito
			 */
			void writeInt64(const long& pInt64);
			/**
			 * Método para escrever um float no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const float& pFloat, valor a ser escrito
			 */
			void writeFloat(const float& pFloat);
			/**
			 * Método para escrever um double no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const double& pDouble , valor a ser escrito
			 */
			void writeDouble(const double& pDouble);
			/**
			 * Método para escrever um bool no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	21/06/2009
			 * @param	const bool& pBool, valor a ser escrito
			 */
			void writeBool(const bool& pBool);
			/**
			 * Método para escrever uma string no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const std::string& pString, string a ser escrita
			 */
			void writeString(const std::string& pString);
			/**
			 * Método para escrever uma string de chars no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const char*	pString		, vetor de chars a ser escrito no arquivo
			 * @param	const int&	pStringSize	, tamanho do vetor
			 */
			void writeCharString(const char* pString, const int& pStringSize);
			/**
			 * Método para ler um inteiro de 8 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @return	char
			 */
			char readInt8();
			/**
			 * Método para ler um inteiro sem sinal de 8 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @return	unsigned char
			 */
			unsigned char readUnsignedInt8();
			/**
			 * Método para ler um inteiro de 16 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @return	short
			 */
			short readInt16();
			/**
			 * Método para ler um inteiro sem sinal de 16 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @return	unsigned short
			 */
			unsigned short readUnsignedInt16();
			/**
			 * Método para ler um inteiro de 32 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @return	int
			 */
			int readInt32();
			/**
			 * Método para ler um inteiro sem sinal de 32 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @return	unsigned int
			 */
			unsigned int readUnsignedInt32();
			/**
			 * Método para ler um inteiro de 64 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @return	long
			 */
			long readInt64();
			/**
			 * Método para ler um inteiro sem sinal de 64 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @return	unsigned long
			 */
			unsigned long readUnsignedInt64();
			/**
			 * Método para ler um float do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @return	float
			 */
			float readFloat();
			/**
			 * Método para ler um double do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @return	double
			 */
			double readDouble();
			/**
			 * Método para ler um bool do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @return	bool
			 */
			bool readBool();
			/**
			 * Método para ler uma string do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const int& pStringSize, tamanho da string a ser lida
			 * @return	std::string
			 */
			std::string readString(const int& pStringSize);
			/**
			 * Método para ler um vetor de chars do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	const int& pStringSize, tamanho da string a ser lida
			 * @return	const char*
			 * @details
			 *			Esse método aloca a memória suficiente para o vetor, para desalocar a memória, deve-se
			 * desaloca-la com delete
			 */
			const char* readCharString(const int& pStringSize);
			/**
			 * Método para ler um inteiro de 8 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	06/08/2009
			 * @param	char& pInt8, variável a receber o valor lido
			 */
			void readInt8(char& pInt8);
			/**
			 * Método para ler um inteiro sem sinal de 8 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @param	unsigned char& pInt8, variável a receber o valor lido
			 */
			void readUnsignedInt8(unsigned char& pInt8);
			/**
			 * Método para ler um inteiro de 16 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	06/08/2009
			 * @param	short& pInt16, variável a receber o valor lido
			 */
			void readInt16(short& pInt16);
			/**
			 * Método para ler um inteiro sem sinal de 16 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @param	unsigned short& pInt16, variável a receber o valor lido
			 */
			void readUnsignedInt16(unsigned short& pInt16);
			/**
			 * Método para ler um inteiro de 32 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	06/08/2009
			 * @param	int& pInt32, variável a receber o valor lido
			 */
			void readInt32(int& pInt32);
			/**
			 * Método para ler um inteiro sem sinal de 32 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @param	unsigned int& pInt32, variável a receber o valor lido
			 */
			void readUnsignedInt32(unsigned int& pInt32);
			/**
			 * Método para ler um inteiro de 64 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	06/08/2009
			 * @param	long& pInt64, variável a receber o valor lido
			 */
			void readInt64(long& pInt64);
			/**
			 * Método para ler um inteiro sem sinal de 64 bits do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/08/2009
			 * @final	06/08/2009
			 * @param	unsigned long& pInt64, variável a receber o valor lido
			 */
			void readUnsignedInt64(unsigned long& pInt64);
			/**
			 * Método para ler um float do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	float& pFloat, variável a receber o valor lido
			 */
			void readFloat(float& pFloat);
			/**
			 * Método para ler um double do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	double& pDouble, variável a receber o valor lido
			 */
			void readDouble(double& pDouble);
			/**
			 * Método para ler um bool do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	bool& pBool, variável a receber o valor lido
			 */
			void readBool(bool& pBool);
			/**
			 * Método para ler uma string do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	std::string& pString, variável a receber a string lida
			 * @param	const int& pStringSize, tamanho da string lida
			 */
			void readString(std::string& pString,const int& pStringSize);
			/**
			 * Método para ler uma string do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @final	21/06/2009
			 * @param	char*& pString, variável a receber a string lida, já deve estar alocada previamente
			 * @param	const int& pStringSize, tamanho da string lida
			 */
			void readCharString(char*& pString,const int& pStringSize);
			/**
			 * Método que retorna se o nome de um arquivo passado é de uma extenção fornecida
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @final	05/08/2009
			 * @param	const std::string& pFileName	, nome completo do arquivo
			 * @param	const std::string& pExtension	, extenção a ser verificada
			 * @return	bool
			 */
			static bool extensionIs(const std::string& pFileName,const std::string& pExtension);

			/**
			 * Método para comprimir os dados do arquivo usando a Zlib
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/04/2010
			 * @version	21/04/2010
			 */
			void compressZlib();
			/**
			 * Método para descomprimir os dados do arquivo usando a Zlib
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/04/2010
			 * @version	21/04/2010
			 */
			void decompressZlib();
	};
}}
#endif
