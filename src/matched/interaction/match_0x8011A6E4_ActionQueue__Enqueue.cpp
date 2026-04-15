/* ActionQueue::Enqueue(Interaction&) - 0x8011A6E4 (48 bytes) */
struct Interaction;
struct ActionQueue {
    char pad0[680];
    char* m_begin;   // +680
    char* m_end;     // +684

    unsigned int Insert(Interaction& inter, unsigned int pos);
    void Enqueue(Interaction& inter);
};

void ActionQueue::Enqueue(Interaction& inter) {
    unsigned int pos = (unsigned int)(m_end - m_begin);
    Insert(inter, pos);
}
