CFLAGS += -Wall -Wextra
CC=gcc
OBJS = calculation.o calculation_test.o


minunit_test: $(OBJS)
	$(CC) -o minunit_test $(OBJS)

calculation.o: ../calculation.c
	$(CC) -c $<

calculation_test.o: ../calculation_test.c ../minunit.h ../calculation.h
	$(CC) -c $<

clean:
	rm *.o minunit_test
