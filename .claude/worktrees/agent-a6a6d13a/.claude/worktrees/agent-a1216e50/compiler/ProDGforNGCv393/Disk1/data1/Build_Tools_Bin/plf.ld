/*
 * Copyright © 2000-2001 SN Systems Software Limited
 * All Rights Reserved
 * Description : 
 *
 *  SN Systems Ltd : File Revision History
 *
 *  $Archive: /Dolphin/makerel/SDK/plf.ld $
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
	}
	.ctors 
	{
        	*(.ctors)
	}
	.dtors 
	{
        	*(.dtors)
	}
    	.rodata 
	{
		*(.rodata)
	}
        .data 
	{
		*(.data)
	}
	.bss 
	{
        	*(.bss)
	}
 }
}
