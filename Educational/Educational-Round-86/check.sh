for ((i=1;i<1000;i++)) do
	echo $i
	./gen $i > in
	./correct < in > out
	diff -w <(./c < in) out || break
done