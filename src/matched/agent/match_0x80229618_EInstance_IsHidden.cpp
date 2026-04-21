// 0x80229618 (60B) EInstance::IsHidden(void)

typedef int (*HiddenFn)(void*);

struct EInstance {
    char pad[44];
    void* m_this;
    HiddenFn m_fn;
    int IsHidden();
};

int EInstance::IsHidden() {
    if (m_fn != 0) return m_fn(m_this);
    return 0;
}
