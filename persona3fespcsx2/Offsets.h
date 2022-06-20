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
	static LONG persona4_modifer = 0x20836C4A;
	static LONG persona4_level = 0x20836C4C;
	static LONG persona4_str = 0x20836C65;
	static LONG persona4_mag = 0x20836C66;
	static LONG persona4_en = 0x20836C67;
	static LONG persona4_ag = 0x20836C68;
	static LONG persona4_luc = 0x20836C69;
	static LONG persona4_skill1 = 0x20836C54;
	static LONG persona4_skill2 = 0x20836C56;
	static LONG persona4_skill3 = 0x20836C58;
	static LONG persona4_skill4 = 0x20836C5A;
	static LONG persona4_skill5 = 0x20836C5C;
	static LONG persona4_skill6 = 0x20836C5E;
	static LONG persona4_skill7 = 0x20836C60;
	static LONG persona4_skill8 = 0x20836C62;

	//Persona 5
	static LONG persona5_modifer = 0x20836C7E;
	static LONG persona5_level = 0x20836C80;
	static LONG persona5_str = 0x20836C99;
	static LONG persona5_mag = 0x20836C9A;
	static LONG persona5_en = 0x20836C9B;
	static LONG persona5_ag = 0x20836C9C;
	static LONG persona5_luc = 0x20836C9D;
	static LONG persona5_skill1 = 0x20836C88;
	static LONG persona5_skill2 = 0x20836C8A;
	static LONG persona5_skill3 = 0x20836C8C;
	static LONG persona5_skill4 = 0x20836C8E;
	static LONG persona5_skill5 = 0x20836C90;
	static LONG persona5_skill6 = 0x20836C92;
	static LONG persona5_skill7 = 0x20836C94;
	static LONG persona5_skill8 = 0x20836C96;

	//Persona 6
	static LONG persona6_modifer = 0x20836CB2;
	static LONG persona6_level = 0x20836CB4;
	static LONG persona6_str = 0x20836CCD;
	static LONG persona6_mag = 0x20836CCE;
	static LONG persona6_en = 0x20836CCF;
	static LONG persona6_ag = 0x20836CD0;
	static LONG persona6_luc = 0x20836CD1;
	static LONG persona6_skill1 = 0x20836CBC;
	static LONG persona6_skill2 = 0x20836CBE;
	static LONG persona6_skill3 = 0x20836CC0;
	static LONG persona6_skill4 = 0x20836CC2;
	static LONG persona6_skill5 = 0x20836CC4;
	static LONG persona6_skill6 = 0x20836CC6;
	static LONG persona6_skill7 = 0x20836CC8;
	static LONG persona6_skill8 = 0x20836CCA;

	//Persona 7
	static LONG persona7_modifer = 0x20836CE6;
	static LONG persona7_level = 0x20836CE8;
	static LONG persona7_str = 0x20836D01;
	static LONG persona7_mag = 0x20836D02;
	static LONG persona7_en = 0x20836D03;
	static LONG persona7_ag = 0x20836D04;
	static LONG persona7_luc = 0x20836D05;
	static LONG persona7_skill1 = 0x20836CF0;
	static LONG persona7_skill2 = 0x20836CF2;
	static LONG persona7_skill3 = 0x20836CF4;
	static LONG persona7_skill4 = 0x20836CF6;
	static LONG persona7_skill5 = 0x20836CF8;
	static LONG persona7_skill6 = 0x20836CFA;
	static LONG persona7_skill7 = 0x20836CFC;
	static LONG persona7_skill8 = 0x20836CFE;

	//Persona 8
	static LONG persona8_modifer = 0x20836D1A;
	static LONG persona8_level = 0x20836D1C;
	static LONG persona8_str = 0x20836D35;
	static LONG persona8_mag = 0x20836D36;
	static LONG persona8_en = 0x20836D37;
	static LONG persona8_ag = 0x20836D38;
	static LONG persona8_luc = 0x20836D39;
	static LONG persona8_skill1 = 0x20836D24;
	static LONG persona8_skill2 = 0x20836D26;
	static LONG persona8_skill3 = 0x20836D28;
	static LONG persona8_skill4 = 0x20836D2A;
	static LONG persona8_skill5 = 0x20836D2C;
	static LONG persona8_skill6 = 0x20836D2E;
	static LONG persona8_skill7 = 0x20836D30;
	static LONG persona8_skill8 = 0x20836D32;

	//Persona 9
	static LONG persona9_modifer = 0x20836D4E;
	static LONG persona9_level = 0x20836D50;
	static LONG persona9_str = 0x20836D69;
	static LONG persona9_mag = 0x20836D6A;
	static LONG persona9_en = 0x20836D6B;
	static LONG persona9_ag = 0x20836D6C;
	static LONG persona9_luc = 0x20836D6D;
	static LONG persona9_skill1 = 0x20836D58;
	static LONG persona9_skill2 = 0x20836D5A;
	static LONG persona9_skill3 = 0x20836D5C;
	static LONG persona9_skill4 = 0x20836D5E;
	static LONG persona9_skill5 = 0x20836D60;
	static LONG persona9_skill6 = 0x20836D62;
	static LONG persona9_skill7 = 0x20836D64;
	static LONG persona9_skill8 = 0x20836D66;

	//Persona 10
	static LONG persona10_modifer = 0x20836D82;
	static LONG persona10_level = 0x20836D84;
	static LONG persona10_str = 0x20836D9D;
	static LONG persona10_mag = 0x20836D9E;
	static LONG persona10_en = 0x20836D9F;
	static LONG persona10_ag = 0x20836DA0;
	static LONG persona10_luc = 0x20836DA1;
	static LONG persona10_skill1 = 0x20836D8C;
	static LONG persona10_skill2 = 0x20836D8E;
	static LONG persona10_skill3 = 0x20836D90;
	static LONG persona10_skill4 = 0x20836D92;
	static LONG persona10_skill5 = 0x20836D94;
	static LONG persona10_skill6 = 0x20836D96;
	static LONG persona10_skill7 = 0x20836D98;
	static LONG persona10_skill8 = 0x20836D9A;

	//Persona 11
	static LONG persona11_modifer = 0x20836DB6;
	static LONG persona11_level = 0x20836DB8;
	static LONG persona11_str = 0x20836DD1;
	static LONG persona11_mag = 0x20836DD2;
	static LONG persona11_en = 0x20836DD3;
	static LONG persona11_ag = 0x20836DD4;
	static LONG persona11_luc = 0x20836DD5;
	static LONG persona11_skill1 = 0x20836DC0;
	static LONG persona11_skill2 = 0x20836DC2;
	static LONG persona11_skill3 = 0x20836DC4;
	static LONG persona11_skill4 = 0x20836DC6;
	static LONG persona11_skill5 = 0x20836DC8;
	static LONG persona11_skill6 = 0x20836DCA;
	static LONG persona11_skill7 = 0x20836DCC;
	static LONG persona11_skill8 = 0x20836DCE;

	//Persona 12
	static LONG persona12_modifer = 0x20836DEA;
	static LONG persona12_level = 0x20836DEC;
	static LONG persona12_str = 0x20836E05;
	static LONG persona12_mag = 0x20836E06;
	static LONG persona12_en = 0x20836E07;
	static LONG persona12_ag = 0x20836E08;
	static LONG persona12_luc = 0x20836E09;
	static LONG persona12_skill1 = 0x20836DF4;
	static LONG persona12_skill2 = 0x20836DF6;
	static LONG persona12_skill3 = 0x20836DF8;
	static LONG persona12_skill4 = 0x20836DFA;
	static LONG persona12_skill5 = 0x20836DFC;
	static LONG persona12_skill6 = 0x20836DFE;
	static LONG persona12_skill7 = 0x20836E00;
	static LONG persona12_skill8 = 0x20836E02;
};

