CC      = g++
O_NAME  = lab03
PROF    = -o
NOCRYPT =
C_FLAGS =  -Wall $(PROF) $(NOCRYPT)
L_FLAGS =  $(PROF)
O_FILES = Course.obj StudentCollection.obj Student.obj StudentProfile.obj Person.obj


lab03: $(O_FILES)
	rm -f $(O_NAME)
	$(CC) lab03.cpp $(O_FILES) -o $(O_NAME)

Person.obj: Person.cpp
	$(CC) -c Person.cpp -o Person.obj

Course.obj: Course.cpp
	$(CC) -c Course.cpp -o Course.obj

Student.obj: Course.obj Student.cpp
	$(CC) -c Student.cpp -o Student.obj

StudentProfile.obj: Course.obj Student.obj
	$(CC) -c StudentProfile.cpp -o StudentProfile.obj

StudentCollection.obj: StudentCollection.cpp Course.obj StudentProfile.obj
	$(CC) -c StudentCollection.cpp -o StudentCollection.obj


