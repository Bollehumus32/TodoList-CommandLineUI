#ifndef TODOLIST_H
#define TODOLIST_H
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "TODOTask.h"

class TodoList
{
private:
    // Private Utility function.
    int Index_Of(int ID);

public:
    // Public Variables
    std::string _list_name;
    std::string _list_description;
    std::vector<TodoTask> _TodoTasks;

    // Public Functions:
    TodoList(std::string name, std::string description);
    int View_Todo_List_Items();
    int View_Todo_List_Items_Short();
    int Add_Todo_Item();
    int Edit_Todo_Item();
    int Remove_Todo_Item();
    int Mark_As_Completed();
};

#endif //TODOLIST_H