// 0x8011A6E4 ActionQueue::Enqueue (48b)
void aq_insert(void*, void*, int);

void Enqueue_test(char* self, void* action) {
    int remaining = *(int*)(self + 684) - *(int*)(self + 680);
    aq_insert(self, action, remaining);
}
