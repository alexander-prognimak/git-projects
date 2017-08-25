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
};

class Tree{
public:
  Node* head;
  int size;
  Tree(Node& new_node)
  {
    head = &new_node;
    size = 1;
  }

  ~Tree()
  {
    if (this->size > 1)
      while(this->size > 1)
        remove_node(1);
    delete(this->head);
    this->head = NULL;
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
      this->head = new_node;

    ++this->size;
  }

  Node* scroll_list(int index, int print = 0)
  {
    //std::cout<<"DEBUG " << index <<"|" << this->size;
    assert(index<=this->size);
    assert(index>0);
    int counter(0);

    Node* current_node = this->head;
    // Scroll through the list
    while (current_node != NULL && counter <= index-1) // we start counting from 0
    {
      if (print)
        std::cout << "node[" << counter << "]=" << current_node->value <<";\n";

      current_node = current_node->next_node;
      ++counter;
    }

    return current_node;
  }

  int  remove_node(int index)
  {
    if (index>this->size || index<=0) // head node deleted with tree
    {
      std::cout << "Can't remove index " << index << "- less thatn size of linked list" << this->size<<std::endl;
      return 0;
    }
    else
    {
        Node* node_to_delete = scroll_list(index-1);
        // we assume it is not NULL because other size >0

        if ((Node*)(node_to_delete->next_node)->next_node == NULL) // last node
        {
          delete(node_to_delete->next_node);
          node_to_delete->next_node = NULL;
          --this->size;
        }
        else   // mid node
        {
          Node* next_to_delete = node_to_delete->next_node;
          node_to_delete->next_node = NULL;
          while(next_to_delete!=NULL)
          {
            node_to_delete = next_to_delete;
            next_to_delete= next_to_delete->next_node;
            delete(node_to_delete);
            --this->size;
          }
        }
    }

    return 1;
  }

};

/* Task 1 Remove duplicates from linked list*/
int main()
{
  Node head_node(0);
  Tree test_tree(head_node);

  for (int i=0; i< 10; ++i)
    test_tree.add_node(i);

  test_tree.scroll_list(test_tree.size, 1);


}
