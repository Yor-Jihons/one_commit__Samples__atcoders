# testor

このtestor.exeはAtCoderの問題を解くときの入力値に対しての出力値が合っているかを自動的に行うシステムです。

## インストール

makeをしてbinディレクトリに生成されたtestor.exe(環境によっては拡張子が異なることもある)をutilsディレクトリに入れるだけ。

```
$ make
$ move .\bin\testor.exe ..\utils\tesor.exe
```

## 使い方

### Step1. 各プロジェクトをカレントディレクトリにする

```
$ cd A__test1
```

### Step2. testorを動かす

```
$ ..\systems\utils\testor.exe ..\test\input1.txt ..\test\output1.txt
```

## コマンドライン引数

```
$ testor.exe <INPUTFILE> <OUTPUTFILE>

<INPUTFILE>:
    入力値が書かれているファイル (必須)
<OUTPUTFILE>:
    出力値が書かれているファイル (必須)
```
