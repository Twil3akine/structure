# コンパイラの設定
CC = gcc
CFLAGS = -std=c11 -g

# 出力ファイル名
TARGET = program

# ソースファイルの探索
SRC = $(wildcard ./*.c) $(wildcard ./src/*.c)

# オブジェクトファイルの生成
OBJ = $(SRC:.c=.o)

# 最終的なターゲット（実行ファイル）
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# オブジェクトファイルの生成ルール
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# クリーンアップルール
clean:
	rm -f $(OBJ) $(TARGET)
