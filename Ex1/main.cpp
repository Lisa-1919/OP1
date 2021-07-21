#include <cstdlib>
#include <iostream>
#include <string>

#include "robots.h"

int main() {
	std::cout << "\n";

	// Создаем робота 1 в пункте x=0, y=0
	Position pos1 = {0, 0};
	Robot *robot1 = InitializeRobot("Alice", pos1);
	// Робот, отзовись!
	EchoRobot(robot1);

	// Создаем робота 2
	Position pos2 = {5, -3};
	Robot *robot2 = InitializeRobot("Bob", pos2);
	EchoRobot(robot2);

	// Попытка создания робота 3
	Robot *robot3 = InitializeRobot("Freddy", pos1);
	EchoRobot(robot3);

	// Попытки создания еще некольких роботов
	for (int i = 1; i < 5; ++i) {
		Position pos = {i * 2, i * 3};
		Robot *robot = InitializeRobot("noname", pos);
		EchoRobot(robot);
	}

	std::cout << "\n";

	// Робот 1 совершает шаг на dx=1 и dy=3
	MoveX(robot1, 1);
	MoveY(robot1, 3);
	EchoRobot(robot1);

	std::cout << "\n";

	// Робот 1 пытается пойти
	MoveX(robot1, 4);
	MoveY(robot1, -6);
	EchoRobot(robot1);

	std::cout << "\n";

	// Несколько операций на роботе
	Operation moveXY[] = {MoveX, MoveY, MoveX, MoveY, MoveY};
	int shifts[] = {-2, 3, 5, 100, -23};
	int opsize = sizeof(moveXY) / sizeof(Operation);
	for (int i = 0; i < opsize; ++i)
		moveXY[i](robot2, shifts[i]);
	EchoRobot(robot2);

	DeleteRobots();

	return 0;
}
