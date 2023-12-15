# CD-Lab
This are the codes for Compiler Design Lab

# How to Run
In Linux Terminal: <br>
## 1. Lex Programs
```
lex filename.l
```
```
gcc lex.yy.c
```
```
./a.out
```
<br>

## 2. YACC Program <br>
```
lex filename.l
```
```
yacc -d identifier.y
```
```
gcc lex.yy.c y.tab.c -lfl
```
```
./a.out
```
<br>

## 3. C Program
```
gcc filename.c
```
```
./a.out
```
