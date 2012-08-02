APP=pragmaPrinter

TINYXMLSRCS=ticpp.cpp tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp
SRCS= Channel.cpp Control.cpp Q2XMLFile.cpp Exception.cpp $(TINYXMLSRCS)
OBJS=$(SRCS:%.cpp=%.o)

CXX=g++
CXXFLAGS=-O0 -g -std=c++0x -DTIXML_USE_TICPP
LDFLAGS=
INCLUDES=-I. 

all: $(APP)

$(APP): $(OBJS)
	@echo Linking $(APP) 
	$(CXX) $(LDFLAGS) $(LIBS) $(OBJS) -o $(APP)

%.o: %.cpp
	@echo Compiling $< 
	@$(CXX) $(INCLUDES) $(CXXFLAGS) -c $<   

run: $(APP)
	./$(APP)
	
.depend:
	@echo Determining dependencies...
	@for file in $(SRCS); do $(CXX) -MM $$file >> .depend; done

clean:
	@-rm -rf *.o .depend $(APP) *.cpp~ *.h~  Makefile~ *.xml~


include .depend
