#include <terminal.h>

extern const dbg_entry outputEntry;
extern const dbg_entry analogEntry;
extern const dbg_entry thEntry;

const dbg_entry* dbg_entries[] =
{
		&helpEntry,
		&outputEntry,
		&analogEntry,
		&thEntry,
		0
};
