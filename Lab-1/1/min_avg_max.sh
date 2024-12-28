#!/bin/bash

num=0
min=99999999
max=0
for i in {1..10}
do
	timed=$(./phods-unoptimized.o)
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
	timed=$(./phods-optimized.o)
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
echo "Optimized: Minimum Time: ${min}usec Average Time: ${num}usec Max Time: ${max}usec" 


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

echo "Best B was ${beta} with time ${min}"


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
echo "Best Bx, By was ${betax},${betay} with time ${min}"
