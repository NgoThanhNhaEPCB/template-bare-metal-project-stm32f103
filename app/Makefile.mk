CFLAGS += -I./app
CPPFLAGS += -I./app

VPATH += ./app

#C source files
SOURCES_CPP += ./app/app.cpp
SOURCES_CPP += ./app/task_polling.cpp
SOURCES_CPP += ./app/screen_idle.cpp