//
// Atari1050Duplicator class
// (c) 2018 Eric BACHER
//

#ifndef ATARI1050Duplicator_HPP
#define ATARI1050Duplicator_HPP 1

#include "AtariDrive.hpp"

#define A1050_FREQUENCY 1000000L

#define A1050_TICKS_BETWEEN_BITS 52
#define A1050_TICKS_AFTER_START_BITS 20

// This class defines a common interface for all the computer models.
class Atari1050Duplicator : public AtariDrive {

protected:

    // 8192 bytes on Duplicator board
    Ram                     *m_ramDuplicator;
    Ram                     *m_unmapped;
    int                     m_bankNumber;

	// find the chip targeted with a given address
	virtual Chip			*FindChip(unsigned short addr, unsigned short *chipAddr);
	virtual char			*GetAddressLabel(unsigned short addr);
    virtual void			Dump(char *folder, int sequenceNumber);

public:

	// constructors and destructor
                            Atari1050Duplicator(Rom *rom, eHARDWARE eHardware, int rpm);
    virtual					~Atari1050Duplicator();
};

#endif
