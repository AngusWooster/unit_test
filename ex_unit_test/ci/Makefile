CC=gcc
INCLUDE_DIRS = -I../
CFLAGS = -Wall $(INCLUDE_DIRS) -DUNIT_TEST

TARGET = sensor_unit_test
OBJS = sensor_test.o sensor.o

all: $(TARGET)

$(TARGET) : $(OBJS) 
	$(CC) -o $@ $(OBJS)

sensor.o: ../sensor.c
	@echo "Compiling "$@
	@echo "BUILD...    "$<
	$(CC) $(CFLAGS) -c $<

sensor_test.o: ../sensor_test.c 
	@echo "Compiling "$@
	@echo "BUILD...    "$<
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o

