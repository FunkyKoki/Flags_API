#include "flags.h"
#include <stdio.h>
#include <inttypes.h>

 
/***********JSP ©copyright***********/
/*******Version 2.0 2019.02.05*******/

static volatile uint64_t FLAGS_1 = 0x0000000000000000;
static volatile uint64_t FLAGS_2 = 0x0000000000000000;
static volatile uint16_t  FLAGS_COUNT = 0;
 
void Reset_All_Flags(void){
	FLAGS_1 &= 0x0000000000000000;
	FLAGS_2 &= 0x0000000000000000;
}

void Set_All_Flags(void){
	FLAGS_1 |= 0xFFFFFFFFFFFFFFFF;
	FLAGS_2 |= 0xFFFFFFFFFFFFFFFF;
}

int Creat_Flag(Flag_e Flag_ID, uint64_t init_value){
	if (FLAGS_COUNT >= 128){
		printf("All the flags has been used out!\r\n");
		return 0;
	}
	else if (Flag_ID >= Flag_MAX){
		printf("The flag ID is too big!\r\n");
		return 0;
	}
	else if (init_value != 0 && init_value != 1){
		printf("Initial flag value is not valid!\r\n");
		return 0;
	}
	else if (Flag_ID >= 64){
		FLAGS_2 |= ((0x0000000000000001 & init_value) << (Flag_ID - 64));
		FLAGS_COUNT++;
		return 1;
	}
	else{
		FLAGS_1 |= ((0x0000000000000001 & init_value) << Flag_ID);
		FLAGS_COUNT++;
		return 1;
	}
}

int Set_Flag(Flag_e Flag_ID){
	if (Flag_ID >= Flag_MAX){
		printf("The flag ID is too big!\r\n");
		return 0;
	}
	else if (Flag_ID >= 64){
		FLAGS_2 |= (0x0000000000000001 << (Flag_ID-64));
		return 1;
	}
	else{
		FLAGS_1 |= (0x0000000000000001 << Flag_ID);
		return 1;
	}
}

int Reset_Flag(Flag_e Flag_ID){
	if (Flag_ID >= Flag_MAX){
		printf("The flag ID is too big!\r\n");
		return 0;
	}
	else if (Flag_ID >= 64){
		FLAGS_2 &= ~(0x0000000000000001 << (Flag_ID-64));
		return 1;
	}
	else{
		FLAGS_1 &= ~(0x0000000000000001 << Flag_ID);
		return 1;
	}
}

int Get_Flag(Flag_e Flag_ID){
	if (Flag_ID >= Flag_MAX){
		printf("The flag ID is too big!\r\n");
		return 0;
	}
	else if (Flag_ID >= 64){
		return ((FLAGS_2 >> (Flag_ID-64)) & 0x0000000000000001);
	}
	else{
		return ((FLAGS_1 >> Flag_ID) & 0x0000000000000001);
	}
}

void Toggle_Flag(Flag_e Flag_ID){
    if (Flag_ID >= Flag_MAX){
		printf("The flag ID is too big!\r\n");
	}
	else if (Flag_ID>=64){
		FLAGS_2 = FLAGS_2 ^ (0x0000000000000001 << (Flag_ID-64));
	}
	else
	{
		FLAGS_1 = FLAGS_1 ^ (0x0000000000000001 << Flag_ID);
	}
	
}

void Force_Flag(Flag_e Flag_ID, uint8_t init_value){
    if (Flag_ID >= Flag_MAX){
		printf("The flag ID is too big!\r\n");
	}
	else if (init_value != 0 && init_value != 1){
		printf("Initial flag value is not valid!\r\n");
	}
	else if(init_value == 0){
		if (Flag_ID>=64){
			FLAGS_2 &= ~(0x0000000000000001 << (Flag_ID-64));
		}
		else{
			FLAGS_1 &= ~(0x0000000000000001 << Flag_ID);
		}
	}
	else{
		if (Flag_ID>=64){
			FLAGS_2 |= (0x0000000000000001 << (Flag_ID-64));
		}
		else{
			FLAGS_1 |= (0x0000000000000001 << Flag_ID);
		}
	  
	}
}

/* You can and //only// can create_flag() here! */
void Flags_Init(void){
	Creat_Flag(Shoot, 0);
	Creat_Flag(Shoot_mode, 0);
	Creat_Flag(Fric_accel_ok, 0);
	Creat_Flag(Shoot_command, 0);
	Creat_Flag(BS_Shoot_mode, 0);
	Creat_Flag(BS_Shoot_command, 0);
	Creat_Flag(Shoot_speed_mode, 0);
	Creat_Flag(start_fix, 0);
	Creat_Flag(target_angle_fix, 0);
	Creat_Flag(PC_online, 0);
	Creat_Flag(Auto_aim, 0);
	Creat_Flag(BS_recg_state_in, 0);
	Creat_Flag(B_has_press_down, 0);
	Creat_Flag(Z_has_press_down, 0);
	Creat_Flag(V_has_press_down, 0);
	Creat_Flag(normal_stat, 0);
	Creat_Flag(autoaim_stat, 0);
	Creat_Flag(BS_hit_stat_y, 0);
	Creat_Flag(BS_hit_stat_p, 0);
	Creat_Flag(BS_hit_stat_p, 0);
	Creat_Flag(Flag_128, 1);
}

int main(){
	Flags_Init();
	printf("%d\r\n", Get_Flag(Flag_128));
	Set_Flag(Flag_128);
	printf("%d\r\n", Get_Flag(Flag_128));
	Reset_Flag(Flag_128);
	printf("%d\r\n", Get_Flag(Flag_128));
	Toggle_Flag(Flag_128);
	printf("%d\r\n", Get_Flag(Flag_128));
	Toggle_Flag(Flag_128);
	printf("%d\r\n", Get_Flag(Flag_128));
	Force_Flag(Flag_128, 1);
	printf("%d\r\n", Get_Flag(Flag_128));
	Force_Flag(Flag_128, 0);
	printf("%d\r\n", Get_Flag(Flag_128));
	return 0;
}
