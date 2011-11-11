PROGRAM = lott_userlevel
CC      = gcc
LD      = $(CC)
MAKE    = gmake -k
LIB	= liblott
UTILS   = lott_chuser lott_ctl lott_rinfo lott_stat run_tickets\
          set_tickets set_funding force_sched show_tickets show_funding\
          set_handoff
KMEM_UTILS = 
SHELL = /bin/sh

$(PROGRAM):
	cd $(LIB);			\
        make FREEBSD-DEPEND;		\
        make clean;			\
        make FREEBSD;			\
	cd ..;				
	for PROG in $(UTILS); do	\
	    cd $$PROG;			\
            make FREEBSD-DEPEND;	\
            make clean;			\
            make FREEBSD;		\
	    cd ..;			\
	done				
	for PROG in $(KMEM_UTILS); do	\
	    cd $$PROG;			\
            make FREEBSD-DEPEND;	\
            make clean;			\
            make FREEBSD;		\
	    chown bin:kmem $$PROG;	\
	    cd ..;			\
	done

install:
	cd $(LIB);			\
        make FREEBSD-DEPEND;		\
        make clean;			\
        make FREEBSD;			\
	cd ..;				
	for PROG in $(UTILS); do	\
	    cd $$PROG;			\
            make FREEBSD-DEPEND;	\
            make clean;			\
            make FREEBSD;		\
            chown bin:bin $$PROG;	\
            chmod 555 $$PROG;		\
	    cd ..;			\
	done				
	for PROG in $(KMEM_UTILS); do	\
	    cd $$PROG;			\
            make FREEBSD-DEPEND;	\
            make clean;			\
            make FREEBSD;		\
	    chown bin:kmem $$PROG;	\
            chmod 555 $$PROG;		\
	    chmod g+s $$PROG;		\
	    cd ..;			\
	done
