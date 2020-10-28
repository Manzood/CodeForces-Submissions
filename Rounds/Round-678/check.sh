for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./d < in) <(./correct < in) || break
done
