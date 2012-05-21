/*
$Id$
    OWFS -- One-Wire filesystem
    OWHTTPD -- One-Wire Web Server
    Written 2003 Paul H Alfille
	email: palfille@earthlink.net
	Released under the GPL
	See the header file: ow.h for full attribution
	1wire/iButton system from Dallas Semiconductor
*/

#include <config.h>
#include "owfs_config.h"
#include "ow.h"
#include "ow_counters.h"
#include "ow_connection.h"
#include "ow_codes.h"
#include "ow_external.h"

static void External_setroutines(struct connection_in *in);

static void External_setroutines(struct connection_in *in)
{
	in->iroutines.detect = External_detect;
	in->iroutines.reset = NO_RESET_ROUTINE ;
	in->iroutines.next_both = NO_NEXT_BOTH_ROUTINE;
	in->iroutines.PowerByte = NO_POWERBYTE_ROUTINE;
    in->iroutines.ProgramPulse = NO_PROGRAMPULSE_ROUTINE;
	in->iroutines.sendback_data = NO_SENDBACKDATA_ROUTINE ;
	in->iroutines.sendback_bits = NO_SENDBACKBITS_ROUTINE;
	in->iroutines.select = NO_SELECT_ROUTINE ;
	in->iroutines.select_and_sendback = NO_SELECTANDSENDBACK_ROUTINE;
	in->iroutines.reconnect = NO_RECONNECT_ROUTINE;
	in->iroutines.close = NO_CLOSE_ROUTINE;
	in->iroutines.flags = 0 ;
	in->bundling_length = 1;
}

GOOD_OR_BAD External_detect(struct connection_in *in)
{
	External_setroutines(in);
	in->Adapter = adapter_external;
	in->adapter_name = "External";
	return gbGOOD ;
}