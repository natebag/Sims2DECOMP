/* EHouse::Rain(void) at 0x800248F4 (76B) */

void SetIsRaining(int);

struct EHouse {
    char pad_00[0x30];
    int m_weather;

    void Rain(void);
    void WeatherChanging(void);
};

void EHouse::Rain(void) {
    if (m_weather != 1) {
        m_weather = 1;
        SetIsRaining(1);
        WeatherChanging();
    }
}
