#include "TaskExecution.h"
#include "Task.h"

#include <exception>
#include <iostream>
#include <future>

TaskExecution::TaskExecution()
{
	try
	{
		threadTasks_ = std::make_shared<CreatorTasks>();
		threadTasks_->enter();
		work();
	}

	catch (const std::exception&)
	{
		std::cout << "Error by creating the task.\n";

	}

	catch (...)
	{
		std::cout << "Uknown error.\n";
	}
}


TaskExecution::~TaskExecution()
{
}

void TaskExecution::showTasksTypes()
{
	for (auto i = 0; i < threadTasks_->numberTask_; ++i)
	{
		std::lock_guard<std::mutex> lock(mutexTasks_);

		std::cout << "Type of task #" << i << ": " << threadTasks_->tasks_[i]->getTaskType() << std::endl;
	}

	std::cout << std::endl;
}

void TaskExecution::showTasksProgress()
{
	for (auto i = 0; i < threadTasks_->numberTask_; ++i)
	{
		std::lock_guard<std::mutex> lock(mutexTasks_);

		std::cout << "Progress of task #" << i << std::endl;

		threadTasks_->tasks_[i]->showProgressTask();

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void TaskExecution::showTasksDescriptions()
{
	for (auto i = 0; i < threadTasks_->numberTask_; ++i)
	{
		std::lock_guard<std::mutex> lock(mutexTasks_);

		std::cout << "Description of task #" << i << ": " << threadTasks_->tasks_[i]->getTaskDescription() << std::endl;
	}

	std::cout << std::endl;
}

void TaskExecution::work()
{
	std::async(std::launch::async, &TaskExecution::showTasksTypes,this);
	std::async(std::launch::async, &TaskExecution::showTasksDescriptions, this);
	std::async(std::launch::async, &TaskExecution::showTasksProgress, this);
}
