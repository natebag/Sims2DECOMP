// 0x800756BC SimsMemCardWrap::GetSpaceRequiredForSave (32b)

extern int GetTotalSaveGameSize_void();

int SimsMemCardWrap_GetSpaceRequiredForSave() {
    return GetTotalSaveGameSize_void();
}
