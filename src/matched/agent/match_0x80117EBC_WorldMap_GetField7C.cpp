/* WorldMap getter at offset 0x7C - 0x80117EBC - 8 bytes */

class WorldMap_7C {
public:
    char _pad[0x7C];
    int m_field7C;

    int GetField7C(void);
};

int WorldMap_7C::GetField7C(void) {
    return m_field7C;
}
