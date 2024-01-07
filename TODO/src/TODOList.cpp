#include "TODOList.h"

TodoList::TodoList(std::string name, std::string description)
{
    list_name = name;
    list_description = description;
}


int TodoList::View_Todo_List_Items()
{

    if(TodoList::TodoTasks.empty())
    {
        std::cout << "No items in this list." << std::endl;
        return 1;
    }
    std::cout << "List items:" << std::endl;
    for(auto& item : TodoList::TodoTasks)
    {
        item.show();
    }
    std::cout << std::endl;
    return 0;
}

int TodoList::View_Todo_List_Items_Short()
{
    std::cout << "List items:" << std::endl;
    for(auto& item : TodoList::TodoTasks)
    {
        item.show_short();
    }
    std::cout << std::endl;
    return 0;
}

// Passing argument as constant reference, such that value can be copied into vector, but not changed.
// Memory efficient.
int TodoList::Add_Todo_Item()
{
    std::string name;
    std::string description;

    std::cout << "Enter Task Name:" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    // Newline between inputs for tidiness.
    std::cout << std::endl;

    std::cout << "Enter Task Description:" << std::endl;
    std::getline(std::cin, description);

    // Use emplace_back for this scenario instead of push_back
    TodoTasks.emplace_back(name, description);
    return 0;
}


int TodoList::Edit_Todo_Item()
{
    int ID;

    std::cout << "Select a task by ID:" << std::endl;

    View_Todo_List_Items_Short();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin >> ID;

    std::string new_name;
    std::string new_description;

    int index = Index_Of(ID);

    int choice = -1;

    bool valid_not_selected = true;


    std::cout << "Select which part of the task you'd like to edit:" << std::endl;
    while(valid_not_selected)
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "1. Name" << std::endl;
        std::cout << "2. Task Description" << std::endl;
        std::cout << "3. Cancel" << std::endl;
        std::cout << "-----------------------" << std::endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;

        if(choice > 3 || choice <= 0)
        {
            std::cout << "Invalid choice. Try again." << std::endl;
        }

        else valid_not_selected = false;
    }

    switch(choice)
    {
        case 1:
            std::cout << "Enter a new name for the task:" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, new_name);
            TodoList::TodoTasks[index].task_name = new_name;
            break;

        case 2:
            std::cout << "Enter a new description for the task:" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, new_name);
            TodoList::TodoTasks[index].task_description = new_description;
            break;

        case 3:
            std::cout << "Cancelling Operation ..." << std::endl;
            break;

        // Default case will never happen because of checks earlier in function...
        default:
            break;
    }

    return 0;
}


int TodoList::Remove_Todo_Item()
{
    int ID;

    std::cout << "Select a task by ID:" << std::endl;

    View_Todo_List_Items_Short();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> ID;

    int index = Index_Of(ID);
    if(index == -1)
    {
        std::cout << "Object not found" << std::endl;
        return 1;
    }

    TodoList::TodoTasks.erase(TodoList::TodoTasks.begin() + index);
    return 0;
}


int TodoList::Mark_as_completed()
{
    int ID;

    std::cout << "Select a task by ID:" << std::endl;

    View_Todo_List_Items_Short();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> ID;


    int index = Index_Of(ID);
    if(index == -1)
    {
        std::cout << "Object not found" << std::endl;
        return 1;
    }

    TodoList::TodoTasks[index].task_completion_status = true;
    return 0;
}

// UTILITY FUNCTION:
// -1 means object does not exist with that ID;
int TodoList::Index_Of(int ID)
{
    int index = 0;
    for(auto& item : TodoTasks)
    {
        if(item.Id == ID)
        {
            return index;
        }
        index++;
    }
    return -1;
}
