TARGET:=dlist.out
SOURCES:=$(wildcard *.c)

${TARGET}: ${SOURCES}
					gcc ${SOURCES} -o ${TARGET}

clean:
					rm ${TARGET}
