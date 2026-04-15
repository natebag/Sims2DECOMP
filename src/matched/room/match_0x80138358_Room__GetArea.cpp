/* Room::GetArea(void) - 0x80138358 (20 bytes) */
class Room {
public:
    char pad[76];
    int m_val;
    int GetArea(void);
};
int Room::GetArea(void) {
    return m_val / 2;
}
