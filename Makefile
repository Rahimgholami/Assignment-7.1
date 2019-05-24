

CPP11 = g++ -std=c++11
OBJ = main.o FileSystemInterface.o CommandHandler.o User.o Film.o Publisher.o Comment.o

result.out: $(OBJ)
	$(CPP11) $(OBJ)  -o result.out

FileSystemInterface.o:	FileSystemInterface.cpp FileSystemInterface.h CommandHandler.cpp CommandHandler.h Define.h
	$(CPP11) FileSystemInterface.cpp -c

CommandHandler.o:	CommandHandler.cpp CommandHandler.h User.cpp User.h Publisher.cpp Publisher.h User.cpp User.h Film.cpp Film.h Exception.h  
	$(CPP11) CommandHandler.cpp -c

Publisher.o:	Publisher.cpp Publisher.h User.cpp User.h Define.h Exception.h Film.cpp Film.h
		$(CPP11) Publisher.cpp -c

Film.o:	Film.cpp Film.h Define.h Exception.h Comment.cpp Comment.h
	$(CPP11) Film.cpp -c

User.o:	User.cpp User.h Define.h Exception.h Film.cpp Film.h
		$(CPP11) User.cpp -c

Comment.o: Comment.cpp Comment.h Exception.h Define.h
		$(CPP11) Comment.cpp -c

main.o:		main.cpp FileSystemInterface.h CommandHandler.h Publisher.h User.h Film.h Exception.h Define.h
	$(CPP11) main.cpp -c

clean:
	rm *.o *.out
