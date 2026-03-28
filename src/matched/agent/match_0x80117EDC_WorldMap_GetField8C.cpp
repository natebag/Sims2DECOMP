/* WorldMap getter at offset 0x8C - 0x80117EDC - 8 bytes */

class WorldMap_8C {
public:
    char _pad[0x8C];
    int m_field8C;

    int GetField8C(void);
};

int WorldMap_8C::GetField8C(void) {
    return m_field8C;
}
