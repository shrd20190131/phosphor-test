AM_DEFAULT_SOURCE_EXT = .cpp

# Build these headers, don't install them
noinst_HEADERS = \
    usi_log.hpp

sbin_PROGRAMS = phosphor-test-manager

phosphor_test_manager_SOURCES = \
    usi_log_main.cpp \
    usi_log.cpp 

BUILT_SOURCES = \
    com/usi/Ssdarray/Switch/error.cpp \
    com/usi/Ssdarray/Switch/error.hpp 

CLEANFILES = ${BUILT_SOURCES}

com/usi/Ssdarray/Switch/error.hpp: ${top_srcdir}/com/usi/Ssdarray/Switch.errors.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) error exception-header com.usi.Ssdarray.Switch > $@

com/usi/Ssdarray/Switch/error.cpp: ${top_srcdir}/com/usi/Ssdarray/Switch.errors.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) error exception-cpp com.usi.Ssdarray.Switch > $@

phosphor_test_manager_LDFLAGS = $(SDBUSPLUS_LIBS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_LIBS) \
                                 $(USI_DBUS_INTERFACES_LIBS) \
                                 $(PHOSPHOR_LOGGING_LIBS)
                                 
phosphor_test_manager_CFLAGS =  $(SDBUSPLUS_CFLAGS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_CFLAGS) \
                                 $(USI_DBUS_INTERFACES_CFLAGS) \
                                 $(PHOSPHOR_LOGGING_CFLAGS)