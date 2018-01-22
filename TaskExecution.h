#pragma once

#include "CreatorTasks.h"

#include <memory>

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

private:
	std::mutex mutexTasks_;
	std::shared_ptr<CreatorTasks> threadTasks_;
};

