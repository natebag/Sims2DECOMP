struct AptFile {
    int m_refCount;
};

int AptSharedPtrDecRef(AptFile* ptr) {
    return --ptr->m_refCount;
}
