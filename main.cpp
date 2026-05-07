#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <time.h>
#include <thread>
#include <chrono>
#include <filesystem>


bool file_exists(const std::string & path) {
	return std::filesystem::exists(path);
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	// ВЫБОР РЕЖИМА РАНДОМА
	bool hard_mode = false;
	std::string user_input;
	int user_input2;
	std::string user_path_to_cs;

	std::cout << "Перед началом в самой CS вам нужно забиндить команду \"exec crosshair.cfg\" на любую удобную кнопку\n\n";

	if (file_exists("C:\\config\\path_to_cs.txt")) {
		std::cout << "Путь найден (C:\\config\\path_to_cs.txt)\n" << std::endl;
	}
	else {
		std::filesystem::create_directory("C:\\config");
		std::ofstream user_path_to_cs_file("C:\\config\\path_to_cs.txt");
		std::cout << "Скопируйте путь до корневой папки CS, зайти в неё можно через steam/свойства/установленные файлы/обзор...\n(например: D:\\SteamLibrary\\steamapps\\common\\Counter-Strike Global Offensive\nили C:\steam\steamapps\common\Counter-Strike Global Offensive)\nВвод: "; std::getline(std::cin, user_path_to_cs); std::cout << std::endl;
		user_path_to_cs_file << user_path_to_cs;
	}

	std::cout << "Режим рандома(hard, light(по дефолту light)): "; std::cin >> user_input; std::cout;

	if (user_input == "hard") {
		hard_mode = true;
		std::cout << "Выбран hard режим.\n " << std::endl;
	}
	else {
		hard_mode = false;
		std::cout << "Выбран light режим.\n " << std::endl;
	}

	std::cout << "Задержка смены в милисекундах: "; std::cin >> user_input2; std::cout << std::endl;

	std::ifstream user_path_to_cs_file("C:\\config\\path_to_cs.txt");
	std::getline(user_path_to_cs_file, user_path_to_cs);

	std::cout << user_path_to_cs + "\\game\\csgo\\cfg\\crosshair.cfg";

	//ПЕРЕМЕННЫЕ ПАРАМЕТРОВ ПРИЦЕЛА
	int cl_crosshairsize;
	int cl_crosshairthickness;
	int cl_crosshaircolor;
	int cl_crosshairdot;
	int cl_crosshairgap;
	int cl_crosshair_drawoutline;


	while (true) {

		//РАНДОМНЫЕ ЗНАЧЕНИЯ ДЛЯ ПЕРЕМЕННЫХ
		if (hard_mode) {
			cl_crosshairsize = 1 + rand() % 150;
			cl_crosshairthickness = 1 + rand() % 150;
			cl_crosshaircolor = 0 + rand() % 9;
			cl_crosshairdot = rand() % 2;
			cl_crosshairgap = rand() % 41 - 20;
			cl_crosshair_drawoutline = rand() % 2;
		}
		else {
			cl_crosshairsize = 1 + rand() % 15;
			cl_crosshairthickness = 1 + rand() % 5;
			cl_crosshaircolor = 0 + rand() % 9;
			cl_crosshairdot = rand() % 2;
			cl_crosshairgap = rand() % 11 - 5;
			cl_crosshair_drawoutline = rand() % 2;
		}

		//ПЕРЕЗАПИСЬ КОНФИГА
		std::ofstream cfg(user_path_to_cs + "\\game\\csgo\\cfg\\crosshair.cfg", std::ios_base::out);
		if (cfg.is_open()) {
			cfg << "cl_crosshairsize " << cl_crosshairsize << "\ncl_crosshairthickness " << cl_crosshairthickness << "\ncl_crosshaircolor " << cl_crosshaircolor << "\ncl_crosshairdot " << cl_crosshairdot << "\ncl_crosshairgap " << cl_crosshairgap << "\ncl_crosshair_drawoutline " << cl_crosshair_drawoutline;
			std::cout << "Конфиг перезаписан!" << std::endl;
			cfg.flush();
		}
		cfg.close();

		std::this_thread::sleep_for(std::chrono::milliseconds(user_input2));

	}




}