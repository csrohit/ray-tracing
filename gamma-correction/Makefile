TARGET = ray

SRC_DIRS = src
INC_DIRS = inc
BUILD_DIR = build
OUT_FILE = out.ppm

SRCS = $(shell find $(SRC_DIRS) -name "*.cpp")
OBJS = $(patsubst %.cpp,build/%.o,$(SRCS))

CPP_FLAGS = $(addprefix -I,$(INC_DIRS))

all: $(TARGET)

render: $(OUT_FILE)

$(OUT_FILE): $(TARGET)
	./$(TARGET) > $(OUT_FILE)

open: $(OUT_FILE)
	open $(OUT_FILE)

$(TARGET): $(OBJS)
	g++ -o $@ $^ $(CPP_FLAGS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	g++ -c -o $@ $< $(CPP_FLAGS)

clean:
	rm -rf $(OBJS) $(TARGET) $(OUT_FILE)
