#include <iostream>
#include <vector>

struct QueueNode {
  QueueNode *next;
  int value;
};

struct Queue {
  QueueNode *head;
  int len;
};

void queue_init(Queue &queue) {
  queue.head = nullptr;
  queue.len = 0;
}

void queue_init(Queue &queue, int array[], int array_len) {
  QueueNode **node_iter = &queue.head;
  for (int i = 0; i < array_len; i += 1) {
    *node_iter = new QueueNode{nullptr, array[i]};
    node_iter = &(*node_iter)->next;
  }
  queue.len = array_len;
}

void enqueue(Queue &queue, int value) {
  QueueNode **node_iter = &queue.head;
  for (int i = 0; i < queue.len; i += 1) {
    node_iter = &(**node_iter).next;
  }
  *node_iter = new QueueNode{nullptr, value};
  queue.len += 1;
}

int dequeue(Queue &queue) {
  int head_value = queue.head->value;
  QueueNode *head = queue.head;
  queue.head = queue.head->next;
  delete head;
  queue.len -= 1;
  return head_value;
}

int main() {
  Queue queue;
  queue_init(queue);

  for (int i = 0; i < 4; i += 1) {
    enqueue(queue, i);
  }

  dequeue(queue);
  dequeue(queue);

  std::cout << queue.head->value << std::endl;

  QueueNode **node_iter = &queue.head;
  int queue_len = queue.len;

  for (int i = 0; i < queue_len; i += 1) {
    std::cout << (**node_iter).value << " ";
    node_iter = &(**node_iter).next;
  }
  std::cout << std::endl;

  return 0;
}
