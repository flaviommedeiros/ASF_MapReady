CFLAGS += $(HDF5_CFLAGS)
CFLAGS += $(GEOTIFF_CFLAGS)
CFLAGS += $(HDF5_CFLAGS)
# Makefile for		: deramp
# Module Author		: Mike Shindle

include ../../make_support/system_rules

LIBS  = \
	$(LIBDIR)/libasf_insar.a \
	$(LIBDIR)/asf_meta.a \
	$(GSL_LIBS) \
	$(LIBDIR)/libasf_proj.a \
	$(PROJ_LIBS) \
	$(LIBDIR)/asf.a \
	$(XML_LIBS) \
	-lm 
OBJS = deramp.o 
        

deramp: $(OBJS)
	$(CC) $(CFLAGS) -o deramp $(OBJS) $(LIBS) $(LDFLAGS)
	mv deramp$(BIN_POSTFIX) $(BINDIR)
	rm *.o
	cp deramp.1 ../../man/man1
