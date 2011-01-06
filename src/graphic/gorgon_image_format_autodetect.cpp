#include "graphic/gorgon_image_format_autodetect.hpp"

namespace Gorgon
{
	/**
	 * Função que tenta carregar uma imagem de um determinado formato
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	05/08/2009
	 * @version	06/08/2009
	 * @param	Image&			pImage			, imagem que receberá a imagem carregada
	 * @param	File&			pFile			, arquivo que a imagem supostamente está
	 * @param	ImageFormat*	pImageFormat	, formato a carregar o arquivo
	 * @return	bool
	 * @details
	 *			Esse método tenta carregar a imagem a partir do arquivo cedido,
	 * se não conseguir, retorna o ponteiro do arquivo para a posição inicial quando
	 * foi chamada, e retorna false, se conseguir carregar a imagem, retorna verdadeiro e
	 * a imagem pImage recebe o conteúdo do arquivo carregado
	 */
	inline bool tryLoadFormat
	(
		Image& pImage,
		Core::File& pFile,
		const ImageFormat& pImageFormat
	)
	{
		long initPosition = pFile.tellg();
		try
		{
			pImageFormat.load(pImage,pFile);
			return true;
		}
		catch(const ImageException& e)
		{
			pFile.seekg(initPosition); //retorna o ponteiro
			return false;
		}
	}

	ImageFormat* ImageFormatAutodetect::guessFormat(const std::string& pImageName) const
	{
		if(Core::File::extensionIs(pImageName,".bmp"))		return new ImageFormatBmp();
		else if(Core::File::extensionIs(pImageName,".pcx"))	return new ImageFormatPcx();
		/*else if(File::extensionIs(pImageName,".png"))	return new ImageFormatPng();
		else if(File::extensionIs(pImageName,".gif"))	return new ImageFormatGif();*/
		return new ImageFormatUnknown();
	}

	void ImageFormatAutodetect::load(Image& pImage,const std::string& pImageName) const
	{
		ImageFormat* tip = guessFormat(pImageName);	//primeiramente olha se no nome do arquivo tem alguma dica sobre o formato do mesmo
		try
		{
			tip->load(pImage,pImageName);
			delete tip;
		}
		catch(const ImageException& e) // se não conseguir carregar do formato da extenção, carrega pela força bruta
		{
			delete tip;
			Core::File file(pImageName,std::ios::binary | std::ios::in);
			load(pImage,file);
		}
	}

	void ImageFormatAutodetect::load(Image& pImage, Core::File& pFile) const
	{
		//tenta carregar as imagens por ordem de formatos mais comuns
		if
		(
			!(
				tryLoadFormat(pImage,pFile,ImageFormatBmp()) ||
				tryLoadFormat(pImage,pFile,ImageFormatPcx()) /*||
				tryLoadFormat(pImage,pFile,ImageFormatPng()) ||
				tryLoadFormat(pImage,pFile,ImageFormatGif())*/
			)
		)
		{
			throw ImageException("format unknown.");
		}
	}

	void ImageFormatAutodetect::save(Image& pImage, const std::string& pImageName) const
	{
		ImageFormatBmp defaultFormat;
		defaultFormat.save(pImage,pImageName); //salva em bmp, por ser o formato padrão
	}

	void ImageFormatAutodetect::save(Image& pImage, Core::File& pFile) const
	{
		ImageFormatBmp defaultFormat;
		defaultFormat.save(pImage,pFile);  //salva em bmp, por ser o formato padrão
	}
}
