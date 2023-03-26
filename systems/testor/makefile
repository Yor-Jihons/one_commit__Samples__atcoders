#----------------------------------------------------------#
# Definition of the directory paths

## The directory "src".
SRCDIRPATH=.\src

## The directory you want to create on.
BINDIRPATH=.\bin

#----------------------------------------------------------#
# Definition of the target which you compile

## The target paths
TARGET=$(BINDIRPATH)\testor
TESTOR=$(BINDIRPATH)\test_main

## The targets
all: $(TARGET) $(TESTOR)

#----------------------------------------------------------#
# Definition of the arguments of compilation

## コンパイラの指定
CCX=g++

## 最適化について
OPTIMIZE=-o2

## C++のバージョン指定
CPP_VERSION=-std=c++11

## インクルードの指定 ( -Iでやるやつ )
ICOMMAND=

## リンカのフラグ
LDFLAG=-O0

## コンパイラフラグ
CFLAG=$(OPTIMIZE) $(CPP_VERSION) $(ICOMMAND)

COMMON_LINKAGEFILES=$(SRCDIRPATH)\IO\iofile.o $(SRCDIRPATH)\Processes\process.o \
$(SRCDIRPATH)\CommandLines\cmdline.o $(SRCDIRPATH)\Comparision\vectorcomparer.o

LINKAGEFILES4TARGET=$(SRCDIRPATH)\main.o $(COMMON_LINKAGEFILES)
LINKAGEFILES4TESTOR=$(SRCDIRPATH)\test_main.o $(COMMON_LINKAGEFILES)

#----------------------------------------------------------#
# Compilation

## Compile the target
$(TARGET): $(LINKAGEFILES4TARGET)
	$(CCX) $(CFLAG) -o $(TARGET) $(LINKAGEFILES4TARGET)

## Compile the testor of this testor
$(TESTOR): $(LINKAGEFILES4TESTOR)
	$(CCX) $(CFLAG) -o $(TESTOR) $(LINKAGEFILES4TESTOR)


$(SRCDIRPATH)\main.o: $(SRCDIRPATH)\main.cpp
	$(CCX) -c $< -o $@
$(SRCDIRPATH)\test_main.o: $(SRCDIRPATH)\test_main.cpp
	$(CCX) -c $< -o $@
$(SRCDIRPATH)\IO\iofile.o: $(SRCDIRPATH)\IO\iofile.cpp
	$(CCX) -c $< -o $@
$(SRCDIRPATH)\Processes\process.o: $(SRCDIRPATH)\Processes\process.cpp
	$(CCX) -c $< -o $@
$(SRCDIRPATH)\CommandLines\cmdline.o: $(SRCDIRPATH)\CommandLines\cmdline.cpp
	$(CCX) -c $< -o $@
$(SRCDIRPATH)\Comparision\vectorcomparer.o: $(SRCDIRPATH)\Comparision\vectorcomparer.cpp
	$(CCX) -c $< -o $@

#----------------------------------------------------------#
# Definition of Original commands

.PHONY: test
test:
	$(TESTOR)

.PHONY: clean
clean:
	@rm -rf $(COMMON_LINKAGEFILES) $(SRCDIRPATH)\main.o $(SRCDIRPATH)\test_main.o


.PHONY: cleanEx
cleanEx:
	@rm $(TARGET) $(TESTOR) $(COMMON_LINKAGEFILES) $(SRCDIRPATH)\main.o $(SRCDIRPATH)\test_main.o

.PHONY: full
full:
	@make
	@make test
	@make clean

