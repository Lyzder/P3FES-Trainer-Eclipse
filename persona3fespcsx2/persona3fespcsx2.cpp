// persona3fespcsx2.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <tchar.h>
#include <string>
#include "Global.h"
#include "Offsets.h"

using namespace persona3fespcsx2;

HWND hwind;
DWORD pid;

class PersonaOffsets
{
	public:
		LONG modifier;
		LONG level;
		LONG exp;
		LONG strength;
		LONG magic;
		LONG endurance;
		LONG agility;
		LONG luck;
		LONG skill1;
		LONG skill2;
		LONG skill3;
		LONG skill4;
		LONG skill5;
		LONG skill6;
		LONG skill7;
		LONG skill8;
};

PersonaOffsets ValueOffsets;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}

BOOL CALLBACK WorkerProc(HWND hwnd, LPARAM lParam) {
    static TCHAR buffer[50];

    GetWindowText(hwnd, buffer, 50);
    if(_tcsstr(buffer, TEXT("PCSX2"))) {
		//Found the pid, gonna put the pid in.
        hwind = hwnd;
        return FALSE;
    }

    return TRUE;
}

System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{			
	//Find PCSX2
	EnumWindows(WorkerProc, NULL);

	
	if (hwind == NULL)
	{
		//Cant find PCSX2. Is PCSX2 ready?
		bool messageboxloop = true;
		bool cancelPressed = false;
		while (messageboxloop)
		{
			int boxResult = MessageBoxA(0, "ERROR: PCSX2 not found running", "PCSX2 wasn't found!\nMake sure it's running!", MB_RETRYCANCEL);
			switch(boxResult)
			{
				case IDRETRY:
					EnumWindows(WorkerProc, NULL);
					if (hwind != NULL)
						messageboxloop = false;
						break;
				case IDCANCEL:
					cancelPressed = true;
					break;
			}
				if (cancelPressed)
				{
					exit(0x0);
				}
		}
	}


	//Found it.
	GetWindowThreadProcessId(hwind,&pid);

	//Quick fix until I figure out how to access from a non form method
	int data = 0;
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	ReadProcessMemory(pHandle, (LPVOID)COffsets::mc_level, &data, 1, 0);
	num_mc_level->Value = data;
	ReadProcessMemory(pHandle, (LPVOID)COffsets::mc_exp, &data, 4, 0);
	MC_exp->Value = data;
	
	//Timer to refresh stats.
	timer1->Interval = 100;
    timer1->Enabled = true;

}

System::Void Form1::PersonaBox_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = PersonaBox->SelectedIndex;

	//After ID 169, Theres a 21-sized dummy gap, so we have to skip it.
	if (index > 169)
		index += 21;

	int desiredPersona = index;

	setValue(COffsets::persona1_modifer, index, 2);
}

System::Void Form1::num_mc_level_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_level->Value;

	setValue(COffsets::mc_level, index, 1);
}

System::Void Form1::MC_exp_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)MC_exp->Value;

	setValue(COffsets::mc_exp, index, 4);
}

System::Void Form1::num_mc_current_hp_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_current_hp->Value;

	setValue(COffsets::mc_current_hp, index, 2);
}

System::Void Form1::num_mc_current_mp_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_current_mp->Value;

	setValue(COffsets::mc_current_mp, index, 2);
}

System::Void Form1::mc_mood_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)mc_mood->SelectedIndex;
	
	setValue(COffsets::mc_mood, index, 2);
}

System::Void Form1::mc_academics_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)mc_academics->Value;
	
	setValue(COffsets::mc_academics, index, 2);
}

System::Void Form1::num_mc_charm_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_charm->Value;
	
	setValue(COffsets::mc_charm, index, 2);
}

System::Void Form1::num_mc_courage_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_courage->Value;
	
	setValue(COffsets::mc_courage, index, 2);
}

System::Void Form1::num_mc_equip_persona_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_equip_persona->Value;
	
	setValue(COffsets::mc_equipped_persona, index, 2);
}

System::Void Form1::num_mc_money_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_money->Value;
	
	setValue(COffsets::mc_money, index, 4);
}

System::Void Form1::persona_level_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_level->Value;

	setValue(ValueOffsets.level, index, 1);
}

System::Void Form1::persona_exp_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_exp->Value;

	setValue(ValueOffsets.exp, index, 4);
}

System::Void Form1::persona_st_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_st->Value;

	setValue(ValueOffsets.strength, index, 1);
}

System::Void Form1::persona_ma_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_ma->Value;

	setValue(ValueOffsets.magic, index, 1);
}

System::Void Form1::persona_en_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_en->Value;

	setValue(ValueOffsets.endurance, index, 1);
}

