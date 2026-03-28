struct AptWord2 {
    char pad[0x14];
    int m_lineFeedCount;
};

void AptWord_AddLineFeed(AptWord2* self) {
    self->m_lineFeedCount = self->m_lineFeedCount + 1;
}
