// hello.cpp file
#include <iostream>

class Base_node{
    public:
    virtual void add_node(Base_node* new_node){}
    virtual Base_node* incr(){return nullptr;}
    virtual void print(){}
    virtual void* get_value(){return nullptr;}
    virtual std::string get_type(){return "l";}
    
};

template<class T>
class node: public Base_node{
    private:
        Base_node* next_node = nullptr;
        T value;
        std::string type;
        
    public:
        void* get_value(){
            return &value;
        }
        std::string get_type(){
            return this->type;
        }
        node(T value){
            
            this->type = typeid(T).name();
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
        
        Base_node* get(int index){
            int count = 0;
            Base_node* current_node = root;
            while (current_node != nullptr){
                if(count == index){
                    
                    current_node->print();
                
                    return current_node;
                }
                count += 1;
                current_node = current_node->incr();
            }
            return nullptr;
        }
        template<class T>
        T get_value(int index){
            int count = 0;
            Base_node* current_node = root;
            while (current_node != nullptr){
                if(count == index){
                    return *(T*)current_node->get_value();
      
                }
                count += 1;
                current_node = current_node->incr();
            }
            throw std::invalid_argument("index does not exist");        
        }
        std::string get_type(int index){
            int count = 0;
            Base_node* current_node = root;
            while (current_node != nullptr){
                if(count == index){
                    

                    return current_node->get_type();
                }
                count += 1;
                current_node = current_node->incr();
            }
            throw std::invalid_argument("index does not exist");              
        }
};





int main()
{
    linked_list* new_list = new linked_list;
    new_list->push(3);
    new_list->push(4.5f);
    std::string data ="Hello World!";
    new_list->push("Hello World!");
    new_list->print();
  

    int x = new_list->get_value<int>(0);
    std::cout<<x<<"\n";
    std::cout<<new_list->get_value<char*>(2);
    return 0;
}