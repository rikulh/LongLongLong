# LongLongLong
めっちゃでかい計算する。  
## 使い方の例
```
~$ g++ *.cpp
~$ ./a.out
Number(decimal):47
Pow(decimal):200
26276746248058029653195062543129241459776623599356316704415102882061300448681424404847986996096365206815681096496216030097368319180733042317571923927029564217440089767464660502082082343958954759710975698452264507212880027185746469395879234762400523717778375299952423104962244062864774718828864821063729460139712904807268093590692624001
0.18sec.
```
### LongLongLong(string val,int base)  
LongLongLong型を2進数、10進数の正の整数の文字列で初期化する。
baseには2か10をいれ、valには正の整数の文字列を入れる。
(10進数の場合には内部でlong long型を使用しているため値の大きさには注意。)
### LongLongLong ply(LongLongLong)
掛け算。
### LongLongLong plus(LongLongLong)
足し算。
### LongLongLong minus(LongLongLong)
引き算。(差が負になった場合の挙動は未検証。)
### LongLongLong pow(string times)
累乗。timesには10進数で累乗の回数を入れる。
### LongLongLong twoTimes(int times)
2の累乗乗する関数。timesには2の何乗乗するかを入れる。
### string toBiString()
LongLongLong型を2進数の文字列に変換。
### string toDecString()
LongLongLong型を10進数の文字列に変換。

