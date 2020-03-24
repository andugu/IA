#!/bin/bash

CLASSPATH=.:libs/AIMA.jar:libs/DistributedFS.jar

echo ""
echo "##############################"
echo "#   Jar Automaker Utility    #"
echo "##############################"
echo ""
echo "Please select an option:"
echo ""
echo "1. Compile project & make .jar executable"
echo "2. Remove all *.class and *.jar files from /src"
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

echo ""
echo "Done, enjoy!"
echo ""