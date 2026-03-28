struct LightData {
    char data[0x20];
    void Clear(void);
};

struct RoomData {
    LightData ambient;
    LightData directional;
    int m_pad40;
    int m_field44;
    int m_field48;
    int m_field4C;
    int m_field50;

    void Flush(void);
};

void RoomData::Flush(void) {
    directional.Clear();
    ambient.Clear();
    m_field48 = 0;
    m_field50 = 256;
    m_field44 = 0;
    m_field4C = 256;
}
