#ifndef _FLAGS_H_
#define _FLAGS_H_

#include <inttypes.h>
 
typedef enum{
	Shoot,            // shoot(1) or not(0) : shooting
	Shoot_mode,       // single shoot(1) or continuous shoot(0) : ShootMode
	Fric_accel_ok,    // friction accelerate complete(1) or not(0) : Frion_Flag
	Shoot_command,    // mouse left press down(1) or not(0) when human control : Mouse_press_l
	BS_Shoot_mode,    // single shoot(1) or continuous shoot(0) when robot control : BigSymbol_ShootMode
	BS_Shoot_command, // simulation mouse pree down(1) or not(0) when robot control : BigSymbol_Mouse_press_l
	Shoot_speed_mode, // high(1) or low(0) speed : Flag_ShootSpeed
	start_fix,        // : fixed_start
	target_angle_fix, // : target_fixed_angle
	PC_online,        // : upperMonitorOnline
	Auto_aim,         // : upperMonitorWork
	BS_recg_state_in, // Is(1) in BS_recg_state or not(0) : Is_Big_Symbol_Recognition_On
	B_has_press_down, // key B press down(1) or not(0) : key_B
	Z_has_press_down, // key Z press down(1) or not(0) : key_Z
	V_has_press_down, // key V press down(1) or not(0) : key_V
	normal_stat,      // first control cycle getting in NORMAL_STATE from other state(0) or not(1) : NormalFlag
	autoaim_stat,     // first control cycle getting in AUTOAIM_STATE from other state(0) or not(1) : UpMonitorFlag
	BS_hit_stat_y,    // first control cycle getting in BS_HIT_STATE from other state(0) or not(1) of yaw: BigSymbolRecgFlag
	BS_hit_stat_p,    // first control cycle getting in BS_HIT_STATE from other state(0) or not(1) of pitch: BigSymbolRecgFlag
	Flag_20,
	Flag_21,
	Flag_22,
	Flag_23,
	Flag_24,
	Flag_25,
	Flag_26,
	Flag_27,
	Flag_28,
	Flag_29,
	Flag_30,
	Flag_31,
    Flag_32,
	Flag_33,
	Flag_34,
	Flag_35,
	Flag_36,
	Flag_37,
	Flag_38,
	Flag_39,
	Flag_40,
	Flag_41,
	Flag_42,
	Flag_43,
	Flag_44,
	Flag_45,
	Flag_46,
	Flag_47,
	Flag_48,
	Flag_49,
	Flag_50,
	Flag_51,
	Flag_52,
	Flag_53,
	Flag_54,
	Flag_55,
	Flag_56,
	Flag_57,
	Flag_58,
	Flag_59,
	Flag_60,
	Flag_61,
	Flag_62,
	Flag_63,
	Flag_64,
	Flag_65,
	Flag_66,
	Flag_67,
	Flag_68,
	Flag_69,
	Flag_70,
	Flag_71,
	Flag_72,
	Flag_73,
	Flag_74,
	Flag_75,
	Flag_76,
    Flag_77,
	Flag_78,
	Flag_79,
	Flag_80,
	Flag_81,
	Flag_82,
	Flag_83,
	Flag_84,
	Flag_85,
	Flag_86,
	Flag_87,
	Flag_88,
	Flag_89,
	Flag_90,
	Flag_91,
	Flag_92,
	Flag_93,
	Flag_94,
	Flag_95,
	Flag_96,
	Flag_97,
	Flag_98,
	Flag_99,
	Flag_100,
	Flag_101,
	Flag_102,
	Flag_103,
	Flag_104,
	Flag_105,
	Flag_106,
	Flag_107,
	Flag_108,
	Flag_109,
	Flag_110,
	Flag_111,
	Flag_112,
	Flag_113,
	Flag_114,
	Flag_115,
	Flag_116,
	Flag_117,
	Flag_118,
	Flag_119,
	Flag_120,
	Flag_121,
	Flag_122,
	Flag_123,
	Flag_124,
	Flag_125,
	Flag_126,
	Flag_127,
	Flag_128,
	Flag_MAX,
}Flag_e;

int Set_Flag(Flag_e Flag_ID);
int Reset_Flag(Flag_e Flag_ID);
int Get_Flag(Flag_e Flag_ID);
void Toggle_Flag(Flag_e Flag_ID);
void Force_Flag(Flag_e Flag_ID, uint8_t init_value);

void Flags_Init(void);

#endif
