////-----------------------------------------UNCLASSIFIED-------------------------------------------
//// File: xcc_stack_utils.h
//// Desc: This is the header file for stack utilites.
//// Hist: When       Who  What
////       04/27/2001 ptb  Initial Code.
////       10/20/2025 ptb  Initial Code.
////------------------------------------------------------------------------------------------------
//// Preprocessor directives -----------------------------------------------------------------------
////------------------------------------------------------------------------------------------------
//#ifndef XCC_STACK_UTILS_H
//#define XCC_STACK_UTILS_H
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//// Include files ---------------------------------------------------------------------------------
////------------------------------------------------------------------------------------------------
//#include "xcc.h"
//#include "xcc_stack_utils.h"
//
//// Constants -------------------------------------------------------------------------------------
////------------------------------------------------------------------------------------------------
//#define XCC_STACK_NAME_LENGTH 64
//#define XCC_STACK_TYPE_LENGTH  8
//
//// Type defines ----------------------------------------------------------------------------------
////------------------------------------------------------------------------------------------------
//#define COMMON_STACK_ELEMENTS  CHR08 name[XCC_STACK_NAME_LENGTH]; \
//                               CHR08 type[XCC_STACK_TYPE_LENGTH]; \
//                               RXNT64 size;                       \
//                               RINT64 index;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS;
//  RFLT32 *theStack;
//} xccStackRFLT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RFLT64 *theStack;
//} xccStackRFLT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RINT08 *theStack;
//} xccStackRINT08_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RINT16 *theStack;
//} xccStackRINT16_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RINT32 *theStack;
//} xccStackRINT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RINT64 *theStack;
//} xccStackRINT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RXNT08 *theStack;
//} xccStackRXNT08_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RXNT16 *theStack;
//} xccStackRXNT16_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RXNT32 *theStack;
//} xccStackRXNT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  RXNT64 *theStack;
//} xccStackRXNT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VOID **theStack;
//} xccStackVOIDP_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRFLT32 *theStack;
//} xccStackCRFLT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRFLT64 *theStack;
//} xccStackCRFLT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRINT08 *theStack;
//} xccStackCRINT08_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRINT16 *theStack;
//} xccStackCRINT16_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRINT32 *theStack;
//} xccStackCRINT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRINT64 *theStack;
//} xccStackCRINT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRXNT08 *theStack;
//} xccStackCRXNT08_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRXNT16 *theStack;
//} xccStackCRXNT16_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRXNT32 *theStack;
//} xccStackCRXNT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  CRXNT64 *theStack;
//} xccStackCRXNT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRFLT32 *theStack;
//} xccStackVRFLT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRFLT64 *theStack;
//} xccStackVRFLT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRINT08 *theStack;
//} xccStackVRINT08_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRINT16 *theStack;
//} xccStackVRINT16_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRINT32 *theStack;
//} xccStackVRINT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRINT64 *theStack;
//} xccStackVRINT64_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRXNT08 *theStack;
//} xccStackVRXNT08_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRXNT16 *theStack;
//} xccStackVRXNT16_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRXNT32 *theStack;
//} xccStackVRXNT32_t;
//
//typedef struct
//{
//  COMMON_STACK_ELEMENTS
//  VRXNT64 *theStack;
//} xccStackVRXNT64_t;
//
//// Macros ----------------------------------------------------------------------------------------
////------------------------------------------------------------------------------------------------
//// Prototypes ------------------------------------------------------------------------------------
////------------------------------------------------------------------------------------------------
//
///* xccStackFull -------------------------------------------------------------*/
//RINT32 xccStackFullRFLT32 ( xccStackRFLT32_t  *p2Stack );
//RINT32 xccStackFullRFLT64 ( xccStackRFLT64_t  *p2Stack );
//RINT32 xccStackFullRINT08 ( xccStackRINT08_t  *p2Stack );
//RINT32 xccStackFullRINT16 ( xccStackRINT16_t  *p2Stack );
//RINT32 xccStackFullRINT32 ( xccStackRINT32_t  *p2Stack );
//RINT32 xccStackFullRINT64 ( xccStackRINT64_t  *p2Stack );
//RINT32 xccStackFullRXNT08 ( xccStackRXNT08_t  *p2Stack );
//RINT32 xccStackFullRXNT16 ( xccStackRXNT16_t  *p2Stack );
//RINT32 xccStackFullRXNT32 ( xccStackRXNT32_t  *p2Stack );
//RINT32 xccStackFullRXNT64 ( xccStackRXNT64_t  *p2Stack );
//RINT32 xccStackFullCRFLT32( xccStackCRFLT32_t *p2Stack );
//RINT32 xccStackFullCRFLT64( xccStackCRFLT64_t *p2Stack );
//RINT32 xccStackFullCRINT08( xccStackCRINT08_t *p2Stack );
//RINT32 xccStackFullCRINT16( xccStackCRINT16_t *p2Stack );
//RINT32 xccStackFullCRINT32( xccStackCRINT32_t *p2Stack );
//RINT32 xccStackFullCRINT64( xccStackCRINT64_t *p2Stack );
//RINT32 xccStackFullCRXNT08( xccStackCRXNT08_t *p2Stack );
//RINT32 xccStackFullCRXNT16( xccStackCRXNT16_t *p2Stack );
//RINT32 xccStackFullCRXNT32( xccStackCRXNT32_t *p2Stack );
//RINT32 xccStackFullCRXNT64( xccStackCRXNT64_t *p2Stack );
//RINT32 xccStackFullVRFLT32( xccStackVRFLT32_t *p2Stack );
//RINT32 xccStackFullVRFLT64( xccStackVRFLT64_t *p2Stack );
//RINT32 xccStackFullVRINT08( xccStackVRINT08_t *p2Stack );
//RINT32 xccStackFullVRINT16( xccStackVRINT16_t *p2Stack );
//RINT32 xccStackFullVRINT32( xccStackVRINT32_t *p2Stack );
//RINT32 xccStackFullVRINT64( xccStackVRINT64_t *p2Stack );
//RINT32 xccStackFullVRXNT08( xccStackVRXNT08_t *p2Stack );
//RINT32 xccStackFullVRXNT16( xccStackVRXNT16_t *p2Stack );
//RINT32 xccStackFullVRXNT32( xccStackVRXNT32_t *p2Stack );
//RINT32 xccStackFullVRXNT64( xccStackVRXNT64_t *p2Stack );
//RINT32 xccStackFullVOIDP ( xccStackVOIDP_t  *p2Stack );
//RINT32 xccStringStackFull( xccStackVOIDP_t  *p2Stack );
//
///* xccStackClear ----------------------------------------------------------------*/
//VOID  xccStackClearRFLT32( xccStackRFLT32_t *p );
//VOID  xccStackClearRFLT64( xccStackRFLT64_t *p );
//VOID  xccStackClearRINT08( xccStackRINT08_t *p );
//VOID  xccStackClearRINT16( xccStackRINT16_t *p );
//VOID  xccStackClearRINT32( xccStackRINT32_t *p );
//VOID  xccStackClearRINT64( xccStackRINT64_t *p );
//VOID  xccStackClearRXNT08( xccStackRXNT08_t *p );
//VOID  xccStackClearRXNT16( xccStackRXNT16_t *p );
//VOID  xccStackClearRXNT32( xccStackRXNT32_t *p );
//VOID  xccStackClearRXNT64( xccStackRXNT64_t *p );
//VOID  xccStackClearVOIDP( xccStackVOIDP_t *p );
//
///* xccStackCompare --------------------------------------------------------------*/
//RINT32 xccStackCompareRFLT32 ( xccStackRFLT32_t *p2Src, xccStackRFLT32_t *p2Des );
//RINT32 xccStackCompareRFLT64 ( xccStackRFLT64_t *p2Src, xccStackRFLT64_t *p2Des );
//RINT32 xccStackCompareRINT08 ( xccStackRINT08_t *p2Src, xccStackRINT08_t *p2Des );
//RINT32 xccStackCompareRINT16 ( xccStackRINT16_t *p2Src, xccStackRINT16_t *p2Des );
//RINT32 xccStackCompareRINT32 ( xccStackRINT32_t *p2Src, xccStackRINT32_t *p2Des );
//RINT32 xccStackCompareRINT64 ( xccStackRINT64_t *p2Src, xccStackRINT64_t *p2Des );
//RINT32 xccStackCompareRXNT08 ( xccStackRXNT08_t *p2Src, xccStackRXNT08_t *p2Des );
//RINT32 xccStackCompareRXNT16 ( xccStackRXNT16_t *p2Src, xccStackRXNT16_t *p2Des );
//RINT32 xccStackCompareRXNT32 ( xccStackRXNT32_t *p2Src, xccStackRXNT32_t *p2Des );
//RINT32 xccStackCompareRXNT64 ( xccStackRXNT64_t *p2Src, xccStackRXNT64_t *p2Des );
//RINT32 xccStackCompareVOIDP ( xccStackVOIDP_t *p2Src, xccStackVOIDP_t *p2Des );
//
///* xccStackCopy -----------------------------------------------------------------*/
//RINT32 xccStackCopyRFLT32 ( xccStackRFLT32_t *p2Src, xccStackRFLT32_t *p2Des );
//RINT32 xccStackCopyRFLT64 ( xccStackRFLT64_t *p2Src, xccStackRFLT64_t *p2Des );
//RINT32 xccStackCopyRINT08 ( xccStackRINT08_t *p2Src, xccStackRINT08_t *p2Des );
//RINT32 xccStackCopyRINT16 ( xccStackRINT16_t *p2Src, xccStackRINT16_t *p2Des );
//RINT32 xccStackCopyRINT32 ( xccStackRINT32_t *p2Src, xccStackRINT32_t *p2Des );
//RINT32 xccStackCopyRINT64 ( xccStackRINT64_t *p2Src, xccStackRINT64_t *p2Des );
//RINT32 xccStackCopyRXNT08 ( xccStackRXNT08_t *p2Src, xccStackRXNT08_t *p2Des );
//RINT32 xccStackCopyRXNT16 ( xccStackRXNT16_t *p2Src, xccStackRXNT16_t *p2Des );
//RINT32 xccStackCopyRXNT32 ( xccStackRXNT32_t *p2Src, xccStackRXNT32_t *p2Des );
//RINT32 xccStackCopyRXNT64 ( xccStackRXNT64_t *p2Src, xccStackRXNT64_t *p2Des );
//RINT32 xccStackCopyVOIDP ( xccStackVOIDP_t *p2Src, xccStackVOIDP_t *p2Des );
//
///* xccStackFlip -----------------------------------------------------------------*/
//RINT32 xccStackFlipRFLT32( xccStackRFLT32_t *p );
//RINT32 xccStackFlipRFLT64( xccStackRFLT64_t *p );
//RINT32 xccStackFlipRINT08( xccStackRINT08_t *p );
//RINT32 xccStackFlipRINT16( xccStackRINT16_t *p );
//RINT32 xccStackFlipRINT32( xccStackRINT32_t *p );
//RINT32 xccStackFlipRINT64( xccStackRINT64_t *p );
//RINT32 xccStackFlipRXNT08( xccStackRXNT08_t *p );
//RINT32 xccStackFlipRXNT16( xccStackRXNT16_t *p );
//RINT32 xccStackFlipRXNT32( xccStackRXNT32_t *p );
//RINT32 xccStackFlipRXNT64( xccStackRXNT64_t *p );
//RINT32 xccStackFlipVOIDP( xccStackVOIDP_t *p );
//RINT32 xccStackFlipCRFLT32( xccStackCRFLT32_t *p2Stack );
//RINT32 xccStackFlipCRFLT64( xccStackCRFLT64_t *p2Stack );
//RINT32 xccStackFlipCRINT08( xccStackCRINT08_t *p2Stack );
//RINT32 xccStackFlipCRINT16( xccStackCRINT16_t *p2Stack );
//RINT32 xccStackFlipCRINT32( xccStackCRINT32_t *p2Stack );
//RINT32 xccStackFlipCRINT64( xccStackCRINT64_t *p2Stack );
//RINT32 xccStackFlipCRXNT08( xccStackCRXNT08_t *p2Stack );
//RINT32 xccStackFlipCRXNT16( xccStackCRXNT16_t *p2Stack );
//RINT32 xccStackFlipCRXNT32( xccStackCRXNT32_t *p2Stack );
//RINT32 xccStackFlipCRXNT64( xccStackCRXNT64_t *p2Stack );
//RINT32 xccStackFlipVRFLT32( xccStackVRFLT32_t *p2Stack );
//RINT32 xccStackFlipVRFLT64( xccStackVRFLT64_t *p2Stack );
//RINT32 xccStackFlipVRINT08( xccStackVRINT08_t *p2Stack );
//RINT32 xccStackFlipVRINT16( xccStackVRINT16_t *p2Stack );
//RINT32 xccStackFlipVRINT32( xccStackVRINT32_t *p2Stack );
//RINT32 xccStackFlipVRINT64( xccStackVRINT64_t *p2Stack );
//RINT32 xccStackFlipVRXNT08( xccStackVRXNT08_t *p2Stack );
//RINT32 xccStackFlipVRXNT16( xccStackVRXNT16_t *p2Stack );
//RINT32 xccStackFlipVRXNT32( xccStackVRXNT32_t *p2Stack );
//RINT32 xccStackFlipVRXNT64( xccStackVRXNT64_t *p2Stack );
//
///* xccStackInit -----------------------------------------------------------------*/
//xccStackRFLT32_t  *xccStackInitRFLT32 (RXNT64 size, CCHAR *name);
//xccStackRFLT64_t  *xccStackInitRFLT64 (RXNT64 size, CCHAR *name);
//xccStackRINT08_t  *xccStackInitRINT08 (RXNT64 size, CCHAR *name);
//xccStackRINT16_t  *xccStackInitRINT16 (RXNT64 size, CCHAR *name);
//xccStackRINT32_t  *xccStackInitRINT32 (RXNT64 size, CCHAR *name);
//xccStackRINT64_t  *xccStackInitRINT64 (RXNT64 size, CCHAR *name);
//xccStackRXNT08_t  *xccStackInitRXNT08 (RXNT64 size, CCHAR *name);
//xccStackRXNT16_t  *xccStackInitRXNT16 (RXNT64 size, CCHAR *name);
//xccStackRXNT32_t  *xccStackInitRXNT32 (RXNT64 size, CCHAR *name);
//xccStackRXNT64_t  *xccStackInitRXNT64 (RXNT64 size, CCHAR *name);
//xccStackVOIDP_t  *xccStackInitVOIDP (RXNT64 size, CCHAR *name);
//xccStackCRFLT32_t *xccStackInitCRFLT32(RXNT64 size, CCHAR *name);
//xccStackCRFLT64_t *xccStackInitCRFLT64(RXNT64 size, CCHAR *name);
//xccStackCRINT08_t *xccStackInitCRINT08(RXNT64 size, CCHAR *name);
//xccStackCRINT16_t *xccStackInitCRINT16(RXNT64 size, CCHAR *name);
//xccStackCRINT32_t *xccStackInitCRINT32(RXNT64 size, CCHAR *name);
//xccStackCRINT64_t *xccStackInitCRINT64(RXNT64 size, CCHAR *name);
//xccStackCRXNT08_t *xccStackInitCRXNT08(RXNT64 size, CCHAR *name);
//xccStackCRXNT16_t *xccStackInitCRXNT16(RXNT64 size, CCHAR *name);
//xccStackCRXNT32_t *xccStackInitCRXNT32(RXNT64 size, CCHAR *name);
//xccStackCRXNT64_t *xccStackInitCRXNT64(RXNT64 size, CCHAR *name);
//xccStackVRFLT32_t *xccStackInitVRFLT32(RXNT64 size, CCHAR *name);
//xccStackVRFLT64_t *xccStackInitVRFLT64(RXNT64 size, CCHAR *name);
//xccStackVRINT08_t *xccStackInitVRINT08(RXNT64 size, CCHAR *name);
//xccStackVRINT16_t *xccStackInitVRINT16(RXNT64 size, CCHAR *name);
//xccStackVRINT32_t *xccStackInitVRINT32(RXNT64 size, CCHAR *name);
//xccStackVRINT64_t *xccStackInitVRINT64(RXNT64 size, CCHAR *name);
//xccStackVRXNT08_t *xccStackInitVRXNT08(RXNT64 size, CCHAR *name);
//xccStackVRXNT16_t *xccStackInitVRXNT16(RXNT64 size, CCHAR *name);
//xccStackVRXNT32_t *xccStackInitVRXNT32(RXNT64 size, CCHAR *name);
//xccStackVRXNT64_t *xccStackInitVRXNT64(RXNT64 size, CCHAR *name);
//
///* xccStackPop ------------------------------------------------------------------*/
//RINT32 xccStackPopRFLT32  ( xccStackRFLT32_t *p, RFLT32 *value );
//RINT32 xccStackPopRFLT64  ( xccStackRFLT64_t *p, RFLT64 *value );
//RINT32 xccStackPopRINT08  ( xccStackRINT08_t *p, RINT08 *value );
//RINT32 xccStackPopRINT16  ( xccStackRINT16_t *p, RINT16 *value );
//RINT32 xccStackPopRINT32  ( xccStackRINT32_t *p, RINT32 *value );
//RINT32 xccStackPopRINT64  ( xccStackRINT64_t *p, RINT64 *value );
//RINT32 xccStackPopRXNT08  ( xccStackRXNT08_t *p, RXNT08 *value );
//RINT32 xccStackPopRXNT16  ( xccStackRXNT16_t *p, RXNT16 *value );
//RINT32 xccStackPopRXNT32  ( xccStackRXNT32_t *p, RXNT32 *value );
//RINT32 xccStackPopRXNT64  ( xccStackRXNT64_t *p, RXNT64 *value );
//RINT32 xccStackPopCRFLT32( xccStackCRFLT32_t *p2Stack, CRFLT32 *p2value );
//RINT32 xccStackPopCRFLT64( xccStackCRFLT64_t *p2Stack, CRFLT64 *p2value );
//RINT32 xccStackPopCRINT08( xccStackCRINT08_t *p2Stack, CRINT08 *p2value );
//RINT32 xccStackPopCRINT16( xccStackCRINT16_t *p2Stack, CRINT16 *p2value );
//RINT32 xccStackPopCRINT32( xccStackCRINT32_t *p2Stack, CRINT32 *p2value );
//RINT32 xccStackPopCRINT64( xccStackCRINT64_t *p2Stack, CRINT64 *p2value );
//RINT32 xccStackPopCRXNT08( xccStackCRXNT08_t *p2Stack, CRXNT08 *p2value );
//RINT32 xccStackPopCRXNT16( xccStackCRXNT16_t *p2Stack, CRXNT16 *p2value );
//RINT32 xccStackPopCRXNT32( xccStackCRXNT32_t *p2Stack, CRXNT32 *p2value );
//RINT32 xccStackPopCRXNT64( xccStackCRXNT64_t *p2Stack, CRXNT64 *p2value );
//RINT32 xccStackPopVRFLT32( xccStackVRFLT32_t *p2Stack, VRFLT32 *p2value );
//RINT32 xccStackPopVRFLT64( xccStackVRFLT64_t *p2Stack, VRFLT64 *p2value );
//RINT32 xccStackPopVRINT08( xccStackVRINT08_t *p2Stack, VRINT08 *p2value );
//RINT32 xccStackPopVRINT16( xccStackVRINT16_t *p2Stack, VRINT16 *p2value );
//RINT32 xccStackPopVRINT32( xccStackVRINT32_t *p2Stack, VRINT32 *p2value );
//RINT32 xccStackPopVRINT64( xccStackVRINT64_t *p2Stack, VRINT64 *p2value );
//RINT32 xccStackPopVRXNT08( xccStackVRXNT08_t *p2Stack, VRXNT08 *p2value );
//RINT32 xccStackPopVRXNT16( xccStackVRXNT16_t *p2Stack, VRXNT16 *p2value );
//RINT32 xccStackPopVRXNT32( xccStackVRXNT32_t *p2Stack, VRXNT32 *p2value );
//RINT32 xccStackPopVRXNT64( xccStackVRXNT64_t *p2Stack, VRXNT64 *p2value );
//RINT32 xccStackPopVOIDP  ( xccStackVOIDP_t *p, VOID **value );
//RINT32 xccStringStackPop( xccStackVOIDP_t *p2Stack, CHR08 **stringPointer );
//
///* xccStackPush -----------------------------------------------------------------*/
//RINT32 xccStackPushRFLT32 ( xccStackRFLT32_t *p, RFLT32  value );
//RINT32 xccStackPushRFLT64 ( xccStackRFLT64_t *p, RFLT64  value );
//RINT32 xccStackPushRINT08 ( xccStackRINT08_t *p, RINT08  value );
//RINT32 xccStackPushRINT16 ( xccStackRINT16_t *p, RINT16  value );
//RINT32 xccStackPushRINT32 ( xccStackRINT32_t *p, RINT32  value );
//RINT32 xccStackPushRINT64 ( xccStackRINT64_t *p, RINT64  value );
//RINT32 xccStackPushRXNT08 ( xccStackRXNT08_t *p, RXNT08  value );
//RINT32 xccStackPushRXNT16 ( xccStackRXNT16_t *p, RXNT16  value );
//RINT32 xccStackPushRXNT32 ( xccStackRXNT32_t *p, RXNT32  value );
//RINT32 xccStackPushRXNT64 ( xccStackRXNT64_t *p, RXNT64  value );
//RINT32 xccStackPushCRFLT32( xccStackCRFLT32_t *p2Stack, CRFLT32 value );
//RINT32 xccStackPushCRFLT64( xccStackCRFLT64_t *p2Stack, CRFLT64 value );
//RINT32 xccStackPushCRINT08( xccStackCRINT08_t *p2Stack, CRINT08 value );
//RINT32 xccStackPushCRINT16( xccStackCRINT16_t *p2Stack, CRINT16 value );
//RINT32 xccStackPushCRINT32( xccStackCRINT32_t *p2Stack, CRINT32 value );
//RINT32 xccStackPushCRINT64( xccStackCRINT64_t *p2Stack, CRINT64 value );
//RINT32 xccStackPushCRXNT08( xccStackCRXNT08_t *p2Stack, CRXNT08 value );
//RINT32 xccStackPushCRXNT16( xccStackCRXNT16_t *p2Stack, CRXNT16 value );
//RINT32 xccStackPushCRXNT32( xccStackCRXNT32_t *p2Stack, CRXNT32 value );
//RINT32 xccStackPushCRXNT64( xccStackCRXNT64_t *p2Stack, CRXNT64 value );
//RINT32 xccStackPushVRFLT32( xccStackVRFLT32_t *p2Stack, VRFLT32 value );
//RINT32 xccStackPushVRFLT64( xccStackVRFLT64_t *p2Stack, VRFLT64 value );
//RINT32 xccStackPushVRINT08( xccStackVRINT08_t *p2Stack, VRINT08 value );
//RINT32 xccStackPushVRINT16( xccStackVRINT16_t *p2Stack, VRINT16 value );
//RINT32 xccStackPushVRINT32( xccStackVRINT32_t *p2Stack, VRINT32 value );
//RINT32 xccStackPushVRINT64( xccStackVRINT64_t *p2Stack, VRINT64 value );
//RINT32 xccStackPushVRXNT08( xccStackVRXNT08_t *p2Stack, VRXNT08 value );
//RINT32 xccStackPushVRXNT16( xccStackVRXNT16_t *p2Stack, VRXNT16 value );
//RINT32 xccStackPushVRXNT32( xccStackVRXNT32_t *p2Stack, VRXNT32 value );
//RINT32 xccStackPushVRXNT64( xccStackVRXNT64_t *p2Stack, VRXNT64 value );
//RINT32 xccStackPushVOIDP ( xccStackVOIDP_t *p, VOID  *value );
//RINT32 xccStringStackPush( xccStackVOIDP_t *p, const CHR08 *string );
//RINT32 xccStringStackSearch( xccStackVOIDP_t *p, const CHR08 *stringToLookFor );
//
///* xccStackSort -----------------------------------------------------------------*/
//VOID xccStackSortRFLT32 ( xccStackRFLT32_t  *p2Stack );
//VOID xccStackSortRFLT64 ( xccStackRFLT64_t  *p2Stack );
//VOID xccStackSortRINT08 ( xccStackRINT08_t  *p2Stack );
//VOID xccStackSortRINT16 ( xccStackRINT16_t  *p2Stack );
//VOID xccStackSortRINT32 ( xccStackRINT32_t  *p2Stack );
//VOID xccStackSortRINT64 ( xccStackRINT64_t  *p2Stack );
//VOID xccStackSortRXNT08 ( xccStackRXNT08_t  *p2Stack );
//VOID xccStackSortRXNT16 ( xccStackRXNT16_t  *p2Stack );
//VOID xccStackSortRXNT32 ( xccStackRXNT32_t  *p2Stack );
//VOID xccStackSortRXNT64 ( xccStackRXNT64_t  *p2Stack );
//VOID xccStackSortCRFLT32( xccStackCRFLT32_t *p2Stack );
//VOID xccStackSortCRFLT64( xccStackCRFLT64_t *p2Stack );
//VOID xccStackSortCRINT08( xccStackCRINT08_t *p2Stack );
//VOID xccStackSortCRINT16( xccStackCRINT16_t *p2Stack );
//VOID xccStackSortCRINT32( xccStackCRINT32_t *p2Stack );
//VOID xccStackSortCRINT64( xccStackCRINT64_t *p2Stack );
//VOID xccStackSortCRXNT08( xccStackCRXNT08_t *p2Stack );
//VOID xccStackSortCRXNT16( xccStackCRXNT16_t *p2Stack );
//VOID xccStackSortCRXNT32( xccStackCRXNT32_t *p2Stack );
//VOID xccStackSortCRXNT64( xccStackCRXNT64_t *p2Stack );
//VOID xccStackSortVRFLT32( xccStackVRFLT32_t *p2Stack );
//VOID xccStackSortVRFLT64( xccStackVRFLT64_t *p2Stack );
//VOID xccStackSortVRINT08( xccStackVRINT08_t *p2Stack );
//VOID xccStackSortVRINT16( xccStackVRINT16_t *p2Stack );
//VOID xccStackSortVRINT32( xccStackVRINT32_t *p2Stack );
//VOID xccStackSortVRINT64( xccStackVRINT64_t *p2Stack );
//VOID xccStackSortVRXNT08( xccStackVRXNT08_t *p2Stack );
//VOID xccStackSortVRXNT16( xccStackVRXNT16_t *p2Stack );
//VOID xccStackSortVRXNT32( xccStackVRXNT32_t *p2Stack );
//VOID xccStackSortVRXNT64( xccStackVRXNT64_t *p2Stack );
//VOID xccStringStackSort( xccStackVOIDP_t  *p2Stack );
//
///* xccStackTop ------------------------------------------------------------------*/
//RFLT32  xccStackTopRFLT32( xccStackRFLT32_t *p );
//RFLT64  xccStackTopRFLT64( xccStackRFLT64_t *p );
//RINT08  xccStackTopRINT08( xccStackRINT08_t *p );
//RINT16  xccStackTopRINT16( xccStackRINT16_t *p );
//RINT32  xccStackTopRINT32( xccStackRINT32_t *p );
//RINT64  xccStackTopRINT64( xccStackRINT64_t *p );
//RXNT08  xccStackTopRXNT08( xccStackRXNT08_t *p );
//RXNT16  xccStackTopRXNT16( xccStackRXNT16_t *p );
//RXNT32  xccStackTopRXNT32( xccStackRXNT32_t *p );
//RXNT64  xccStackTopRXNT64( xccStackRXNT64_t *p );
//VOID  *xccStackTopVOIDP( xccStackVOIDP_t *p );
//
///* xccStackTerm -----------------------------------------------------------------*/
//VOID  xccStackTermRFLT32( xccStackRFLT32_t *p );
//VOID  xccStackTermRFLT64( xccStackRFLT64_t *p );
//VOID  xccStackTermRINT08( xccStackRINT08_t *p );
//VOID  xccStackTermRINT16( xccStackRINT16_t *p );
//VOID  xccStackTermRINT32( xccStackRINT32_t *p );
//VOID  xccStackTermRINT64( xccStackRINT64_t *p );
//VOID  xccStackTermRXNT08( xccStackRXNT08_t *p );
//VOID  xccStackTermRXNT16( xccStackRXNT16_t *p );
//VOID  xccStackTermRXNT32( xccStackRXNT32_t *p );
//VOID  xccStackTermRXNT64( xccStackRXNT64_t *p );
//VOID  xccStackTermVOIDP( xccStackVOIDP_t *p );
//VOID xccStackTermCRFLT32(xccStackCRFLT32_t *p2WS);
//VOID xccStackTermCRFLT64(xccStackCRFLT64_t *p2WS);
//VOID xccStackTermCRINT08(xccStackCRINT08_t *p2WS);
//VOID xccStackTermCRINT16(xccStackCRINT16_t *p2WS);
//VOID xccStackTermCRINT32(xccStackCRINT32_t *p2WS);
//VOID xccStackTermCRINT64(xccStackCRINT64_t *p2WS);
//VOID xccStackTermCRXNT08(xccStackCRXNT08_t *p2WS);
//VOID xccStackTermCRXNT16(xccStackCRXNT16_t *p2WS);
//VOID xccStackTermCRXNT32(xccStackCRXNT32_t *p2WS);
//VOID xccStackTermCRXNT64(xccStackCRXNT64_t *p2WS);
//VOID xccStackTermVRFLT32(xccStackVRFLT32_t *p2WS);
//VOID xccStackTermVRFLT64(xccStackVRFLT64_t *p2WS);
//VOID xccStackTermVRINT08(xccStackVRINT08_t *p2WS);
//VOID xccStackTermVRINT16(xccStackVRINT16_t *p2WS);
//VOID xccStackTermVRINT32(xccStackVRINT32_t *p2WS);
//VOID xccStackTermVRINT64(xccStackVRINT64_t *p2WS);
//VOID xccStackTermVRXNT08(xccStackVRXNT08_t *p2WS);
//VOID xccStackTermVRXNT16(xccStackVRXNT16_t *p2WS);
//VOID xccStackTermVRXNT32(xccStackVRXNT32_t *p2WS);
//VOID xccStackTermVRXNT64(xccStackVRXNT64_t *p2WS);
//
//// Packing routines ------------------------------------------------------------------------------
//RINT32 xccCHR08UnpackMSB_RINT08( xccStackRINT08_t *p, RINT08 c );
//RINT32 xccCHR08UnpackLSB_RINT08( xccStackRINT08_t *p, RINT08 c );
//RINT32 xccCHR08PackMSB_RINT08(   xccStackRINT08_t *p, RINT08 *c);
//RINT32 xccCHR08PackLSB_RINT08(   xccStackRINT08_t *p, RINT08 *c);
//
//// End preprocessor directives -------------------------------------------------------------------
////------------------------------------------------------------------------------------------------
//#ifdef __cplusplus
//}
//#endif
//
//#endif
///*-------------------------------UNCLASSIFIED---------------------------------*/
