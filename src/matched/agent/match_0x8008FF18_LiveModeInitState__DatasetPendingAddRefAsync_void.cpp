// 0x8008FF18 LiveModeInitState::DatasetPendingAddRefAsync(void) (24 B)
struct LiveModeInitState {
    char _pad[0x1c];
    int m_field_0x1c;
    int DatasetPendingAddRefAsync();
};
int LiveModeInitState::DatasetPendingAddRefAsync() {
    return m_field_0x1c != 0;
}
