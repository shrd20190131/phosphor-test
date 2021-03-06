AC_PREREQ([2.69])
AC_INIT([usi-ssdarray-manager], [1.0], [https://github.com/openbmc/shrd20190131/usi-ssdarray-manager/issues])
AC_LANG([C++])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([subdir-objects -Wall -Werror foreign dist-xz])
AM_SILENT_RULES([yes])

# Checks for programs
AC_PROG_CXX
AC_PROG_INSTALL #Checks/sets the install variable to be used
AC_PROG_MAKE_SET

# Check for libraries
PKG_CHECK_MODULES([SYSTEMD], [libsystemd >= 221])
PKG_CHECK_MODULES([PHOSPHOR_DBUS_INTERFACES], [phosphor-dbus-interfaces])
PKG_CHECK_MODULES([USI_DBUS_INTERFACES], [usi-dbus-interfaces])
PKG_CHECK_MODULES([SDBUSPLUS], [sdbusplus])

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_17([noext])
AX_APPEND_COMPILE_FLAGS([-Wall -Werror], [CXXFLAGS])

# Checks for library functions
LT_INIT # Removes WARNING: unrecognized options: --with-libtool-sysroot

AC_DEFINE(PS_BUSNAME, "com.usi.Ssdarray.Test", [The log manager DBus busname to own.])
AC_DEFINE(PS_OBJPATH, "/xyz/openbmc_project/ssdarray/test", [The log manager DBus object path.])

# Check for header files.
AC_CHECK_HEADER(systemd/sd-bus.h, ,[AC_MSG_ERROR([Could not find systemd/sd-bus.h...systemd development package required])])
AC_CHECK_HEADER(sdbusplus/server.hpp, ,[AC_MSG_ERROR([Could not find sdbusplus/server.hpp...openbmc/sdbusplus package required])])

AC_ARG_VAR(CLASS_VERSION, [Class version to register with Cereal])
AS_IF([test "x$CLASS_VERSION" == "x"], [CLASS_VERSION=1])
AC_DEFINE_UNQUOTED([CLASS_VERSION], [$CLASS_VERSION], [Class version to register with Cereal])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
