
  typedef struct ListNode node;

  node *create_node(int num)
  {
  	node *new_nd = (node *) malloc(sizeof(node));
  	new_nd -> val = num;
  	new_nd -> next = NULL;
  	return new_nd;
  }

  void sum_llists(node *a, node *b, int c, node **curr_nd)
  {
      int a_val = 0, b_val = 0;
      if (a)
      {
          a_val = a -> val;
          a = a -> next;
      }
      if (b)
      {
          b_val = b -> val;
          b = b -> next;
      }

      int num = a_val + b_val + c;
      c = num / 10;
      num = num % 10;

      node *new_nd = create_node(num);

  	if (*curr_nd != NULL)
  	{
          (*curr_nd) -> next = new_nd;
  	}
      else
      {
          *curr_nd = new_nd;
      }

      if (a || b || c)
      {
          sum_llists(a, b, c, &new_nd);
      }
  }

  node* addTwoNumbers(node *l1, node *l2)
  {
      node **curr_node = (node**) calloc(sizeof(node*), sizeof(node*));

      sum_llists(l1,l2,0,curr_node);

      return *curr_node;  
  }
