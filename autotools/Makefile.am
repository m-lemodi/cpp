SUBDIRS = libhello

bin_PROGRAMS = hello

hello_SOURCES = main.cc

noinst_LIBRARIES = libhello/libhello.a
libhello_libhello_a_SOURCES = libhello/hello.cc libhello/hello.hh

hello_LDADD = libhello/libhello.a

hello_CXXFLAGS = -Wall -Wextra -Werror