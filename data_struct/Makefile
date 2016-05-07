default: all

LIBDIR=lib

COPTS := -Wall -Werror
DEFINES := -Dwubo
INCLUDES := -I/mnt/d/test/data_struct


CFLAGS = $(COPTS) $(DEFINES) $(INCLUDES)

CC = gcc
AR = ar
RM = rm -f

CSRCS := $(wildcard *.c)
OBJS := $(CSRCS:%.c=%.o)
DEPS := $(CSRCS:%.c=%.d)
LIBS :=


LDFLAGS =


ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),mkdbg)
ifdef DEPS
sinclude $(DEPS)
endif
endif
endif



LIB=
EXE=test

$(LIB): $(OBJS)
	@mkdir -p $(LIBDIR)
	$(AR) ru $@ $^

$(EXE): $(LIBS) $(LDS) $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

all: $(OBJS) $(EXE)

clean:
	$(foreach d, $(SUBDIRS), make -C $(d) clean;)
	$(RM) *.o
	$(RM) $(LIB)


mkdbg:
	@echo pwd=`pwd`
	@echo SUBDIRS = $(SUBDIRS)
	@echo CSRCS = $(CSRCS)
	@echo OBJS = $(OBJS)
	@echo DEPS = $(DEPS)
	@echo LIBS = $(LIBS)
	@echo CC = $(CC) at `which $(CC)`
	@echo CFLAGS = $(CFLAGS)
	@echo LDFLAGS = $(LDFLAGS)
