struct AptLinkerThingy {
    int m_refCount;
};

int AptSharedPtrIncRef(AptLinkerThingy* ptr) {
    return ++ptr->m_refCount;
}
