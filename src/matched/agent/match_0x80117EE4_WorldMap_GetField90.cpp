/* WorldMap getter at offset 0x90 - 0x80117EE4 - 8 bytes */

class WorldMap_90 {
public:
    char _pad[0x90];
    int m_field90;

    int GetField90(void);
};

int WorldMap_90::GetField90(void) {
    return m_field90;
}
