AM_DEFAULT_SOURCE_EXT = .cpp

sbin_PROGRAMS = phosphor-test-manager 
            
phosphor_test_manager_SOURCES = \
    usi_log_main.cpp \
    usi_log.cpp 

phosphor_test_manager_LDFLAGS = $(SDBUSPLUS_LIBS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_LIBS) \
                                 $(USI_DBUS_INTERFACES_LIBS)
                                 
phosphor_test_manager_CFLAGS =  $(SDBUSPLUS_CFLAGS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_CFLAGS) \
                                 $(USI_DBUS_INTERFACES_LIBS)