System::Void Form1::persona_ag_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_ag->Value;

	setValue(ValueOffsets.agility, index, 1);
}

System::Void Form1::persona_lu_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_lu->Value;

	setValue(ValueOffsets.luck, index, 1);
}

System::Void Form1::persona_skill1_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill1->SelectedIndex;

	setValue(ValueOffsets.skill1, index, 2);
}

System::Void Form1::persona_skill2_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill2->SelectedIndex;

	setValue(ValueOffsets.skill2, index, 2);
}

System::Void Form1::persona_skill3_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill3->SelectedIndex;

	setValue(ValueOffsets.skill3, index, 2);
}

System::Void Form1::persona_skill4_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill4->SelectedIndex;

	setValue(ValueOffsets.skill4, index, 2);
}

System::Void Form1::persona_skill5_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill5->SelectedIndex;

	setValue(ValueOffsets.skill5, index, 2);
}

System::Void Form1::persona_skill6_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill6->SelectedIndex;

	setValue(ValueOffsets.skill6, index, 2);
}

System::Void Form1::persona_skill7_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill7->SelectedIndex;

	setValue(ValueOffsets.skill7, index, 2);
}

System::Void Form1::persona_skill8_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill8->SelectedIndex;

	setValue(ValueOffsets.skill8, index, 2);
}

