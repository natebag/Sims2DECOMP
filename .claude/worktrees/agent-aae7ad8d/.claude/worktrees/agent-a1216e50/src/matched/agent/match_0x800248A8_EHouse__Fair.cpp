/* EHouse::Fair(void) at 0x800248A8 (76B) */

void SetIsRaining(int);

struct EHouse {
    char pad_00[0x30];
    int m_weather;

    void Fair(void);
    void WeatherChanging(void);
};

void EHouse::Fair(void) {
    if (m_weather != 0) {
        m_weather = 0;
        SetIsRaining(0);
        WeatherChanging();
    }
}
