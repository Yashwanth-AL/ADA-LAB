#!/bin/bash

# Set variables
filename="Quick-Sort"
xrange="[0:1050]"
yrange="[-50:600000]"
b_file="q_b.txt"
w_file="q_w.txt"
a_file="q_a.txt"

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
plot "${b_file}" title "best-case", "${w_file}" title "worst-case", "${a_file}" title "avg-case"
EOF

echo "Plot saved as ${filename}.png"
