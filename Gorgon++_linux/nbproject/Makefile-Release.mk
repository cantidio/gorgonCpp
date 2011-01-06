#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collision.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_palette.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inffast.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_system.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inflate.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzwrite.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_system_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_point.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inftrees.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_file_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_file.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/infback.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_info_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/uncompr.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzclose.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_mirroring.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_zlib.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_polygon.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_autodetect.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzlib.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_log.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_handler.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collision_frame.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack_header.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_unknown.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_video.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/trees.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sff_spritepack.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_rectangle.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/zutil.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_return.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/deflate.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/crc32.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collisionpack.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_frame.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/adler32.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_color.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_argument.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/compress.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_param.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_line.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack_exception.o \
	${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzread.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/libGorgon__.so

dist/Release/GNU-Linux-x86/libGorgon__.so: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libGorgon__.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collision.o: nbproject/Makefile-${CND_CONF}.mk ../src/collision/gorgon_collision.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collision.o ../src/collision/gorgon_collision.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_bmp.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp.o ../src/graphic/gorgon_image_format_bmp.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_palette.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_palette.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_palette.o ../src/graphic/gorgon_palette.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_spritepack.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack.o ../src/graphic/gorgon_spritepack.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inffast.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/inffast.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inffast.o ../third_party/zlib-1.2.5/inffast.c

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_pcx.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx.o ../src/graphic/gorgon_image_format_pcx.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound.o: nbproject/Makefile-${CND_CONF}.mk ../src/audio/gorgon_sound.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/audio
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound.o ../src/audio/gorgon_sound.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_bmp_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_header.o ../src/graphic/gorgon_image_format_bmp_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_sprite_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite_header.o ../src/graphic/gorgon_sprite_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_animation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation.o ../src/graphic/gorgon_animation.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_system.o: nbproject/Makefile-${CND_CONF}.mk ../src/audio/gorgon_sound_system.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/audio
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_system.o ../src/audio/gorgon_sound_system.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inflate.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/inflate.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inflate.o ../third_party/zlib-1.2.5/inflate.c

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_pcx_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx_header.o ../src/graphic/gorgon_image_format_pcx_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzwrite.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/gzwrite.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzwrite.o ../third_party/zlib-1.2.5/gzwrite.c

${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_system_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/audio/gorgon_sound_system_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/audio
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_system_exception.o ../src/audio/gorgon_sound_system_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_animation_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_exception.o ../src/graphic/gorgon_animation_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/script/gorgon_lua_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/script
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_exception.o ../src/script/gorgon_lua_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_point.o: nbproject/Makefile-${CND_CONF}.mk ../src/geometry/gorgon_point.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/geometry
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_point.o ../src/geometry/gorgon_point.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inftrees.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/inftrees.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/inftrees.o ../third_party/zlib-1.2.5/inftrees.c

${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_file_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/core/gorgon_file_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/core
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_file_header.o ../src/core/gorgon_file_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_file.o: nbproject/Makefile-${CND_CONF}.mk ../src/core/gorgon_file.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/core
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_file.o ../src/core/gorgon_file.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/infback.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/infback.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/infback.o ../third_party/zlib-1.2.5/infback.c

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_sprite_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite_exception.o ../src/graphic/gorgon_sprite_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/core/gorgon_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/core
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_exception.o ../src/core/gorgon_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_info_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_bmp_info_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_info_header.o ../src/graphic/gorgon_image_format_bmp_info_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/uncompr.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/uncompr.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/uncompr.o ../third_party/zlib-1.2.5/uncompr.c

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzclose.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/gzclose.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzclose.o ../third_party/zlib-1.2.5/gzclose.c

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_pcx_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_pcx_exception.o ../src/graphic/gorgon_image_format_pcx_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_spritepack_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack_header.o ../src/graphic/gorgon_spritepack_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sprite.o ../src/graphic/gorgon_sprite.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_mirroring.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_mirroring.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_mirroring.o ../src/graphic/gorgon_mirroring.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua.o: nbproject/Makefile-${CND_CONF}.mk ../src/script/gorgon_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/script
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua.o ../src/script/gorgon_lua.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_zlib.o: nbproject/Makefile-${CND_CONF}.mk ../src/core/gorgon_zlib.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/core
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_zlib.o ../src/core/gorgon_zlib.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_animation_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_header.o ../src/graphic/gorgon_animation_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_polygon.o: nbproject/Makefile-${CND_CONF}.mk ../src/geometry/gorgon_polygon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/geometry
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_polygon.o ../src/geometry/gorgon_polygon.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_autodetect.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_autodetect.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_autodetect.o ../src/graphic/gorgon_image_format_autodetect.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzlib.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/gzlib.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzlib.o ../third_party/zlib-1.2.5/gzlib.c

${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_log.o: nbproject/Makefile-${CND_CONF}.mk ../src/core/gorgon_log.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/core
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/core/gorgon_log.o ../src/core/gorgon_log.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_exception.o ../src/graphic/gorgon_image_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_handler.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_animation_handler.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animation_handler.o ../src/graphic/gorgon_animation_handler.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collision_frame.o: nbproject/Makefile-${CND_CONF}.mk ../src/collision/gorgon_collision_frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collision_frame.o ../src/collision/gorgon_collision_frame.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack_header.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_animationpack_header.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack_header.o ../src/graphic/gorgon_animationpack_header.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_unknown.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_unknown.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_unknown.o ../src/graphic/gorgon_image_format_unknown.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_video.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_video.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_video.o ../src/graphic/gorgon_video.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/trees.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/trees.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/trees.o ../third_party/zlib-1.2.5/trees.c

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sff_spritepack.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_sff_spritepack.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_sff_spritepack.o ../src/graphic/gorgon_sff_spritepack.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_rectangle.o: nbproject/Makefile-${CND_CONF}.mk ../src/geometry/gorgon_rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/geometry
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_rectangle.o ../src/geometry/gorgon_rectangle.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/zutil.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/zutil.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/zutil.o ../third_party/zlib-1.2.5/zutil.c

${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_return.o: nbproject/Makefile-${CND_CONF}.mk ../src/script/gorgon_lua_return.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/script
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_return.o ../src/script/gorgon_lua_return.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/deflate.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/deflate.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/deflate.o ../third_party/zlib-1.2.5/deflate.c

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/crc32.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/crc32.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/crc32.o ../third_party/zlib-1.2.5/crc32.c

${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collisionpack.o: nbproject/Makefile-${CND_CONF}.mk ../src/collision/gorgon_collisionpack.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/collision/gorgon_collisionpack.o ../src/collision/gorgon_collisionpack.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_frame.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_frame.o ../src/graphic/gorgon_frame.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/audio/gorgon_sound_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/audio
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/audio/gorgon_sound_exception.o ../src/audio/gorgon_sound_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_animationpack.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack.o ../src/graphic/gorgon_animationpack.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/adler32.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/adler32.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/adler32.o ../third_party/zlib-1.2.5/adler32.c

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_color.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_color.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_color.o ../src/graphic/gorgon_color.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image.o ../src/graphic/gorgon_image.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_animationpack_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_animationpack_exception.o ../src/graphic/gorgon_animationpack_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_argument.o: nbproject/Makefile-${CND_CONF}.mk ../src/script/gorgon_lua_argument.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/script
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_argument.o ../src/script/gorgon_lua_argument.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_image_format_bmp_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_image_format_bmp_exception.o ../src/graphic/gorgon_image_format_bmp_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/compress.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/compress.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/compress.o ../third_party/zlib-1.2.5/compress.c

${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_param.o: nbproject/Makefile-${CND_CONF}.mk ../src/script/gorgon_lua_param.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/script
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/script/gorgon_lua_param.o ../src/script/gorgon_lua_param.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_line.o: nbproject/Makefile-${CND_CONF}.mk ../src/geometry/gorgon_line.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/geometry
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/geometry/gorgon_line.o ../src/geometry/gorgon_line.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack_exception.o: nbproject/Makefile-${CND_CONF}.mk ../src/graphic/gorgon_spritepack_exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/graphic/gorgon_spritepack_exception.o ../src/graphic/gorgon_spritepack_exception.cpp

${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzread.o: nbproject/Makefile-${CND_CONF}.mk ../third_party/zlib-1.2.5/gzread.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5
	${RM} $@.d
	$(COMPILE.c) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/third_party/zlib-1.2.5/gzread.o ../third_party/zlib-1.2.5/gzread.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/libGorgon__.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
