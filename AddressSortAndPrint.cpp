#include <iostream>
#include <cmath>
#include <vector>
#include <OpenXLSX.hpp>

#ifdef _WIN32
#include <Windows.h>
int get_console_width() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
#elif
#include <unistd.h>
#include <sys/ioctl.h>
int get_console_width() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
}
#endif;

bool is_even(int num);
std::string center_text(const std::string& text, int width);
struct People;
std::string get_path();
std::vector<People> parse_document(const std::string& path);


int main()
{
	std::string lsep = std::string(get_console_width(), '-');

	std::cout << lsep << "\n";
	std::cout << "";
	std::cout << lsep << "\n";

	std::cout << std::string(79, '-') << "\n";
	std::cout << "          Address Sorting and Selection Printer Labeling Operator Program           " << std::endl;
	std::cout << std::string(79, '-') << "\n";
	std::cout << "Welcome user, Please ensure the Excel file is in the proper format. " << std::endl;

	return 0;
}

bool is_even(int num) {
	return !((num < 0 ? -(num) : num) & 1);
}

std::string center_text(const std::string& text, int width) {
	int pad_size = width - text.length();

	if (pad_size <= 0) return text;

	bool even = is_even(pad_size);
	int quotient = (even ? pad_size : pad_size - 1) / 2;
	std::string l_pad(even ? quotient : quotient + 1, ' '), r_pad(quotient, ' ');

	return (l_pad + text + r_pad);

	struct People {
		std::string name;
		std::string address;
		std::string city;
		std::string state;
		uint16_t zip;
	};

	std::string get_path() {
		std::string path;
		for (const auto& file : std::filesystem::directory_iterator("../")) {
			if (file.path().extension().string() == "xlsx") {
				path = file.path().string();
				break;
			}
		}
		return path;
	}
}

std::vector<People> parse_document(const std::string& path) {
}