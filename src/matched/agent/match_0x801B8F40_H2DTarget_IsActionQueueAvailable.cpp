// 0x801B8F40 (76B) H2DTarget::IsActionQueueAvailable(int) const
class ACTTarget {
public:
    int IsActionQueueAvailable(int) const;
};

struct H2DTarget {
    char pad[180];
    ACTTarget* m_queues[2];
    int IsActionQueueAvailable(int idx) const;
};

int H2DTarget::IsActionQueueAvailable(int idx) const {
    if ((unsigned int)idx <= 1) {
        ACTTarget* q = m_queues[idx];
        if (q == 0) return 0;
        return q->IsActionQueueAvailable(idx);
    }
    return 0;
}
