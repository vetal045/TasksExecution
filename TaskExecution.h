#pragma once

#include "CreatorTasks.h"

#include <memory>
#include <future>

//
// Declaration of the class TaskExecution.
//

class TaskExecution
{
	//
	// Construction and destruction.
	//

public:
	TaskExecution();
	~TaskExecution();

	//
	// Public methods.
	//

public:
	void showTasksTypes();
	void showTasksProgress();
	void showTasksDescriptions();
	void work();

	//
	// Private data members.
	//

private:
	std::mutex mutexTasks_;
	std::shared_ptr<CreatorTasks> threadTasks_;
	std::future<void> tasksFutureType_;
	std::future<void> tasksFutureDescription_;
	std::future<void> tasksFutureProgress_;
};

