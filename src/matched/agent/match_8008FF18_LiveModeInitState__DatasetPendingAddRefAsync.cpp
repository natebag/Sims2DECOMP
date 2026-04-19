/* LiveModeInitState_DPA::DatasetPendingAddRefAsync() at 0x8008FF18 (24B) */

struct LiveModeInitState_DPA {
    char m_pad[28];
    int m_field;
    int DatasetPendingAddRefAsync();
};

int LiveModeInitState_DPA::DatasetPendingAddRefAsync() {
    if (m_field) return 1;
    return 0;
}
