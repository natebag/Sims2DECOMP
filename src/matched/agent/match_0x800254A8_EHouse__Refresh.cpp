extern char gHouseRefreshData[];

void RefreshImpl(char* data);

void EHouse_Refresh() {
    RefreshImpl(gHouseRefreshData);
}
