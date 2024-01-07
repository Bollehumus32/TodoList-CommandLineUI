//
// Created by Simen on 06.01.2024.
//

#include "TODOTask.h"

#include <utility>

std::atomic_uint32_t TodoTask::_current_id(0);

TodoTask::TodoTask(std::string name, std::string description)
{
    _task_name = std::move(name);
    _task_description = std::move(description);
    _task_completion_status = false; // Initialize as false.
    _Id = _current_id;
    _current_id++;
}

void TodoTask::Show() const
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Id: " << TodoTask::_Id << std::endl;
    std::cout << "Name: " << TodoTask::_task_name << std::endl;
    std::cout << "Completion Status: " << TodoTask::_task_completion_status << std::endl;
    std::cout << "Description: " << TodoTask::_task_description << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void TodoTask::Show_Short() const
{
    std::cout << "Id: " << TodoTask::_Id << std::endl;
    std::cout << "Name: " << TodoTask::_task_name << std::endl;

    std::cout << std::endl;
}

bool TodoTask::Empty() const
{
    return (_task_name.empty() && _task_description.empty());
}