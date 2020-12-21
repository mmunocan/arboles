reset

set terminal png size 800,600
set grid
set key out horiz

set xtics ("1x10^5" 1, "2x10^5" 2, "3x10^5" 3, "4x10^5" 4, "5x10^5" 5, "6x10^5" 6, "7x10^5" 7, "8x10^5" 8, "9x10^5" 9, "10x10^5" 10)
set xrange [0.5:10.5]
set xlabel "Cantidad de datos insertados" font ",18"
set yrange [0.1:0.9]
set ylabel "Tiempo [ms]" font ",18"

set key font ",16"
set tics font ",12"

set style line 1 linecolor rgb "blue" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5
set style line 2 linecolor rgb "red" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5
set style line 3 linecolor rgb "dark-chartreuse" dashtype 8 linewidth 1.5 pointtype 5 pointsize 1.5

set output 'fig_hipotesis_1.png'
plot 'data_hipotesis_1' u 1:2 w lp t 'BST' ls 1, '' u 1:3 w lp t 'AVL' ls 2, '' u 1:4 w lp t 'RBT' ls 3


set yrange [8:1400]
set logscale y

set output 'fig_hipotesis_3.png'
plot 'data_hipotesis_3' u 1:3 w lp t 'AVL' ls 2, '' u 1:4 w lp t 'RBT' ls 3

unset logscale y
set yrange [15:65]
set ylabel "Altura" font ",18"

set output 'fig_hipotesis_2.png'
plot 'data_hipotesis_2' u 1:2 w lp t 'BST' ls 1, '' u 1:3 w lp t 'AVL' ls 2, '' u 1:4 w lp t 'RBT' ls 3

