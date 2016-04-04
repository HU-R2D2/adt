#include <stdio.h>
#include <iostream>
#include "../include/Box.hpp"
#include "../include/Speed.hpp"

int main() {
	std::cout << "Hello world" << std::endl;
	//Test code
	Length l = 5 * Length::METER;
	Length t = 6 * Length::METER;
	std::cout << "created length l: " << l << std::endl;
	std::cout << "created length t: " << t << std::endl;
	Duration d = 2 * Duration::SECOND;
	std::cout << "created duration d:" << d << std::endl;
	Speed s = t / d;
	std::cout << "created speed by dividing t(" << t <<") by d(" << d << ") result =" << s << std::endl; 
}