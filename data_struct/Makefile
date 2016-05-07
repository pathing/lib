default: all

LIBDIR=lib

LINK_LIST_DIR=link_list
JSON_DIR=json
BSON_DIR=bson
HASH_DIR=hash

SAMPLE_DIR=sample

COPTS := -Wall -Werror
DEFINES := -Dpathing
INCLUDES := -I$(LINK_LIST_DIR) -I$(JSON_DIR)  \
			-I$(BSON_DIR) -I$(BSON_DIR) -I$(BSON_DIR)



CFLAGS = $(COPTS) $(DEFINES) $(INCLUDES)

CC = gcc
AR = ar
RM = rm -f

CSRCS := $(wildcard *.c)
CSRCS += $(wildcard $(LINK_LIST_DIR)/*.c)
CSRCS += $(wildcard $(JSON_DIR)/*.c)
CSRCS += $(wildcard $(BSON_DIR)/*.c)
CSRCS += $(wildcard $(HASH_DIR)/*.c)
CSRCS += $(wildcard $(SAMPLE_DIR)/*.c)
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
	$(RM) $(JSON_DIR)/*.o
	$(RM) $(BSON_DIR)/*.o
	$(RM) $(LINK_LIST_DIR)/*.o
	$(RM) $(HASH_DIR)/*.o
	$(RM) $(SAMPLE_DIR)/*.o
	$(RM) $(LIB)
	$(RM) $(EXE)


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
