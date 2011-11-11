PROGRAM = liblott
CC      = gcc
LD      = $(CC)
MAKE    = gmake -k

C_SRCS  = liblott.c
CC_SRCS =
OBJS    = ${CC_SRCS:.cc=.o} ${C_SRCS:.c=.o}

FREEBSD:
	@$(MAKE) \
	'CFLAGS = -Wall -g' \
	'INCDIRS= ' \
	'LIBDIRS= ' \
	'LIBS   = ' \
	$(PROGRAM)

FREEBSD-DEPEND:
	@$(MAKE) \
	'INCDIRS= ' \
	depend

$(PROGRAM): $(OBJS) 
#@echo "Linking $(PROGRAM)..."
#$(LD) $(OBJS) $(LIBDIRS) $(LIBS) -o $(PROGRAM)
#@echo "done."
	@echo "Creating $(PROGRAM) library..."
	ar -rv liblott.a $(OBJS)
	@echo "done."

%.o: %.cc
	$(CC) $(CFLAGS) $(INCDIRS) -c $<

clean:
	@/bin/rm -f *.o *~ core *.bak *.yy.c

depend:
	@makedepend $(INCDIRS) $(C_SRCS) $(CC_SRCS)

# DO NOT DELETE THIS LINE -- make depend depends on it.

liblott.o: /usr/include/sys/param.h /usr/include/sys/types.h
liblott.o: /usr/include/machine/ansi.h /usr/include/machine/types.h
liblott.o: /usr/include/machine/endian.h /usr/include/sys/cdefs.h
liblott.o: /usr/include/sys/syslimits.h /usr/include/sys/signal.h
liblott.o: /usr/include/machine/signal.h /usr/include/machine/trap.h
liblott.o: /usr/include/machine/param.h /usr/include/machine/limits.h
liblott.o: /usr/include/sys/syscall.h /usr/include/unistd.h
liblott.o: /usr/include/sys/unistd.h liblott.h /usr/include/sys/queue.h
liblott.o: /usr/include/sys/lottery.h
