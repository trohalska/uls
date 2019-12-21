
echo ------------------------------------------ Without flags

echo Test: ls
ls 1> test.txt
./uls 1> user.txt
diff test.txt user.txt

echo Test: ls | cat -e
ls | cat -e 1> test.txt
./uls | cat -e 1> user.txt
diff -q test.txt user.txt

echo Test: ls libmx
ls libmx 1> test.txt
./uls libmx 1> user.txt
diff -q test.txt user.txt

echo Test: ls libmx | cat -e
ls libmx | cat -e 1> test.txt
./uls libmx | cat -e 1> user.txt
diff -q test.txt user.txt

echo Test: ls Makefile
ls Makefile 1> test.txt
./uls Makefile 1> user.txt
diff -q test.txt user.txt

echo Test: ls libmx Makefile
ls libmx Makefile 1> test.txt
./uls libmx Makefile 1> user.txt
diff -q test.txt user.txt

echo Test: ls /dev
ls /dev 1> test.txt
./uls /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls /usr/bin
ls /usr/bin 1> test.txt
./uls /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls /Users
ls /Users 1> test.txt
./uls /Users 1> user.txt
diff -q test.txt user.txt
