for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./E < in) <(./correct < in) || break
done