System::Void Form1::SlotBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	int index = (int)SlotBox->SelectedIndex;

	switch (index)
	{
	case 0:
		ValueOffsets.modifier = COffsets::persona1_modifer;
		ValueOffsets.level = COffsets::persona1_level;
		ValueOffsets.exp = COffsets::persona1_exp;
		ValueOffsets.strength = COffsets::persona1_str;
		ValueOffsets.magic = COffsets::persona1_mag;
		ValueOffsets.endurance = COffsets::persona1_en;
		ValueOffsets.agility = COffsets::persona1_ag;
		ValueOffsets.luck = COffsets::persona1_luc;
		ValueOffsets.skill1 = COffsets::persona1_skill1;
		ValueOffsets.skill2 = COffsets::persona1_skill2;
		ValueOffsets.skill3 = COffsets::persona1_skill3;
		ValueOffsets.skill4 = COffsets::persona1_skill4;
		ValueOffsets.skill5 = COffsets::persona1_skill5;
		ValueOffsets.skill6 = COffsets::persona1_skill6;
		ValueOffsets.skill7 = COffsets::persona1_skill7;
		ValueOffsets.skill8 = COffsets::persona1_skill8;
		break;
	case 1:
		ValueOffsets.modifier = COffsets::persona2_modifer;
		ValueOffsets.level = COffsets::persona2_level;
		ValueOffsets.exp = COffsets::persona2_exp;
		ValueOffsets.strength = COffsets::persona2_str;
		ValueOffsets.magic = COffsets::persona2_mag;
		ValueOffsets.endurance = COffsets::persona2_en;
		ValueOffsets.agility = COffsets::persona2_ag;
		ValueOffsets.luck = COffsets::persona2_luc;
		ValueOffsets.skill1 = COffsets::persona2_skill1;
		ValueOffsets.skill2 = COffsets::persona2_skill2;
		ValueOffsets.skill3 = COffsets::persona2_skill3;
		ValueOffsets.skill4 = COffsets::persona2_skill4;
		ValueOffsets.skill5 = COffsets::persona2_skill5;
		ValueOffsets.skill6 = COffsets::persona2_skill6;
		ValueOffsets.skill7 = COffsets::persona2_skill7;
		ValueOffsets.skill8 = COffsets::persona2_skill8;
		break;
	case 2:
		ValueOffsets.modifier = COffsets::persona3_modifer;
		ValueOffsets.level = COffsets::persona3_level;
		ValueOffsets.exp = COffsets::persona3_exp;
		ValueOffsets.strength = COffsets::persona3_str;
		ValueOffsets.magic = COffsets::persona3_mag;
		ValueOffsets.endurance = COffsets::persona3_en;
		ValueOffsets.agility = COffsets::persona3_ag;
		ValueOffsets.luck = COffsets::persona3_luc;
		ValueOffsets.skill1 = COffsets::persona3_skill1;
		ValueOffsets.skill2 = COffsets::persona3_skill2;
		ValueOffsets.skill3 = COffsets::persona3_skill3;
		ValueOffsets.skill4 = COffsets::persona3_skill4;
		ValueOffsets.skill5 = COffsets::persona3_skill5;
		ValueOffsets.skill6 = COffsets::persona3_skill6;
		ValueOffsets.skill7 = COffsets::persona3_skill7;
		ValueOffsets.skill8 = COffsets::persona3_skill8;
		break;
	case 3:
		ValueOffsets.modifier = COffsets::persona4_modifer;
		ValueOffsets.level = COffsets::persona4_level;
		ValueOffsets.exp = COffsets::persona4_exp;
		ValueOffsets.strength = COffsets::persona4_str;
		ValueOffsets.magic = COffsets::persona4_mag;
		ValueOffsets.endurance = COffsets::persona4_en;
		ValueOffsets.agility = COffsets::persona4_ag;
		ValueOffsets.luck = COffsets::persona4_luc;
		ValueOffsets.skill1 = COffsets::persona4_skill1;
		ValueOffsets.skill2 = COffsets::persona4_skill2;
		ValueOffsets.skill3 = COffsets::persona4_skill3;
		ValueOffsets.skill4 = COffsets::persona4_skill4;
		ValueOffsets.skill5 = COffsets::persona4_skill5;
		ValueOffsets.skill6 = COffsets::persona4_skill6;
		ValueOffsets.skill7 = COffsets::persona4_skill7;
		ValueOffsets.skill8 = COffsets::persona4_skill8;
		break;
	case 4:
		ValueOffsets.modifier = COffsets::persona5_modifer;
		ValueOffsets.level = COffsets::persona5_level;
		ValueOffsets.exp = COffsets::persona5_exp;
		ValueOffsets.strength = COffsets::persona5_str;
		ValueOffsets.magic = COffsets::persona5_mag;
		ValueOffsets.endurance = COffsets::persona5_en;
		ValueOffsets.agility = COffsets::persona5_ag;
		ValueOffsets.luck = COffsets::persona5_luc;
		ValueOffsets.skill1 = COffsets::persona5_skill1;
		ValueOffsets.skill2 = COffsets::persona5_skill2;
		ValueOffsets.skill3 = COffsets::persona5_skill3;
		ValueOffsets.skill4 = COffsets::persona5_skill4;
		ValueOffsets.skill5 = COffsets::persona5_skill5;
		ValueOffsets.skill6 = COffsets::persona5_skill6;
		ValueOffsets.skill7 = COffsets::persona5_skill7;
		ValueOffsets.skill8 = COffsets::persona5_skill8;
		break;
	case 5:
		ValueOffsets.modifier = COffsets::persona6_modifer;
		ValueOffsets.level = COffsets::persona6_level;
		ValueOffsets.exp = COffsets::persona6_exp;
		ValueOffsets.strength = COffsets::persona6_str;
		ValueOffsets.magic = COffsets::persona6_mag;
		ValueOffsets.endurance = COffsets::persona6_en;
		ValueOffsets.agility = COffsets::persona6_ag;
		ValueOffsets.luck = COffsets::persona6_luc;
		ValueOffsets.skill1 = COffsets::persona6_skill1;
		ValueOffsets.skill2 = COffsets::persona6_skill2;
		ValueOffsets.skill3 = COffsets::persona6_skill3;
		ValueOffsets.skill4 = COffsets::persona6_skill4;
		ValueOffsets.skill5 = COffsets::persona6_skill5;
		ValueOffsets.skill6 = COffsets::persona6_skill6;
		ValueOffsets.skill7 = COffsets::persona6_skill7;
		ValueOffsets.skill8 = COffsets::persona6_skill8;
		break;
	case 6:
		ValueOffsets.modifier = COffsets::persona7_modifer;
		ValueOffsets.level = COffsets::persona7_level;
		ValueOffsets.exp = COffsets::persona7_exp;
		ValueOffsets.strength = COffsets::persona7_str;
		ValueOffsets.magic = COffsets::persona7_mag;
		ValueOffsets.endurance = COffsets::persona7_en;
		ValueOffsets.agility = COffsets::persona7_ag;
		ValueOffsets.luck = COffsets::persona7_luc;
		ValueOffsets.skill1 = COffsets::persona7_skill1;
		ValueOffsets.skill2 = COffsets::persona7_skill2;
		ValueOffsets.skill3 = COffsets::persona7_skill3;
		ValueOffsets.skill4 = COffsets::persona7_skill4;
		ValueOffsets.skill5 = COffsets::persona7_skill5;
		ValueOffsets.skill6 = COffsets::persona7_skill6;
		ValueOffsets.skill7 = COffsets::persona7_skill7;
		ValueOffsets.skill8 = COffsets::persona7_skill8;
		break;
	case 7:
		ValueOffsets.modifier = COffsets::persona8_modifer;
		ValueOffsets.level = COffsets::persona8_level;
		ValueOffsets.exp = COffsets::persona8_exp;
		ValueOffsets.strength = COffsets::persona8_str;
		ValueOffsets.magic = COffsets::persona8_mag;
		ValueOffsets.endurance = COffsets::persona8_en;
		ValueOffsets.agility = COffsets::persona8_ag;
		ValueOffsets.luck = COffsets::persona8_luc;
		ValueOffsets.skill1 = COffsets::persona8_skill1;
		ValueOffsets.skill2 = COffsets::persona8_skill2;
		ValueOffsets.skill3 = COffsets::persona8_skill3;
		ValueOffsets.skill4 = COffsets::persona8_skill4;
		ValueOffsets.skill5 = COffsets::persona8_skill5;
		ValueOffsets.skill6 = COffsets::persona8_skill6;
		ValueOffsets.skill7 = COffsets::persona8_skill7;
		ValueOffsets.skill8 = COffsets::persona8_skill8;
		break;
	case 8:
		ValueOffsets.modifier = COffsets::persona9_modifer;
		ValueOffsets.level = COffsets::persona9_level;
		ValueOffsets.exp = COffsets::persona9_exp;
		ValueOffsets.strength = COffsets::persona9_str;
		ValueOffsets.magic = COffsets::persona9_mag;
		ValueOffsets.endurance = COffsets::persona9_en;
		ValueOffsets.agility = COffsets::persona9_ag;
		ValueOffsets.luck = COffsets::persona9_luc;
		ValueOffsets.skill1 = COffsets::persona9_skill1;
		ValueOffsets.skill2 = COffsets::persona9_skill2;
		ValueOffsets.skill3 = COffsets::persona9_skill3;
		ValueOffsets.skill4 = COffsets::persona9_skill4;
		ValueOffsets.skill5 = COffsets::persona9_skill5;
		ValueOffsets.skill6 = COffsets::persona9_skill6;
		ValueOffsets.skill7 = COffsets::persona9_skill7;
		ValueOffsets.skill8 = COffsets::persona9_skill8;
		break;
	case 9:
		ValueOffsets.modifier = COffsets::persona10_modifer;
		ValueOffsets.level = COffsets::persona10_level;
		ValueOffsets.exp = COffsets::persona10_exp;
		ValueOffsets.strength = COffsets::persona10_str;
		ValueOffsets.magic = COffsets::persona10_mag;
		ValueOffsets.endurance = COffsets::persona10_en;
		ValueOffsets.agility = COffsets::persona10_ag;
		ValueOffsets.luck = COffsets::persona10_luc;
		ValueOffsets.skill1 = COffsets::persona10_skill1;
		ValueOffsets.skill2 = COffsets::persona10_skill2;
		ValueOffsets.skill3 = COffsets::persona10_skill3;
		ValueOffsets.skill4 = COffsets::persona10_skill4;
		ValueOffsets.skill5 = COffsets::persona10_skill5;
		ValueOffsets.skill6 = COffsets::persona10_skill6;
		ValueOffsets.skill7 = COffsets::persona10_skill7;
		ValueOffsets.skill8 = COffsets::persona10_skill8;
		break;
	case 10:
		ValueOffsets.modifier = COffsets::persona11_modifer;
		ValueOffsets.level = COffsets::persona11_level;
		ValueOffsets.exp = COffsets::persona11_exp;
		ValueOffsets.strength = COffsets::persona11_str;
		ValueOffsets.magic = COffsets::persona11_mag;
		ValueOffsets.endurance = COffsets::persona11_en;
		ValueOffsets.agility = COffsets::persona11_ag;
		ValueOffsets.luck = COffsets::persona11_luc;
		ValueOffsets.skill1 = COffsets::persona11_skill1;
		ValueOffsets.skill2 = COffsets::persona11_skill2;
		ValueOffsets.skill3 = COffsets::persona11_skill3;
		ValueOffsets.skill4 = COffsets::persona11_skill4;
		ValueOffsets.skill5 = COffsets::persona11_skill5;
		ValueOffsets.skill6 = COffsets::persona11_skill6;
		ValueOffsets.skill7 = COffsets::persona11_skill7;
		ValueOffsets.skill8 = COffsets::persona11_skill8;
		break;
	default:
		ValueOffsets.modifier = COffsets::persona12_modifer;
		ValueOffsets.level = COffsets::persona12_level;
		ValueOffsets.exp = COffsets::persona12_exp;
		ValueOffsets.strength = COffsets::persona12_str;
		ValueOffsets.magic = COffsets::persona12_mag;
		ValueOffsets.endurance = COffsets::persona12_en;
		ValueOffsets.agility = COffsets::persona12_ag;
		ValueOffsets.luck = COffsets::persona12_luc;
		ValueOffsets.skill1 = COffsets::persona12_skill1;
		ValueOffsets.skill2 = COffsets::persona12_skill2;
		ValueOffsets.skill3 = COffsets::persona12_skill3;
		ValueOffsets.skill4 = COffsets::persona12_skill4;
		ValueOffsets.skill5 = COffsets::persona12_skill5;
		ValueOffsets.skill6 = COffsets::persona12_skill6;
		ValueOffsets.skill7 = COffsets::persona12_skill7;
		ValueOffsets.skill8 = COffsets::persona12_skill8;
		break;
	}
	PersonaBox->Enabled = TRUE;
	persona_level->Enabled = TRUE;
	persona_exp->Enabled = TRUE;
	persona_skill1->Enabled = TRUE;
	persona_skill2->Enabled = TRUE;
	persona_skill3->Enabled = TRUE;
	persona_skill4->Enabled = TRUE;
	persona_skill5->Enabled = TRUE;
	persona_skill6->Enabled = TRUE;
	persona_skill7->Enabled = TRUE;
	persona_skill8->Enabled = TRUE;
	persona_st->Enabled = TRUE;
	persona_ma->Enabled = TRUE;
	persona_en->Enabled = TRUE;
	persona_ag->Enabled = TRUE;
	persona_lu->Enabled = TRUE;
	readValuesPersona();
}


