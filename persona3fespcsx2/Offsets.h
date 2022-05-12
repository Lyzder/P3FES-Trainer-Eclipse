#include <Windows.h>

#pragma once
ref class COffsets
{
public:
	COffsets(void);
	
	//MC
	static LONG mc_level = 0x2083622A;
	static LONG mc_current_hp = 0x2083622C;
	static LONG mc_current_mp = 0x2083622E;
	static LONG mc_equipped_persona = 0x20836BA8;
	static LONG mc_mood = 0x2083626C;
	static LONG mc_academics = 0x20836260;
	static LONG mc_charm = 0x20836262;
	static LONG mc_courage = 0x20836264;
	static LONG mc_money = 0x2083A6DC;

	//Persona 1
	static LONG persona1_modifer = 0x20836BAE;
	static LONG persona1_level = 0x20836BB0;
	static LONG persona1_str = 0x20836BC8;
	static LONG persona1_mag = 0x20836BC9;
	static LONG persona1_en = 0x20836BCA;
	static LONG persona1_ag = 0x20836BCB;
	static LONG persona1_luc = 0x20836BCC;
	static LONG persona1_skill1 = 0x20836BB8;
	static LONG persona1_skill2 = 0x20836BBA;
	static LONG persona1_skill3 = 0x20836BBC;
	static LONG persona1_skill4 = 0x20836BBE;
	static LONG persona1_skill5 = 0x20836BC0;
	static LONG persona1_skill6 = 0x20836BC2;
	static LONG persona1_skill7 = 0x20836BC4;
	static LONG persona1_skill8 = 0x20836BC6;

	//Persona 2
	static LONG persona2_modifer = 0x20836BE2;
	static LONG persona2_level = 0x20836BE4;
	static LONG persona2_str = 0x20836BFC;
	static LONG persona2_mag = 0x20836BFD;
	static LONG persona2_en = 0x20836BFE;
	static LONG persona2_ag = 0x20836BFF;
	static LONG persona2_luc = 0x20836C00;
	static LONG persona2_skill1 = 0x20836BEC;
	static LONG persona2_skill2 = 0x20836BEE;
	static LONG persona2_skill3 = 0x20836BF0;
	static LONG persona2_skill4 = 0x20836BF2;
	static LONG persona2_skill5 = 0x20836BF4;
	static LONG persona2_skill6 = 0x20836BF6;
	static LONG persona2_skill7 = 0x20836BF8;
	static LONG persona2_skill8 = 0x20836BFA;

	//Persona 3
	static LONG persona3_modifer = 0x20836C16;
	static LONG persona3_level = 0x20836C18;
	static LONG persona3_str = 0x20836C31;
	static LONG persona3_mag = 0x20836C32;
	static LONG persona3_en = 0x20836C33;
	static LONG persona3_ag = 0x20836C34;
	static LONG persona3_luc = 0x20836C35;
	static LONG persona3_skill1 = 0x20836C20;
	static LONG persona3_skill2 = 0x20836C22;
	static LONG persona3_skill3 = 0x20836C24;
	static LONG persona3_skill4 = 0x20836C26;
	static LONG persona3_skill5 = 0x20836C28;
	static LONG persona3_skill6 = 0x20836C2A;
	static LONG persona3_skill7 = 0x20836C2C;
	static LONG persona3_skill8 = 0x20836C2E;

	//Persona 4
	static LONG persona4_modifer = 0x20836BAE;
	static LONG persona4_level = 0x20836BB0;
	static LONG persona4_str = 0x20836BC8;
	static LONG persona4_mag = 0x20836BC9;
	static LONG persona4_en = 0x20836BCA;
	static LONG persona4_ag = 0x20836BCB;
	static LONG persona4_luc = 0x20836BCC;
	static LONG persona4_skill1 = 0x20836BB8;
	static LONG persona4_skill2 = 0x20836BBA;
	static LONG persona4_skill3 = 0x20836BBC;
	static LONG persona4_skill4 = 0x20836BBE;
	static LONG persona4_skill5 = 0x20836BC0;
	static LONG persona4_skill6 = 0x20836BC2;
	static LONG persona4_skill7 = 0x20836BC4;
	static LONG persona4_skill8 = 0x20836BC6;

	//Persona 5
	static LONG persona5_modifer = 0x20836BAE;
	static LONG persona5_level = 0x20836BB0;
	static LONG persona5_str = 0x20836BC8;
	static LONG persona5_mag = 0x20836BC9;
	static LONG persona5_en = 0x20836BCA;
	static LONG persona5_ag = 0x20836BCB;
	static LONG persona5_luc = 0x20836BCC;
	static LONG persona5_skill1 = 0x20836BB8;
	static LONG persona5_skill2 = 0x20836BBA;
	static LONG persona5_skill3 = 0x20836BBC;
	static LONG persona5_skill4 = 0x20836BBE;
	static LONG persona5_skill5 = 0x20836BC0;
	static LONG persona5_skill6 = 0x20836BC2;
	static LONG persona5_skill7 = 0x20836BC4;
	static LONG persona5_skill8 = 0x20836BC6;

	//Persona 6
	static LONG persona6_modifer = 0x20836BAE;
	static LONG persona6_level = 0x20836BB0;
	static LONG persona6_str = 0x20836BC8;
	static LONG persona6_mag = 0x20836BC9;
	static LONG persona6_en = 0x20836BCA;
	static LONG persona6_ag = 0x20836BCB;
	static LONG persona6_luc = 0x20836BCC;
	static LONG persona6_skill1 = 0x20836BB8;
	static LONG persona6_skill2 = 0x20836BBA;
	static LONG persona6_skill3 = 0x20836BBC;
	static LONG persona6_skill4 = 0x20836BBE;
	static LONG persona6_skill5 = 0x20836BC0;
	static LONG persona6_skill6 = 0x20836BC2;
	static LONG persona6_skill7 = 0x20836BC4;
	static LONG persona6_skill8 = 0x20836BC6;

	//Persona 7
	static LONG persona7_modifer = 0x20836BAE;
	static LONG persona7_level = 0x20836BB0;
	static LONG persona7_str = 0x20836BC8;
	static LONG persona7_mag = 0x20836BC9;
	static LONG persona7_en = 0x20836BCA;
	static LONG persona7_ag = 0x20836BCB;
	static LONG persona7_luc = 0x20836BCC;
	static LONG persona7_skill1 = 0x20836BB8;
	static LONG persona7_skill2 = 0x20836BBA;
	static LONG persona7_skill3 = 0x20836BBC;
	static LONG persona7_skill4 = 0x20836BBE;
	static LONG persona7_skill5 = 0x20836BC0;
	static LONG persona7_skill6 = 0x20836BC2;
	static LONG persona7_skill7 = 0x20836BC4;
	static LONG persona7_skill8 = 0x20836BC6;

	//Persona 8
	static LONG persona8_modifer = 0x20836BAE;
	static LONG persona8_level = 0x20836BB0;
	static LONG persona8_str = 0x20836BC8;
	static LONG persona8_mag = 0x20836BC9;
	static LONG persona8_en = 0x20836BCA;
	static LONG persona8_ag = 0x20836BCB;
	static LONG persona8_luc = 0x20836BCC;
	static LONG persona8_skill1 = 0x20836BB8;
	static LONG persona8_skill2 = 0x20836BBA;
	static LONG persona8_skill3 = 0x20836BBC;
	static LONG persona8_skill4 = 0x20836BBE;
	static LONG persona8_skill5 = 0x20836BC0;
	static LONG persona8_skill6 = 0x20836BC2;
	static LONG persona8_skill7 = 0x20836BC4;
	static LONG persona8_skill8 = 0x20836BC6;

	//Persona 9
	static LONG persona9_modifer = 0x20836BAE;
	static LONG persona9_level = 0x20836BB0;
	static LONG persona9_str = 0x20836BC8;
	static LONG persona9_mag = 0x20836BC9;
	static LONG persona9_en = 0x20836BCA;
	static LONG persona9_ag = 0x20836BCB;
	static LONG persona9_luc = 0x20836BCC;
	static LONG persona9_magic1 = 0x20836BB8;
	static LONG persona9_magic2 = 0x20836BBA;
	static LONG persona9_magic3 = 0x20836BBC;
	static LONG persona9_magic4 = 0x20836BBE;
	static LONG persona9_magic5 = 0x20836BC0;
	static LONG persona9_magic6 = 0x20836BC2;
	static LONG persona9_magic7 = 0x20836BC4;
	static LONG persona9_magic8 = 0x20836BC6;

	//Persona 10
	static LONG persona10_modifer = 0x20836BAE;
	static LONG persona10_level = 0x20836BB0;
	static LONG persona10_str = 0x20836BC8;
	static LONG persona10_mag = 0x20836BC9;
	static LONG persona10_en = 0x20836BCA;
	static LONG persona10_ag = 0x20836BCB;
	static LONG persona10_luc = 0x20836BCC;
	static LONG persona10_magic1 = 0x20836BB8;
	static LONG persona10_magic2 = 0x20836BBA;
	static LONG persona10_magic3 = 0x20836BBC;
	static LONG persona10_magic4 = 0x20836BBE;
	static LONG persona10_magic5 = 0x20836BC0;
	static LONG persona10_magic6 = 0x20836BC2;
	static LONG persona10_magic7 = 0x20836BC4;
	static LONG persona10_magic8 = 0x20836BC6;

	//Persona 11
	static LONG persona11_modifer = 0x20836BAE;
	static LONG persona11_level = 0x20836BB0;
	static LONG persona11_str = 0x20836BC8;
	static LONG persona11_mag = 0x20836BC9;
	static LONG persona11_en = 0x20836BCA;
	static LONG persona11_ag = 0x20836BCB;
	static LONG persona11_luc = 0x20836BCC;
	static LONG persona11_magic1 = 0x20836BB8;
	static LONG persona11_magic2 = 0x20836BBA;
	static LONG persona11_magic3 = 0x20836BBC;
	static LONG persona11_magic4 = 0x20836BBE;
	static LONG persona11_magic5 = 0x20836BC0;
	static LONG persona11_magic6 = 0x20836BC2;
	static LONG persona11_magic7 = 0x20836BC4;
	static LONG persona11_magic8 = 0x20836BC6;

	//Persona 12
	static LONG persona12_modifer = 0x20836BAE;
	static LONG persona12_level = 0x20836BB0;
	static LONG persona12_str = 0x20836BC8;
	static LONG persona12_mag = 0x20836BC9;
	static LONG persona12_en = 0x20836BCA;
	static LONG persona12_ag = 0x20836BCB;
	static LONG persona12_luc = 0x20836BCC;
	static LONG persona12_magic1 = 0x20836BB8;
	static LONG persona12_magic2 = 0x20836BBA;
	static LONG persona12_magic3 = 0x20836BBC;
	static LONG persona12_magic4 = 0x20836BBE;
	static LONG persona12_magic5 = 0x20836BC0;
	static LONG persona12_magic6 = 0x20836BC2;
	static LONG persona12_magic7 = 0x20836BC4;
	static LONG persona12_magic8 = 0x20836BC6;
};

