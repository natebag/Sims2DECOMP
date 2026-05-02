// 0x80024828 (128B) EHouse::WeatherChanging(void)
// Double virtual call with mulli arithmetic.

struct IWeatherGlobal {
    virtual int V0(int);
    virtual int V1(int);
    virtual int V2(int);
    virtual int V3(int);
    virtual int V4(int);
    virtual int GetWeatherValue(int type);
};

extern IWeatherGlobal* g_pWeatherGlobal;

struct EHouse {
    char pad[0x34];
    int m_weatherValue;
    int m_weatherFlags;
    
    void WeatherChanging();
};

void EHouse::WeatherChanging() {
    int a = g_pWeatherGlobal->GetWeatherValue(0);
    int b = g_pWeatherGlobal->GetWeatherValue(5);
    m_weatherFlags = 1;
    m_weatherValue = a * 60 + b;
}
