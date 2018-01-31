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
	tasksFutureType_.get();
	tasksFutureDescription_.get();
	tasksFutureProgress_.get();
}

void TaskExecution::showTasksTypes()
{
	for (auto i = 0; i < threadTasks_->getSize(); ++i)
	{
		std::lock_guard<std::mutex> lock(mutexTasks_);

		std::cout << "Type of task #" << i << ": " << threadTasks_->getTask(i)->getTaskType() << std::endl;
	}

	std::cout << std::endl;
}

void TaskExecution::showTasksProgress()
{
	for (auto i = 0; i < threadTasks_->getSize(); ++i)
	{
		std::lock_guard<std::mutex> lock(mutexTasks_);

		std::cout << "Progress of task #" << i << std::endl;

		threadTasks_->getTask(i)->showProgressTask();

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void TaskExecution::showTasksDescriptions()
{
	for (auto i = 0; i < threadTasks_->getSize(); ++i)
	{
		std::lock_guard<std::mutex> lock(mutexTasks_);

		std::cout << "Description of task #" << i << ": " << threadTasks_->getTask(i)->getTaskDescription() << std::endl;
	}

	std::cout << std::endl;
}

void TaskExecution::work()
{
	tasksFutureType_ = std::async(std::launch::async, &TaskExecution::showTasksTypes,this);
	tasksFutureDescription_ = std::async(std::launch::async, &TaskExecution::showTasksDescriptions, this);
	tasksFutureProgress_ = std::async(std::launch::async, &TaskExecution::showTasksProgress, this);
}
