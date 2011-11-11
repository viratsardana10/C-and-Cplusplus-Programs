PROGRAM = show_tickets
CC      = gcc
LD      = $(CC)
MAKE    = gmake -k

C_SRCS  = show_tickets.c
CC_SRCS =
OBJS    = ${CC_SRCS:.cc=.o} ${C_SRCS:.c=.o}

FREEBSD:
	@$(MAKE) \
	'CFLAGS = -Wall -g' \
	'INCDIRS= ' \
	'LIBDIRS= -L../liblott' \
	'LIBS   = -lkvm -llott' \
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

show_tickets.o: /usr/include/sys/types.h /usr/include/machine/ansi.h
show_tickets.o: /usr/include/machine/types.h /usr/include/machine/endian.h
show_tickets.o: /usr/include/sys/cdefs.h /usr/include/errno.h
show_tickets.o: /usr/include/fcntl.h /usr/include/kvm.h /usr/include/nlist.h
show_tickets.o: /usr/include/limits.h /usr/include/machine/limits.h
show_tickets.o: /usr/include/sys/syslimits.h /usr/include/stdio.h
show_tickets.o: /usr/include/stdlib.h /usr/include/unistd.h
show_tickets.o: /usr/include/sys/unistd.h ../liblott/liblott.h
show_tickets.o: /usr/include/sys/queue.h /usr/include/sys/lottery.h
show_tickets.o: /usr/include/sys/param.h /usr/include/sys/signal.h
show_tickets.o: /usr/include/machine/signal.h /usr/include/machine/trap.h
show_tickets.o: /usr/include/machine/param.h
