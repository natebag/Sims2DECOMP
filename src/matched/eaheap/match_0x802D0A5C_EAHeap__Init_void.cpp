/* EAHeap::Init(void*, unsigned int) - 0x802D0A5C (72 bytes) */

struct EAHeap {
    int Init6(void *p, unsigned int size, int a, int b, int c, int d);
    int Init(void *p, unsigned int size);
};

int EAHeap::Init(void *p, unsigned int size) {
    if (p != 0 && size != 0)
        return Init6(p, size, 0, 0, 0, 0);
    return 1;
}
