struct AptFile {
    int m_refCount;
};

int AptSharedPtrIncRef(AptFile* ptr) {
    return ++ptr->m_refCount;
}
