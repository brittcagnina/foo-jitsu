foo-jitsu

A wrapper for commonly used UNIX programs

Current ideas for fj:
 
fj => ls
fj -l => ls -l
fj <file> => vi <file>
fj -r <file> => rm <file>
fj mk <dir> => mkdir <dir>
fj <dir> => cd <dir>
fj -p <dir> => pushd <dir>
fj -p => popd 
fj -r <dir> => rm -r <dir>
fj <file1> <file2> => cp <file1> <file2>
fj mv <file1> <file2> => mv <file1> <file2>
fj -f <dir> <file> => find <dir> -name <file> 
fj -g <pattern> <dir> => grep <pattern> <dir>
