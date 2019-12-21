
echo ------------------------------------------ links

ln -s /libmx/ link1
ln -s Makefile link2
cd libmx && rm -rf libmx && cd ..

echo Test: ls link1
ls link1 1> test.txt
./uls link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls link2
ls link2 1> test.txt
./uls link2 1> user.txt
diff -q test.txt user.txt

echo Test: ls -l link1
ls -l link1 1> test.txt
./uls -l link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls -l link2
ls -l link2 1> test.txt
./uls -l link2 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ Attr @ and ACL +

echo Test: ls -l, ls -l /Users - if was correct

echo ------------------------------------------ multicolumn

echo Test: ls limx /Users/ Makefile link1
ls limx /Users/ Makefile link1 1> test.txt
./uls limx /Users/ Makefile link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls /dev/
ls /dev/ 1> test.txt
./uls /dev/ 1> user.txt
diff -q test.txt user.txt

echo Test: ls /usr/bin
ls /usr/bin 1> test.txt
./uls /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls /Users
ls /Users 1> test.txt
./uls /Users 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ flag -R

echo Test: ls -R
ls -R 1> test.txt
./uls -R 1> user.txt
diff -q test.txt user.txt

echo Test: ls -Rl
ls -Rl 1> test.txt
./uls -Rl 1> user.txt
diff -q test.txt user.txt

echo Test: ls -Rl libmx inc Makefile link1
ls -Rl libmx inc Makefile link1 1> test.txt
./uls -Rl libmx inc Makefile link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls -RL /dev
ls -RL /dev 1> test.txt
./uls -RL /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -Rl /usr/bin
ls -Rl /usr/bin 1> test.txt
./uls -Rl /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -lR link1
ls -lR link1 1> test.txt
./uls -lR link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls -R link1
ls -R link1 1> test.txt
./uls -R link1 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ flag -a -A -f

echo Test: ls -a
ls -a 1> test.txt
./uls -a 1> user.txt
diff -q test.txt user.txt

echo Test: ls -A
ls -A 1> test.txt
./uls -A 1> user.txt
diff -q test.txt user.txt

echo Test: ls -f
ls -f 1> test.txt
./uls -f 1> user.txt
diff -q test.txt user.txt

echo Test: ls -a libmx inc Makefile link1
ls -a libmx inc Makefile link1 1> test.txt
./uls -a libmx inc Makefile link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls -A libmx inc Makefile link1
ls -A libmx inc Makefile link1 1> test.txt
./uls -A libmx inc Makefile link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls -f libmx inc Makefile link1
ls -f libmx inc Makefile link1 1> test.txt
./uls -f libmx inc Makefile link1 1> user.txt
diff -q test.txt user.txt

echo Test: ls -a /Users/
ls -a /Users/ 1> test.txt
./uls -a /Users/ 1> user.txt
diff -q test.txt user.txt

echo Test: ls -A /Users/
ls -A /Users/ 1> test.txt
./uls -A /Users/ 1> user.txt
diff -q test.txt user.txt

echo Test: ls -f /Users/
ls -f /Users/ 1> test.txt
./uls -f /Users/ 1> user.txt
diff -q test.txt user.txt

echo Test: ls -a /dev
ls -a /dev 1> test.txt
./uls -a /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -A /dev
ls -A /dev 1> test.txt
./uls -A /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -f /dev
ls -f /dev 1> test.txt
./uls -f /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -a /usr/bin
ls -a /usr/bin 1> test.txt
./uls -a /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -A /usr/bin
ls -A /usr/bin 1> test.txt
./uls -A /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -f /usr/bin
ls -f /usr/bin 1> test.txt
./uls -f /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -fS
ls -fS 1> test.txt
./uls -fS 1> user.txt
diff -q test.txt user.txt

echo Test: ls -ftu
ls -ftu 1> test.txt
./uls -ftu 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ flag -Ra -RA

echo Test: ls -aR
ls -aR 1> test.txt
./uls -aR 1> user.txt
diff -q test.txt user.txt

echo Test: ls -AR
ls -AR 1> test.txt
./uls -AR 1> user.txt
diff -q test.txt user.txt

echo Test: ls -aR /Users/
ls -aR /Users/ 1> test.txt
./uls -aR /Users/ 1> user.txt
diff -q test.txt user.txt

echo Test: ls -AR /Users/
ls -AR /Users/ 1> test.txt
./uls -AR /Users/ 1> user.txt
diff -q test.txt user.txt

echo Test: ls -aR /dev
ls -aR /dev 1> test.txt
./uls -aR /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -AR /dev
ls -AR /dev 1> test.txt
./uls -AR /dev 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ flag -lh, -le, -lT, -l@

echo Test: ls -lh
ls -lh 1> test.txt
./uls -lh 1> user.txt
diff -q test.txt user.txt

echo Test: ls -lh /dev/
ls -lh /dev/ 1> test.txt
./uls -lh /dev/ 1> user.txt
diff -q test.txt user.txt

echo Test: ls -lh /Users
ls -lh /Users 1> test.txt
./uls -lh /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -lh /usr/bin
ls -lh /usr/bin 1> test.txt
./uls -lh /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -h
ls -h 1> test.txt
./uls -h 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ flag -r, -t, -S, -c, -u

echo Test: ls -S
ls -S 1> test.txt
./uls -S 1> user.txt
diff -q test.txt user.txt

