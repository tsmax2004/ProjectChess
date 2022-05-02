#!/bin/bash

start_path=$(pwd)
project_dir=$(dirname $0)
mkdir $project_dir/source/build
cd $project_dir/source/build
cmake ..
make
cd ..
rm -R build
cd $start_path
