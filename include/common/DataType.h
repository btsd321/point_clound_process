//***************************************************
//*******Copyright (C),2019-2099,btsd.Co.,Ltd*******
//*
//*	文件名			：	DateType.h
//*	文件功能		：	btsd标准化的数据类型
//*	编程者			：	XinlongLi
//*	日期			：	2024.05.13
//*	编号---作者---------日期----注释
//*	00	XinlongLi	2024.05.13	创建
//*	说明：这个文件不准改
//***************************************************
#ifndef _DATA_TYPE_DEF_H_
#define _DATA_TYPE_DEF_H_

#ifdef __cplusplus
namespace btsd {

	extern "C" {
#endif

#ifndef VOID
#define VOID void
#endif


#ifndef UCHAR
        typedef unsigned char UCHAR;
#endif

#ifndef UINT8
        typedef unsigned char UINT8;
#endif

#ifndef INT8U
        typedef unsigned char INT8U;
#endif

#ifndef INT8
        typedef signed char INT8;
#endif

#ifndef UINT16
        typedef unsigned short UINT16;
#endif

#ifndef INT16U
        typedef unsigned short INT16U;
#endif

#ifndef INT16
        typedef signed short INT16;
#endif

#ifndef UINT32
        typedef unsigned int UINT32;
#endif

#ifndef INT32U
        typedef unsigned int INT32U;
#endif

#ifndef INT32
        typedef signed int INT32;
#endif

#ifndef INT
        typedef signed int INT;
#endif

#ifndef UINT
        typedef unsigned int UINT;
#endif

#ifndef UINT64
#if !defined(WIN32)
		typedef unsigned long long JUINT64;
#else
        typedef unsigned __int64 UINT64;
#endif
#endif

#ifndef INT64U
#if !defined(WIN32)
        typedef unsigned long long INT64U;
#else
        typedef unsigned __int64 INT64U;
#endif
#endif

#ifndef INT64
#if !defined(WIN32)
		typedef signed long long INT64;
#else
        typedef signed __int64 INT64;
#endif
#endif

#ifndef FLOAT32
        typedef float FLOAT32;
#endif

#ifndef FLOAT64
        typedef double FLOAT64;
#endif

#ifndef BOOL
#define BOOL	bool
#endif

#ifndef FILE
#define FILE int
#endif

#ifndef FALSE
#define FALSE (0U)
#endif

#ifndef NULL
#ifdef __cplusplus
#define	NULL nullptr
#else
#define	NULL ((void *)0)
#endif
#endif

#ifndef TRUE
#define TRUE (1U)
#endif

#ifndef WIN32
#define _PACKED __attribute__((packed))
#endif

#ifndef DIS
#define DIS (0U)
#endif

#ifndef ENA
#define ENA (0U)
#endif

#ifndef HDL_INVALIA
#define HDL_INVALIA ((INT)(-1))
#endif

#ifndef EOF
#define EOF ((INT)(-1))
#endif

#ifndef EM_COM_FD_REAL
#define EM_COM_FD_REAL ((FILE *)(-2))
#endif

#ifndef EM_VCOM_FD_REAL
#define EM_VCOM_FD_REAL ((FILE *)(-3))
#endif

		//常用函数定义
#ifndef SHIFT_BIT
#define SHIFT_BIT(x)	((UINT32)(1Ul<<(x)))
#endif

#ifndef ADD_ONE
#define ADD_ONE(Type, Val)	if((Type)((Val) + 1) > 0) {Val++;}
#endif

#ifndef DEC_ONE
#define DEC_ONE(Type, Val)	if((Type)((Val) - 1) > 0) {Val--;}
#endif

#ifndef ADD_N
#define ADD_N(Type, Val, n)	if((Type)((Val) + (n) > 0) {Val += (n);}
#endif

#ifndef DEC_N
#define DEC_N(Type, Val, n)	if((Type)((Val) - (n) > 0) {Val -= (n);}
#endif

#ifndef ABS
#define ABS(x)	(((x) > 0) ? (x) : (-(x)))
#endif

//浮点比较函数
#ifndef EPS
#define EPS 0.000001f
#endif

#ifndef FLOAT_EQU
#define FLOAT_EQU(x, y)	(ABS((x) - (y)) < EPS)
#endif

#ifndef FLOAT_MORE
#define FLOAT_MORE(x, y)	(((FLOAT32)(x) - (FLOAT32)(y)) > EPS)
#endif

#ifndef FLOAT_MOREEQU
#define FLOAT_MOREEQU(x, y)		(((FLOAT32)(x) - (FLOAT32)(y)) > -EPS)
#endif

#ifndef FLOAT_LESS
#define FLOAT_LESS(x, y)		(((FLOAT32)(x) - (FLOAT32)(y)) < -EPS)
#endif

#ifndef FLOAT_LESSEQU
#define FLOAT_LESSEQU(x, y)		(((FLOAT32)(x) - (FLOAT32)(y)) < EPS)
#endif

#ifdef __cplusplus
	}
}
#endif

#endif
