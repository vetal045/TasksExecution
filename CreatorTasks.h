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
	const int getSize() const;
	const std::shared_ptr<Task>& getTask( const int i) const;

	//
	// Private data members.
	//

private:
	int numberTask_;
	std::vector <std::shared_ptr<Task>> tasks_;
};

