TEMPLATE	= app
LANGUAGE	= C++
CONFIG		+= qt thread warn_on dll console
CONFIG		+= debug

debug_and_release {
	CONFIG(debug, debug|release) {
		TARGET = observer_d

		LIBS +=
	}
	CONFIG(release, debug|release) {
		TARGET = observer

		LIBS +=
	}
} else {
	debug {
		TARGET = observer_d

		LIBS +=
	}
	release {
		TARGET = observer

		LIBS +=
	}
}

DESTDIR		= ./lib
DLLDESTDIR	= ./bin
OBJECTS_DIR	= ./obj

HEADERS	+=	observer.pro \
			observer.h \
			subject.h

SOURCES	+=	main.cpp \
			observer.cpp \
			subject.cpp

DEPENDPATH *= 

INCLUDEPATH *= $$DEPENDPATH

win32 {
	DEFINES *= OBSERVER_DLL
}