echo Test: ls -S /dev
ls -S /dev 1> test.txt
./uls -S /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -S /Users
ls -S /Users 1> test.txt
./uls -S /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -S /usr/bin
ls -S /usr/bin 1> test.txt
./uls -S /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -t
ls -t 1> test.txt
./uls -t 1> user.txt
diff -q test.txt user.txt

echo Test: ls -t /Users
ls -t /Users 1> test.txt
./uls -t /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -t /dev
ls -t /dev 1> test.txt
./uls -t /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -t /usr/bin
ls -t /usr/bin 1> test.txt
./uls -t /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tu
ls -tu 1> test.txt
./uls -tu 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tu /dev
ls -tu /dev 1> test.txt
./uls -tu /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tu /Users
ls -tu /Users 1> test.txt
./uls -tu /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tu /usr/bin
ls -tu /usr/bin 1> test.txt
./uls -tu /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tc
ls -tc 1> test.txt
./uls -tc 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tc /dev
ls -tc /dev 1> test.txt
./uls -tc /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tc /Users
ls -tc /Users 1> test.txt
./uls -tc /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -tc /usr/bin
ls -tc /usr/bin 1> test.txt
./uls -tc /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -St
ls -St 1> test.txt
./uls -St 1> user.txt
diff -q test.txt user.txt

echo Test: ls -r
ls -r 1> test.txt
./uls -r 1> user.txt
diff -q test.txt user.txt

echo Test: ls -r /dev
ls -r /dev 1> test.txt
./uls -r /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -r /Users
ls -r /Users 1> test.txt
./uls -r /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -r /usr/bin
ls -r /usr/bin 1> test.txt
./uls -r /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rt
ls -rt 1> test.txt
./uls -rt 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rt /dev
ls -rt /dev 1> test.txt
./uls -rt /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rt /Users
ls -rt /Users 1> test.txt
./uls -rt /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rt /usr/bin
ls -rt /usr/bin 1> test.txt
./uls -rt /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rS
ls -rS 1> test.txt
./uls -rS 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rS /dev
ls -rS /dev 1> test.txt
./uls -rS /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rS /usr/bin
ls -rS /usr/bin 1> test.txt
./uls -rS /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rS /Users
ls -rS /Users 1> test.txt
./uls -rS /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtu
ls -rtu 1> test.txt
./uls -rtu 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtu /dev
ls -rtu /dev 1> test.txt
./uls -rtu /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtu /Users
ls -rtu /Users 1> test.txt
./uls -rtu /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtu /usr/bin
ls -rtu /usr/bin 1> test.txt
./uls -rtu /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtc
ls -rtc 1> test.txt
./uls -rtc 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtc /dev
ls -rtc /dev 1> test.txt
./uls -rtc /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtc /Users
ls -rtc /Users 1> test.txt
./uls -rtc /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -rtc /usr/bin
ls -rtc /usr/bin 1> test.txt
./uls -rtc /usr/bin 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ flags -C, -1, -m

echo Test: ls -C
ls -C 1> test.txt
./uls -C 1> user.txt
diff -q test.txt user.txt

echo Test: ls -C /dev
ls -C /dev 1> test.txt
./uls -C /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -C /Users
ls -C /Users 1> test.txt
./uls -C /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -C /usr/bin
ls -C /usr/bin 1> test.txt
./uls -C /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -1
ls -1 1> test.txt
./uls -1 1> user.txt
diff -q test.txt user.txt

echo Test: ls -1 /dev
ls -1 /dev 1> test.txt
./uls -1 /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -1 /Users
ls -1 /Users 1> test.txt
./uls -1 /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -1 /usr/bin
ls -1 /usr/bin 1> test.txt
./uls -1 /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -m
ls -m 1> test.txt
./uls -m 1> user.txt
diff -q test.txt user.txt

echo Test: ls -m /dev
ls -m /dev 1> test.txt
./uls -m /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -m /Users
ls -m /Users 1> test.txt
./uls -m /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -m /usr/bin
ls -m /usr/bin 1> test.txt
./uls -m /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -mC
ls -mC 1> test.txt
./uls -mC 1> user.txt
diff -q test.txt user.txt

echo Test: ls -mC /dev
ls -mC /dev 1> test.txt
./uls -mC /dev 1> user.txt
diff -q test.txt user.txt

echo Test: ls -Cm /Users
ls -Cm /Users 1> test.txt
./uls -Cm /Users 1> user.txt
diff -q test.txt user.txt

echo Test: ls -Cm /usr/bin
ls -Cm /usr/bin 1> test.txt
./uls -Cm /usr/bin 1> user.txt
diff -q test.txt user.txt

echo Test: ls -ml
ls -ml 1> test.txt
./uls -ml 1> user.txt
diff -q test.txt user.txt

echo Test: ls -m1
ls -m1 1> test.txt
./uls -m1 1> user.txt
diff -q test.txt user.txt

echo ------------------------------------------ speed

echo Test: ls -lR /Users/login
#diff -q time ls -lR /Users/login time ./uls -lR /Users/login
#time ls -lR /Users/trohalska
#time ./uls -lR /Users/trohalska


echo ------------------------------------------ memory leeks

echo add system "leaks -q uls" in main

diff -q ls $1 $2 $3 $4 $5 $6 ./uls $1 $2 $3 $4 $5 $6
