#!/bin/bash

# Set variables
filename="Seleection-Sort"
xrange="[0:40000]"
yrange="[-50000:500000000]"
a_file="s.txt"

# Gnuplot commands
gnuplot << EOF
set terminal png
set output "${filename}.png"
set title "${filename}"
set xrange ${xrange}
set yrange ${yrange}
set xlabel "input-size"
set ylabel "op-count"
set style data linespoints
plot "${a_file}" title "avg-case"
EOF

echo "Plot saved as ${filename}.png"
