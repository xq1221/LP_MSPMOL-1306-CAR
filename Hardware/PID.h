#ifndef __PID_H
#define	__PID_H

typedef struct
{
	float target_val;   //目标值
	float Error;          /*第 k 次偏差 */
	float LastError;     /* Error[-1],第 k-1 次偏差 */
	float PrevError;    /* Error[-2],第 k-2 次偏差 */
	float Kp,Ki,Kd;     //比例、积分、微分系数
	float integral;     //积分值
	float output_val;   //输出值 
} PID;

#include "Motor.h"

extern PID Sensor_PID;
extern PID Motor1_PID;
extern PID Motor2_PID;

void PID_Param_Init(void);
void Clear_Params(PID *pid);
void set_PID_target(PID *pid,float temp_val);
float get_pid_target(PID *pid);
void set_PID(PID *pid,float p, float i, float d);
float addPID_realize(PID *pid, float actual_val);
float PosionPID_realize(PID *pid, float actual_val);

#endif
