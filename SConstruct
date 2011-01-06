def makeObj(env,name,ext='.cpp'):
	Obj=[]
	Obj.extend(env.Object('./obj/'+name+'.o','./'+name+ext))
	return Obj
	

#env = Environment(
#	CCFLAGS=['-O2','-Wunused-label','-Wunused-parameter','-Wunused-value','-Wunused-variable']
#	)
env = Environment()
env['CPPPATH'] = "./include/"
env.Clean(
	'temp',
	Glob('./src/*/include/*~')+
	Glob('./src/*/src/*~')+
	Glob('./src/*/*~')+
	Glob('./src/*~')+
	Glob('./examples/*/*~')+
	Glob('./examples/*~')+
	Glob('./bin/*.a')+
	Glob('./bin/*.so')+
	Glob('./*~')
	)

conf= Configure(env)
if not conf.CheckLib('alleg'):
	print 'Did not found lib allegro, exiting!'
	Exit(1)
env = conf.Finish()

Export('makeObj');
Export('env');

#SConscript("./src/SConscript")

libEnv=env.Clone();
#prgEnv=env.Clone();
#static	= libEnv.StaticLibrary('./bin/gorgon', Glob('./src/*/obj/*.o')+Glob('./src/third_party/lua-5.1.4/src/*.o'))
shared	= libEnv.SharedLibrary('./bin/gorgon', Glob('./src/*/*.cpp'))
#prgEnv.Tool('registerObjects', package = 'gorgon', libraries = [static], includes = Glob('src/*/include/*.hpp'))

#shared	= env.SharedLibrary('./bin/gorgon', Glob('./src/*/obj/*.o')+Glob('./src/third_party/bin/*.a'))
#shared	= SharedLibrary('./bin/gorgon', Glob('./src/*/obj/*.so')+Glob('./src/third_party/bin/*.os'))
#SConscript('examples/SConscript')


