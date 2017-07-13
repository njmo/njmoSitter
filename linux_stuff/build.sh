#!/bin/bash
mkdir -p build
cmake -B~/njmositter/build -H~/njmositter/rpi
if [ $? -eq 0 ]; then
  currdir=`pwd`
  cd ~/njmositter/build
  make
  ./application/application
  cd $currdir
fi
