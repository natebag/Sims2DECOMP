/* WorldMap getter at offset 0x80 - 0x80117EC4 - 8 bytes */

class WorldMap_80 {
public:
    char _pad[0x80];
    int m_field80;

    int GetField80(void);
};

int WorldMap_80::GetField80(void) {
    return m_field80;
}
