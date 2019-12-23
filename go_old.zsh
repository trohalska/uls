

echo --------------------------------------- ERRORS

echo Test: ls -#
diff <(ls -#) <(./uls -#)

echo Test: ls --
diff <(ls --) <(./uls --)

echo Test: ls xxx
diff <(ls xxx) <(./uls xxx)

echo Test: ls -- -l
diff <(ls -- -l) <(./uls -- -l)

echo Test: ls -- libmx
diff <(ls -- libmx) <(./uls -- libmx)

echo Test: ls -- Makefile
diff <(ls -- Makefile) <(./uls -- Makefile)

echo Test: ls xxx Makefile
diff <(ls xxx Makefile) <(./uls xxx Makefile)

echo Test: ls -- xxx Makefile
diff <(ls -- xxx Makefile) <(./uls -- xxx Makefile)

echo Test: ls -- xxx libmx
diff <(ls -- xxx libmx) <(./uls -- xxx libmx)

echo Test: ls -- xxx libmx -l
diff <(ls xxx libmx -l) <(./uls xxx libmx -l)

echo Test: ls -- xxx libmx -l Makefile
diff <(ls xxx libmx -l Makefile) <(./uls xxx libmx -l Makefile)

echo --------------------------------------- Without flags

echo Test: ls
diff <(ls) <(./uls)

echo Test: ls | cat -e
diff <(ls | cat -e) <(./uls | cat -e)

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
diff <(ls -l /dev) <(./uls -l /dev)

echo Test: ls -l /dev/null
diff -q <(ls -l /dev/null) <(./uls -l /dev/null)

echo Test: ls -l /Users
diff <(ls -l /Users) <(./uls -l /Users)

echo Test: ls -l /usr/bin
diff -q <(ls -l /usr/bin) <(./uls -l /usr/bin)

echo --------------------------------------- links

ln -s libmx link1
ln -s Makefile link2

echo Test: ls -l
diff -q <(ls -l) <(./uls -l)

echo Test: ls link1
diff -q <(ls link1) <(./uls link1)

echo Test: ls link2
diff -q <(ls link2) <(./uls link2)

echo Test: ls -l link1
diff -q <(ls -l link1) <(./uls -l link1)

echo Test: ls -l link2
diff -q <(ls link2) <(./uls link2)

echo --------------------------------------- Attr @ and ACL +

echo Test: ls -l, ls -l /Users - if was correct

echo ---------------------------------------multicolumn

echo Test: ls /dev/
diff -q <(ls /dev/) <(./uls /dev/)

echo Test: ls /usr/bin
diff -q <(ls /usr/bin) <(./uls /usr/bin)

echo Test: ls /Users
diff -q <(ls /Users) <(./uls /Users)

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
diff -q <(ls -Rl libmx inc Makefile link1) <(./uls -Rl libmx inc Makefile link1)

echo Test: ls -lR link1
diff -q <(ls -lR link1) <(./uls -lR link1)

echo Test: ls -R link1
diff -q <(ls -R link1) <(./uls -R link1)

echo Test: ls -Rl /usr/bin
diff -q <(ls -Rl /usr/bin) <(./uls -Rl /usr/bin)

echo --------------------------------------- flag -a -A -f

echo Test: ls -a
diff -q <(ls -a) <(./uls -a)

echo Test: ls -A
diff -q <(ls -A) <(./uls -A)

echo Test: ls -f
diff -q <(ls -f) <(./uls -f)

echo Test: ls -al
diff -q <(ls -al) <(./uls -al)

echo Test: ls -Al
diff -q <(ls -Al) <(./uls -Al)

echo Test: ls -fl
diff -q <(ls -fl) <(./uls -fl)

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

echo Test: ls -a /dev
diff -q <(ls -a /dev) <(./uls -a /dev)

echo Test: ls -A /dev
diff -q <(ls -A /dev) <(./uls -A /dev)

echo Test: ls -f /dev
diff -q <(ls -f /dev) <(./uls -f /dev)

echo Test: ls -a /usr/bin
diff -q <(ls -a /usr/bin) <(./uls -a /usr/bin)

echo Test: ls -A /usr/bin
diff -q <(ls -A /usr/bin) <(./uls -A /usr/bin)

echo Test: ls -f /usr/bin
diff -q <(ls -f /usr/bin) <(./uls -f /usr/bin)

echo Test: ls -fS
diff -q <(ls -fS) <(./uls -fS)

echo Test: ls -ftu
diff -q <(ls -ftu) <(./uls -ftu)

echo --------------------------------------- flag -Ra -RA

echo Test: ls -aR
diff -q <(ls -Ra) <(./uls -aR)

echo Test: ls -AR
diff <(ls -AR) <(./uls -AR)

echo Test: ls -aR libmx
diff -q <(ls -Ra libmx) <(./uls -aR libmx)

echo Test: ls -AR libmx
diff -q <(ls -AR libmx) <(./uls -AR libmx)

#echo Test: ls -aR /Users
#diff -q <(ls -Ra /Users) <(./uls -aR /Users)

#echo Test: ls -AR /Users
#diff -q <(ls -AR /Users) <(./uls -AR /Users)

echo --------------------------------------- flag -G

echo Test: ls -G
diff -q <(ls -G) <(./uls -G)

echo Test: ls -G | cat -e
diff -q <(ls -G | cat -e) <(./uls -G | cat -e)

echo Test: ls -Gl
diff -q <(ls -Gl) <(./uls -Gl)

echo Test: ls -Gl /dev
diff -q <(ls -Gl /dev) <(./uls -Gl /dev)

echo Test: ls -Gl /Users/
diff -q <(ls -Gl /Users/) <(./uls -Gl /Users/)

echo Test: ls -Gl /usr/bin
diff -q <(ls -Gl /usr/bin) <(./uls -Gl /usr/bin)

echo --------------------------------------- flag -lh, -le, -lT, -l@

echo Test: ls -lh
diff -q <(ls -lh) <(./uls -lh)

echo Test: ls -lh /dev/
diff -q <(ls -lh /dev/) <(./uls -lh /dev/)

echo Test: ls -lh /Users/
diff -q <(ls -lh /Users/) <(./uls -lh /Users/)

echo Test: ls -lh /usr/bin/
diff -q <(ls -lh /usr/bin/) <(./uls -lh /usr/bin/)

echo Test: ls -lT /dev/
diff -q <(ls -lT /dev/) <(./uls -lT /dev/)

echo Test: ls -lT /Users/
diff -q <(ls -lT /Users/) <(./uls -lT /Users/)

echo Test: ls -lT /usr/bin/
diff -q <(ls -lT /usr/bin/) <(./uls -lT /usr/bin/)

echo Test: ls -lT
diff -q <(ls -lT) <(./uls -lT)

#echo Test: ls -le
#diff -q <(ls -le) <(./uls -le)

#echo Test: ls -l@
#diff -q <(ls -l@) <(./uls -l@)

echo --------------------------------------- flag -r, -t, -S, -c, -u

echo Test: ls -S
diff -q <(ls -S) <(./uls -S)

echo Test: ls -S /Users
diff -q <(ls -S /Users) <(./uls -S /Users)

echo Test: ls -S /dev
diff -q <(ls -S /dev) <(./uls -S /dev)

echo Test: ls -S /usr/bin
diff -q <(ls -S /usr/bin) <(./uls -S /usr/bin)

echo Test: ls -t
diff -q <(ls -t) <(./uls -t)

echo Test: ls -t /Users
diff -q <(ls -t /Users) <(./uls -t /Users)

#echo Test: ls -t /dev
#diff -q <(ls -t /dev) <(./uls -t /dev)

#echo Test: ls -t /usr/bin
#diff -q <(ls -t /usr/bin) <(./uls -t /usr/bin)

echo Test: ls -tu
diff -q <(ls -tu) <(./uls -tu)

echo Test: ls -tu /Users
diff -q <(ls -tu /Users) <(./uls -tu /Users)

echo Test: ls -tu /dev
diff -q <(ls -tu /dev) <(./uls -tu /dev)

echo Test: ls -tu /usr/bin
diff -q <(ls -tu /usr/bin) <(./uls -tu /usr/bin)

echo Test: ls -tc
diff -q <(ls -tc) <(./uls -tc)

echo Test: ls -tc /Users
diff -q <(ls -tc /Users) <(./uls -tc /Users)

echo Test: ls -tc /dev
diff -q <(ls -tc /dev) <(./uls -tc /dev)

echo Test: ls -tc /usr/bin
diff -q <(ls -tc /usr/bin) <(./uls -tc /usr/bin)

echo Test: ls -St
diff -q <(ls -St) <(./uls -St)

echo Test: ls -r
diff -q <(ls -r) <(./uls -r)

echo Test: ls -rt
diff -q <(ls -rt) <(./uls -rt)

echo Test: ls -r /Users
diff -q <(ls -r /Users) <(./uls -r /Users)

echo Test: ls -r /dev
diff -q <(ls -r /dev) <(./uls -r /dev)

echo Test: ls -r /usr/bin
diff -q <(ls -r /usr/bin) <(./uls -r /usr/bin)

echo Test: ls -rS
diff  <(ls -rS) <(./uls -rS)

echo Test: ls -rS /Users
diff -q <(ls -rS /Users) <(./uls -rS /Users)

echo Test: ls -rS /dev
diff -q <(ls -rS /dev) <(./uls -rS /dev)

echo Test: ls -rS /usr/bin
diff -q <(ls -rS /usr/bin) <(./uls -rS /usr/bin)

echo Test: ls -rtu
diff -q <(ls -rtu) <(./uls -rtu)

echo Test: ls -rtu /Users
diff -q <(ls -rtu /Users) <(./uls -rtu /Users)

echo Test: ls -rtu /dev
diff -q <(ls -rtu /dev) <(./uls -rtu /dev)

echo Test: ls -rtu /usr/bin
diff -q <(ls -rtu /usr/bin) <(./uls -rtu /usr/bin)

echo Test: ls -rtc
diff -q <(ls -rtc) <(./uls -rct)

echo Test: ls -rtc /Users
diff -q <(ls -rtc /Users) <(./uls -rtc /Users)

#echo Test: ls -rtc /dev
#diff -q <(ls -rtc /dev) <(./uls -rtc /dev)

#echo Test: ls -rtc /usr/bin
#diff -q <(ls -rtc /usr/bin) <(./uls -rtc /usr/bin)

echo --------------------------------------- speed

echo Test: ls -lR /Users/login
#diff -q <(time ls -lR /Users/login) <(time ./uls -lR /Users/login)
#time ls -lR /Users/trohalska
#time ./uls -lR /Users/trohalska

echo --------------------------------------- memory leeks

echo add system "leaks -q uls" in main

rm -rf link1 link2
echo -----------------------------------
echo PRINT FLAGS m and C in diff behave not usual like cat -e
