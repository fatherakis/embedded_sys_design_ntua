#!/bin/bash

num=0
min=99999999
max=0

for i in {1..10}
do
	timed=$(./tables_basic.o)
	if [ $((timed)) -le $((min)) ]
	then
		min=$((timed))
	fi
	if [ $((timed)) -ge $((max)) ]
	then
		max=$((timed))
	fi
	num=$((num+timed))
done

num=$((num/10))
echo "Unoptimized: Minimum Time: ${min}usec Average Time: ${num}usec Max Time: ${max}usec" 

num=0
min=99999999
max=0

for i in {1..10}
do
	timed=$(./tables_exhaustive.o)
	if [ $((timed)) -le $((min)) ]
	then
		min=$((timed))
	fi
	if [ $((timed)) -ge $((max)) ]
	then
		max=$((timed))
	fi
	num=$((num+timed))
done

num=$((num/10))
echo "Exhaustive: Minimum Time: ${min}usec Average Time: ${num}usec Max Time: ${max}usec" 

num=0
min=99999999
max=0

for i in {1..10}
do
	timed=$(./tables_randomsearch.o)
	if [ $((timed)) -le $((min)) ]
	then
		min=$((timed))
	fi
	if [ $((timed)) -ge $((max)) ]
	then
		max=$((timed))
	fi
	num=$((num+timed))
done

num=$((num/10))
echo "Randomsearch: Minimum Time: ${min}usec Average Time: ${num}usec Max Time: ${max}usec" 


num=0
min=99999999
max=0

for i in {1..10}
do
	timed=$(./tables_simplex.o)
	if [ $((timed)) -le $((min)) ]
	then
		min=$((timed))
	fi
	if [ $((timed)) -ge $((max)) ]
	then
		max=$((timed))
	fi
	num=$((num+timed))
done

num=$((num/10))
echo "Simplex: Minimum Time: ${min}usec Average Time: ${num}usec Max Time: ${max}usec" 
