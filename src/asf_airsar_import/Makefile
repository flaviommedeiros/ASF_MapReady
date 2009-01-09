# Makefile for: asf_airsar_import
# Wrapper for ingesting AirSAR data

include ../../make_support/system_rules

LIBS  = \
	$(LIBDIR)/libasf_import.a \
	$(LIBDIR)/libasf_sar.a \
	$(LIBDIR)/asf_meta.a \
	$(LIBDIR)/libasf_proj.a \
	$(LIBDIR)/asf.a \
	$(PROJ_LIBS) \
	$(GSL_LIBS) \
	-lm

all: asf_airsar_import

asf_airsar_import: asf_airsar_import.c
	$(CC) $(CFLAGS) -o asf_airsar_import asf_airsar_import.c $(LIBS)
	mv  asf_airsar_import$(BIN_POSTFIX) $(BINDIR)

clean:
	rm -f *.o core