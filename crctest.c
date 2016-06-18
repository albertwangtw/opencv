/*---------------------------------------------------------

---------------------------------------------------------*/
#include <stdio.h>
#include "hdlccrc8.h"

typedef unsigned char	BYTE;
typedef unsigned int	WORD;
typedef unsigned long	DWORD;

/*---------------------------------------------------------

---------------------------------------------------------*/


void main()
{
	BYTE crc;
	BYTE pollack[4] = {0x05, 0x51, 0xBF, 0x06};	

	crc = HdlcCrc8(pollack, 4);
	printf("\r\n -- The CRC result : 0x%x 0x%x\r\n", crc, (crc ^= 0xFF));

	pollack[3] = 0x07;
	crc = HdlcCrc8(pollack, 4);
	printf("\r\n -- The CRC result : 0x%x 0x%x\r\n", crc, (crc ^= 0xFF));

}
