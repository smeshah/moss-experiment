
  struct Node;
  typedef struct Node *PtrToNode;
  typedef PtrToNode Stack;

  struct Node
  {
      char Element;
      PtrToNode Next;
  };

  int IsEmpty(Stack S)
  {
      return S->Next == NULL;
  }

  void Pop(Stack S)
  {
      PtrToNode FirstCell;

      FirstCell = S->Next;
      S->Next = S->Next->Next;
      free(FirstCell);
  }

  void Push(char X, Stack S)
  {
      PtrToNode TmpCell;
      TmpCell = malloc(sizeof(struct Node));
      TmpCell->Element = X;
      TmpCell->Next = S->Next;
      S->Next = TmpCell;
  }

  Stack CreateStack(void)
  {
      Stack S;
      S = malloc(sizeof(struct Node));
      S->Next = NULL;
      while(!IsEmpty(S))
          Pop(S);
      return S;
  }

  int isValid(char *s)
  {
      Stack S = CreateStack();
      while(*s != ' ')
      {
          if( *s == '(' || *s == '[' || *s == '{')
          {
              Push(*s, S);
          }
          else
          {
              if(!IsEmpty(S)){
                  switch(*s){
                      case ')':
                          if(S->Next->Element == '(')
                              Pop(S);
                          else
                              Push(*s, S);
                          break;
                      case ']':
                          if(S->Next->Element == '[')
                              Pop(S);
                          else
                              Push(*s, S);
                          break;
                      case '}':
                          if(S->Next->Element == '{')
                              Pop(S);
                          else
                              Push(*s, S);
                          break;
                      default: break;
                  }
              }else
                  Push(*s, S);
          }
          s++;
      }
      return IsEmpty(S);
  }
