#include "Task.h"

#include <iostream>
#include <Windows.h>
#include <string>
#include <random>
#include <ctime>

Task::Task()
{
	strTaskType_ = '\0';
	strTaskDescription_ = '\0';
	taskTime_ = 0;
}

Task::Task(std::string strTaskType, std::string strTaskDescription, int taskTime)
{
	strTaskType_ = strTaskType;
	strTaskDescription_ = strTaskDescription;
	taskTime_ = taskTime;
}

Task::~Task()
{}

const std::string& Task::getTaskType() const
{
	//std::cout << strTaskType_ << std::endl;
	return strTaskType_;
}

const std::string& Task::getTaskDescription() const
{
	return strTaskDescription_;
}

const int Task::getTaskTime() const
{
	return taskTime_;
}

void Task::setTaskType(const std::string& strTaskType)
{
	strTaskType_ = strTaskType;
}

void Task::setTaskDescription(const std::string& strTaskDescription)
{
	strTaskDescription_ = strTaskDescription;
}

void Task::setTaskTime(const int taskTime)
{
	taskTime_ = taskTime;
}

void Task::showTaskType() const
{
	std::cout << strTaskType_ << "\n";
}

void Task::showTaskDescription() const
{
	std::cout << strTaskDescription_ << "\n";
}

void Task::showProgressTask() const
{
	std::cout << "In progress...\n";

	Sleep(taskTime_*N);

	std::cout << "Finished\n";
}

void RandomTask::showProgressTask() const
{
	std::cout << "In progress...\n";

	std::mt19937 gen(time(0)); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<int> dis(0, 5);

	if (dis(gen) == 0)
	{
		std::cout << "Finished\n";
	}
	else
	{
		Sleep(taskTime_*N);

		std::cout << "Finished\n";
	}
}

