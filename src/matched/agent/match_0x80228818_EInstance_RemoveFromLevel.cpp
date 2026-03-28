struct EInstance_RL {
    char pad[4];
    void* m_level;
};

extern void ERLevel_RemoveInstance(void* level, void* inst);

void EInstance_RemoveFromLevel(EInstance_RL* self) {
    if (self->m_level != 0) {
        ERLevel_RemoveInstance(self->m_level, self);
    }
}
