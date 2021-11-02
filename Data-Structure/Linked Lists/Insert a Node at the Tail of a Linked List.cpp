// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(data); 
    if (head == nullptr) {
        head = node;
    } else {
        SinglyLinkedListNode *temp = head; 
        while (temp->next != nullptr) {
            temp = temp->next; 
        }
        temp->next = node;
    }
    return head;
}
