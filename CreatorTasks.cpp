#include "CreatorTasks.h"
#include "Task.h"

#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <string>

CreatorTasks::CreatorTasks()
{
	enter();
	thread_print();
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
			task_ = new NormalTask();
			task_->setTaskType("NormalTask");

			std::cout << "Enter description of normal task: ";
			std::cin>>strDescription;
			task_->setTaskDescription(strDescription);

			std::cout << "Enter time of execution task: ";
			std::cin >> intTimeTask;
			task_->setTaskTime(intTimeTask);

			tasks_.push_back(task_);

			break;

		case 1:
			task_ = new RandomTask();
			task_->setTaskType("RandomTask");

			std::cout << "Enter description of normal task: ";
			std::cin >> strDescription;
			task_->setTaskDescription(strDescription);

			std::cout << "Enter time of execution task: ";
			std::cin >> intTimeTask;
			task_->setTaskTime(intTimeTask);

			tasks_.push_back(task_);

			break;

		default:
			std::cout << "Error enter\n\n";

			break;
		}
	}
}

const std::string& CreatorTasks::showTypes(int i)
{
	std::string str(tasks_[i]->getTaskType());

	if (i < tasks_.size() && mutexTasks_.try_lock())
	{
		std::cout << str << std::endl;

		mutexTasks_.unlock();
	}

	return str;
}

const std::string& CreatorTasks::showDescriptions(int i)
{
	std::string str(tasks_[i]->getTaskDescription());

	if (i < tasks_.size() && mutexTasks_.try_lock())
	{
		std::cout << str << std::endl;

		mutexTasks_.unlock();	
	}

	return str;
}

const int CreatorTasks::showProgress(int i)
{
	if (i < tasks_.size() && mutexTasks_.try_lock())
	{
		tasks_[i]->showProgressTask();

		std::cout << std::endl;

		mutexTasks_.unlock();
	}

	return tasks_[i]->getTaskTime();
}

void CreatorTasks::thread_print() 
{
	std::cout << std::endl;

	auto printTypes = [&]()
	{
		for (auto i = 0; i<numberTask_; ++i)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));

			std::unique_lock<std::mutex> lock(mutexThreads_);

			std::cout << "Type of task#" << i+1 << " - ";
			std::async(std::launch::async, &CreatorTasks::showTypes, this,i);

			std::cout << std::endl;
		}
		isDoneTypes_ = true;

		condTasks_.notify_one();
	};

	auto printDescriptions = [&]()
	{
		std::unique_lock<std::mutex> lock(mutexThreads_);

		while (!isDoneTypes_) 
		{
			condTasks_.wait(lock);

			if (isDoneTypes_)
			{
				for (auto i = 0; i < numberTask_; ++i)
				{
					std::cout << "Description of task#" << i + 1 <<" - ";
					std::async(std::launch::async, &CreatorTasks::showDescriptions, this, i);

					std::cout << std::endl;
				}
			}
		}
		isDoneDescriptions_ = true;

		condDescriptions_.notify_one();
	};

	auto printProgress = [&]()
	{
		std::unique_lock<std::mutex> lock(mutexThreads_);

		while (!isDoneDescriptions_)
		{
			condDescriptions_.wait(lock);

			if (isDoneDescriptions_)
			{
				for (auto i = 0; i < numberTask_; ++i)
				{
					std::cout << "Execution of task#" << i + 1 << ".\n";
					std::async(std::launch::async, &CreatorTasks::showProgress, this, i);
				}
			}
		}
	};

	std::thread t1(printTypes);
	std::thread t2(printDescriptions);
	std::thread t3(printProgress);

	t1.join();
	t2.join();
	t3.join();
}
