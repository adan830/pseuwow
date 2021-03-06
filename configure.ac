#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(FULL-PACKAGE-NAME, VERSION, BUG-REPORT-ADDRESS)
AM_INIT_AUTOMAKE(pseuwow, 0.1)
#AC_CONFIG_SRCDIR([src/shared/ProgressBar.h])
AM_CONFIG_HEADER([src/config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_RANLIB
AC_PROG_LIBTOOL

# Checks for libraries.
AC_CHECK_LIB([Xxf86vm], [main], [], [echo "ERROR: Xxf86vm library not found." && exit 1])
AC_CHECK_LIB([GL], [main], [], [echo "ERROR: GL library not found." && exit 1])
AC_CHECK_LIB([GLU], [main], [], [echo "ERROR: GLU library not found." && exit 1])
AC_CHECK_LIB([ssl], [main], [], [echo "ERROR: ssl library not found." && exit 1])
AC_CHECK_LIB([crypto], [main], [], [echo "ERROR: ssl crypto library not found." && exit 1])

# Checks for header files.
AC_PATH_X
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([arpa/inet.h fcntl.h float.h inttypes.h limits.h malloc.h memory.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h sys/param.h sys/socket.h sys/time.h sys/timeb.h unistd.h utime.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_HEADER_TIME
AC_STRUCT_TM
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_C_VOLATILE
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_STAT
AC_FUNC_UTIME_NULL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([floor ftime ftruncate getcwd gethostbyaddr gethostbyname gethostname gettimeofday memmove memset mkdir pow realpath select socket sqrt strerror strrchr strstr strtol strtoul uname utime])


# Check if IrrKlang stub needs to be built

AC_ARG_WITH(irrklang,
[  --with-irrklang            Use IrrKlang stub (needed for x64 (default: no)],
[case "${withval}" in
    yes) DO_IRRKLANG=yes ;;
    no)  DO_IRRKLANG=no ;;
    maybe) DO_IRRKLANG=maybe ;;
    *)   AC_MSG_ERROR(Bad value ${withval} for --with-irrklang) ;;
    esac],
[DO_IRRKLANG=no])
AC_MSG_CHECKING(whether to build/link IrrKlang)
if test "x$DO_IRRKLANG" = "xyes"; then
  AC_MSG_RESULT($DO_IRRKLANG)
  IRRKLANG_DIR=irrKlang
  IRRKLANG_LIB=../dep/src/irrKlang/libIrrKlang.la
else
  AC_MSG_RESULT($DO_IRRKLANG)
  IRRKLANG_DIR=
  IRRKLANG_LIB=$(prefix)/bin/libIrrKlang.so
fi
AC_SUBST([IRRKLANG_DIR])
AC_SUBST([IRRKLANG_LIB])



AC_CONFIG_FILES([Makefile
		 src/Makefile
		 src/dep/Makefile
         src/dep/src/Makefile
		 src/dep/src/zlib/Makefile
		 src/dep/src/zthread/Makefile
         src/dep/src/irrKlang/Makefile
         src/dep/src/StormLib/Makefile
         src/tools/Makefile
         src/tools/viewer/Makefile
		 src/tools/stuffextract/Makefile
		 src/shared/Makefile
		 src/shared/Auth/Makefile
		 src/shared/Network/Makefile
		 src/Client/Makefile
		 src/Client/GUI/Makefile
		 src/Client/Realm/Makefile
		 src/Client/World/Makefile
		 src/Client/DefScript/Makefile])
AC_OUTPUT
