CC=g++
CPPFLAGS=-o2 -flto -lcurses

main:
	${CC}  main.cc ${CPPFLAGS} -o password_learner
