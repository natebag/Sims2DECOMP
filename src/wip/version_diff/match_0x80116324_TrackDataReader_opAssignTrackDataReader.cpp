/* TrackDataReader::operator=(TrackDataReader &) - 0x80116324 - 24 bytes */
/* lwz r11, 0(r4); mr r9, r3; stw r11, 0(r9); lwz r0, 4(r4); stw r0, 4(r9); blr */

class ERSoundTrackData;

class TrackDataReader {
public:
    ERSoundTrackData* m_trackData;
    int m_index;

    TrackDataReader& operator=(TrackDataReader &);
};

TrackDataReader& TrackDataReader::operator=(TrackDataReader &other) {
    m_trackData = other.m_trackData;
    m_index = other.m_index;
    return *this;
}
