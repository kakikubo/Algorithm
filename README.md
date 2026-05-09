# Algorithm

C 言語の入門・アルゴリズム学習用リポジトリです。各 `.c` ファイルが章ごとのサンプルに対応しています。

ソース一覧および各ファイルの学習テーマは [CLAUDE.md](CLAUDE.md) を参照してください。

## macOS でのコンパイル方法

Xcode Command Line Tools に含まれる `cc`（Apple Clang）を利用します。未導入の場合は次のコマンドでインストールします。

```sh
xcode-select --install
```

### 個別にビルドする

`.c` ファイルごとに、拡張子を除いた名前で実行ファイルを生成します。

```sh
cc -o 1to5 1to5.c
./1to5
```

警告を有効にしてビルドする場合は `-Wall` を付けます。

```sh
cc -Wall -o function function.c
./function
```

### まとめてビルドする

リポジトリ内のすべての `.c` を一括でビルドする場合は次のようにします。

```sh
for f in *.c; do cc -o "${f%.c}" "$f"; done
```

### `simple-cat` の実行について

`simple-cat` は同階層の `abc.txt` を読み込みます。リポジトリのルートをカレントディレクトリにして実行してください。

```sh
cc -o simple-cat simple-cat.c
./simple-cat
```

## 補足

- 既存ソースは古い K&R 風の書き方（`main()` の戻り値型省略など）を含み、Apple Clang ではいくつかの警告が出ますが学習履歴保全のためそのままにしています。
- 生成された実行ファイルはコミット対象外です。
