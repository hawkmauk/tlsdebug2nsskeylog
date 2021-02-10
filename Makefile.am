AM_CPPFLAGS = -I/home/user/Development/boost_1_75_0/stage/include \
			  -I../include \
			  -fexceptions -Wall
AM_LDFLAGS = -L/home/user/Development/boost_1_75_0/stage/lib \
			 -lboost_program_options \
			 -lboost_filesystem

bin_PROGRAMS = dist/tlsdebug2nsskeylog
dist_tlsdebug2nsskeylog_SOURCES = main.cpp \
								  src/Application.cpp \
								  src/NssLogFormat.cpp \
								  src/Session.cpp \
								  src/SessionStore.cpp \
								  src/TlsDebugData.cpp

tlsdebug2nsskeylog_CPPFLAGS = -I$(top_srcdir)
