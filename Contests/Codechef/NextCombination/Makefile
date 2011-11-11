########################################################################
# C++ Makefile -- Tom Draper 
# Installs and tests next_combination template
########################################################################
# testfile runs some tests on next_compbination template

testfile=TestNextCombination
hfile=next_combination.h

PREFIX=~

# things removed by "make clean"
junk= $(testfile) core.*

all:	$(testfile)

.C:
	g++ $@.C -o $@

test:	$(testfile)
	./$(testfile)

install:	$(hfile)
	 /bin/ln -fs $(PWD)/$(hfile) $(PREFIX)/include/$(hfile)

uninstall:
	/bin/rm -f $(PREFIX)/include/$(hfile)

clean:  
	/bin/rm -f $(junk)

