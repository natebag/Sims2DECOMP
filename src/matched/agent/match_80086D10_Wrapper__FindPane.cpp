struct Wrapper {
    char pad[140]; void** m_begin; void** m_end;
    void* FindPane(void* target);
};
void* Wrapper::FindPane(void* target) {
    void** it = m_begin;
    while (it != m_end) {
        if (*it == target) return *it;
        it++;
    }
    return 0;
}
