#MAKEFILE

FILENAME = tp1
FILENAME2 = tp2
FILENAME3 = tp3
FILETARGET2 = tcv.o malib.h malib.c
FILETARGET = tcv
FILETARGET3 = tcv.o malib.h malib.c outil3.h outil3.c
CFLAGS = -Wall -Werror=vla -pedantic -std=c11 -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu
FILEURL = https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip

$(FILENAME3): $(FILENAME3).c
	gcc $(CFLAGS) -o $(FILENAME3) $(FILENAME3).c $(FILETARGET3) -lm

$(FILENAME2): $(FILENAME2).c
	gcc $(CFLAGS) -o $(FILENAME2) $(FILENAME2).c $(FILETARGET3) -lm

$(FILENAME): $(FILENAME).c
	gcc $(CFLAGS) -o $(FILENAME) $(FILENAME).c $(FILETARGET).o -lcunit

lib:
	wget -q $(FILEURL) -P ./data
	unzip ./data/$(FILENAME2).zip -d ./

test-tp1a:
			-./tp1

test-tp1b:
	-./tp1 > output.txt
	-./liste.sh output.txt
	rm -f output.txt

test-$(FILENAME2):
	-./tp2

.PHONY: clean test-tp1b test-tp1a test-$(FILENAME2)

clean:
	rm -f $(FILENAME) *.o tcv.h
	rm -rf data
	rm -rf *.gch
	rm -f $(FILENAME2) *.o tcv.h
