#!/bin/sh

apk add --update gcc musl-dev curl

if [ ! -f 100mbtest.bin ]; then
    curl -s http://speedtest.reliableservers.com/100MBtest.bin --output 100mbtest.bin
fi

gcc -Wall -g -O0 -o file_sum_1 file_sum_1.c

gcc -Wall -g -O0 -o file_sum_2 file_sum_2.c

gcc -Wall -g -O0 -o file_sum_3 file_sum_3.c

gcc -Wall -g -O3 -o file_sum_3_2 file_sum_3.c

for a in 1 2 3 4 5 6 7 8 9 10
do
    time ./file_sum_1 100mbtest.bin
done

echo "---------------------------"

for a in 1 2 3 4 5 6 7 8 9 10
do
    time ./file_sum_2 100mbtest.bin
done

echo "---------------------------"

for a in 1 2 3 4 5 6 7 8 9 10
do
    time ./file_sum_3 100mbtest.bin
done

echo "---------------------------"

for a in 1 2 3 4 5 6 7 8 9 10
do
    time ./file_sum_3_2 100mbtest.bin
done
