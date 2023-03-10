/*

Level wise linkedlist

Given a binary tree, write code to create a separate linked list for each level. 
You need to return the array which contains head of each level linked list.

Input format :
The first line of input contains data of the nodes of the tree in level 
order form. The data of the nodes of the tree is separated by space. 
If any node does not have left or right child, take -1 in its place. 
Since -1 is used as an indication whether the left or right nodes exist, 
therefore, it will not be a part of the data of any node.

Output format :
Each level linked list is printed in new line (elements are separated by space).

Constraints:
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9

*/

/**********************************************************

        Following are the Binary Tree Node class structure and
        the Node class structure

        template <typename T>
        class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this->data = data;
                left = NULL;
                right = NULL;
        }
        };

        template <typename T>
        class Node {
                public:
        T data;
        Node<T> *next;
        Node(T data) {
                this->data=data;
                this->next=NULL;
        }
        };

***********************************************************/

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
  // Write your code here
  vector<Node<int> *> v;

  if (root == NULL) {
    v.push_back(NULL);

    return v;
  }

  queue<BinaryTreeNode<int> *> pn;

  pn.push(root);
  pn.push(NULL);

  Node<int> *head = NULL;
  Node<int> *tail = head;

  while (pn.size() != 0) {
    BinaryTreeNode<int> *front = pn.front();
    pn.pop();

    if (front == NULL) {
      tail->next = NULL;

      if (pn.size() == 0)
        break;

      pn.push(NULL);

      head = NULL;
      tail = NULL;

    }

    else {
      Node<int> *n = new Node<int>(front->data);
      if (head == NULL) {
        head = tail = n;
        v.push_back(head);
      } else {
        tail->next = n;
        tail = n;
      }

      if (front->left)
        pn.push(front->left);
      if (front->right)
        pn.push(front->right);
    }
  }
}