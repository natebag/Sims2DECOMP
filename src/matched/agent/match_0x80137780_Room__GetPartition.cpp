// 0x80137780 Room::GetPartition() (88B)

struct PenaltyRect {
    int a;
    int b;
    int c;
    int d;
    int e;  // 20 bytes
};

template<class T>
class vector {
public:
    T* m_begin;
    T* m_end;
    T* m_storage_end;
    int empty() const { return (int)(m_end - m_begin) == 0; }
};

extern void BuildRoomPartition(unsigned short id, vector<PenaltyRect>* v);

class Room {
public:
    unsigned short m_0;
    char pad[0x22];
    vector<PenaltyRect> m_24;
    vector<PenaltyRect>* GetPartition();
};

vector<PenaltyRect>* Room::GetPartition() {
    if (m_24.empty()) {
        BuildRoomPartition(m_0, &m_24);
    }
    return &m_24;
}
