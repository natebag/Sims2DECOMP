/* ChangeHouseLoadHouse_DPA::DatasetPendingAddRefAsync() at 0x8009018C (24B) */

struct ChangeHouseLoadHouse_DPA {
    char m_pad[28];
    int m_field;
    int DatasetPendingAddRefAsync();
};

int ChangeHouseLoadHouse_DPA::DatasetPendingAddRefAsync() {
    if (m_field) return 1;
    return 0;
}
