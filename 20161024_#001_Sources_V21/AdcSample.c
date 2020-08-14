/*
 * FileName:       AdcSample.h
 * Author:         Rock.Wang  Version: v1.0  Date: 2015-4-15
 * Description:    
 * Version:        
 * Function List:  
 *                 1.
 * History:        
 *     <author>   <time>    <version >   <desc>
 */

#include	"AllHead.h"

/*******************************************************************
 * pipe temperature AD value
 * AD = 8.06/(8.06+Rx)*255
 * temperature = (ADTempPipe_Tab[x] -30)/2
 * while Rx = 35.2024k, then AD = 47, 
 * so temperature = (ADTempPipe_Tab[47] - 30)/2 = 0
********************************************************************/
const U8 u8Tab_ADPipeTemp[]=
{
/*	0		1		2		3		4		5		6		7		8		9  */
	0,		0,		0,		0,		0,		0,		0,		0,		0,		0,	//0-9
	0,		0,		0,		0,		0,		0,		0,		0,		0,		0,	//11-19
	0,		0,		0,		2,		3,		4,		6,		8,		9,		10,	//20-29
	11,		12,		14,		15,		16,		17,		18,		19,		20,		21,	//30-39
	22,		23,		24,		26,		27,		28,		29,		30,		31,		32,	//40-49
	33,		34,		34,		35,		36,		37,		38,		38,		39,		40,	//50-59
	41,		42,		42,		43,		44,		44,		45,		46,		46,		48,	//60-69
	49,		50,		50,		51,		52,		53,		53,		54,		55,		56,	//70-79
	56,		57,		58,		59,		59,		60,		61,		61,		62,		63,	//80-89
	63,		64,		65,		65,		66,		67,		68,		68,		69,		70,	//90-99
	70,		71,		72,		73,		73,		74,		75,		75,		76,		77,	//100-109
	77,		78,		79,		79,		80,		81,		81,		82,		83,		83,	//110-119
	84,		85,		85,		86,		87,		87,		88,		89,		90,		90,	//120-129
	91,		92,		93,		93,		94,		95,		95,		96,		97,		97,	//130-139
	98,		99,		100,	100,	101,	102,	103,	103,	104,	105,//140-149
	106,	106,	107,	108,	109,	109,	110,	111,	112,	113,//150-159
	113,	114,	115,	116,	117,	118,	118,	119,	120,	121,//160-169
	122,	123,	124,	124,	125,	126,	127,	128,	129,	130,//170-179
	131,	132,	133,	134,	135,	136,	137,	138,	139,	140,//180-189
	141,	142,	143,	144,	146,	146,	148,	149,	150,	152,//190-199
	152,	154,	155,	156,	158,	159,	160,	162,	164,	165,//200-209
	166,	168,	170,	171,	172,	174,	176,	178,	180,	182,//210-219
	184,	185,	186,	188,	190,	190,	190,	190,	190,	190,//220-229
	190,	190,	190,	190,	190,	190,	190,	190,	190,	190,//230-239
	190,	190,	190,	190,	190,	190,	190,	190,	190,	190,//240-249
	190,	190,	190,	190,	190,	190,								//250-255
};

