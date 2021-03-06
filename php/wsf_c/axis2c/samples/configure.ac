dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(axis2c-sample-src, 1.7.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
dnl AM_INIT_AUTOMAKE([tar-ustar])
AM_INIT_AUTOMAKE
m4_ifdef([_A][M_PROG_TAR],[_A][M_SET_OPTION([tar-ustar])])
AC_PREFIX_DEFAULT(/usr/local/axis2c)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl check for flavours of varargs macros (test from GLib)
AC_MSG_CHECKING(for ISO C99 varargs macros in C)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(...) a(1,__VA_ARGS__)
call_a(2,3);
],axis2c_have_iso_c_varargs=yes,axis2c_have_iso_c_varargs=no)
AC_MSG_RESULT($axis2c_have_iso_c_varargs)

AC_MSG_CHECKING(for GNUC varargs macros)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(params...) a(1,params)
call_a(2,3);
],axis2c_have_gnuc_varargs=yes,axis2c_have_gnuc_varargs=no)
AC_MSG_RESULT($axis2c_have_gnuc_varargs)

dnl Output varargs tests
if test x$axis2c_have_iso_c_varargs = xyes; then
    AC_DEFINE(HAVE_ISO_VARARGS,1,[Have ISO C99 varargs macros])
fi
if test x$axis2c_have_gnuc_varargs = xyes; then
    AC_DEFINE(HAVE_GNUC_VARARGS,1,[Have GNU-style varargs macros])
fi

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)

CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
       CFLAGS="$CFLAGS -ansi -Wall  -Wno-implicit-function-declaration -g -D_GNU_SOURCE"
fi

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC

CFLAGS="$CFLAGS $GUTHTHILA_CFLAGS"

AC_MSG_CHECKING(whether to build dynamic invocation client)
AC_ARG_ENABLE(diclient, [  --enable-diclient    build diclient. default=no],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    DICLIENT_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    DICLIENT_DIR="diclient"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  DICLIENT_DIR=""
)

AC_MSG_CHECKING(To Use Axis2 C . This is a compulsory module to build Axis2 C samples)
AC_ARG_WITH(axis2,
[  --with-axis2[=PATH]     Find the AXIS2 header files in 'PATH'.
    'PATH' should point to AXIS2 include files location.
    If you omit the '=PATH' part completely, the configure script will search
    '${WSFC_HOME}/include/axis2-1.7.0' for AXIS2 headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find axis2 include dir in the path
    if test -d $withval; then
        axis2inc="-I$withval"
    dnl else find the axiom include dir in ${WSFC_HOME}/include
    elif test -d "${WSFC_HOME}/include"; then
        axis2inc="-I${WSFC_HOME}/include/axis2-1.7.0"
    else
        AC_MSG_ERROR(could not find axis2. stop)
    fi
    ;;
  esac ],
  if test -d "${WSFC_HOME}/include"; then
  	axis2inc="-I${WSFC_HOME}/include/axis2-1.7.0"
  fi
  AC_MSG_RESULT(no)
)

APACHE2INC=$apache2inc
AXIS2INC=$axis2inc
APRINC=$aprinc

AC_SUBST(APACHE2INC)
AC_SUBST(APRINC)
AC_SUBST(AXIS2INC)
AC_SUBST(GUTHTHILA_DIR)
AC_SUBST(GUTHTHILA_LIBS)
AC_SUBST(DICLIENT_DIR)

AC_CONFIG_FILES([Makefile \
    server/Makefile \
    server/echo/Makefile \
    server/math/Makefile \
    server/version/Makefile \
    server/Calculator/Makefile \
    server/notify/Makefile \
    server/sg_math/Makefile \
    server/mtom/Makefile \
    server/mtom_callback/Makefile \
    server/session/Makefile \
    client/Makefile \
    client/echo/Makefile \
    client/math/Makefile \
    client/version/Makefile \
    client/mtom/Makefile \
    client/mtom_callback/Makefile \
    client/mtom/resources/Makefile \
    client/notify/Makefile \
    client/google/Makefile \
    client/yahoo/Makefile \
    client/amqp/Makefile \
    client/amqp/echo/Makefile \
    client/amqp/notify/Makefile \
    client/amqp/mtom/Makefile \
    client/amqp/mtom/resources/Makefile \
    client/session/Makefile \
    user_guide/Makefile \
    user_guide/clients/Makefile \
    mtom_caching_callback/Makefile \
    mtom_sending_callback/Makefile    
    ])
    
AC_OUTPUT

