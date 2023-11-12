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
        void pop(){
            
            Base_node *temp_ptr = root;
            root = root->incr();
            delete temp_ptr;
        }
        void remove(int index){
            int count = 0;
            //they want to delete first node. quicker to pop
    
            if (index == 0){
                this->pop();
                return;              
            }
            Base_node* current_node = root;
            Base_node* previous_node = nullptr;
            while (current_node != nullptr){
                if(count == index){
                    
                    //this is the node i want to delete
                    //the node taht the current one points to
                    Base_node* temp_ref = current_node->incr();
                    //free up memory
                    
                    //rewire everything
                    previous_node->add_node(temp_ref);
                    delete current_node;
                    return;
                }
                count += 1;
                previous_node = current_node;
                current_node = current_node->incr();
            }
            throw std::invalid_argument("index does not exist");               
        }
};

template<class T>
class static_node{
    private:
        T val;
        static_node* next_node = nullptr;
    public:
        static_node(T new_val){
            this->val = new_val;
        }
        void add_link(static_node* new_link){
            this->next_node = new_link;
        }
        static_node* incr(){
            return this->next_node;
        }
        T get_val(){
            return this->val;
        }
    void print(){
        std::cout<<this->val;
    }
};

template <class T>
class static_linked_list{
    private:
        static_node<T>* root = nullptr;
        static_node<T>* last_node = nullptr;
    public:
        
        void push(T new_val){
            if (root == nullptr){
                root = new static_node<T>(new_val);
                last_node = root;
                return;
            }
            static_node<T>* temp_ref = last_node;
            last_node = new static_node<T>(new_val);
            temp_ref->add_link(last_node);
            temp_ref = nullptr;
            
        }
        void pop(){
            static_node<T>* temp_ref = root;
            root = root->incr();
            delete temp_ref;
            
        }
        void print(){
            std::cout << "[";
            static_node<T>* current_node = this->root;
            current_node->print();
            while (current_node->incr() != nullptr){
                
                current_node = current_node->incr();
                std::cout <<",";
                current_node->print();
                

            }
            std::cout <<"]"<<"\n";
        }
        void remove(int index){
            int count = 0;
            //they want to delete first node. quicker to pop
    
            if (index == 0){
                this->pop();
                return;              
            }
            static_node<T>* current_node = root;
            static_node<T>* previous_node = nullptr;
            while (current_node != nullptr){
                if(count == index){
                    
                    //this is the node i want to delete
                    //the node that the current one points to
                    static_node<T>* temp_ref = current_node->incr();
                    //free up memory
                    
                    //rewire everything
                    previous_node->add_link(temp_ref);
                    delete current_node;
                    return;
                }
                count += 1;
                previous_node = current_node;
                current_node = current_node->incr();
            }
            throw std::invalid_argument("index does not exist");                 
        }
        T get_value(int index){
            int count = 0;
            //they want to delete first node. quicker to pop
    
            
            static_node<T>* current_node = root;
            static_node<T>* previous_node = nullptr;
            while (current_node != nullptr){
                if(count == index){
                    
                    //this is the node i want to delete
                    //the node that the current one points to
                    
                    return current_node->get_val();
                }
                count += 1;
                previous_node = current_node;
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
    new_list->push(true);
    new_list->push(24);
    std::string data ="Hello World!";
    new_list->push("Hello World!");
    new_list->print();
  

    int x = new_list->get_value<int>(0);
    std::cout<<x<<"\n";
    std::cout<<new_list->get_value<char*>(4)<<"\n";
    new_list->pop();
    new_list->remove(2);
    new_list->print();
    static_linked_list<int>* new_static_linked_list = new static_linked_list<int>;
    new_static_linked_list->push(1);
    new_static_linked_list->push(3);
    new_static_linked_list->push(2);
    new_static_linked_list->push(24);
    new_static_linked_list->push(5);
    new_static_linked_list->print();
    new_static_linked_list->pop();
    new_static_linked_list->remove(2);
    new_static_linked_list->print();
    std::cout<<new_static_linked_list->get_value(1)<<"\n";

    return 0;
}