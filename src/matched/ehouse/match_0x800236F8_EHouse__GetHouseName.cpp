struct EHouse {
    char pad[0x54];
    int m_houseId;
};

void* GetHouseNameText(int id);

void* EHouse_GetHouseName(EHouse* self) {
    return GetHouseNameText(self->m_houseId);
}
