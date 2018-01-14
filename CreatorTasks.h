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
	const std::string& showTypes(int i);
	const std::string& showDescriptions(int i);
	const int showProgress(int i);
	void thread_print() ;

	//
	// Private data members.
	//

private:
	int numberTask_;
	std::mutex mutexTasks_;
	Task *task_;
	std::vector <Task *> tasks_;
	std::mutex mutexThreads_;
	std::condition_variable condTasks_;
	std::condition_variable condDescriptions_;
	bool isDoneTypes_ = false;
	bool isDoneDescriptions_ = false;
	/*std::condition_variable condDescriptions_;
	std::condition_variable condProgres_;*/
};