System::Void Form1::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	//TODO: This needs to be fixed. Buff comes out corrupted.
	/*HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);

	int buff = 0;

	//MC Level
	ReadProcessMemory(pHandle,(LPVOID)COffsets::mc_level,&buff,sizeof(buff),NULL);
	//num_mc_level->Value = buff;

	CloseHandle(pHandle);*/
}

System::Void Form1::setValue(LONG pokeAddress, int value, int byteSize)
{
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);

	if (byteSize == 1)
		WriteProcessMemory(pHandle,(LPVOID)pokeAddress,&value,sizeof(bool),NULL);
	else if (byteSize == 2)
		WriteProcessMemory(pHandle,(LPVOID)pokeAddress,&value,sizeof(short int),NULL);
	else if (byteSize == 4)
		WriteProcessMemory(pHandle,(LPVOID)pokeAddress,&value,sizeof(long),NULL);

	CloseHandle(pHandle);
}


System::Void Form1::readValuesPersona()
{
	int data = 0;
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	persona_skill1->SelectedIndex = -1;
	persona_skill2->SelectedIndex = -1;
	persona_skill3->SelectedIndex = -1;
	persona_skill4->SelectedIndex = -1;
	persona_skill5->SelectedIndex = -1;
	persona_skill6->SelectedIndex = -1;
	persona_skill7->SelectedIndex = -1;
	persona_skill8->SelectedIndex = -1;

	//Load Persona in slot
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.modifier, &data, 2, 0);
	if (data > 169) {
		data -= 21;
	}
	PersonaBox->SelectedIndex = data;

	//Load Persona level and exp
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.level, &data, 2, 0);
	persona_level->Value = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.exp, &data, 4, 0);
	persona_exp->Value = data;

	//Reset the variable to clean up bytes
	data = 0;

	//Load skills
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill1, &data, 2, 0);
	if (data != 0)
		persona_skill1->SelectedIndex = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill2, &data, 2, 0);
	if (data != 0)
		persona_skill2->SelectedIndex = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill3, &data, 2, 0);
	if (data != 0)
		persona_skill3->SelectedIndex = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill4, &data, 2, 0);
	if (data != 0)
		persona_skill4->SelectedIndex = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill5, &data, 2, 0);
	if (data != 0)
		persona_skill5->SelectedIndex = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill6, &data, 2, 0);
	if (data != 0)
		persona_skill6->SelectedIndex = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill7, &data, 2, 0);
	if (data != 0)
		persona_skill7->SelectedIndex = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.skill8, &data, 2, 0);
	if (data != 0)
		persona_skill8->SelectedIndex = data;

	//Load Persona stats
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.strength, &data, 1, 0);
	if (data != 0)
		persona_st->Value = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.magic, &data, 1, 0);
	if (data != 0)
		persona_ma->Value = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.endurance, &data, 1, 0);
	if (data != 0)
		persona_en->Value = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.agility, &data, 1, 0);
	if (data != 0)
		persona_ag->Value = data;
	ReadProcessMemory(pHandle, (LPVOID)ValueOffsets.luck, &data, 1, 0);
	if (data != 0)
		persona_lu->Value = data;

	CloseHandle(pHandle);
}