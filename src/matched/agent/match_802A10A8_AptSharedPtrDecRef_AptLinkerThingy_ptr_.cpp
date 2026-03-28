struct AptLinkerThingy {
    int m_refCount;
};

int AptSharedPtrDecRef(AptLinkerThingy* ptr) {
    return --ptr->m_refCount;
}
