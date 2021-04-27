include config.mk

FILES         := $(DRIVER) $(IMPLEMS) $(HEADERS)
SHELL         := /bin/bash
HAS_CLANGTDY  := $(shell command -v clang-tidy 2> /dev/null)
HAS_CLANGFMT  := $(shell command -v clang-format 2> /dev/null)


.PHONY: test clean

$(TEST_PATH)/unittest: $(TEST_PATH)/unittest.cpp $(DRIVER) $(IMPLEMS) $(HEADERS)
	@clang++ -std=c++17 -fsanitize=address $(IMPLEMS) $(TEST_PATH)/unittest.cpp -o $(TEST_PATH)/unittest -pthread -lgtest

/usr/lib/libgtest.a:
	@echo -e "google test library not installed\n"
	@echo -e "Installing cmake. Please provide the password when asked\n"
	@sudo apt-get install cmake # install cmake
	@echo -e "\nDownloading and installing googletest\n"
	@cd /tmp/; git clone https://github.com/google/googletest.git; cd googletest; cmake CMakeLists.txt; make; sudo cp -r googletest/include/. /usr/include; sudo cp -r googlemock/include/. /usr/include; sudo cp lib/*.a /usr/lib
	@echo -e "Finished installing google test library\n"

test: /usr/lib/libgtest.a $(TEST_PATH)/unittest
	@echo -e "\n========================\nRunning unit test\n========================\n"
	@./$(TEST_PATH)/unittest --gtest_output="xml:test/unittest.xml"
	@echo -e "\n========================\nUnit test complete\n========================\n"

$(TEST_PATH)/compile_commands.json :
	@bash test/gen_ccjs.sh $(EXECFILE) $(DRIVER) "$(IMPLEMS)" "$(HEADERS)"
ifndef HAS_CLANGTDY
	@echo -e "clang-tidy not installed\n"
	@echo -e "Installing clang-tidy. Please provide password when asked\n"
	@sudo apt-get -y install clang-tidy
	@echo -e "Finished installing clang-tidy\n"
endif

clean:
	@rm -f $(TEST_PATH)/compile_commands.json
	@rm -f $(TEST_PATH)/unittest
