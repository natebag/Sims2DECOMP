/* ECheats::ECheats(void) at 0x8001ECAC (72B) */

void* memset(void*, int, unsigned int);

struct ECheats {
    char pad_00[0x104];
    int m_field104;

    ECheats();
    void EmptyLookupList(void);
};

ECheats::ECheats() {
    memset(this, 0, 256);
    EmptyLookupList();
    m_field104 = 0;
}
