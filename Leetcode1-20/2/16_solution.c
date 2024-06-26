
  int get_len(struct ListNode* l) {
  	if(l == NULL) return 0;

  	int len = 0;
  	while(l != NULL) {
  		len++;
  		l = l->next;
  	}
  	return len;
  }

  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
  	if( l1 == NULL || l2 == NULL) return NULL;

  	/* Find length of l1 */
  	int l1_len = get_len(l1);

  	/* Find length of l2 */
  	int l2_len = get_len(l2);

  	/* result is stored in longer link list */
  	struct ListNode *res = (l1_len > l2_len) ? l1 : l2;
  	struct ListNode *oth = (l1_len <= l2_len) ? l1 : l2;
  	struct ListNode *tmp = res, *last = NULL;

  	/* Traverse link list adding nodes */
  	int r = 0;
  	while(tmp != NULL) {
  		if(oth != NULL) {
  			r = r + tmp->val + oth->val;
  			oth = oth->next;
  		}else {
  			r = r + tmp->val;
  		}
  		tmp->val = r % 10;
  		r = r / 10;
        last = tmp;
  		tmp = tmp->next;
  	}

  	/* Add result if anything pending */
  	if( r != 0) {
  		struct ListNode *t = malloc(sizeof(struct ListNode));
  		t->val = r;
  		t->next = NULL;
  		last->next = t;
  	}
  	/* Return res */
  	return res;
  }
