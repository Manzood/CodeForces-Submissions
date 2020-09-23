for ((i=400;;i++)) do
    echo $i
    ./gen $i > in
    ./d < in > expected
    diff -w <(./correct < in) expected || break
done
