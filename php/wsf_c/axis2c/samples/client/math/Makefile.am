prgbindir=$(prefix)/samples/bin
prgbin_PROGRAMS = math
noinst_HEADERS = axis2_math_stub.h
math_SOURCES = axis2_math_stub.c \
                math_client.c

math_LDADD   =  \
                -L$(WSFC_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                    $(GUTHTHILA_LIBS)

INCLUDES = @AXIS2INC@

EXTRA_DIST=math.mk
