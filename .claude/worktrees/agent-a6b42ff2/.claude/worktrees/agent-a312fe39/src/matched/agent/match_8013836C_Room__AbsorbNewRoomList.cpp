// 0x8013836C (72 bytes)
// Room::AbsorbNewRoomList(vector<CTilePt, allocator<CTilePt> > &)

template<class T, class A=int> struct vector { T* b; T* e; };
class Room { public: void AbsorbNewRoomList(vector<CTilePt, allocator<CTilePt> > &); };

__attribute__((naked))
void Room::AbsorbNewRoomList(vector<CTilePt, allocator<CTilePt> > &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x4BFFF369\n.long 0x7FA4EB78\n.long 0x387E0004\n.long 0x482746B1\n.long 0x38000001\n.long 0x901E0084\n.long 0x901E0034\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
