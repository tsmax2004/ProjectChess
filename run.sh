#!/bin/bash

start_path=$(pwd)
project_dir=$(dirname $0)
cd $project_dir/source

FILE=run
if [ ! -f "$FILE" ]; then
    echo "Build project"
    ../build.sh
fi

./run
cd $start_path
