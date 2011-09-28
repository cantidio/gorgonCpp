#include <core/zlib.hpp>
#include <zlib.h>
#include <assert.h>
#include <fstream>
#define CHUNK 256

namespace Gorgon{
namespace Core
{
	int Zlib::compress
	(
		std::stringstream&	pSource,
		std::stringstream&	pDest,
		const int&			pLevel
	)
	{
		int ret, flush;
		unsigned have;
		z_stream strm;
		unsigned char in[CHUNK];
		unsigned char out[CHUNK];

		/* allocate deflate state */
		strm.zalloc	= Z_NULL;
		strm.zfree	= Z_NULL;
		strm.opaque	= Z_NULL;
		ret = deflateInit(&strm, pLevel);
		if (ret != Z_OK)
		{
			return ret;
		}

		std::streampos pos;
		long length;
		pos		= pSource.tellg();
		pSource.seekg(0,std::ios::end);
		length	= pSource.tellg();
		pSource.seekg(pos);

		/* compress until end of file */
		do
		{
			strm.avail_in = pSource.readsome((char*)&in,CHUNK);
			if (!pSource.good())
			{
				(void)deflateEnd(&strm);
				return Z_ERRNO;
			}

			flush = (pSource.tellg() == length) ? Z_FINISH : Z_NO_FLUSH;
			strm.next_in = in;
			/* run deflate() on input until output buffer not full, finish
			   compression if all of source has been read in */
			do
			{
				strm.avail_out	= CHUNK;
				strm.next_out	= out;
				ret = deflate(&strm, flush);    /* no bad return value */
				assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
				have = CHUNK - strm.avail_out;
				if(pDest.write((char*)&out,have).bad() || !pDest.good())
				{
					(void)deflateEnd(&strm);
					return Z_ERRNO;
				}
			}while (strm.avail_out == 0);
			assert(strm.avail_in == 0);     /* all input will be used */

			/* done when last data in file processed */
		} while (flush != Z_FINISH);
		assert(ret == Z_STREAM_END);        /* stream will be complete */

		/* clean up and return */
		(void)deflateEnd(&strm);
		return Z_OK;
	}

	int Zlib::decompress(std::stringstream& pSource, std::stringstream& pDest)
	{
		int ret;
		unsigned have;
		z_stream strm;
		unsigned char in[CHUNK];
		unsigned char out[CHUNK];

		/* allocate inflate state */
		strm.zalloc		= Z_NULL;
		strm.zfree		= Z_NULL;
		strm.opaque		= Z_NULL;
		strm.avail_in	= 0;
		strm.next_in	= Z_NULL;
		ret				= inflateInit(&strm);
		if (ret != Z_OK)
		{
			return ret;
		}

		/* decompress until deflate stream ends or end of file */
		do
		{
			strm.avail_in = pSource.readsome((char*)&in,CHUNK); //le a quantidade de dados e salvo o número de dados lidos
			if(!pSource.good())
			{
				(void)inflateEnd(&strm);
				return Z_ERRNO;
			}
			if (strm.avail_in == 0)
			{
				break;
			}
			strm.next_in = in;

			/* run inflate() on input until output buffer not full */
			do
			{
				strm.avail_out	= CHUNK;
				strm.next_out	= out;
				ret = inflate(&strm, Z_NO_FLUSH);
				assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
				switch (ret)
				{
					case Z_NEED_DICT:		ret = Z_DATA_ERROR;     /* and fall through */
					case Z_DATA_ERROR:
					case Z_MEM_ERROR:		(void)inflateEnd(&strm);	return ret;
				}
				have = CHUNK - strm.avail_out;
				if(pDest.write((char*)&out,have).bad() || !pDest.good())//escreve no destino
				{
					(void)inflateEnd(&strm);
					return Z_ERRNO;
				}
			}while (strm.avail_out == 0);

		/* done when inflate() says it's done */
		} while (ret != Z_STREAM_END);
		(void)inflateEnd(&strm);/* clean up and return */
		return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
	}

	void Zlib::passBuffer(std::fstream& pSource, std::stringstream& pDest)
	{
		char buffer[128];
		pSource.seekg(0, std::ios::beg);
		pDest.seekg(0, std::ios::beg);
		int read = 0;
		while((read = pSource.readsome(buffer,sizeof(buffer))) > 0)
		{
			pDest.write(buffer,read);
		}
		pDest.seekg(0, std::ios::beg);
		pSource.seekg(0, std::ios::beg);
	}

	void Zlib::passBuffer(std::stringstream& pSource, std::fstream& pDest)
	{
		char buffer[128];
		pDest.seekg(0, std::ios::beg);
		pSource.seekg(0, std::ios::beg);
		int read = 0;
		while((read = pSource.readsome(buffer,sizeof(buffer))) > 0)
		{
			pDest.write(buffer,read);
		}
		pDest.seekg(0, std::ios::beg);
		pSource.seekg(0, std::ios::beg);
	}
}}
