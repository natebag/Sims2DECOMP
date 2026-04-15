/* LiveModeInitState::DatasetFinishAddRefAsync(void) - 0x8008CA18 (64B) */

class EResourceManager {
public:
    int DelRefAsync(unsigned int handle);
};

extern char g_ResMgrData[100];

class LiveModeInitState {
public:
    char pad[28];
    unsigned int m_handle;

    void DatasetFinishAddRefAsync(void);
};

void LiveModeInitState::DatasetFinishAddRefAsync(void) {
    ((EResourceManager*)g_ResMgrData)->DelRefAsync(m_handle);
    m_handle = 0;
}
