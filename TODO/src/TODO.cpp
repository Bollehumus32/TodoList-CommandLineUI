#include <iostream>
#include <any>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "TODOList.h"
#include "TODOTask.h"

std::vector<TodoList> TodoLists;

void readInput(int& input) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> input;
}

void readLine(std::string& input) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
}


void menu(std::vector<std::string>& menu_choices)
{
    if(menu_choices.empty())
    {
        std::cout << "Invalid Input. No menu choices provided.";
        return;
    }

    for(int i{0}; i < menu_choices.size(); ++i)
    {
        std::cout << i+1 << ". " << menu_choices[i] << std::endl;
    }
}

int Create_List()
{
    std::string name;
    std::string description;

    std::cout << "Enter a name for the list:" << std::endl;
    readLine(name);

    std::cout << "Enter a description for the list (optional):" << std::endl;
    std::getline(std::cin, description);

    TodoLists.emplace_back(name, description);

    return 0;
}

int View_Lists()
{
    if(TodoLists.empty())
    {
        std::cout << "There are no existing lists." << std::endl;
        return 1;
    }

    int i = 1;
    std::cout << "---------- Lists ----------------" << std::endl;
    for(auto& list : TodoLists)
    {
        std::cout << i << ". " << list._list_name << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    return 0;
}

int View_List_Contents()
{
    int choice = -1;
    int list_contents;

    std::cout << "Select a TODO List:" << std::endl;
    list_contents = View_Lists();
    if(list_contents)
    {
        return 1;
    }

    readInput(choice);

    TodoLists[choice-1].View_Todo_List_Items();
    return 0;
}

int Add_ItemWRAPPER()
{
    int choice = -1;
    int list_contents;

    std::cout << "Select a TODO List:" << std::endl;
    list_contents = View_Lists();
    if(list_contents)
    {
        return 1;
    }

    readInput(choice);

    TodoLists[choice-1].Add_Todo_Item();
    return 0;
}

int Edit_ItemWRAPPER()
{
    int choice = -1;
    int list_contents;

    std::cout << "Select a TODO List:" << std::endl;
    list_contents = View_Lists();
    if(list_contents)
    {
        return 1;
    }

    readInput(choice);

    TodoLists[choice-1].Edit_Todo_Item();
    return 0;
}

int Remove_ItemWRAPPER()
{
    int choice = -1;
    int list_contents;


    std::cout << "Select a TODO List:" << std::endl;
    list_contents = View_Lists();
    if(list_contents)
    {
        return 1;
    }

    readInput(choice);

    TodoLists[choice-1].Remove_Todo_Item();
    return 0;
}

int Mark_Item_CompleteWRAPPER()
{
    int choice = -1;
    int list_contents;

    std::cout << "Select a TODO List:" << std::endl;
    list_contents = View_Lists();
    if(list_contents)
    {
        return 1;
    }

    readInput(choice);

    TodoLists[choice - 1].Mark_As_Completed();
    return 0;
}

int main()
{
    std::vector<std::string> choices = {"Create TODO-List", "View TODO-Lists", "View TODO-List contents", "Add a TODO item", "Edit a TODO item", "Remove a TODO item", "Mark an item as complete", "Quit"};
    std::map<std::string, std::function<int()>> str_to_func_map;

    str_to_func_map[choices[0]] = Create_List;
    str_to_func_map[choices[1]] = View_Lists;
    str_to_func_map[choices[2]] = View_List_Contents;
    str_to_func_map[choices[3]] = Add_ItemWRAPPER;
    str_to_func_map[choices[4]] = Edit_ItemWRAPPER;
    str_to_func_map[choices[5]] = Remove_ItemWRAPPER;
    str_to_func_map[choices[6]] = Mark_Item_CompleteWRAPPER;


    int choice = -1;

    while(true)
    {
        std::cout << std::endl;
        menu(choices);
        std::cin >> choice;
        if(choice > choices.size())
        {
            std::cout << "Not a valid menu choice option. Try again.";
            continue;
        }

        if(choice == choices.size())
        {
            return 0;
        }

        str_to_func_map[choices[choice-1]]();

    }
}