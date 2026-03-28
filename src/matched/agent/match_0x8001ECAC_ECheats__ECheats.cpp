void MemSet(void* dst, int val, int size);
void ECheatsReset(void* self);

struct ECheats {
    char pad[0x104];
    int m_f104;

    ECheats();
};

ECheats::ECheats() {
    MemSet(this, 0, 256);
    ECheatsReset(this);
    m_f104 = 0;
}
