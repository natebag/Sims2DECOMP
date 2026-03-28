struct AptWord {
    char pad[0x18];
    int m_spaceCount;
};

void AptWord_AddSpace(AptWord* self) {
    self->m_spaceCount = self->m_spaceCount + 1;
}
