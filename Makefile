SOURCE_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c17 -I$(INCLUDE_DIR) `sdl2-config --cflags`
LDLIBS = `sdl2-config --libs`

OBJS = $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(SOURCE_DIR)/*.c))
HEADERS = $(wildcard $(SOURCE_DIR)/*.h)

sdl-test: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(HEADERS) $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
	rm -f sdl-test
