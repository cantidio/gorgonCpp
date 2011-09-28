#include <gorgon++/gorgon.hpp>
using namespace Gorgon;
using namespace std;
int main()
{
	Lua coiso("../resources/teste.lua");
	vector<LuaParam> param;

	double	a=coiso.function("teste",Gorgon::LuaParam("dd",13.3,12.2))->getNumericValue();
	cout <<  ">" << a << "\n";
	return 0;
}

