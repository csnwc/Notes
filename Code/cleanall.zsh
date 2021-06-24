#!/usr/bin/zsh
base=`pwd`
for chapter in $base/Chap?(/); do
   cd $chapter
   echo
   pwd
   echo
   make -f ../generalmakefile.mk clean
done
