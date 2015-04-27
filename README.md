foo-jitsu

A wrapper for commonly used UNIX programs

All deleterious actions require options (Ex: fj -r <file> for removal of <file>)

Current ideas for fj:
 
fj => ls

fj -l => ls -l

fj -la => ls -la

fj -c <file> => wc <file>

fj <file> => vi <file>

fj -r <file> => rm <file>

fj <dir> => mkdir <dir> (If <dir> D.N.E.)

fj <dir> => cd <dir>

fj -p <dir> => pushd <dir>

fj -p => popd 

fj -r <dir> => rm -r <dir>

fj <file1> <file2> => cp <file1> <file2>

fj mv <file1> <file2> => mv <file1> <file2>

fj -f <dir> <pattern> => find <dir> -name <pattern> 

fj -nf <dir> <pattern> => find <dir> -not -name <pattern> 

fj -g <pattern> <dir> => grep <pattern> <dir>

