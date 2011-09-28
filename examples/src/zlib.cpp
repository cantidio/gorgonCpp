#include "gorgon++/gorgon.hpp"

int main(int argc, char **argv)
{
	std::stringstream a(std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	std::stringstream b(std::ios_base::in | std::ios_base::out | std::ios_base::binary);

	std::fstream file("mammon.gspk");
	Gorgon::Zlib::passBuffer(file,a);

	Gorgon::Zlib::compress(a,b,7);

	std::fstream file2("lemin2.gspk",std::ios_base::out | std::ios_base::binary);
	Gorgon::Zlib::passBuffer(b,file2);

	file.close();
	file2.close();
	return 0;
}

