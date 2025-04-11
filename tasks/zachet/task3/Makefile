.PHONY: test build run clean

config:
	cmake -B ./build -DCMAKE_BUILD_TYPE=Release

build: config
	cmake --build ./build --target all --config Release

run: build zachet_task3
	rm -f result.txt
	./zachet_task3

clean:
	rm -rf build/ zachet_task3