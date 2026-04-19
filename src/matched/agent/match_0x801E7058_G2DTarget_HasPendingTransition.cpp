// 0x801E7058 (32B) G2DTarget::HasPendingTransition(void)
// Returns true unless state is 0 or 3. Leaf.

class G2DTarget {
public:
    char pad_000[0x134];
    int m_state;
    bool HasPendingTransition(void);
};

bool G2DTarget::HasPendingTransition(void) {
    int s = m_state;
    return s && (s != 3);
}
