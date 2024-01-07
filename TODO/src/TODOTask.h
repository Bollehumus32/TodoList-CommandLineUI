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
    // Public Variabes
    int _Id;
    static std::atomic_uint32_t _current_id;
    TodoTask(std::string name, std::string description);
    std::string _task_name;
    bool _task_completion_status;
    std::string _task_description;


    // Public utility functions
    void Show() const;
    void Show_Short() const;
    bool Empty() const;
};


#endif //CODE_TODOTASK_H
