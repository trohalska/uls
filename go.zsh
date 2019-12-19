
echo --------------------------------------- ERRORS

echo Test: ls --
diff <(ls --) <(./uls --)

echo Test: ls xxx
diff <(ls xxx) <(./uls xxx)

echo Test: ls -- -l
diff <(ls -- -l) <(./uls -- -l)

echo Test: ls -- libmx
diff <(ls -- libmx) <(./uls -- libmx)

echo Test: ls -- xxx libmx
diff <(ls -- xxx libmx) <(./uls -- xxx libmx)

echo Test: ls -- xxx libmx -l
diff <(ls xxx libmx -l) <(./uls xxx libmx -l)

echo --------------------------------------- Without flags

echo Test: ls
diff <(ls) <(./uls)

echo Test: ls -C
diff -q <(ls -C) <(./uls -C)

echo Test: ls | cat -e
diff <(ls | cat -e) <(./uls | cat -e)

#echo Test: ls -C | cat -e
#diff <(ls -C | cat -e) <(./uls -C | cat -e)

echo Test: ls libmx
diff <(ls libmx) <(./uls libmx)

echo Test: ls libmx | cat -e
diff <(ls libmx | cat -e) <(./uls libmx | cat -e)

echo Test: ls Makefile
diff <(ls Makefile) <(./uls Makefile)

echo Test: ls libmx Makefile
diff <(ls libmx Makefile) <(./uls libmx Makefile)

echo --------------------------------------- Flag -l

echo Test: ls -l
diff -q <(ls -l) <(./uls -l)

echo Test: ls -l | cat -e
diff -q <(ls -l | cat -e) <(./uls -l | cat -e)

echo Test: ls -l libmx
diff -q <(ls -l libmx) <(./uls -l libmx)

echo Test: ls -l /dev
diff -q <(ls -l /dev) <(./uls -l /dev)

echo Test: ls -l /dev/null
diff -q <(ls -l /dev/null) <(./uls -l /dev/null)

echo Test: ls -l /usr/bin
diff -q <(ls -l /usr/bin) <(./uls -l /usr/bin)

echo --------------------------------------- links

ln -s /libmx/ link1
ln -s Makefile link2
cd libmx && rm -rf libmx && cd ..

echo Test: ls -l
diff -q <(ls -l) <(./uls -l)

echo Test: ls link1
diff -q <(ls link1) <(./uls link1)

echo Test: ls link2
diff -q <(ls link2) <(./uls link2)

echo Test: ls -l link1
diff -q <(ls -l link1) <(./uls -l link1)

echo Test: ls -l link2
diff -q <(ls link1) <(./uls link1)

echo --------------------------------------- Attr @ and ACL +

echo Test: ls -l
diff -q <(ls -l) <(./uls -l)

echo Test: ls -l /Users/
diff -q <(ls -l /Users/) <(./uls -l /Users/)

echo ---------------------------------------multicolumn

echo Test: ls /dev/
diff -q <(ls /dev/) <(./uls /dev/)

echo Test: ls libmx /Users/ Makefile link1
diff -q <(ls libmx /Users/ Makefile link1) <(./uls libmx /Users/ Makefile link1)

echo --------------------------------------- flag -R

echo Test: ls -R
diff -q <(ls -R) <(./uls -R)

echo Test: ls -Rl
diff -q <(ls -Rl) <(./uls -Rl)

echo Test: ls -Rl | cat -e
diff -q <(ls -Rl | cat -e) <(./uls -Rl | cat -e)

echo Test: ls -Rl libmx inc Makefile link1
diff -q <(ls -Rl) <(./uls -Rl)

echo Test: ls -lR link1
diff -q <(ls -lR link1) <(./uls -lR link1)

echo Test: ls -R link1
diff -q <(ls -R link1) <(./uls -R link1)

echo --------------------------------------- flag -a -A -f

echo Test: ls -a
diff -q <(ls -a) <(./uls -a)

