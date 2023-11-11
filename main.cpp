// hello.cpp file
#include <iostream>
class Base_node{
    public:
    virtual void add_node(Base_node* new_node){}
    virtual Base_node* incr(){return nullptr;}
    virtual void print(){}
};

template<class T>
class node: public Base_node{
    private:
        Base_node* next_node = nullptr;
        T value;
    public:
        
        node(T value){
            this->value = value;
        }
        void add_node(Base_node* new_node){
            next_node = new_node;
        }
        Base_node* incr(){
            
            if (next_node != nullptr){
                return next_node;
            }
            return nullptr;
        }
        void print(){

            std::cout<<this->value;
        }
};

class linked_list{
    private:
        Base_node *root = nullptr;
        Base_node *last_node = nullptr; 
    public:
        
        template<class T>
        void push(T new_value){
            
            if (root == nullptr){
                root = new node<T>(new_value);
                last_node = root;
                return;
            }
            Base_node *new_node = new node<T>(new_value);
            
            last_node->add_node(new_node);
            last_node = new_node;
            new_node = nullptr;
        }

        void print(){
            std::cout << "[";
            Base_node* current_node = this->root;
            current_node->print();
            while (current_node->incr() != nullptr){
                
                current_node = current_node->incr();
                std::cout <<",";
                current_node->print();
                

            }
            std::cout <<"]"<<"\n";
        }
        // std::ostream is the type for object std::cout
        
 
};





int main()
{
    linked_list* new_list = new linked_list;
    new_list->push(3);
    new_list->push(4.5);
    new_list->push("T");
    new_list->print();
   
    return 0;
}