CC=gcc
AR=ar
OBJECT_LOOP= basicClassification.o advancedClassificationLoop.o
OBJECT_RECURCION= basicClassification.o advancedClassificationRecursion.o 
FLAGS= -g -Wall 

all: loops loopd recursives recursived mains maindloop maindrec
loops: libclassloops.a
loopd: libclassloops.so
recursives: libclassrec.a
recursived: libclassrec.so 

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c 

libclassloops.a: $(OBJECT_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECT_LOOP)
libclassrec.a: $(OBJECT_RECURCION)
	$(AR) -rcs libclassrec.a $(OBJECT_RECURCION) 
libclassloops.so: $(OBJECT_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECT_LOOP)
libclassrec.so: $(OBJECT_RECURCION) 
	$(CC) -shared -o libclassrec.so $(OBJECT_RECURCION) 

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a
maindloop: main.o libclassloops.so 
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so
maindrec: main.o libclassrec.so 
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec