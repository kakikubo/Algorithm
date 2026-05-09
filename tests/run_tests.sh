#!/usr/bin/env bash
# 各 .c プログラムの stdout を期待値と完全一致で検証する。
# 使い方: make test  あるいは  bash tests/run_tests.sh

set -uo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

# 念のためビルド（既にビルド済みなら no-op）
make --silent all >/dev/null

pass=0
fail=0
failures=()

assert_eq() {
  local name="$1" expected="$2" actual="$3"
  if [ "$expected" = "$actual" ]; then
    printf 'TEST %-22s ... ok\n' "$name"
    pass=$((pass + 1))
  else
    printf 'TEST %-22s ... FAIL\n' "$name"
    diff <(printf '%s\n' "$expected") <(printf '%s\n' "$actual") | sed 's/^/    /'
    fail=$((fail + 1))
    failures+=("$name")
  fi
}

# ---------------- 1to5 ----------------
expected=$(cat <<'EOF'
1
3
6
10
15
15
EOF
)
assert_eq "1to5" "$expected" "$(./1to5)"

# ---------------- argc ----------------
expected=$(cat <<'EOF'
argv[0] : ./argc
argv[1] : enum
argv[2] : foo
argv[3] : bar
EOF
)
assert_eq "argc/enum" "$expected" "$(./argc enum foo bar)"

assert_eq "argc/count" "コマンドライン引数の数: 4" "$(./argc count foo bar baz)"

assert_eq "argc/empty" "" "$(./argc)"

# ---------------- arraysearch ----------------
expected=$(cat <<'EOF'
7があったよ
7があったよ
EOF
)
assert_eq "arraysearch" "$expected" "$(./arraysearch)"

assert_eq "arraysearch2" "7はなかったよ" "$(./arraysearch2)"

assert_eq "arraysearch3" "7があったよ" "$(./arraysearch3)"

# ---------------- average ----------------
assert_eq "average" "平均は75です。" "$(./average)"

# ---------------- calendar ----------------
expected=$(cat <<'EOF'
カレンダーを表示します。
西暦と月をスペースで区切って入力してください。
西暦2024年 2月
-----------------------------
 Sun Mon Tue Wed Thu Fri Sat
-----------------------------
                   1   2   3
   4   5   6   7   8   9  10
  11  12  13  14  15  16  17
  18  19  20  21  22  23  24
  25  26  27  28  29
------------------------------
EOF
)
assert_eq "calendar/2024-02" "$expected" "$(echo '2024 2' | ./calendar)"

expected=$(cat <<'EOF'
カレンダーを表示します。
西暦と月をスペースで区切って入力してください。
西暦2025年 5月
-----------------------------
 Sun Mon Tue Wed Thu Fri Sat
-----------------------------
                   1   2   3
   4   5   6   7   8   9  10
  11  12  13  14  15  16  17
  18  19  20  21  22  23  24
  25  26  27  28  29  30  31
------------------------------
EOF
)
assert_eq "calendar/2025-05" "$expected" "$(echo '2025 5' | ./calendar)"

# ---------------- charcat ----------------
assert_eq "charcat" "book+marks=bookmarks" "$(./charcat)"

# ---------------- coin ----------------
# srand(time) を使うため対局結果は非決定的。
# 終了値(3)を入力した場合の冒頭2行のみが決定的なので、その範囲だけ検証する。
expected=$(cat <<'EOF'
表は1,裏は2,終了は他の値を入力して下さい
コインを投げました。表？裏？
EOF
)
assert_eq "coin/exit" "$expected" "$(echo 3 | ./coin)"

# ---------------- function ----------------
assert_eq "function" "15" "$(./function)"

# ---------------- graph ----------------
expected=$(cat <<'EOF'
a[0]=4|****
a[1]=5|*****
a[2]=2|**
a[3]=3|***
EOF
)
assert_eq "graph" "$expected" "$(./graph)"

# ---------------- recursive ----------------
assert_eq "recursive" "5! = 120" "$(./recursive)"

# ---------------- reverse ----------------
expected=$(cat <<'EOF'
DOGは
逆さから読むと
GOD
EOF
)
assert_eq "reverse" "$expected" "$(./reverse)"

# ---------------- simple-cat ----------------
expected=$(cat <<'EOF'
0001:abcdefg
feof:0
0002:hijklmn
feof:0
0003:opqrstu
feof:0
0004:vwxyz
feof:0
EOF
)
assert_eq "simple-cat" "$expected" "$(./simple-cat)"

# ---------------- swap ----------------
expected=$(cat <<'EOF'
1+2+3+4+5=15
1から5までの和は15
5+6+7+8+9+10=45
5から10までの和は45
1+2+3+4+5+6+7+8+9+10=55
1から10までの和は55
2=2
2から2までの和は2
EOF
)
assert_eq "swap" "$expected" "$(./swap)"

# ---------------- swapval ----------------
expected=$(cat <<'EOF'
a= 2, b= 7
a= 7, b= 2
EOF
)
assert_eq "swapval" "$expected" "$(./swapval)"

# ---------------- summary ----------------
total=$((pass + fail))
echo
echo "${pass}/${total} passed"
if [ "$fail" -gt 0 ]; then
  echo "Failures:"
  printf '  %s\n' "${failures[@]}"
  exit 1
fi
