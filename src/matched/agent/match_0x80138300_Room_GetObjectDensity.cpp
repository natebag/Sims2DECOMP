// 0x80138300 Room::GetObjectDensity() (88B)
// (float)m_field54 / (float)m_field4C — int-to-double cookie idiom for both ops, divs.

class Room {
public:
    char pad[0x4C];
    int m_field4C;
    char pad2[0x4];
    int m_field54;
    float GetObjectDensity();
};

float Room::GetObjectDensity() {
    return (float)m_field54 / (float)m_field4C;
}
