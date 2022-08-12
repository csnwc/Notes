#!/usr/bin/zsh
base=`pwd`
for chapter in ${base}/Chap?(/); do
   cd ${chapter}
   echo ${chapter}
   echo
   make -f ../generalmakefile.mk all
done
