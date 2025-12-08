#pragma once

#include <fstream>

class FileReader {
private:
	std::ifstream file;
private:
	bool is_open()			const noexcept;
	void open(const std::string& path);
	void close();
	size_t file_size()		noexcept;
public:
	FileReader(const std::string& path);
	std::string read();
	~FileReader();
};