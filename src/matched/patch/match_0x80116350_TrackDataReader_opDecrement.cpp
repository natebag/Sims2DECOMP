/* TrackDataReader::operator--(void) - 0x80116350 - 20 bytes */
/* mr r11, r3; lwz r9, 4(r11); addi r9, r9, -1; stw r9, 4(r11); blr */

class ERSoundTrackData;

class TrackDataReader {
public:
    ERSoundTrackData* m_trackData;
    int m_index;

    TrackDataReader& operator--(void);
};

TrackDataReader& TrackDataReader::operator--(void) {
    --m_index;
    return *this;
}
