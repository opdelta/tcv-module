#MAKEFILE

FILENAME = tp1
FILENAME2 = tp2
FILETARGET2 = tcv.o malib.h malib.c
FILETARGET = tcv
CFLAGS = -Wall -Werror=vla -pedantic -std=c11 -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu
FILEURL = https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip


$(FILENAME2).o: $(FILENAME2).c
	gcc $(CFLAGS) -o $(FILENAME2) $(FILENAME2).c $(FILETARGET2) -lm

tp1: $(FILENAME).c
	gcc $(CFLAGS) -o $(FILENAME) $(FILENAME).c $(FILETARGET).o -lcunit

lib:
	wget $(FILEURL) -P ./data
	cd data; unzip $(FILENAME).zip -d ../;rm tp1.zip
test-tp1a:
	-./tp1

test-tp1b:
	-./tp1 > output.txt
	-./liste.sh output.txt
	rm -f output.txt


.PHONY: clean

clean:
	rm -f $(FILENAME) *.o tcv.h
	rm -rf data
	rm -rf *.gch
	