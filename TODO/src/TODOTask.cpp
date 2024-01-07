//
// Created by Simen on 06.01.2024.
//

#include "TODOTask.h"

#include <utility>

std::atomic_uint32_t TodoTask::current_id(0);

TodoTask::TodoTask(std::string name, std::string description)
{
    task_name = std::move(name);
    task_description = std::move(description);
    task_completion_status = false; // Initialize as false.
    Id = current_id;
    current_id++;
}

void TodoTask::show() const
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Id: " << TodoTask::Id << std::endl;
    std::cout << "Name: " << TodoTask::task_name << std::endl;
    std::cout << "Completion Status: " << TodoTask::task_completion_status << std::endl;
    std::cout << "Description: " << TodoTask::task_description << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void TodoTask::show_short() const
{
    std::cout << "Id: " << TodoTask::Id << std::endl;
    std::cout << "Name: " << TodoTask::task_name << std::endl;

    std::cout << std::endl;
}

bool TodoTask::empty() const
{
    return (task_name.empty() && task_description.empty());
}