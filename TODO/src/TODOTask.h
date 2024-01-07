//
// Created by Simen on 06.01.2024.
//

#ifndef CODE_TODOTASK_H
#define CODE_TODOTASK_H
#include <iostream>
#include <string>
#include <atomic>

class TodoTask
{
public:
    int Id;
    static std::atomic_uint32_t current_id;
    TodoTask(std::string name, std::string description);
    std::string task_name;
    bool task_completion_status;
    std::string task_description;


    // Public functions for a single task:
    void show() const;
    void show_short() const;
    bool empty() const;
};


#endif //CODE_TODOTASK_H
