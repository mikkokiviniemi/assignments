/*
Exercise 1.

Here we will create an interface for an UI element (these are usually called widgets).  
It should have require functionality such as reacting to user actions "on_click()", "on_focus()", etc.  
In addition it should have a way to move and get position of the UI element.  
In addition, UI elements usually have child elements (that also fulfill the interface), 
you should require functionality to add / remove / list those as well.

Exercise 2.

Make some mock class that inherits the interface.  
It does not need to be a real UI or anything, just something that implements the UI interface.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

//UI class
class UI {
    public:
        virtual ~UI(){};
        virtual void on_click() = 0;
        virtual void on_focus() = 0;
        virtual void move(int x, int y) = 0;
        virtual int get_position() = 0;
        virtual void add_child(UI* child) = 0;
        virtual void remove_child(UI* child) = 0;
        virtual std::vector<UI*> get_children() const = 0;
};

//Some widget
class Widget : public UI {
    public:
        Widget(){};
        void on_click() override {
            std::cout << "Clicked\n";
        }
        void on_focus() override {
            std::cout << "Focus\n";
        }
        void move(int move_x,int move_y) override{
            x = move_x;
            y = move_y;
        }
        int get_position() override {
            return x*y;
        }
        void add_child(UI* child) override {
            children.push_back(child);
        } 
        void remove_child(UI* child) override {
            auto i = std::find(children.begin(), children.end(), child);
            if (i != children.end()) {
                children.erase(i);
            }
        } 
        std::vector<UI*> get_children() const override {
            return children;
        } 
    private:
        int x, y;
        std::vector<UI*> children;
};


int main()
{
    Widget new_widget;
    new_widget.move(6,6);
    new_widget.on_click();
    new_widget.on_focus();
    std::cout << new_widget.get_position() << "\n";

    Widget new_child;
    new_child.move(2,2);
    new_widget.add_child(&new_child);
    for(auto& children : new_widget.get_children()) {
        std::cout << children->get_position() << "\n";
    }
    return 0;
}
