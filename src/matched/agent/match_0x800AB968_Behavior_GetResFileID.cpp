// 0x800AB968 Behavior::GetResFileID (76b)

struct Behavior {
    int* field4;
};

extern int g_something;

int Behavior_GetResFileID(Behavior* this, short id) {
    // Bounds check: id - 256 <= 8744
    if ((unsigned short)(id - 256) > 8744) {
        return -1;
    }
    
    if (id <= 4095) {
        return g_something;
    }
    
    if (id <= 8191) {
        return this->field4[1];
    }
    
    if (id > 9000) {
        return -1;
    }
    
    return this->field4[2];
}
