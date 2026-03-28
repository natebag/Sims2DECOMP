/*
 * Copyright © 2000-2001 SN Systems Software Limited
 * All Rights Reserved
 * Description : 
 *
 *  SN Systems Ltd : File Revision History
 *
 *  $Archive: /Dolphin/makerel/SDK/preplf.ld $
 *
 *  Last Modified 
 *  $Date: 22/10/01 11:28 $ by $Author: Bill $
 *
 *	$Revision: 2 $
 * 
 *  $NoKeywords: $
 *
 */

SECTIONS
{
	OVERLAY :
{
	.init 
	{
		*(.init)
	}
        .text 
	{
        	*(.text)
		*(.gnu.linkonce.t.*)
	}
	.ctors 
	{
		_ctors = .;
        	*(.ctors)
		LONG(0);
	}
	.dtors 
	{
		_dtors = .;
        	*(.dtors)
		LONG(0);
	}
    	.rodata 
	{
		*(.rodata)
	}
        .data 
	{
		*(.data)
		*(.gnu.linkonce.d.*)
	}
	.bss 
	{
        	*(.bss)
        	*(.sbss)
        	*(.sbss2)
		*(COMMON)
		*(.scommon)
	}
 }
}
