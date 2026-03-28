/* EMsgQueue::Empty() at 0x8035C9CC (64 bytes) */

struct EMsgQueue {
    int Remove(void* p1, void* p2);
    void Empty();
};

void EMsgQueue::Empty()
{
    while (Remove(0, 0) != 0) {
    }
}
