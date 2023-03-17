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

## 対象リスト
all: $(TARGET)

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

## リンクする独自ソースコード
LINKAGEFILES=$(SRCDIRPATH)\main.o $(SRCDIRPATH)\IO\iofile.o $(SRCDIRPATH)\Processes\process.o

#----------------------------------------------------------#
# コンパイル

## 対象プロジェクトのコンパイル
$(TARGET): $(LINKAGEFILES)
	$(CCX) $(CFLAG) -o $(TARGET) $(LINKAGEFILES)

## 必要なオブジェクトファイルのコンパイル
main.o: main.cpp
	$(CCX) -c $< -o $@
$(SRCDIRPATH)\IO\iofile.o: $(SRCDIRPATH)\IO\iofile.cpp
	$(CCX) -c $< -o $@
$(SRCDIRPATH)\Processes\process.o: $(SRCDIRPATH)\Processes\process.cpp
	$(CCX) -c $< -o $@

#----------------------------------------------------------#
# 後始末

## 削除系
clean:
	@rm -rf $(LINKAGEFILES) $(TARGET)
