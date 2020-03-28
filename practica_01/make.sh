#!/bin/bash

CLASSPATH=.:libs/AIMA.jar:libs/DistributedFS.jar

echo ""
echo "##############################"
echo "#     Automaker Utility      #"
echo "##############################"
echo ""
echo "Please select an option:"
echo ""
echo "1. Compile project and docs & make .jar executabl & docs pdf"
echo "2. Remove all *.class and *.jar files from /src and pdf docs"
echo "3. Remove all *.class and *.jar files from /scr and keep pdf docs"
echo ""
echo "I choose:"
echo ""
read n
echo ""

if [ $n == 1 ]; then
	javac -cp $CLASSPATH src/*.java
	jar cfm practica_01.jar Manifest.txt src/*.class

	echo ""

	pdflatex -output-directory=./docs ./docs/docs.tex
	rm ./docs/*.aux
	rm ./docs/*.log
fi

if [ $n == 2 ]; then
	rm -rf ./src/*.class
	rm -rf ./*.jar
	rm -rf ./docs/documentació.pdf
fi

if [ $n == 3 ]; then
	rm -rf ./src/*.class
	rm -rf ./*.jar
fi

echo ""
echo "Done, enjoy!"
echo ""
