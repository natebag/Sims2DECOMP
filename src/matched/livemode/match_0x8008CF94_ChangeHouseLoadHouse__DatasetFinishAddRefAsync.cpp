/* ChangeHouseLoadHouse::DatasetFinishAddRefAsync(void) - 0x8008CF94 (64B) */

class EResourceManager {
public:
    int DelRefAsync(unsigned int handle);
};

extern char g_ResMgrData[100];

class ChangeHouseLoadHouse {
public:
    char pad[28];
    unsigned int m_handle;

    void DatasetFinishAddRefAsync(void);
};

void ChangeHouseLoadHouse::DatasetFinishAddRefAsync(void) {
    ((EResourceManager*)g_ResMgrData)->DelRefAsync(m_handle);
    m_handle = 0;
}
