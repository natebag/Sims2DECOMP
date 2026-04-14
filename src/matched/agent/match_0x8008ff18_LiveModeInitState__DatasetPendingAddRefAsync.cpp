// 0x8008ff18 LiveModeInitState::DatasetPendingAddRefAsync(void) (24B)

struct LiveModeInitState {
    char pad[0x1C];
    int m_pending;
    int DatasetPendingAddRefAsync(void);
};

int LiveModeInitState::DatasetPendingAddRefAsync(void) {
    return m_pending != 0;
}
