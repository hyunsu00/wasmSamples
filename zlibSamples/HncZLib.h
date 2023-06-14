#ifndef __HNCZLIB_H__
#define __HNCZLIB_H__
#pragma once

#define Z_BUFSIZE	1024 * 16	// 16384 
#define RWSIZE		4096

#include <zlib.h>

typedef void* HGZCMP;

typedef int (*PFNGZCMPR)(HGZCMP hGZ, const void *pUser, void *buf, unsigned int len);
typedef int (*PFNGZCMPW)(HGZCMP hGZ, const void *pUser, const void *buf, unsigned int len);

// return NULL on error
HGZCMP HncGZOpenRead(PFNGZCMPR pfnReader, const void *pUser);
HGZCMP HncGZOpenReadOfCustomMem(PFNGZCMPR pfnReader, const void *pUser);
int HncGZRead(HGZCMP hGZ, void *buf, unsigned int len);
int HncGZReadEx(HGZCMP hGZ, void* buf, unsigned int len, unsigned int& bufSize);
int HncGZCloseRead(HGZCMP hGZ);
uint32_t HncGZUpdateCRC(uint32_t *pInCRC, const void *buf, unsigned int len);


typedef struct tagZHandle {
	z_stream		stream;			// 압축 데이터 스트림
//	PFNGZCMPW		write_func;		// write 함수
	PFNGZCMPR		read_func;		// read 함수
	const void		*pUser;			// 파일 포인터
	void			*databuf;
	void			*inbuf;
	unsigned int	inlen;			// 현재 inbuf의 데이터 길이
	unsigned int	datalen;
	unsigned int	writepos;
	unsigned int	total_in;		// 압축시 원본데이터의 전체 크기
	uint32_t		crc;			// crc 결과
	uint32_t		crc_in;
} ZHandle, *LPZHandle;


#endif

