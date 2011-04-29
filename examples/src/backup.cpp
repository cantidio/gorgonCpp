#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/image_loader/magick++/gorgon_image_loader.hpp>
#include <gorgon++/addon/spritepack/spritepack_sff.hpp>
#include <gorgon++/addon/spritepack/spritepack_lua.hpp>

using namespace Gorgon;
/*
namespace Gorgon{
namespace Core
{
	class String : public std::string
	{
		public:
		String() {}
		String(const String& pString) : std::string(pString) {}
		String(const std::string& pString) : std::string(pString) {}
		String(const char* pString) : std::string(pString) {}

		std::vector<String> explode(const String& pDelimiter) const
		{
			std::vector<String>		pieces;
			std::string::size_type	lastPos = find_first_not_of(pDelimiter, 0);
			std::string::size_type	pos     = find_first_of(pDelimiter, lastPos);

			while (std::string::npos != pos || std::string::npos != lastPos)
			{
				pieces.push_back(String(substr(lastPos, pos - lastPos)));
				lastPos	= find_first_not_of(pDelimiter, pos);
				pos		= find_first_of(pDelimiter, lastPos);
			}
			return pieces;
		}
	};
}}

class SP : public SpritePack
{
	public:
	SP(const Core::String& pFileName)
	{
		if(mNotFound == NULL)
		{
			mNotFound = new Sprite(Image(1,1));
		}
		load(pFileName);
	}
	
	void saveScript(const Core::String& pFileName)
	{
		Core::File file(pFileName,std::ios::out);
		std::vector<Core::String> pieces;
		Core::String subfilename;
		Core::String dir;

		pieces = pFileName.explode("/");
		for(unsigned int i = 0; i < pieces.size() - 1; ++i)
		{
			dir.append(pieces[i]);
			dir.append("/");
		}
		pieces = pieces.back().explode(".");
		subfilename.append(pieces[0]);
		for(unsigned int i = 1; i < pieces.size() - 1; ++i)
		{
			subfilename.append(".");
			subfilename.append(pieces[i]);
		}

		if(file.is_open())
		{
			file << "spritepack = {\n";
			for(unsigned int i = 0; i < getSize(); ++i)
			{
				std::stringstream filename;
				filename << dir << subfilename << "_image_" << i << ".bmp";
				((Image)(*this)[i]).save(filename.str());

				file << "\t{\n";
				file << "\t\tgroup   = " << (*this)[i].getGroup()	<< ",\n";
				file << "\t\tindex   = " << (*this)[i].getIndex()	<< ",\n";
				file << "\t\txoffset = " << (*this)[i].getXOffset()	<< ",\n";
				file << "\t\tyoffset = " << (*this)[i].getYOffset()	<< ",\n";
				file << "\t\timage   = " << "\"" << subfilename << "_image_" << i << ".bmp\"\n";
				file << "\t},\n";
			}
			file << "}";
		}
	}
};


int main()
{
	allegro_init();
	Video::init("teste",10,10,false);
	
//	Gorgon::ImageLoader::setLoader(new Gorgon::ImageLoaderAutodetect());//inicia o loader padrão da gorgon


	SP a("tests/background/saveroom/SaveRoom_layer_2.gspk");
	a.saveScript("tests/background/saveroom/layer2/layer_SP.lua");
	
	return 0;
}
*/

int main(int argc, char** argv)
{
	if(argc < 2 ) return 0;
	allegro_init();
	Video::init("teste",320,240,false);
	ImageLoader::setLoader(new ImageLoaderMagick());
	ImageLoader::getLoader().setSaveFormat("PNG");
	
	SpritePackSff a(argv[1]);
	
//	Palette C("/home/cantidio/Downloads/mugen/shigen/Shigen01.act");
//	C.setColor(255,0,255,0);
//	a.setGlobalPalette(&C);
	a.applyGlobalPalette(true);
	
	//a.saveScript("grant.lua");
	a.save("/home/cantidio/Dev/gorgon++/examples/bin/stage.gsp");
	SpritePackLua b(a);
	b.save("/home/cantidio/Dev/gorgon++/examples/bin/stage.lua");
	printf("pronto\n");
	return 0;
}

