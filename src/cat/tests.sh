#! bin/bash

name1="cat"
name2=".\s21_cat"
DIFF_RES=""
declare -a mas=(
"-b -e new1.txt"
"-v -b -s -t bytes_2.txt"
"-n bytes_2.txt"
"-s bytes_2.txt"
"-t -e -v new1.txt"
"-v bytes_2.txt"
"-b -e bytes_2.txt"
"-b -n bytes_2.txt"
"-b -s bytes_2.txt"
"-b -t bytes_2.txt"
"-t -e -n -s bytes_2.txt"
)

for n in "${mas[@]}"
do
cat $n > cat_result.txt
./s21_cat $n > s21_cat_result.txt

DIFF_RES="$(diff -s cat_result.txt s21_cat_result.txt)"
if (DIFF_RES="Files cat_result.txt and s21_cat_result.txt are identical")
then
echo "OKK"
else
echo "FAIL"
fi
done
