PROGRAM = lott_ctl
CC      = gcc
LD      = $(CC)
MAKE    = gmake -k

C_SRCS  = lott_ctl.c
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

lott_ctl.o: /usr/include/sys/types.h /usr/include/machine/ansi.h
lott_ctl.o: /usr/include/machine/types.h /usr/include/machine/endian.h
lott_ctl.o: /usr/include/sys/cdefs.h /usr/include/errno.h
lott_ctl.o: /usr/include/stdio.h /usr/include/stdlib.h ../liblott/liblott.h
lott_ctl.o: /usr/include/sys/queue.h /usr/include/sys/lottery.h
lott_ctl.o: /usr/include/sys/param.h /usr/include/sys/syslimits.h
lott_ctl.o: /usr/include/sys/signal.h /usr/include/machine/signal.h
lott_ctl.o: /usr/include/machine/trap.h /usr/include/machine/param.h
lott_ctl.o: /usr/include/machine/limits.h
