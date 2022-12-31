#!/bin/bash 
 
./build.sh
[ $? -eq 0 ] && clear && \
    [ ! -d "build" ] && echo "app cannot be run build/main does not exist !" \
        && echo "run ./buildp.sh before ;-)" && exit 1
        ./build/csmk_list
