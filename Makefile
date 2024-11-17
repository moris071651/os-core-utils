include config.mk

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))

all: $(BUILD_DIRS) $(MODE)

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: bin/$(APP).out

release: CFLAGS += $(RELEASE_CFLAGS)
release: bin/client.out bin/server.out

bin/$(APP).out: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

build/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -fr build/* bin/*

$(BUILD_DIRS):
	mkdir -p $@

.PHONY: all clean
