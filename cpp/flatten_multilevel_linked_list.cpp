Given a linked list where in addition to the next pointer, each node has a child pointer, which may or may not point to a separate list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in below figure.You are given the head of the first level of the list. Flatten the list so that all the nodes appear in a single-level linked list. You need to flatten the list in way that all nodes at first level should come first, then nodes of second level, and so on.

The problem clearly say that we need to flatten level by level. The idea of solution is, we start from first level, process all nodes one by one, if a node has a child, then we append the child at the end of list, otherwise we don’t do anything. After the first level is processed, all next level nodes will be appended after first level. Same process is followed for the appended nodes.

void flattenList(Node* head) {
	if (head==NULL) return;
	Node* tail=head;
	while (tail->next!=NULL) tail=tail->next;

	Node *curr=head;
	while (curr!=tail) {
		if (curr->child) {
			tail->next=curr->child;
			curr->child=NULL;
			while (tail->next!=NULL) tail=tail->next;
		}

		curr=curr->next;
	}
}

