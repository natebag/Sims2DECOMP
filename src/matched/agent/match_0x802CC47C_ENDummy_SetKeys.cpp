// 0x802CC47C ENDummy::SetKeys (52b)

extern void SetKeysImpl(void*, int, int);

struct ENDummy {
    char pad[0x44];
    int m_keys;
};

void ENDummy_SetKeys(ENDummy* self, int keys) {
    self->m_keys = keys;
    SetKeysImpl((char*)self + 0x48, keys, 0);
}
