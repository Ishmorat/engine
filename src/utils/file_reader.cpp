#include "file_reader.h"

bool FileReader::is_open() const noexcept {
	return file.is_open();
}

void FileReader::open(const std::string& path) {
	file.open(path);
	if (!is_open())
		throw std::runtime_error("Failed to open file");
}

void FileReader::close() {
	if (is_open()) file.close();
}

size_t FileReader::file_size() noexcept {
	file.seekg(std::ios::beg, std::ios::end);
	size_t sz = file.tellg();
	file.seekg(0);
	return sz;
}

FileReader::FileReader(const std::string& path) {
	open(path);
}

std::string FileReader::read() {
	size_t sz = file_size();
	std::string str(sz, ' ');
	file.read(str.data(), sz);
	return str;
}

FileReader::~FileReader() {
	close();
}