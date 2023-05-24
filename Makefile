SOURCE_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

CC = clang
WARNINGS = -Wall -Wextra -Werror -Wpedantic
CFLAGS = -std=c17 -I$(INCLUDE_DIR) `sdl2-config --cflags`
LDLIBS = `sdl2-config --libs` -lSDL2_image

EXECUTABLE = sdl-demo
OBJS = $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(SOURCE_DIR)/*.c))
HEADERS = $(wildcard $(SOURCE_DIR)/*.h)

.PHONY: all clean

all: $(EXECUTABLE)

clean:
	$(RM) $(OBJS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(WARNINGS) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(HEADERS) $(BUILD_DIR)
	$(CC) $(WARNINGS) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $@
