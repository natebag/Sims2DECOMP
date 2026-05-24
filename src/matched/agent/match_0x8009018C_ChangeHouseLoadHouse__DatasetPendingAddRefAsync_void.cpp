// 0x8009018C ChangeHouseLoadHouse::DatasetPendingAddRefAsync(void) (24 B)
struct ChangeHouseLoadHouse {
    char _pad[0x1c];
    int m_field_0x1c;
    int DatasetPendingAddRefAsync();
};
int ChangeHouseLoadHouse::DatasetPendingAddRefAsync() {
    return m_field_0x1c != 0;
}
