#!/bin/bash

betax=0
betay=0
min=99999999
for Bx in {1..144}
do
	for By in {1..176}
	do
		if [ $((144%Bx)) -eq 0 ] && [ $((176%By)) -eq 0 ]; then
			num=0
			for i in {1..10}
			do
				timed=$(./phods-bxy.o $Bx $By)
				num=$((num+timed))
			done
			num=$((num/10))
			#echo "For Bx ${Bx} By ${By}: Average Time: ${num}usec" 
			if [ $((num)) -le $((min)) ]
				then
					betax=$((Bx))
					betay=$((By))
					min=$((num))
			fi
		fi
	done
done

echo "${betax} ${betay}"
