// 0x8035D214 ENCamera::SetKeys (52b)

extern void SetKeysImpl2(void*, int, int);

struct ENCamera {
    char pad[0x44];
    int m_keys;
};

void ENCamera_SetKeys(ENCamera* self, int keys) {
    self->m_keys = keys;
    SetKeysImpl2((char*)self + 0x48, keys, 0);
}
