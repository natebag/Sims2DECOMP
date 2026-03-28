/* TrackDataReader::operator+=(int) - 0x80116364 - 20 bytes */
/* mr r9, r3; lwz r0, 4(r9); add r0, r0, r4; stw r0, 4(r9); blr */

class ERSoundTrackData;

class TrackDataReader {
public:
    ERSoundTrackData* m_trackData;
    int m_index;

    TrackDataReader& operator+=(int);
};

TrackDataReader& TrackDataReader::operator+=(int n) {
    m_index += n;
    return *this;
}
