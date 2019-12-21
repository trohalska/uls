
echo ------------------------------------------- Flag -l

echo Test: ls -l
ls -l 1> test.txt
./uls -l 1> user.txt
diff -q test.txt user.txt

echo Test: ls -l | cat -e
ls -l | cat -e 1> test.txt
./uls -l | cat -e 1> user.txt
diff -q test.txt user.txt

echo Test: ls -l libmx
ls -l libmx 1> test.txt
./uls -l libmx 1> user.txt
diff -q test.txt user.txt

echo Test: ls -l /dev
ls -l /dev 1> test.txt
./uls -l /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -l /usr/bin
ls -l /usr/bin 1> test.txt
./uls -l /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -l /Users
ls -l /usr/bin 1> test.txt
./uls -l /usr/bin 1> user.txt
diff -q test.txt user.txt