/******************************************************************
 * exhaust port temperature AD value (TempTp)
 * AD = 8.06/(8.06+Rx)*255
 * temperature = ADTempIndoorEnvir_Tab[x]
 * while Rx = 44k, then AD = 40, 
 * so temperature = ADTempTp_Tab[40] = 31
********************************************************************/
const unsigned char ADTempTp_Tab[] = 
{
/*	0		1		2		3		4		5		6		7		8		9   */
	0,		0,		0,		0,		0,		0,		0,		0,		0,		0,	//0-9
	0,		1,		2,		4,		6,		7,		9,		10,		11,		12,	//10-19
	13,		15,		16,		17,		18,		19,		20,		21,		21,		22,	//20-29
	23,		24,		25,		25,		26,		27,		28,		28,		29,		30,	//30-39
	31,		31,		32,		33,		33,		34,		34,		35,		36,		36,	//40-49
	37,		38,		38,		39,		39,		40,		40,		41,		42,		42,	//50-59
	43,		43,		44,		44,		45,		45,		46,		46,		47,		47,	//60-69
	48,		48,		49,		49,		50,		50,		51,		51,		52,		52,	//70-79	
	53,		53,		54,		54,		55,		55,		56,		56,		57,		57,	//80-89	
	58,		58,		58,		59,		59,		60,		60,		61,		61,		62,	//90-99	
	62,		63,		63,		64,		64,		64,		65,		65,		66,		66,	//100-109	
	67,		67,		68,		68,		69,   	69,		69,		70,		70,		71,	//110-119	
	71,		72,		72,		73,		73,		74,		74,		75,		75,		76,	//120-129	
	76,		76,		77,		77,		78,		78,		79,		79,		80,		80,	//130-139	
	81,		81,		82,		82,		83,		83,		84,		84,		85,		85,	//140-149	
	86,		86,		87,		87,		88,		88,		89,		89,		90,		91,	//150-159	
	91,		92,		92,		93,		93,		94,		94,		95,		96,		96,	//160-169	
	97, 	97,		98,		99,		99,		100,	100,	101,	102,	102,//170-179
	103,	104,	104,	105,	106,	106,	107,	108,	109,	109,//180-189
	110,	111,	111,	112,	113,	114,	115,	115,	116,	117,//190-199
	118,	119,	120,	120,	120,	120,	120,	120,	120,	120,//200-209
	120,	120,	120,	120,	120,	120,	120,	120,	120,	120,//210-219
	120,	120,	120,	120,	120,	120,	120,	120,	120,	120,//220-229
	120,	120,	120,	120,	120,	120,	120,	120,	120,	120,//230-239
	120,	120,	120,	120,	120,	120,	120,	120,	120,	120,//240-249
	120,	120,	120,	120,	120,	120,								//250-255
};


/*  ----变量定义--------------------------------------------*/
U8 FG_Time10ms_Adc;
U8 mu8AdcVaule[NUM_ADC_CH];
U8 mu8AdT1;


static U8 u8AdcSampCnt;
static U8 u8AdcScanData[NUM_ADC_CH][NUM_ADC_AVG];



/* ---函数声明----------------------------------------------*/
void AdcResult(void);


/* ********************************************************************************
 * 函数名:   AdcSample 
 * 函数功能: 对各通道ADC采样
 * 创建者:   Rock.Wang
 * 创建日期: 2015年4月15日
 * 修改者:
 * 修改日期:
 * 传入参数:
 * 返回值:
 * 被调用的函数:main()
 * 调用的函数:AdcSample(),ADC驱动库函数
 **********************************************************************************/
void AdcSample(void)
{
	ADC_ScanFIFOInfoT info;
	U16 u16data;
	U8  u8Count;
    
	if (FG_Time10ms_Adc == FALSE)
	{
		return;
	}

	
	if (SET != ADC12_GetScanIntFlag(ADC12_UNIT0))
	{
		return;
	}

	FG_Time10ms_Adc = FALSE;
	
	ADC12_ClrScanIntFlag(ADC12_UNIT0);
	u8Count = NUM_ADC_CH;

	while (u8Count--)
	{
		ADC12_GetScanFIFOInfo(ADC12_UNIT0, &info);

		if(info.Ch == ADC_CH_T1)
		{
			if(info.DataValid == ADC12_SCAN_DATA_VALID)
			{
				u16data = ADC12_GetScanFIFOData(ADC12_UNIT0);
				u8AdcScanData[NUM_CH_T1][u8AdcSampCnt] = (uint8_t)(u16data>>8);
			}
		}
		/********************/	
		else if(info.Ch == ADC_CH_T2)
		{
			if(info.DataValid == ADC12_SCAN_DATA_VALID)
			{
				u16data = ADC12_GetScanFIFOData(ADC12_UNIT0);
				u8AdcScanData[NUM_CH_T2][u8AdcSampCnt] = (uint8_t)(u16data>>8);
			}
		}
	}
	
	NOP();
	NOP();
	AdcResult();
	NOP();
	NOP();
	ADC12_ClrScanFIFO(ADC12_UNIT0); 			/*Clear FIFO*/
	NOP();
	NOP();
	ADC12_StartScan(ADC12_UNIT0);

}

