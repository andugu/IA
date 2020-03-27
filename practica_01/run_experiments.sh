#!/bin/bash

SEED=$1
SERVERS=$2
REPETITIONS=$3
USERS=$4
REQUESTS=$5
ALGORITHM=$6
INITIAL_STATE=$7
SUCCESSORS_FUNCTION=$8
HEURISTIC=$9
ROUNDS=100


./make.sh 1 # create executable
echo "Number of rounds: $ROUNDS"

RANDOM=$SEED
for (( i = 0; i < $ROUNDS ; i++));
do
    SEED=($RANDOM % 10000000)
    echo "Current seed: $SEED"
    java -jar practica_01 $SEED $SERVERS $REPETITIONS $USERS $REQUESTS $ALGORITHM $INITIAL_STATE $SUCCESSORS_FUNCTION

done



