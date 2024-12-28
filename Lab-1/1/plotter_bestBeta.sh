#!/bin/bash

beta=0
min=99999999
for B in {1..144}
do
	if [ $((144%B)) -eq 0 ] && [ $((176%B)) -eq 0 ]; then
		num=0
		for i in {1..10}
		do
			timed=$(./phods-beta.o $B)
			num=$((num+timed))
		done
		num=$((num/10))
		#echo "For B ${B}: Average Time: ${num}usec" 
		if [ $((num)) -le $((min)) ]
			then
				beta=$((B))
				min=$((num))
		fi
	fi
done

echo "${beta}"


