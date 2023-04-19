#----------------------------------------------------------#
# Definition of dir-path


## The directory "src"
SRCDIRPATH=.\src

## The directory "bin"
BINDIRPATH=.\bin

#----------------------------------------------------------#
# Definition of the target

## The target project
TARGET=$(BINDIRPATH)\Main

all: $(TARGET)

#----------------------------------------------------------#
# Definition of arguments for compilation

CCX=g++

OPTIMIZE=-o2

CPP_VERSION=-std=c++11

## インクルードの指定 ( -Iでやるやつ )
ICOMMAND=

LDFLAG=-O0

CFLAG=$(OPTIMIZE) $(CPP_VERSION) $(ICOMMAND)

LINKAGEFILES=$(SRCDIRPATH)\main.o

#----------------------------------------------------------#
# Compilation

## The compilation of the target
$(TARGET): $(LINKAGEFILES)
	$(CCX) $(CFLAG) -o $@ $<

## The compilation of the file you need.
main.o:
	$(CCX) -c $<

#----------------------------------------------------------#
# Other commands

.PHONY: test
test:
	make --file=testor test TESTOR=..\systems\utils\testor.exe TARGET=$(TARGET) -s

## 削除系
.PHONY: clean
clean:
	@rm -rf $(LINKAGEFILES) $(TARGET)
