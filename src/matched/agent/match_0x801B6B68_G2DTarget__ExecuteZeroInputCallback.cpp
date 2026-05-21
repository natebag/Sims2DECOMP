// 0x801B6B68 G2DTarget::ExecuteZeroInputCallback() (68B) — twin of ExecuteSelectionCallback, offset 0x114

class CB {
public:
    char pad[12];
    void* m_fn;
};

class G2DTarget {
public:
    char pad[0x114];
    CB* m_callback;
    void ExecuteZeroInputCallback();
};

void G2DTarget::ExecuteZeroInputCallback() {
    CB* cb = m_callback;
    if (cb == 0) return;
    m_callback = 0;
    ((void(*)(CB*))cb->m_fn)(cb);
}
