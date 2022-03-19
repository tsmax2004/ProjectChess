#!/bin/bash

start_path=$(pwd)
project_dir=$(dirname $0)
mkdir $project_dir/build
cd $project_dir/build
cmake ..
make
cd ..
rm -R build
cd $start_path
