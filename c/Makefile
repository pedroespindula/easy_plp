src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lm -lcurl

build-run: build
	@bin/easy_plp
	@echo ;

build: $(obj)
	@echo "=========="
	@echo "Compiling"
	@echo "=========="
	@mkdir -p bin/
	@$(CC) -o bin/easy_plp $^ $(LDFLAGS)

.PHONY: build-run build clean
clean:
	rm -rf ./bin/
