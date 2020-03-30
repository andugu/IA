#!/bin/bash

CLASSPATH=.:libs/AIMA.jar:libs/DistributedFS.jar

echo ""
echo "##############################"
echo "#     Automaker Utility      #"
echo "##############################"
echo ""
echo "Please select an option:"
echo ""
echo "1. Compile project make .jar executabl"
echo "2. Remove all *.class and *.jar files"
echo ""
echo "I choose:"
echo ""
read n
echo ""

if [ $n == 1 ]; then
	javac -cp $CLASSPATH src/*.java
	jar cfm practica_01.jar Manifest.txt src/*.class
fi

if [ $n == 2 ]; then
	rm -rf ./src/*.class
	rm -rf ./*.jar
fi

#if [ $n == 3 ]; then
#	pdflatex -output-directory=./docs ./docs/docs.tex
#	rm ./docs/*.aux
#	rm ./docs/*.log
#fi

echo ""
echo "Done, enjoy!"
echo ""