/* ********************************************************************************
 * 函数名:   AdcSample 
 * 函数功能: ADC初始化
 * 创建者:   Rock.Wang
 * 创建日期: 2015年4月15日
 * 修改者:
 * 修改日期:
 * 传入参数:
 * 返回值:
 * 被调用的函数:main()
 * 调用的函数:
 **********************************************************************************/
void AdcInit(void)
{
	DT_ConfigT tDT_ConfigTPeriodic = 
	{
		DT_MODE_PERIOD,
		DT_PRE_BY_1,
		DT_CNT_SIZE_32,
	};

	DT_ConfigMode(DT_CH_2, &tDT_ConfigTPeriodic);
	
	/* 将一个周期分隔成6段，以便取对湿度传感器PB1低电平的中间一段来采样 */
	DT_ConfigSetLoadValue (DT_CH_2, (2672-1));		// 16M/2672 = 167us


	/* Set sample time */
	ADC12_SelSampleTimeReg(ADC12_UNIT0, ADC_CH_T1, ADC12_SAMPLE_TIME_SEL_REG0);
	ADC12_SelSampleTimeReg(ADC12_UNIT0, ADC_CH_T2, ADC12_SAMPLE_TIME_SEL_REG0);
	/*  (1/16MHz)*[(9+1)*4+1]=2.05us  */
	ADC12_SetSampleTime0(ADC12_UNIT0, 9, ADC12_SAMPLE_TIME_N4);
	ADC12_EnableOpt(ADC12_UNIT0);	/* Start ADC operation */
	while(SET != ADC12_GetOptStat(ADC12_UNIT0));

	/* Select channel */
	ADC12_SelScanCh(ADC12_UNIT0, 
	((1ul<<ADC_CH_T1)|(1ul<<ADC_CH_T2)));
	
	ADC12_ClrScanFIFO(ADC12_UNIT0);	/* Clear FIFO */
	ADC12_SetScanFIFOStage(ADC12_UNIT0, (ADC12_ScanFIFOStageT)(NUM_ADC_CH-1));	/* Set FIFO stage */
	ADC12_SetScanMode(ADC12_UNIT0 , ADC12_SCAN_MODE_ONE_SHOT);	/* Set Scan mode */
	ADC12_DisableScanInt(ADC12_UNIT0);
	ADC12_StartScan(ADC12_UNIT0);	/* Start scan */

}


/* ********************************************************************************
 * 函数名:   AdcResult 
 * 函数功能: 采样结果处理
 * 创建者:   Rock.Wang
 * 创建日期: 2015年4月15日
 * 修改者:
 * 修改日期:
 * 传入参数:
 * 返回值:
 * 被调用的函数:AdcSample()
 * 调用的函数:
 **********************************************************************************/
