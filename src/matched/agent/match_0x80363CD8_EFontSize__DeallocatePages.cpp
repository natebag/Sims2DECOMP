struct EFontSize {
    char _pad[0x20];
    char m_sub;
    void DeallocatePages();
};

void Impl_80363CD8(void*);

void EFontSize::DeallocatePages() {
    Impl_80363CD8(&m_sub);
}
