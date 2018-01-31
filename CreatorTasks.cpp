#include "CreatorTasks.h"
#include "Task.h"

#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <string>
#include <memory>

CreatorTasks::CreatorTasks()
{
}

CreatorTasks::~CreatorTasks()
{
}

void CreatorTasks::enter()
{
	std::cout << "***************Creating tasks*****************\n\n";

	std::cout << "Enter number of tasks: ";
	std::cin >> numberTask_;

	int choice, intTimeTask = 0;
	std::string strDescription;

	for (auto i(1); i<=numberTask_;++i)
	{
		std::cout << "\nChoose type of task#"<<i<<" (0 - NormalTask, 1 - RandomTask): ";

		std::cin >> choice;

		switch (choice)
		{
			case 0:
			{
				std::shared_ptr<Task> task_ = std::make_shared<NormalTask>();

				std::cout << "Enter description of normal task: ";
				std::cin >> strDescription;
				task_->setTaskDescription(strDescription);

				std::cout << "Enter time of execution task: ";
				std::cin >> intTimeTask;
				task_->setTaskTime(intTimeTask);

				tasks_.push_back(task_);

				break;
			}

			case 1:
			{
				std::shared_ptr<Task> task_ = std::make_shared<RandomTask>();

				std::cout << "Enter description of normal task: ";
				std::cin >> strDescription;
				task_->setTaskDescription(strDescription);

				std::cout << "Enter time of execution task: ";
				std::cin >> intTimeTask;
				task_->setTaskTime(intTimeTask);

				tasks_.push_back(task_);

				break;
			}

		default:
			std::cout << "Error enter\n\n";

			break;
		}
	}
	std::cout << std::endl;
}

const std::vector<std::shared_ptr<Task>>& CreatorTasks::getTasksVector() const
{
	return tasks_;
}

const int CreatorTasks::getSize() const
{
	return tasks_.size();
}

const std::shared_ptr<Task>& CreatorTasks::getTask(const int i) const
{
	return tasks_[i];
}