void AdcResult(void)
{
	U8 i,j,Max,Min;
	U16	Total;
	
	if(u8AdcSampCnt < NUM_ADC_AVG)
	{
		u8AdcSampCnt++;
		return;
	}
	else	
	{
		u8AdcSampCnt = 0;
		
		for(i=0; i < NUM_ADC_CH; i++)
		{
			Max = 0;
			Min = 0xff;
			Total = 0;
			for(j = 0; j < NUM_ADC_AVG; j++)
			{
				if(u8AdcScanData[i][j] > Max)
				{
					Max = u8AdcScanData[i][j];
				}
				if(u8AdcScanData[i][j] < Min)
				{
					Min = u8AdcScanData[i][j];
				}			
				Total += (U16)u8AdcScanData[i][j];
			}
			mu8AdcVaule[i] = (U8)((Total - Max - Min) >> 3);
		}
	}

	/* --ADC_CH_T1--*/
	if (mu8SelfSenseSta != NO_SELF_SEN)
	{
		mu8TempT1 = mu8SelfSenseT1;
	}
	else if ((mu8AdcVaule[NUM_CH_T1] < AD_ERR_MIN) 
	 || (mu8AdcVaule[NUM_CH_T1] > AD_ERR_MAX))
	{
		#if (NOADERR_DEBUG == OFF)
		FG_ErrT1 = TRUE;
		mu8TempT1 = TMP_T1_ERR;
		#endif
	}
	else
	{
		FG_ErrT1 = FALSE;
		#if (NOT1T2_DEBUG == OFF)
		mu8TempT1 = u8Tab_ADPipeTemp[mu8AdcVaule[NUM_CH_T1]];
		#endif
	}

	
	/* --ADC_CH_T2--*/
	if ((mu8AdcVaule[NUM_CH_T2] < AD_ERR_MIN) 
	 || (mu8AdcVaule[NUM_CH_T2] > AD_ERR_MAX))
	{
		#if (NOADERR_DEBUG == OFF)
		FG_ErrT2 = TRUE;
		mu8TempT2 = TMP_T2_ERR;
		#endif
		
		if (FG_ErrT1 == FALSE)
		{
			if (mu8ModeRun == MOD_HEAT)
			{
				if (mu8TempT1 < TMP_T1A_HEAT)
				{
					mu8FreT2ErrArea = AREA_T2ERR_A;
				}
				else if (mu8TempT1 > TMP_T1B_HEAT)
				{
					mu8FreT2ErrArea = AREA_T2ERR_B;
				}
			}
			else
			{
				if (mu8TempT1 < TMP_T1A_COOL)
				{
					mu8FreT2ErrArea = AREA_T2ERR_A;
				}
				else if (mu8TempT1 > TMP_T1B_COOL)
				{
					mu8FreT2ErrArea = AREA_T2ERR_B;
				}
			}
		}
	}
	else
	{
		FG_ErrT2 = FALSE;
		#if (NOT1T2_DEBUG == OFF)
		mu8TempT2 = u8Tab_ADPipeTemp[mu8AdcVaule[NUM_CH_T2]];
		#endif
		mu8FreT2ErrArea = AREA_T2ERR_A;
	}

#if (NOOUT_DEBUG == OFF)
	if (FG_CommOK == TRUE)
	{
		/* --ADC_CH_T3--*/
		if ((mu8T3Ad < AD_ERR_MIN) 
		 || (mu8T3Ad > AD_ERR_MAX))
		{
			mu8TempT3 = GT(25);		/* 故障时默认为25℃ */
		}
		else
		{
			#if (NOT3T4_DEBUG == OFF)
			mu8TempT3 = u8Tab_ADPipeTemp[mu8T3Ad];
			#endif
		}

		/* --ADC_CH_T4--*/
		if ((mu8T4Ad < AD_ERR_MIN) 
		 || (mu8T4Ad > AD_ERR_MAX))
		{
			mu8TempT4 = GT(15);		/* 故障时默认为15℃ */
		}
		else
		{
			#if (NOT3T4_DEBUG == OFF)
			mu8TempT4 = u8Tab_ADPipeTemp[mu8T4Ad];
			#endif
		}

		/* --ADC_CH_Tp--*/
		if ((mu8TpAd < AD_ERR_MIN) 
		 || (mu8TpAd > AD_ERR_MAX))
		{
			mu8TempTp = 25; 		/* 故障时默认为25℃ */
		}
		else
		{
			mu8TempTp = ADTempTp_Tab[mu8TpAd];
		}
	}
#endif

}

