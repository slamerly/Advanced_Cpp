#pragma once
enum Race
{
	Elf = 1<<0,
	Orc = 1<<1,
	Gobelin = 1<<2,
	Human = 1<<3,
	Dwarf = 1<<4,
	HalfElf = Human | Elf,
	HalfHuman = Human | Dwarf,
	HalfOrc = Human | Orc
};