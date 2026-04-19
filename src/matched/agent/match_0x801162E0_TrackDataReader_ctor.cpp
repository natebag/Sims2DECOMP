// 0x801162E0 (20B) TrackDataReader::ctor — 8B zero-init POD
// volatile pointer forces mr r9,r3 save + stw order.

class TrackDataReader {
public:
    int m_field_0;
    int m_field_4;
    TrackDataReader(void);
};

TrackDataReader::TrackDataReader(void) {
    volatile int* p = (volatile int*)this;
    p[1] = 0;
    p[0] = 0;
}
