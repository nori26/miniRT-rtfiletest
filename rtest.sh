make re

run=./miniRT
path_ko=rt/invalid
path_ok=rt/valid

result=0
cases=0
ko[0]=KO
k=1

print_result() {
	if [ $1 == 0 ]; then
		let result++
		printf '\n\033[32m%s\033[m\n' '[OK]'
		echo -e "============================================\n"
	else
		ko[k]=$2
		let k++
		printf '\n\033[31m%s\033[m\n' '[KO]'
		echo -e "============================================\n"
	fi
}

file_test() {
	echo "file : $1"
	# $run $2/$1 > /dev/null &
	$run $2/$1 &
	sleep 0.1
	kill $! > /dev/null 2>&1
	test "$?" $3 "0"
	print_result $? $4
	wait $! 2>/dev/null
	let cases++
}

echo "============================================"
echo "==================invalid==================="
echo -e "============================================\n"

for i in {1..100}
do
	file_test $i.rt $path_ko != $i
	FILE="$path_ko/$i.rt"
	if [ ! -e $FILE ]; then
		break
	fi
done

file_test .rt $path_ko != .rt
file_test a $path_ko != a
file_test a.art $path_ko != a.art

segv=1
echo "file : dir.rt"
bash -c './miniRT rt/invalid/dir.rt > rtest1..rt 2>sanitize_res..rt' > Seg_fault..rt 2>&1
strings sanitize_res..rt | grep SEGV > /dev/null || strings Seg_fault..rt | grep Segment > /dev/null || segv=0
print_result $segv dir
rm rtest1..rt sanitize_res..rt Seg_fault..rt
let cases++

echo -e "\n============================================"
echo "===================valid===================="
echo -e "============================================\n"

for i in {1..100}
do
	FILE="$path_ok/$i.rt"
	if [ ! -e $FILE ]; then
		break
	fi
	file_test $i.rt $path_ok = $i
done

cp $path_ok/--save.rt .
file_test ..rt $path_ok = ..rt
file_test --save.rt . = --save.rt
rm ./--save.rt

ps
echo -e "\n"OK $result / $cases
for i in "${ko[@]}"
do
	echo -n "$i "
done