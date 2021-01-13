for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./alternate-b < in) <(./correct < in) || break
done
