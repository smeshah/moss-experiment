
  #define MAX_STACK_SZ 10000

  struct Stack {
      char value[MAX_STACK_SZ];
      size_t count;
  };

  void push(struct Stack *stack, char value)
  {
      assert(stack->count < MAX_STACK_SZ);

      stack->value[stack->count++] = value;
  }

  char pop(struct Stack *stack)
  {
      assert(stack->count);

      return stack->value[--stack->count];
  }

  bool isEmpty(struct Stack *stack)
  {
      return !stack->count;
  }

  bool isFull(struct Stack *stack)
  {
      return stack->count == MAX_STACK_SZ - 1;
  }

  bool isValid(char *s)
  {

      struct Stack stack = {0};

      while(*s) {
          char c = *s++;
          if ((c == '(') 
                  || (c == '{')
                  || (c == '[')) {
              push(&stack, c);
          } else {
              if (isEmpty(&stack))
                  return false;

              char cc = pop(&stack);
              if ((cc == '{' && c == '}')
                  || (cc == '(' && c == ')')
                  || (cc == '[' && c == ']'))
                      continue;
              else
                  return false;
          }
      }

      return isEmpty(&stack);
  }
