/* ObjectDataBehaviorConstants::SetValue(int, short) - 0x80159C44 - 16 bytes */
/* lwz r9, 0x14(r3); rlwinm r4, r4, 1, 0, 30; sthx r5, r4, r9; blr */

class ObjectDataBehaviorConstants {
public:
    char _pad[0x14];
    short* m_values;

    void SetValue(int index, short value);
};

void ObjectDataBehaviorConstants::SetValue(int index, short value) {
    m_values[index] = value;
}
