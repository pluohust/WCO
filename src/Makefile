include pin.mk
srcdir := ./
builddir := ./

user_flags := -D_USING_DEBUG_INFO
CXXFLAGS += -fPIC -D_GNU_SOURCE $(user_flags)
INCS += -I$(srcdir)
LDFLAGS += 
CXXFLAGS += -O3 -fomit-frame-pointer
TOOL_LIBS += -lpthread

pincxxgendepend = $(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) -MM -MT $@ -MF $(builddir)$*.d $<

all: WCO.so
	$(LINKER) $(TOOL_LDFLAGS) $(LINK_DEBUG) ${LINK_EXE}$@ $^ ${TOOL_LPATHS} $(TOOL_LIBS) $(DBG)

WCO.so : main.o monitor_shared_memory.o Detector.o Output.o VectorClocks.o Init_Close.o monitor_function.o
	$(LINKER) $(TOOL_LDFLAGS) $(LINK_DEBUG) ${LINK_EXE}$@ $^ ${TOOL_LPATHS} $(TOOL_LIBS) $(DBG)

main.o : main.cpp main_basictype.h
	@$(pincxxgendepend);
	$(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) $(COMP_OBJ)$@ $<

monitor_shared_memory.o : monitor_shared_memory.cpp monitor_shared_memory.h main_basictype.h
	@$(pincxxgendepend);
	$(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) $(COMP_OBJ)$@ $<

Detector.o : Detector.cpp Detector.h main_basictype.h
	@$(pincxxgendepend);
	$(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) $(COMP_OBJ)$@ $<

Output.o : Output.cpp Output.h main_basictype.h
	@$(pincxxgendepend);
	$(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) $(COMP_OBJ)$@ $<

VectorClocks.o : VectorClocks.cpp VectorClocks.h main_basictype.h
	@$(pincxxgendepend);
	$(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) $(COMP_OBJ)$@ $<

Init_Close.o : Init_Close.cpp Init_Close.h main_basictype.h
	@$(pincxxgendepend);
	$(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) $(COMP_OBJ)$@ $<

monitor_function.o : monitor_function.cpp monitor_function.h main_basictype.h
	@$(pincxxgendepend);
	$(CXX) $(CXXFLAGS) $(TOOL_INCLUDES) $(TOOL_CXXFLAGS) $(INCS) $(COMP_OBJ)$@ $<

clean:
	rm -rf *.o *.d *.so