echo Test: ls -A
diff -q <(ls -A) <(./uls -A)

echo Test: ls -f
diff -q <(ls -f) <(./uls -f)

echo Test: ls -a libmx inc Makefile link1
diff -q <(ls -a libmx inc Makefile link1) <(./uls -a libmx inc Makefile link1)

echo Test: ls -A libmx inc Makefile link1
diff -q <(ls -A libmx inc Makefile link1) <(./uls -A libmx inc Makefile link1)

echo Test: ls -f libmx inc Makefile link1
diff  <(ls -f libmx inc Makefile link1) <(./uls -f libmx inc Makefile link1)

echo Test: ls -a /Users/
diff -q <(ls -a /Users/) <(./uls -a /Users/)

echo Test: ls -A /Users/
diff -q <(ls -A /Users/) <(./uls -A /Users/)

echo Test: ls -f /Users/
diff -q <(ls -f /Users/) <(./uls -f /Users/)

echo Test: ls -fS
diff -q <(ls -fS) <(./uls -fS)

echo Test: ls -ftu
diff -q <(ls -ftu) <(./uls -ftu)

echo --------------------------------------- flag -Ra -RA

echo Test: ls -aR
diff -q <(ls -Ra) <(./uls -aR)

echo Test: ls -AR
diff <(ls -AR) <(./uls -AR)

#(ls -AR) 1> text1.text
#(./uls -AR) 1> text2.text

echo Test: ls -aR libmx
diff -q <(ls -Ra libmx) <(./uls -aR libmx)

echo Test: ls -AR libmx
diff -q <(ls -AR libmx) <(./uls -AR libmx)

#echo Test: ls -aR /Users/trohalska
#diff -q <(ls -Ra /Users/trohalska) <(./uls -aR /Users/trohalska)

echo --------------------------------------- flag -G

#echo Test: ls -G
#diff -q <(ls -G) <(./uls -G)

#echo Test: ls -G | cat -e
#diff -q <(ls -G | cat -e) <(./uls -G | cat -e)

#echo Test: ls -Gl
#diff -q <(ls -Gl) <(./uls -Gl)

#echo Test: ls -Gl /Users/
#diff -q <(ls -Gl) <(./uls -Gl)

echo --------------------------------------- flag -lh, -le, -lT, -l@

echo Test: ls -lh
diff -q <(ls -lh) <(./uls -lh)

echo Test: ls -lh /dev/
diff -q <(ls -lh /dev/) <(./uls -lh /dev/)

#echo Test: ls -le
#diff -q <(ls -le) <(./uls -le)

#echo Test: ls -lT
#diff -q <(ls -lT) <(./uls -lT)

#echo Test: ls -l@
#diff -q <(ls -l@) <(./uls -l@)

echo --------------------------------------- flag -r, -t, -S, -c, -u

echo Test: ls -S
diff -q <(ls -S) <(./uls -S)

echo Test: ls -t
diff -q <(ls -t) <(./uls -t)

echo Test: ls -tu
diff -q <(ls -tu) <(./uls -tu)

echo Test: ls -tc
diff -q <(ls -tc) <(./uls -tc)

echo Test: ls -St
diff -q <(ls -St) <(./uls -St)

echo Test: ls -r
diff -q <(ls -r) <(./uls -r)

echo Test: ls -rt
diff -q <(ls -rt) <(./uls -rt)

echo Test: ls -rS
diff  <(ls -rS) <(./uls -rS)

echo Test: ls -rtu
diff -q <(ls -rtu) <(./uls -rtu)

echo Test: ls -rtc
diff -q <(ls -rtc) <(./uls -rct)

echo --------------------------------------- speed

echo Test: ls -lR /Users/login
#diff -q <(time ls -lR /Users/login) <(time ./uls -lR /Users/login)
#time ls -lR /Users/trohalska
#time ./uls -lR /Users/trohalska

echo --------------------------------------- memory leeks

echo add system "leaks -q uls" in main

rm -rf link1 link2
