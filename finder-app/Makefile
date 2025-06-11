CROSS_COMPILE ?= native
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	COMPILER := aarch64-none-linux-gnu-gcc
else
	COMPILER := gcc
endif

$(CROSS_COMPILE): writer.c
	$(COMPILER) writer.c -o writer
clean:
	rm -f writer
	rm -f *.o
