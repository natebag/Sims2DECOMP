// 0x80138534 Room::SetOverheadLights(bool) (128B)
// Multi-gate state mutator: IsOutside check, equality skip, mutex flag, prev-state,
// then NaN-loose `!(<)` brightness gate before broadcasting GlobalDispatch(237, type).
// Interleaved store: m_field90 = newState happens before prev-state branch decision.

extern void GlobalDispatch(short, int);

class Room {
public:
    unsigned short m_field0;
    char pad1[0x7e];          // 0x02 .. 0x7f
    float m_field80;
    char pad2[0xc];           // 0x84 .. 0x8f
    int m_field90;
    int m_field94;
    char pad3[0x4];           // 0x98 .. 0x9b
    int m_field9c;

    int IsOutside();
    void SetOverheadLights(bool newState);
};

void Room::SetOverheadLights(bool newState) {
    if (IsOutside()) return;
    if (m_field90 == newState) return;
    if (m_field94 != 0) return;
    int prev = m_field9c;
    m_field90 = newState;
    if (prev != 0) return;
    if (!(m_field80 < 0.8f)) return;
    GlobalDispatch(237, m_field0);
}
