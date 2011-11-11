PROGRAM = lott_rinfo
CC      = gcc
LD      = $(CC)
MAKE    = gmake -k

C_SRCS  = lott_rinfo.c
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

lott_rinfo.o: /usr/include/sys/types.h /usr/include/machine/ansi.h
lott_rinfo.o: /usr/include/machine/types.h /usr/include/machine/endian.h
lott_rinfo.o: /usr/include/sys/cdefs.h /usr/include/sys/proc.h
lott_rinfo.o: /usr/include/machine/proc.h /usr/include/sys/rtprio.h
lott_rinfo.o: /usr/include/sys/select.h /usr/include/sys/time.h
lott_rinfo.o: /usr/include/sys/time.h /usr/include/sys/queue.h
lott_rinfo.o: /usr/include/sys/param.h /usr/include/sys/syslimits.h
lott_rinfo.o: /usr/include/sys/signal.h /usr/include/machine/signal.h
lott_rinfo.o: /usr/include/machine/trap.h /usr/include/machine/param.h
lott_rinfo.o: /usr/include/machine/limits.h /usr/include/errno.h
lott_rinfo.o: /usr/include/stdio.h /usr/include/stdlib.h
lott_rinfo.o: /usr/include/string.h ../liblott/liblott.h
lott_rinfo.o: /usr/include/sys/lottery.h
