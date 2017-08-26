#include <iostream>
#include <assert.h>
#include <linked.hpp>
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
