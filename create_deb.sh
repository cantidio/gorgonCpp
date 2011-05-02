#!/bin/sh
PACKAGE_DIR='DEB_PACKAGE/'
LIB_LOCATION='Gorgon++_eclipse/Release/libgorgon.so'
ADDON_LOCATION='Gorgon++_eclipse/Addon/libgorgon_addon.so'
#
# Funćão que cria o script de configuraćão da biblioteca Gorgon
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
# @param	svnRev, número da revisão svn
#
CREATE_GORGON_CONFIG()
{
	echo "\tCriando arquivo de configuraćão da biblioteca"
	GORGON_CONFIG=''
	GORGON_CONFIG=$GORGON_CONFIG'#!/bin/sh\n'
	GORGON_CONFIG=$GORGON_CONFIG'usage()\n'
	GORGON_CONFIG=$GORGON_CONFIG'{\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\tcat <<EOF\n'
	GORGON_CONFIG=$GORGON_CONFIG'Usage: gorgon-config [OPTIONS]\n'
	GORGON_CONFIG=$GORGON_CONFIG'Options:\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\t[--prefix]\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\t[--version]\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\t[--libs]\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\t[--addons]\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\t[--addons_sdl]\n'
	GORGON_CONFIG=$GORGON_CONFIG'EOF\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\texit $1\n'
	GORGON_CONFIG=$GORGON_CONFIG'}\n\n'
	GORGON_CONFIG=$GORGON_CONFIG'if test $# -eq 0; then\n'
	GORGON_CONFIG=$GORGON_CONFIG'    \tusage 1 1>&2\n'
	GORGON_CONFIG=$GORGON_CONFIG'fi\n\n'
	GORGON_CONFIG=$GORGON_CONFIG'while test $# -gt 0; do\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\tcase "$1" in\n'
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t-*=*) optarg=`echo "$1" | sed '"'s/[-_a-zA-Z0-9]*=//'"'` ;;\n'
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t*) optarg= ;;\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\tesac\n\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\tcase $1 in\n'
	
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t--prefix)\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\techo /usr\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\t;;\n'
	
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t--version)\n'
	GORGON_CONFIG=$GORGON_CONFIG"			\t\t\techo 'rev_$1'\n"
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\t;;\n'
	
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t--libs)\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\techo -L/usr${exec_prefix}/lib -lgorgon -lpthread\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\t;;\n'
	
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t--addons)\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\techo -L/usr${exec_prefix}/lib -lgorgon_addon\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\t;;\n'
	
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t--addons_sdl)\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\techo `sdl-config --libs` -L/usr${exec_prefix}/lib -lgorgon_addon -lSDL_image\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\t;;\n'
	
	GORGON_CONFIG=$GORGON_CONFIG'		\t\t*)\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\tusage 1 1>& 2\n'
	GORGON_CONFIG=$GORGON_CONFIG'			\t\t\t;;\n'

	GORGON_CONFIG=$GORGON_CONFIG'	\tesac\n'
	GORGON_CONFIG=$GORGON_CONFIG'	\tshift\n'
	GORGON_CONFIG=$GORGON_CONFIG'done\n'
	echo $GORGON_CONFIG > $PACKAGE_DIR/usr/bin/gorgon-config
	chmod +x $PACKAGE_DIR/usr/bin/gorgon-config
}
#
# Funćão que cria o controle do pacote
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
# @param	svnRev, número da revisão svn
#
CREATE_PACKAGE_CONTROL()
{
	echo "\tCriando arquivo de controle do pacote"
	CONTROL=""
	CONTROL=$CONTROL"Package:		\t\tlibgorgon-dev\n"
	CONTROL=$CONTROL"Priority:		\t\toptional\n"
	CONTROL=$CONTROL"Source:		\t\tgorgon++\n"
	CONTROL=$CONTROL"Version:		\t\t$1\n"
	CONTROL=$CONTROL"Section:		\t\tlibdevel\n"
	CONTROL=$CONTROL"Architecture:	\ti386\n"
	CONTROL=$CONTROL"Depends:		\t\tliballegro4.2-dev, libaudiere-dev, liblua5.1-0-dev, libz-dev\n"
	CONTROL=$CONTROL"Maintainer:	\tCantídio Oliveira Fontes <aniquilatorbloody@gmail.com>\n"
	CONTROL=$CONTROL"Description:	\tBiblioteca de desenvolvimento de games.\n"
	CONTROL=$CONTROL" Este pacote contém os includes e libs dinâmicas necessárias para construir programas que usem a gorgon.\n"
	CONTROL=$CONTROL" .\n"
	CONTROL=$CONTROL" Homepage: http://sites.google.com/site/gorgonsgate\n"
	echo -n $CONTROL > $PACKAGE_DIR/DEBIAN/control
}
#
# Funcão para criar a estrutura de diretórios do pacote
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
#
CREATE_FOLDERS()
{
	echo "\tCriando estrutura de diretórios do pacote."
	mkdir $PACKAGE_DIR ; cd $PACKAGE_DIR
	mkdir DEBIAN usr
	mkdir usr/bin usr/include usr/lib usr/share
	mkdir usr/include/gorgon++
	mkdir usr/share/man usr/share/man/man1
	cd ../
}
#
# Funcão para remover a estrutura de diretórios do pacote
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
#
REMOVE_FOLDERS()
{
	echo "\tRemovendo estrutura de diretórios."
	rm -rf $PACKAGE_DIR
}
#
# Funcão para criar o diretório de inclusão do pacote
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
#
CREATE_DIR_INCLUDE()
{
	echo "\tCriando o diretório INCLUDE"
	cp -r include/* $PACKAGE_DIR/usr/include/gorgon++/
	cp -r addon $PACKAGE_DIR/usr/include/gorgon++/
}
#
# Funcão para criar o diretório libs do pacote
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
#
CREATE_DIR_LIB()
{
	echo "\tCriando o diretório LIB"
	cp $LIB_LOCATION $PACKAGE_DIR/usr/lib/
	cp $ADDON_LOCATION $PACKAGE_DIR/usr/lib/
}
#
# Funcão para criar o diretório Share do pacote
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
#
CREATE_DIR_SHARE()
{
	echo "\tCriando o diretório SHARE"
}
#
# Funcão para criar o pacote
#
# @author	Cantidio Oliveira Fontes
# @since	18/05/2010
# @version	18/05/2010
#
CREATE_DEBIAN_PACKAGE()
{
	echo "\tCriando o pacote .DEB"
	dpkg-deb -b $PACKAGE_DIR ./
}

SVN_VERSION=`svnversion ./`
#SVN_CUT=`expr ${#SVN_VERSION} - 1`
#SVN_VERSION=`expr substr $SVN_VERSION 1 $SVN_CUT`

echo "Gerando Pacote..."
CREATE_FOLDERS						# Cria os diretórios
CREATE_PACKAGE_CONTROL $SVN_VERSION	# Cria o arquivo de controle do pacote
CREATE_GORGON_CONFIG $SVN_VERSION	# Cria o arquivo de configuraćão da biblioteca
CREATE_DIR_INCLUDE					# Cria o diretório de include da biblioteca
CREATE_DIR_SHARE					# Cria o diretório share com manuais
CREATE_DIR_LIB						# Cria o diretório de lib da biblioteca
CREATE_DEBIAN_PACKAGE				# Cria o pacote Debian, com o diretório construido
REMOVE_FOLDERS						# Deleta os diretórios temporários do pacote
echo "OK"


