env = Environment(CPPFLAGS='--std=c++11')
SConscript('SConscript', variant_dir='build', duplicate=0)
SConscript('tests/SConscript', variant_dir='tests/build', exports = ['env'], duplicate=0 )
