#MAKEFILE

FILENAME = tp1
FILETARGET = tcv
CFLAGS = -Wall -Werror=vla -pedantic -std=c11 -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu
FILEURL = https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip

$(FILENAME).o: $(FILENAME).c
	gcc $(CFLAGS) -o $(FILENAME) $(FILENAME).c $(FILETARGET).o -lcunit

lib:
	wget $(FILEURL) -P ./data
	cd data; unzip $(FILENAME).zip -d ../;rm tp1.zip

.PHONY: clean

clean:
	rm -f $(FILENAME)
	rm -rf data


