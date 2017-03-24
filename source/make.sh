#!/bin/sh

echo $#

if [ $# -gt 0 ]; then
	sourceFile=$1
else
	sourceFile=$(ls -rt *.cpp | tail -1)
fi

fileName=${sourceFile%.*}

echo "Compiling " $sourceFile " ..."

g++ -std=c++11 -g $sourceFile -o $fileName
