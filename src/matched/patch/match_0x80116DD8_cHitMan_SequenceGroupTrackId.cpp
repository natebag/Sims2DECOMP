/* cHitMan::SequenceGroupTrackId(int) - 0x80116DD8 - 20 bytes */
/* addi r4, r4, 10; addi r3, r3, 84; rlwinm r4, r4, 2, 0, 29; lwzx r3, r3, r4; blr */
/* Loads from an int array at this+84, index is (param+10) */

class cHitMan_SGT {
public:
    char _pad[0x54];
    int m_trackIds[64];

    int SequenceGroupTrackId(int idx);
};

int cHitMan_SGT::SequenceGroupTrackId(int idx) {
    return m_trackIds[idx + 10];
}
