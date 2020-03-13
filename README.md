# uls
 ### Description:
 Ucode project: recode the MacOS system's utility ls using C.
 
 Designed to work with flags -ACGRSTacfghlmnortu1.
 
 ### Usage:
 ```
 1. make
 2 ./uls [-ACGRSTacfghlmnortu1] [filename]
 ```
 ### Develop details:
 * flags aAf influence on multicolum print;
 * flags mtcu don't work properly on big amounts with multicolum print;
 * whitespaces in filenames doesn't print as '?';
 * time ./uls -Rl /Users/login = 15-20sec (time ls = 6-9sec)
 
