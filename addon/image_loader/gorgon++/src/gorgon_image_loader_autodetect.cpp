#include "../include/gorgon_image_loader_autodetect.hpp"

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
	 * @param	ImageLoader*	pImageLoader	, formato a carregar o arquivo
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
		const ImageLoader& pImageLoader
	)
	{
		long initPosition = pFile.tellg();
		try
		{
			pImageLoader.load(pImage,pFile);
			return true;
		}
		catch(const ImageException& e)
		{
			pFile.seekg(initPosition); //retorna o ponteiro
			return false;
		}
	}

	ImageLoader* ImageLoaderAutodetect::guessFormat(const std::string& pImageName) const
	{
		if(Core::File::extensionIs(pImageName,".bmp"))		return new ImageLoaderBmp();
		else if(Core::File::extensionIs(pImageName,".pcx"))	return new ImageLoaderPcx();
		/*else if(File::extensionIs(pImageName,".png"))	return new ImageLoaderPng();
		else if(File::extensionIs(pImageName,".gif"))	return new ImageLoaderGif();*/
		return new ImageLoaderUnknown();
	}

	void ImageLoaderAutodetect::load(Image& pImage,const std::string& pImageName) const
	{
		ImageLoader* tip = guessFormat(pImageName);	//primeiramente olha se no nome do arquivo tem alguma dica sobre o formato do mesmo
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

	void ImageLoaderAutodetect::load(Image& pImage, Core::File& pFile) const
	{
		//tenta carregar as imagens por ordem de formatos mais comuns
		if
		(
			!(
				tryLoadFormat(pImage,pFile,ImageLoaderBmp()) ||
				tryLoadFormat(pImage,pFile,ImageLoaderPcx()) /*||
				tryLoadFormat(pImage,pFile,ImageLoaderPng()) ||
				tryLoadFormat(pImage,pFile,ImageLoaderGif())*/
			)
		)
		{
			throw ImageException("format unknown.");
		}
	}

	void ImageLoaderAutodetect::save(Image& pImage, const std::string& pImageName) const
	{
		ImageLoaderBmp defaultFormat;
		defaultFormat.save(pImage,pImageName); //salva em bmp, por ser o formato padrão
	}

	void ImageLoaderAutodetect::save(Image& pImage, Core::File& pFile) const
	{
		ImageLoaderBmp defaultFormat;
		defaultFormat.save(pImage,pFile);  //salva em bmp, por ser o formato padrão
	}
}
