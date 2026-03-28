/* ObjectDataBehaviorConstants::GetValue(int) const - 0x8015A6F4 - 16 bytes */
/* lwz r9, 0x14(r3); rlwinm r4, r4, 1, 0, 30; lhax r3, r4, r9; blr */

class ObjectDataBehaviorConstants {
public:
    char _pad[0x14];
    short* m_values;

    short GetValue(int index) const;
};

short ObjectDataBehaviorConstants::GetValue(int index) const {
    return m_values[index];
}
