CC = gcc
CFLAGS += -Wall -std=c99 -g
CPPFLAGS += -MMD

OBJS := example_string_ops.o string_ops.o
DEPS := example_string_ops.d string_ops.d
EXEC := example_string_ops

$(EXEC): $(OBJS)
	gcc -o$@ $^

-include $(DEPS)

.PHONY : clean distclean

clean:
	@echo clean
	@rm -f *.o
	@rm -f *.d

distclean: clean
	@rm -f $(EXEC)
