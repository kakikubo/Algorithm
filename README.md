# Algorithm

[![test](https://github.com/kakikubo/Algorithm/actions/workflows/test.yml/badge.svg)](https://github.com/kakikubo/Algorithm/actions/workflows/test.yml)

C 言語の入門・アルゴリズム学習用リポジトリです。各 `.c` ファイルが章ごとのサンプルに対応しています。

ソース一覧および各ファイルの学習テーマは [CLAUDE.md](CLAUDE.md) を参照してください。

## macOS でのコンパイル方法

Xcode Command Line Tools に含まれる `cc`（Apple Clang）を利用します。未導入の場合は次のコマンドでインストールします。

```sh
xcode-select --install
```

### `make` で一括ビルドする（推奨）

リポジトリ直下の `Makefile` を使うと、すべての `.c` を一括でビルドできます。

```sh
make            # 全ソースをビルド
make 1to5       # 個別にビルド（拡張子なしの名前を指定）
make clean      # 生成物を一括削除
make test       # 全プログラムの出力を期待値と比較してテスト
```

`Makefile` では `-std=gnu89` を指定したうえで、Apple Clang 16 以降でエラー昇格された K&R 風の構文（暗黙 `int` ／戻り値省略など）に関する警告を `-Wno-*` で抑止しています。学習履歴保全のためソースは書き換えません。

### `make` を使わずに個別ビルドする

`.c` ファイルごとに、拡張子を除いた名前で実行ファイルを生成します。

```sh
cc -std=gnu89 -o 1to5 1to5.c
./1to5
```

### `simple-cat` の実行について

`simple-cat` は同階層の `abc.txt` を読み込みます。リポジトリのルートをカレントディレクトリにして実行してください。

```sh
make simple-cat
./simple-cat
```

## テスト

`tests/run_tests.sh` が各プログラムを実行し、stdout を期待値と完全一致で比較します。16 プログラム / 19 ケース（`argc` の 3 パターン、`calendar` の閏年含む 2 パターンを含む）を実行します。`coin` は `srand(time)` のため対局結果が非決定的なので、終了入力(`3`)を与えた直後の冒頭出力のみを検証します。

```sh
make test
```

## CI

`.github/workflows/test.yml` で `master` への push と pull_request の度に、`macos-latest` 上で `make test` が自動実行されます。

## 補足

- 既存ソースは古い K&R 風の書き方（`main()` の戻り値型省略など）を含みますが、`Makefile` の `-Wno-*` フラグでビルド時の警告は出ないようにしてあります。学習履歴保全のためソースは書き換えません。
- 生成された実行ファイルは `.gitignore` で追跡対象外です。`make clean` で削除できます。
- `.gitignore` はホワイトリスト方式（`*` で全無視 → 必要なものだけ `!` で許可）を採用しています。
