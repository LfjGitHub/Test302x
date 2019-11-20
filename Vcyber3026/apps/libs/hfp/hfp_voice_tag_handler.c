/****************************************************************************
Copyright (c) 2004 - 2015 Qualcomm Technologies International, Ltd.
Part of 6.3.0

FILE NAME
    hfp_voice_tag_handler.c

DESCRIPTION
    

NOTES

*/


/****************************************************************************
    Header files
*/
#include "hfp.h"
#include "hfp_private.h"
#include "hfp_parse.h"
#include "hfp_send_data.h"
#include "hfp_voice_tag_handler.h"
#include "hfp_common.h"
#include "hfp_link_manager.h"

#include <panic.h>
#include <string.h>


/****************************************************************************
NAME    
    hfpHandleGetVoiceTagReq

DESCRIPTION
    Issue an "attach number to a voice tag" request to the AG to retrieve
    a phone number.

RETURNS
    void
*/
bool hfpHandleGetVoiceTagReq(hfp_link_data* link)
{
    /* Only send if the AG supports this functionality, otherwise send error */
    if (agFeatureEnabled(link, AG_VOICE_TAG))
    {
        const char binp[] = "AT+BINP=1\r";

        /* Send the AT cmd over the air */
        hfpSendAtCmd(link, sizeof(binp)-1, binp, hfpBinpCmdPending);
        return TRUE;
    }
    return FALSE;
}


/****************************************************************************
NAME    
    hfpHandleDataResponse

DESCRIPTION
    Called by the autogenerated parser whanever it parses a +BINP indication
    received from the AG.

AT INDICATION
    +BINP

RETURNS
    void
*/
void hfpHandleDataResponse(Task link_ptr, const struct hfpHandleDataResponse *res)
{
    hfp_link_data* link = (hfp_link_data*)link_ptr;
    uint16 size_number  = res->num.length;
    
    if(size_number >= HFP_MAX_ARRAY_LEN)
        size_number = HFP_MAX_ARRAY_LEN - 1;
    
    if(size_number)
    {
        /* Allow room to NULL terminate string */
        MAKE_HFP_MESSAGE_WITH_LEN(HFP_VOICE_TAG_NUMBER_IND, size_number + 1);
        message->priority = hfpGetLinkPriority(link);
        message->size_phone_number = size_number;
        memmove(message->phone_number, res->num.data, size_number);
        message->phone_number[size_number] = '\0';
        MessageSend(theHfp->clientTask, HFP_VOICE_TAG_NUMBER_IND, message);
    }
}


/****************************************************************************
NAME    
    hfpHandleDataResponse

DESCRIPTION
    Called by the autogenerated parser whanever it parses a +BINP indication
    received from the AG.

AT INDICATION
    +BINP

RETURNS
    void
*/
void hfpHandleDataResponseExtended(Task link_ptr, const struct hfpHandleDataResponseExtended *res)
{
    struct hfpHandleDataResponse response;
    response.num = res->num;
    hfpHandleDataResponse(link_ptr, &response);
}
