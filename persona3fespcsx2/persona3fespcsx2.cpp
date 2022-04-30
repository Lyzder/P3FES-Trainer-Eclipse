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
	
	//Timer to refresh stats.
	timer1->Interval = 100;
    timer1->Enabled = true;

}

System::Void Form1::comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = PersonaBox->SelectedIndex;

	//After ID 169, Theres a 21-sized dummy gap, so we have to skip it.
	if (index > 169)
		index += 21;

	int desiredPersona = index;

	setValue(COffsets::persona1_modifer, index, 2);
}

System::Void Form1::numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)num_mc_level->Value;

	setValue(COffsets::mc_level, index, 2);
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

System::Void Form1::mc_mood_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
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

System::Void Form1::SlotBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^	e)
{

}

System::Void Form1::persona_level_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_level->Value;

	setValue(COffsets::persona1_level, index, 2);
}

System::Void Form1::persona_st_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_st->Value;

	setValue(COffsets::persona1_str, index, 1);
}

System::Void Form1::persona_ma_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_ma->Value;

	setValue(COffsets::persona1_mag, index, 1);
}

System::Void Form1::persona_en_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_en->Value;

	setValue(COffsets::persona1_en, index, 1);
}

System::Void Form1::persona_ag_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_ag->Value;

	setValue(COffsets::persona1_ag, index, 1);
}

System::Void Form1::persona_lu_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_lu->Value;

	setValue(COffsets::persona1_luc, index, 1);
}

System::Void Form1::persona_skill1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill1->SelectedIndex;

	setValue(COffsets::persona1_skill1, index, 2);
}

System::Void Form1::persona_skill2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill2->SelectedIndex;

	setValue(COffsets::persona1_skill2, index, 2);
}

System::Void Form1::persona_skill3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill3->SelectedIndex;

	setValue(COffsets::persona1_skill3, index, 2);
}

System::Void Form1::persona_skill4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill4->SelectedIndex;

	setValue(COffsets::persona1_skill4, index, 2);
}

System::Void Form1::persona_skill5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill5->SelectedIndex;

	setValue(COffsets::persona1_skill5, index, 2);
}

System::Void Form1::persona_skill6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill6->SelectedIndex;

	setValue(COffsets::persona1_skill6, index, 2);
}

System::Void Form1::persona_skill7_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill7->SelectedIndex;

	setValue(COffsets::persona1_skill7, index, 2);
}

System::Void Form1::persona_skill8_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	int index = (int)persona_skill8->SelectedIndex;

	setValue(COffsets::persona1_skill8, index, 2);
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