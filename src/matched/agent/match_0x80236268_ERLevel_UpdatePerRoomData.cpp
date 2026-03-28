struct ERLevel {
    void UpdateFloorLighting(void);
    void UpdatePerRoomData(void);
};

void ERLevel::UpdatePerRoomData(void) {
    UpdateFloorLighting();
}
