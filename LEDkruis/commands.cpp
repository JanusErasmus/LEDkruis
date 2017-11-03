#include <terminal.h>

extern const dbg_entry outputEntry;
extern const dbg_entry analogEntry;
extern const dbg_entry thEntry;
extern const dbg_entry nextEntry;

const dbg_entry* dbg_entries[] =
{
		&helpEntry,
		&outputEntry,
		&analogEntry,
		&thEntry,
        &nextEntry,
		0
};
