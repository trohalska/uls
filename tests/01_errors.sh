
echo ------------------------------------------ ERRORS

echo Test: ls --
ls -- 1> test.txt
./uls -- 1> user.txt
diff -q test.txt user.txt

echo Test: ls xxx
ls xxx 1> test.txt
./uls xxx 1> user.txt
diff -q test.txt user.txt

echo Test: ls xxx Makefile
ls xxx Makefile 1> test.txt
./uls xxx Makefile 1> user.txt
diff -q test.txt user.txt

echo Test: ls -- -l
ls -- -l 1> test.txt
./uls -- -l 1> user.txt
diff -q test.txt user.txt

echo Test: ls -- libmx
ls -- libmx 1> test.txt
./uls -- libmx 1> user.txt
diff -q test.txt user.txt

echo Test: ls -- xxx libmx
ls -- xxx libmx 1> test.txt
./uls -- xxx libmx 1> user.txt
diff -q test.txt user.txt

echo Test: ls xxx libmx -l
ls xxx libmx -l 1> test.txt
./uls xxx libmx -l 1> user.txt
diff -q test.txt user.txt

echo Test: ls xxx libmx -l Makefile
ls xxx libmx -l Makefile 1> test.txt
./uls xxx libmx -l Makefile 1> user.txt
diff -q test.txt user.txt
