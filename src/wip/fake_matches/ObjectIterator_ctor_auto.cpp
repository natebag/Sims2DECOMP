// 0x800F2A6C ObjectIterator::ObjectIterator (20b)
// FLAGS: -fno-schedule-insns

struct cXObject;

struct ObjectIterator {
    cXObject* m_obj;
    int field_4;
    int field_8;
    ObjectIterator(cXObject* p2, int p3);
};

ObjectIterator::ObjectIterator(cXObject* p2, int p3) {
    field_4 = p3;
    field_8 = (int)p2;
    m_obj = p2;
}
