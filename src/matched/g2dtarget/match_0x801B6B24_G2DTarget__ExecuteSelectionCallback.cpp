// 0x801B6B24 G2DTarget::ExecuteSelectionCallback(int) (68B)

class CB {
public:
    char pad[12];
    void* m_fn;
};

class G2DTarget {
public:
    char pad[0x110];
    CB* m_callback;
    void ExecuteSelectionCallback(int);
};

void G2DTarget::ExecuteSelectionCallback(int) {
    CB* cb = m_callback;
    if (cb == 0) return;
    m_callback = 0;
    ((void(*)(CB*))cb->m_fn)(cb);
}
