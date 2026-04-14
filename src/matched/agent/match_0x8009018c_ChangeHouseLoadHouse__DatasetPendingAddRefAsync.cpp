// 0x8009018c ChangeHouseLoadHouse::DatasetPendingAddRefAsync(void) (24B)

struct ChangeHouseLoadHouse {
    char pad[0x1C];
    int m_pending;
    int DatasetPendingAddRefAsync(void);
};

int ChangeHouseLoadHouse::DatasetPendingAddRefAsync(void) {
    return m_pending != 0;
}
