# Algorithm

C 言語の入門・アルゴリズム学習用の個人リポジトリです。教材（章単位）に沿ってサンプルコードを `.c` ファイルとして書き溜めています。コメントは日本語です。

## ディレクトリ構成

ルート直下にすべての `.c` ソースと入力用テキスト（`abc.txt`）が並ぶフラットな構成です。例外として、ユニットテスト関連のみ `tests/` 以下にまとめています。

```
.                     # 学習サンプル本体（*.c）
├── calendar_lib.{c,h}  # calendar.c から切り出した純粋関数（テスト共有用）
└── tests/
    ├── minunit.h       # MinUnit 本体（vendor 同梱）
    ├── run_tests.sh    # 各プログラムの stdout を検証する shell テスト
    └── unit/
        └── test_calendar.c  # MinUnit によるユニットテスト
```

ビルド手順は `README.md` を参照してください。

## ソース一覧

| ファイル | 学習テーマ |
|---|---|
| `1to5.c` | for ループによる累計計算 |
| `argc.c` | コマンドライン引数（`argc` / `argv`）と `strcmp` による分岐 |
| `arraysearch.c` / `arraysearch2.c` / `arraysearch3.c` | 配列の線形探索（基本 → 件数カウント → `break` で早期終了） |
| `average.c` | 配列の合計と平均 |
| `calendar.c` | 西暦・月入力からカレンダーを描画。`getYearMonth` / `PrintCalendar` の I/O 部分を担当 |
| `calendar_lib.{c,h}` | `calendar.c` から切り出した純粋関数（`getMonthDays` 閏年判定、`getWeekDay` Zeller の公式系）。MinUnit テストから共有 |
| `charcat.c` | 文字配列を `'\0'` を意識して連結 |
| `coin.c` | `rand()` を使ったコイン当てゲーム |
| `function.c` | 関数定義とプロトタイプ宣言 |
| `graph.c` | 配列の各要素を `*` で水平棒グラフ描画 |
| `recursive.c` | 再帰による階乗 |
| `reverse.c` | 文字列の反転 |
| `simple-cat.c` | `fopen` / `fgets` でテキストファイルを読み出し、行番号付きで出力（`abc.txt` を参照） |
| `swap.c` | ポインタによる値の交換と総和の表示 |
| `swapval.c` | 値渡しと参照渡しの違い |

## ビルド・実行

ルートに `Makefile` があり、`make` で一括ビルド、`make test` で「MinUnit ユニットテスト + shell テスト」が走ります。詳細は `README.md` を参照してください。

```sh
cc -o 1to5 1to5.c   # Makefile を使わずに個別ビルドする例
./1to5
```

`simple-cat` は同階層の `abc.txt` を読み込むため、カレントディレクトリをリポジトリルートにして実行します。

## 留意点

- 既存ソースは古い K&R 風の書き方（`main()` の戻り値型省略など）を含みます。学習履歴の保全のため、機能を変えるリファクタは依頼があってから行ってください。
- ビルド済みバイナリはリポジトリに含めません（過去にコミットされていた Mach-O i386 バイナリは削除済み）。`.gitignore` は未設定のため、新規ビルド成果物は手動で除外してください。
- コミットログは日本語・章単位（例: `5章までおわり`、`function`、`fix while condition`）で運用されています。新規コミット時は `~/.claude/rules/commit-style.md` の規約に従ってください。
- `coin.c` には `FIXME` コメント（多次元 char 配列の解釈に関する自問）が残っています。学習メモとしての性格が強いため、勝手に解消せず確認してから対応します。
