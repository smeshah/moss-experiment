
  typedef
  struct stack {
      char            c;
      struct stack   *next;
  } Stack;

  void create(Stack **ptop)
  {
      *ptop = NULL;
  }

  void push(Stack **ptop, char c)
  {
      Stack   *tmp;

      tmp = malloc(sizeof *tmp);
      tmp->c = c;
      tmp->next = *ptop;

      *ptop = tmp;
  }

  void pop(Stack **ptop, char *c)
  {
      Stack   *tmp;

      if (! *ptop) return;

      tmp = *ptop;
      *c = tmp->c;
      *ptop = (*ptop)->next;
      free(tmp);
  }

  int empty(Stack **ptop)
  {
     return *ptop == NULL; 
  }

  bool isValid(char* s) {
      Stack   *ss;
      char    c;

      create(&ss);
      while (*s) {
          switch (*s) {
          case '(':
          case '[':
          case '{':
              push(&ss, *s);
              break;
          case ')':
          case ']':
          case '}':
              if (empty(&ss)) return 0;
              pop(&ss, &c);
              if (c + 1 != *s
                  && c + 2 != *s) return 0;
              break;
          default:
              break;
          }
          ++s;
      }

      if (!empty(&ss)) return 0;
      return 1;
  }
