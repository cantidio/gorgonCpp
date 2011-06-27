#include <gorgon++/core/gorgon_string.hpp>
#include <gorgon++/core/gorgon_file.hpp>
#include <gorgon++/addon/animationpack/gorgon_animationpack_lua.hpp>

using namespace Gorgon;
using namespace Gorgon::Core;
using namespace Gorgon::Graphic;

inline bool checkComment(String& pString)
{
	pString.replace(" ", "");
	return (pString[0] == ';' || pString.length() == 0 ) ? true : false; 
}

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf("./air_to_gap.e [in].air [out].gap\n");
		return 0;
	}
	File a( argv[1] , std::ios::in);
	AnimationPack gap;
	Animation* anim = NULL;
	
	while(!a.eof())
	{
		String str;
		std::getline(a,str);
		
		if ( checkComment(str) )	continue; //pula comentários e linhas em branco
		str.toLower();
		if(str.substr(0,12) == ("[beginaction"))//Action
		{
			if(anim != NULL)
			{
				gap.add(*anim);
				delete anim;
				anim = NULL;
			}
			str.replace("[beginaction", "");
			str.replace("]", "");
			anim = new Animation();
			anim->setGroup( atoi( str.c_str() ) );
			anim->setLooping(true);
			anim->setLoopFrame(0);
			anim->setIndex(0);
			anim->setRepeatNumber(-1);
			printf("Begin Action: %d\n",anim->getGroup());
		}
		else if(str.substr(0,4) == "clsn")			//caixa de colisão
		{}
		else if( str.substr(0,9) == "loopstart")	//registra o loop
		{
			anim->setLoopFrame( anim->getSize() );
		}
		else										//Frame
		{
			std::vector<String> pieces = str.explode(",");
			if(pieces.size() >= 5)
			{
				Frame frame;
				frame.setGroup	( atoi( pieces[0].c_str() ));
				frame.setIndex	( atoi( pieces[1].c_str() ));
				frame.setXOffset( atoi( pieces[2].c_str() ));
				frame.setYOffset( atoi( pieces[3].c_str() ));
				frame.setTime	( atoi( pieces[4].c_str() ));
			
				if(pieces.size() >= 6)
				{
					if(pieces[5].length() > 0)
					{
						if(pieces[5].substr(0,2) == "hv")		frame.setMirroring(Mirroring::HVFlip);
						else if(pieces[5].substr(0,1) == "h")	frame.setMirroring(Mirroring::HFlip);
						else if(pieces[5].substr(0,1) == "v")	frame.setMirroring(Mirroring::VFlip);
					}
				}
				anim->add(frame);
			}
		}
	}
	if(anim != NULL)
	{
		gap.add(*anim);
		delete anim;
		anim = NULL;
	}
	gap.save(argv[2]);
	return 0;
}

