CFLAGS    :=`root-config --cflags --libs`
SYSLIB    := -lz -l TreePlayer -lMathMore

DllSuf    := so
SrcSuf    := cxx
ObjSuf    := o
PcmSuf    := _rdict.pcm

INCLUDES  := -I$(HiRAEVTSRC)/
INCLUDES  += -I$(HiRAEVTSRC)/electronics
INCLUDES  += -I$(HiRAEVTSRC)/shared
INCLUDES  += -I$(HiRAEVTSRC)/HTRunInfo
INCLUDES  += -I$(HiRAEVTSRC)/RBExperiment
INCLUDES  += -I$(HiRAEVTSRC)/FilterUnpacker

RLIBS     := -L$(HiRAEVTLIB)

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall

RBEXPERIMENT_DICT  := RBExperimentDict.$(SrcSuf)
RBEXPERIMENT_DICTH := $(RBEXPERIMENT_DICT:.$(SrcSuf)=.h)
RBEXPERIMENT_DICTO := $(RBEXPERIMENT_DICT:.$(SrcSuf)=.$(ObjSuf))
RBEXPERIMENT_PCM   := RBExperimentDict$(PcmSuf)

RBEXPERIMENT_HDRS  := $(wildcard RB*.$(SrcSuf))

RBEXPERIMENT_HDRS  := $(RBEXPERIMENT_HDRS:.$(SrcSuf)=.h) RBExperimentLinkDef.h
RBEXPERIMENT_HDRS  := $(filter-out $(RBEXPERIMENT_DICTH),$(RBEXPERIMENT_HDRS))

RBEXPERIMENT_LIB := libRBExperiment.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(RBEXPERIMENT_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf) .$(PcmSuf)

$(RBEXPERIMENT_DICT): $(RBEXPERIMENT_HDRS)
	@echo "Generating dictionary $@..."
	$(ROOTCLINGORCINT) -f $@ -p $(INCLUDES) $^

$(RBEXPERIMENT_LIB): $(OBJS) $(RBEXPERIMENT_DICTO)
	@$(CXX) -shared $(CXXFLAGS) $^ $(SYSLIB) $(CFLAGS) $(RLIBS) -o $@
	@echo "$(CXX) -shared $(CXXFLAGS) $^ $(SYSLIB) $(CFLAGS) $(RLIBS) -o $@"

install:
	@cp $(RBEXPERIMENT_LIB) $(RBEXPERIMENT_PCM) $(HiRAEVTLIB)/.

.PHONY: distclean
distclean:
	@rm -f $(RBEXPERIMENT_LIB) $(RBEXPERIMENT_DICT) $(RBEXPERIMENT_DICTH) $(RBEXPERIMENT_PCM)
	@rm -f $(HiRAEVTLIB)/$(RBEXPERIMENT_LIB)
	@rm -f $(HiRAEVTLIB)/$(RBEXPERIMENT_PCM)	

.PHONY: clean
clean:
	@$(RM) -f $(LIB) $(OBJS) $(RBEXPERIMENT_DICTO) $(RBEXPERIMENT_DICT) $(RBEXPERIMENT_DICTH) $(RBEXPERIMENT_PCM)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
