CC      = g++
O_NAME  = a.out
PROF    = -o
NOCRYPT =
C_FLAGS =  -Wall $(PROF) $(NOCRYPT)
L_FLAGS =  $(PROF)
O_FILES = Course.obj StudentCollection.obj Student.obj StudentProfile.obj

lab: $(O_FILES)
	rm -f $(O_NAME)
	$(CC) $(L_FLAGS) $(O_FILES)

.c.o: $(CC) -c $(C_FLAGS) $<

