AM_DEFAULT_SOURCE_EXT = .cpp

bin_PROGRAMS = phosphor-switch-log-manager

phosphor_switch_log_manager_SOURCES = \
    usi_log_main.cpp \
    usi_log.cpp
    
phosphor_switch_log_manager_LDFLAGS = $(SDBUSPLUS_LIBS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_LIBS) \
                                 $(USI_DBUS_INTERFACES_LIBS) \
                                 $(PHOSPHOR_LOGGING_LIBS)
                                 
phosphor_switch_log_manager_CXXFLAGS =  $(SDBUSPLUS_CFLAGS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_CFLAGS) \
                                 $(USI_DBUS_INTERFACES_CFLAGS) \
                                 $(PHOSPHOR_LOGGING_CFLAGS) 