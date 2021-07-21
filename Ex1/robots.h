#pragma once
#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

const int maxNumberOfRobots = 5;
int numberOfRobots = 0;

struct Position
{
  int x;
  int y;
};

struct Robot
{
  string name;
  Position pos;
};

Robot **arr = new Robot*[maxNumberOfRobots];

Robot *InitializeRobot(string Name, Position Pos)
{
  Robot *robot = new Robot;
  robot->name = Name;
  robot->pos = Pos;
  for (int i = 0; i < numberOfRobots; i++)
  {
    if (robot->pos.x == arr[i]->pos.x && robot->pos.y == arr[i]->pos.y)
    {
      cout<<"InitializeRobot: Two robots cannot be placed in the same position."<<endl;
      delete robot;
      return nullptr;
    }
  }
  if (numberOfRobots >= 5)
  {
    cout<<"InitializeRobot: No space for an additional robot."<<endl;
    delete robot;
    return nullptr;
  }
  arr[numberOfRobots] = robot;
  numberOfRobots++;
  return robot;
}

void EchoRobot (Robot *robot)
{
  if (robot == nullptr)
    cout<<"No such robot."<<endl;
  else
    cout<<"> Hello, I'm robot "<<robot->name<<" at x="<<robot->pos.x<<", y="<<robot->pos.y<<"."<<endl;
}

typedef void (*Operation)(Robot* , int);

void MoveX(Robot *robot, int d)
{
  int flag = 0;
  for (int i = 0; i < numberOfRobots; i++)
  {
    if (robot->pos.x + d == arr[i]->pos.x && robot->pos.y == arr[i]->pos.y){
      cout <<"MoveX: Cannot place robots in the same position."<<endl;
      flag++;
    }
  }
  if (flag == 0)
    robot->pos.x += d;
}

void MoveY(Robot *robot, int d)
{
  int flag = 0;
  for (int i = 0; i < numberOfRobots; i++)
  {
    if (robot->pos.x == arr[i]->pos.x && robot->pos.y + d == arr[i]->pos.y){
      cout <<"MoveY: Cannot place robots in the same position."<<endl;
      flag++;
    }
  }
  if (flag == 0)
    robot->pos.y += d;
}

void DeleteRobots()
{
  for (int i = 0; i < numberOfRobots; i++)
  {
    delete arr[i];
  }
  delete[] arr;
}