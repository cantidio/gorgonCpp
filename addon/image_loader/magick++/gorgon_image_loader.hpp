#include <gorgon++/gorgon.hpp>

namespace Gorgon
{
	/**
	 * Classe que representa o loader de imagens da lib Magick++
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/01/2011
	 * @version	08/01/2011
	 */
	class ImageLoaderMagick : public ImageLoader
	{
		public:
			ImageLoaderMagick(char* pRunDir = NULL);
			/**
			 * Método genérico para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	07/01/2011
			 * @param	Image&				pImage		, destino da imagem a ser carregada
			 * @param	const std::string	pImageName	, nome da imagem a ser carregada
			 */
			virtual void load(Image& pImage, const std::string& pImageName) const;
			/**
			 * Método genérico para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	07/01/2011
			 * @param	Image&		pImage			, destino da imagem a ser carregada
			 * @param	File&		pFile			, arquivo onde a imagem está
			 * @param	const int&	pSizeOfImage	, tamanho da imagem a ser carregada
			 */
			virtual void load
			(
				Image&		pImage,
				Core::File&	pFile,
				const int&	pSizeOfImage
			) const;
			/**
			 * Método genérico para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	08/01/2011
			 * @param	Image&	pImage	, destino da imagem a ser carregada
			 * @param	File&	pFile	, arquivo onde a imagem está
			 * @todo	permitir passar o tipo de imagem a ser salva
			 */
			virtual void save(Image& pImage, Core::File& pFile) const;
			/**
			 * Método genérico para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	08/01/2011
			 * @param	Image&				pImage		, destino da imagem a ser carregada
			 * @param	const std::string	pImageName	, nome da imagem a ser carregada
			 */
			virtual void save(Image& pImage, const std::string& pImageName) const;
	};
}
