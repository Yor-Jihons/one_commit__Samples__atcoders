#----------------------------------------------------------#
# ディレクトリパス定義

## srcディレクトリ
SRCDIRPATH=.\src

## 生成する場所の指定
BINDIRPATH=.\bin

#----------------------------------------------------------#
# 生成する対象の指定

## 対象のプロジェクト
TARGET=$(BINDIRPATH)\testor
TESTOR=$(BINDIRPATH)\test_main

## 対象リスト
all: $(TARGET) $(TESTOR)

#----------------------------------------------------------#
# コンパイラ関連の定義

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
# コンパイル

## 対象プロジェクトのコンパイル
$(TARGET): $(LINKAGEFILES4TARGET)
	$(CCX) $(CFLAG) -o $(TARGET) $(LINKAGEFILES4TARGET)

$(TESTOR): $(LINKAGEFILES4TESTOR)
	$(CCX) $(CFLAG) -o $(TESTOR) $(LINKAGEFILES4TESTOR)

## 必要なオブジェクトファイルのコンパイル
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
# 独自コマンド

.PHONY: test
test:
	$(TESTOR)


.PHONY: clean
clean:
	@rm -rf $(COMMON_LINKAGEFILES) $(TARGET) $(TESTOR) $(SRCDIRPATH)\main.o $(SRCDIRPATH)\test_main.o
