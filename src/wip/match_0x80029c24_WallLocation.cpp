// 0x80029c24 WallLocation(unsigned int, bool, short&, short&) (104B)
// FLAGS: -fno-schedule-insns

struct RoomEntry {
    short field_0;
    short field_2;
};

struct RoomManager {
    RoomEntry* GetRoom(unsigned short id);
};

extern RoomManager* RoomManager_sRoomMgr;

void WallLocation(unsigned int id, bool flag, short& out1, short& out2) {
    out2 = (short)id;
    out1 = (short)id;
    RoomManager* mgr = RoomManager_sRoomMgr;
    if (mgr) {
        unsigned short sid = (unsigned short)id;
        if (sid <= 0xFFFA) {
            RoomEntry* room = mgr->GetRoom(sid);
            if (room) {
                out2 = room->field_2;
            }
        }
    }
}
