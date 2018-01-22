#pragma once

#include <vector>
#include <mutex>

class Task;

//
// Declaration of the class CreatorTasks.
//

class CreatorTasks
{
	//
	// Construction and destruction.
	//

public:
	CreatorTasks();
	~CreatorTasks();

	//
	// Public methods.
	//

	void enter();
	const std::vector<std::shared_ptr<Task>>& getTasksVector() const;

	//
	// Protected data members.
	//

public:
	int numberTask_;
	std::mutex mutexTasks_;
	std::shared_ptr<Task> task_;
	std::vector <std::shared_ptr<Task>> tasks_;
};

