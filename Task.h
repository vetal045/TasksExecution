#pragma once

#include <string>

//
// Declaration of the class Task.
//

class Task
{
	//
	// Constructions and destruction.
	//

public:
	Task();
	Task(std::string strTaskType, std::string strTaskDescription, int taskTime);

	~Task();

	//
	// Public methods.
	//

public:
	const std::string& getTaskType() const;
	const std::string& getTaskDescription() const;
	const int getTaskTime() const;

	void setTaskType(const std::string& strTaskType);
	void setTaskDescription(const std::string& strTaskDescription);
	void setTaskTime(const int taskTime);

	virtual void showProgressTask() const;

	//
	// Protected data members.
	//

protected:
	std::string strTaskType_;
	std::string strTaskDescription_;
	int taskTime_;
};

//
// Declaration of the class NormalTask.
//

class NormalTask :public Task
{
	//
	// Constructions and destruction.
	//

public:
	NormalTask() {}
	NormalTask(std::string strNormalTaskType, std::string strNormalTaskDescription, int normalTaskTime):
		Task(strNormalTaskType, strNormalTaskDescription,normalTaskTime) {}

	~NormalTask() {}
};

//
// Declaration of the class RandomTask.
//

class RandomTask : public Task
{
	//
	// Constructions and destruction.
	//

public:

	RandomTask() {}
	RandomTask(std::string strNormalTaskType, std::string strNormalTaskDescription, int normalTaskTime) :
		Task(strNormalTaskType, strNormalTaskDescription, normalTaskTime) {}

	~RandomTask() {}

	//
	// Public methods.
	//

	void showProgressTask() const override;
};
