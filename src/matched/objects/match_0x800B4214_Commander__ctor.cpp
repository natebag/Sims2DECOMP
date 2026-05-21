// 0x800B4214 (60B) Commander::Commander(void)

extern char Commander_vt[];
extern "C" char* Commander__sList;
extern "C" int Commander__sId;

class Commander {
public:
    Commander();
};

Commander::Commander() {
    char* prev_head = Commander__sList;
    *(void**)((char*)this + 12) = (void*)Commander_vt;
    *(int*)((char*)this + 4) = 0;
    int* counter_ptr = &Commander__sId;
    *(char**)((char*)this + 0) = prev_head;
    int id = *counter_ptr;
    *(int*)((char*)this + 8) = id;
    id++;
    Commander__sList = (char*)this;
    *counter_ptr = id;
}
