PROGRAM = run_tickets
CC      = gcc
LD      = $(CC)
MAKE    = gmake -k

C_SRCS  = run_tickets.c
CC_SRCS =
OBJS    = ${CC_SRCS:.cc=.o} ${C_SRCS:.c=.o}

FREEBSD:
	@$(MAKE) \
	'CFLAGS = -Wall -g' \
	'INCDIRS= ' \
	'LIBDIRS= -L../liblott' \
	'LIBS   = -llott' \
	$(PROGRAM)

FREEBSD-DEPEND:
	@$(MAKE) \
	'INCDIRS= ' \
	depend

$(PROGRAM): $(OBJS) 
	@echo "Linking $(PROGRAM)..."
	$(LD) $(OBJS) $(LIBDIRS) $(LIBS) -o $(PROGRAM)
	@echo "done."

%.o: %.cc
	$(CC) $(CFLAGS) $(INCDIRS) -c $<

clean:
	@/bin/rm -f *.o *~ core *.bak *.yy.c

depend:
	@makedepend $(INCDIRS) $(C_SRCS) $(CC_SRCS)

# DO NOT DELETE THIS LINE -- make depend depends on it.

run_tickets.o: /usr/include/sys/types.h /usr/include/machine/ansi.h
run_tickets.o: /usr/include/machine/types.h /usr/include/machine/endian.h
run_tickets.o: /usr/include/sys/cdefs.h /usr/include/errno.h
run_tickets.o: /usr/include/stdio.h /usr/include/stdlib.h
run_tickets.o: /usr/include/unistd.h /usr/include/sys/unistd.h
run_tickets.o: ../liblott/liblott.h /usr/include/sys/queue.h
run_tickets.o: /usr/include/sys/lottery.h /usr/include/sys/param.h
run_tickets.o: /usr/include/sys/syslimits.h /usr/include/sys/signal.h
run_tickets.o: /usr/include/machine/signal.h /usr/include/machine/trap.h
run_tickets.o: /usr/include/machine/param.h /usr/include/machine/limits.h
