#include <iostream>
#include <assert.h>

/*
  My simple implementation of single linked list
*/

class Node
{
public:
  int value;
  Node* next_node;
  Node(int n)
  {
    value=n;
    next_node = NULL;
  };
  ~Node()
  {
//      std::cout << "Destructor Node:"<< value;
      delete(next_node);
  }
};

class Tree{
public:
  Node* head;
  int size;
  Tree(int x)
  {
    head = new Node(x);
    size = 1;
  }

  ~Tree()
  {
//    std::cout << "Destrcutor:"<< this->size <<"!";
    delete(this->head);
  }

  void add_node(int n)
  {
    Node* current_node = this->head;
    Node* new_node = new Node(n);

    if (current_node !=NULL)
    {
      while(current_node->next_node != NULL)
        current_node = current_node->next_node;
      current_node->next_node = new_node;
    }
    else
    {
      std::cout << "AHTUNG NEW HEAD created\n";
      this->head = new_node;
    }
    ++this->size;
  }


  void print_tree()
  {
    int counter(0);

    Node* current_node = this->head;
    // Scroll through the list
    while (current_node != NULL) // we start counting from 0
    {
      std::cout << "node[" << counter << "]=" << current_node->value <<";\n";
      current_node = current_node->next_node;
      ++counter;
    }
  }

  void remove_node(int index)
  {
    assert(index<=this->size);
    assert(index>=0);
    int counter(0);

    if (index ==0)
    { // Head of list
      Node* current_node = this->head;
      this->head = (this->head)->next_node;
      current_node->next_node = NULL;
      delete(current_node);
    }
    else
    {
      Node* current_node = this->head;
      Node* prev_node = this-> head;
      // Scroll through the list
      while (current_node != NULL && counter <= index-1) // we start counting from 0
      {
//        if (print)
//          std::cout << "node[" << counter << "]=" << current_node->value <<";\n";
        prev_node = current_node;
        current_node = current_node->next_node;
        ++counter;
      }

      // Deleting the node
      if (current_node->next_node == NULL)
      { //last node
        prev_node->next_node = NULL;
        delete(current_node);
      }
      else
      { // mid node
          prev_node->next_node = current_node->next_node;
          current_node->next_node = NULL;
          delete(current_node);
      }
    }
  }
};


/* Task 1 Remove duplicates from linked list*/
void tree_remove_duplicates(Tree& tree_to_clean)
{
  int current_index(0);
  Node* current_node = tree_to_clean.head;
  int current_value(0);

  while (current_node->next_node != NULL)
  {
   current_value = current_node->value;
   Node* iterator = current_node->next_node;
   int iterator_index = current_index+1;

   do
   {
     if (iterator->value == current_value)
      {
      std::cout << "removing " << iterator_index << " node\n";
      if (iterator->next_node != NULL)
        iterator = iterator->next_node;
      tree_to_clean.remove_node(iterator_index);
      }
    else
    {
      if (iterator->next_node != NULL)
        iterator = iterator->next_node;
      ++iterator_index;
    }
  }while  (iterator->next_node != NULL);

    if (current_node->next_node !=NULL)
      current_node = current_node->next_node;
    std::cout << "Cleaning end "<< current_index << "+1\n";
    ++current_index;
  }
}

/* TODO there is small bug above with test case i/6 - FIX if have time */


int main()
{
  Tree test_tree(0);
  for (int i=0; i< 10; ++i)
    test_tree.add_node(i/4);
  test_tree.print_tree();
  tree_remove_duplicates(test_tree);
  test_tree.print_tree();
}
