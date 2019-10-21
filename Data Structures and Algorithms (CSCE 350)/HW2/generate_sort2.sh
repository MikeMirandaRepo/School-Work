#!/bin/bash

echo $1
for i in `seq 1 $2`;
do
  let "number=$RANDOM + 1"
  echo $number
done
echo 0
