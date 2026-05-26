/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xcc_debug.h
// Desc: This file contains some macros to use for debugging messages.
// Hist: When       Who  What
//       10/15/2006 ptb  Initial Port.                                                          -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef XCC_DEBUG_H
#define XCC_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define XCC_CURRENT_ASCII_TIME( timeString, format)        \
{                                                          \
  time_t getTime;                                          \
  struct tm *p2tm;                                         \
  getTime = time(NULL);                                    \
  p2tm = gmtime(&getTime);                                 \
  strftime(timeString, strlen(timeString), format, p2tm);  \
}

#define XCC_DEBUG_STDOUT(format, args...)                  \
{                                                          \
  CHR08 timStrng[32];                                      \
  memset(timStrng, 90, 32);                                \
  XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
  fprintf(stdout, "%s: ", __FILE__);                       \
  fprintf(stdout, "%s: ", timStrng);                       \
  fprintf(stdout, format, ##args);                         \
}

#define XCC_DEBUG_STDERR(format, args...)                  \
{                                                          \
  CHR08 timStrng[32];                                      \
  memset(timStrng, 90, 32);                                \
  XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
  fprintf(stderr, "%s: ", __FILE__);                       \
  fprintf(stderr, "%s: ", timStrng);                       \
  fprintf(stderr, format, ##args);                         \
}

#define XCC_DEBUG_LOGFILE(format, args...)                 \
{                                                          \
  FILE *dbfid;                                             \
  char fileName[128];                                      \
  CHR08 timStrng[32];                                      \
  memset(timStrng, 90, 32);                                \
  XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
  sprintf(fileName,"%s.log",__FILE__);                     \
  dbfid = fopen(fileName, "a");		                         \
  fprintf(dbfid, "%s: ", __FILE__);                        \
  fprintf(dbfid, "%s: ", timStrng);                        \
  fprintf(dbfid, format, ##args);                          \
  fclose(dbfid);                                           \
}

#define XCC_ERROR_STDOUT(format, args...)                  \
{                                                          \
  CHR08 timStrng[32];                                      \
  memset(timStrng, 90, 32);                                \
  XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
  fprintf(stdout,"*************************************************************************\n");\
  fprintf(stdout,"** ERROR                                                                 \n");\
  fprintf(stdout,"*************************************************************************\n");\
  fprintf(stdout, "%s: ", __FILE__);                       \
  fprintf(stdout, "%s: ", timStrng);                       \
  fprintf(stdout, format, ##args);                         \
}

#define XCC_ERROR_STDERR(format, args...)                  \
{                                                          \
  CHR08 timStrng[32];                                      \
  memset(timStrng, 90, 32);                                \
  XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
  fprintf(stderr,"*************************************************************************\n");\
  fprintf(stderr,"** ERROR                                                                 \n");\
  fprintf(stderr,"*************************************************************************\n");\
  fprintf(stderr, "%s: ", __FILE__);                       \
  fprintf(stderr, "%s: ", timStrng);                       \
  fprintf(stderr, format, ##args);                         \
}

#define XCC_ERROR_LOGFILE(format, args...)                 \
{                                                          \
  FILE *dbfid;                                             \
  char fileName[128];                                      \
  CHR08 timStrng[32];                                      \
  memset(timStrng, 90, 32);                                \
  XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
  sprintf(fileName,"%s.log",__FILE__);                     \
  dbfid = fopen(fileName, "a");		                   \
  fprintf(dbfid,"************************************************************************\n");\
  fprintf(dbfid,"** ERROR                                                                \n");\
  fprintf(dbfid,"************************************************************************\n");\
  fprintf(dbfid, "%s: ", __FILE__);                        \
  fprintf(dbfid, "%s: ", timStrng);                        \
  fprintf(dbfid, format, ##args);                          \
  fclose(dbfid);                                           \
}


// #define XCC_DEBUG_DATAGRAM(format, args...)                \
// {                                                          \
//   INT32 msgii=0;                                           \
//   CHR08 msg[1024];                                         \
//   CHR08 timStrng[32];                                      \
//   XCCDatagramSocketSpec *spec;                             \
//                                                            \
//   memset(timStrng, 90, 32);                                \
//   XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
//   sprintf(&msg[msgii], "%s: ", __FILE__);                  \
//   msgii = strlen(msg);                                     \
//   sprintf(&msg[msgii], "%s: ", timStrng);                  \
//   msgii = strlen(msg);                                     \
//   sprintf(&msg[msgii], format, ##args);                    \
//   msgii = strlen(msg);                                     \
//                                                            \
//   spec = iccDatagramSocketSendInit(DEBUG_HOST, DEBUG_PORT);\
//   iccDatagramSocketSend(msg,msgii,spec);                   \
//   iccDatagramSocketTerm( spec );                           \
// }

// #define XCC_ERROR_DATAGRAM(format, args...)                \
// {                                                          \
//   INT32 msgii=0;                                           \
//   CHR08 msg[1024];                                         \
//   CHR08 timStrng[32];                                      \
//   XCCDatagramSocketSpec *spec;                             \
//                                                            \
//   memset(timStrng, 90, 32);                                \
//   XCC_CURRENT_ASCII_TIME( timStrng, "%G:%m:%d::%H:%M:%S" );\
//   sprintf(&msg[msgii],"******************************************************************\n");\
//   msgii = strlen(msg);                                     \
//   sprintf(&msg[msgii],"** ERROR                                                          \n");\
//   msgii = strlen(msg);                                     \
//   sprintf(&msg[msgii],"******************************************************************\n");\
//   msgii = strlen(msg);                                     \
//   sprintf(&msg[msgii], "%s: ", __FILE__);                  \
//   msgii = strlen(msg);                                     \
//   sprintf(&msg[msgii], "%s: ", timStrng);                  \
//   msgii = strlen(msg);                                     \
//   sprintf(&msg[msgii], format, ##args);                    \
//   msgii = strlen(msg);                                     \
//                                                            \
//   spec = iccDatagramSocketSendInit(DEBUG_HOST, DEBUG_PORT);\
//   iccDatagramSocketSend(msg,msgii,spec);                   \
//   iccDatagramSocketTerm( spec );                           \
// }

// #define XCC_DEBUG_APACHE(format, args...)                  \
// {                                                          \
//   CHR08 timStrng[32];                                      \
//   memset(timStrng, 90, 32);                                \
//   fprintf(stderr, "%s: ", __FILE__);                       \
//   fprintf(stderr, format, ##args);                         \
// }

/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
