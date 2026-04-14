/* TrackDataReader::IsValid(void) const - 0x80116424 - 24 bytes */
/* lwz r0, 0(r3); li r3, 1; cmpwi r0, 0; bnelr; li r3, 0; blr */

class ERSoundTrackData;

class TrackDataReader {
public:
    ERSoundTrackData* m_trackData;
    int m_index;

    int IsValid(void) const;
};

int TrackDataReader::IsValid(void) const {
    return m_trackData != 0;
}
