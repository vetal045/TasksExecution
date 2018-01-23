#include "Task.h"

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

Task::Task()
{
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

void Task::showProgressTask() const
{
	std::cout << "In progress...\n";

	std::this_thread::sleep_for(std::chrono::seconds(taskTime_));

	std::cout << "Finished\n";
}

NormalTask::NormalTask()
{
	strTaskType_ = "NormalTask";
}

NormalTask::~NormalTask()
{
}

RandomTask::RandomTask()
{
	strTaskType_ = "RandomTask";
}

RandomTask::~RandomTask()
{
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
		std::this_thread::sleep_for(std::chrono::seconds(taskTime_));

		std::cout << "Finished\n";
	}
}

