#! /bin/bash

for d in a1 a2 a3; do
FILE="$d/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
  echo $d": $score / $max" 
elif [ -z "$FILE" ]; then
  grade=`tail -1 $FILE | tr -d [:blank:]`
  echo $d": - / -"
else 
  echo $d": - / -" 
fi
done

printf "\n"

for d in Lab1 Lab2 Lab3 Lab4 Lab5; do
FILE="$d/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
  echo $d": $score / $max" 
elif [ -z "$FILE" ]; then
  grade=`tail -1 $FILE | tr -d [:blank:]`
  echo $d": - / -"
else 
  echo $d": - / -" 
fi
done

echo -e '\n'

for f in a1; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

a1score=$score
a1max=$max

for f in a2; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

a2score=$score
a2max=$max

for f in a3; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

a3score=$score
a3max=$max

sumAscore=$(( $a1score + $a2score + $a3score ))
sumAmax=$(( $a1max + $a2max + $a3max ))
echo "Assignment Total: $sumAscore / $sumAmax"

for f in Lab1; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

lab1score=$score
lab1max=$max

for f in Lab2; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

lab2score=$score
lab2max=$max

for f in Lab3; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

lab3score=$score
lab3max=$max

for f in Lab4; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

lab4score=$score
lab4max=$max

for f in Lab5; do
FILE="$f/feedback.txt"
if [ -f "$FILE" ]; then
  grade=`tail -1 $FILE  | tr -d [:blank:]`
  IFS='/' read -ra grArray <<< "$grade"
  score=${grArray[0]}
  max=${grArray[1]}
else
  score="0"
  max="0"
fi
done

lab5score=$score
lab5max=$max

sumscore=$(( $lab1score + $lab2score + $lab3score + $lab4score + $lab5score ))
summax=$(( $lab1max + $lab2max + $lab3max + $lab4max + $lab5max))
echo "Lab Total: $sumscore / $summax"
