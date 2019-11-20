// -----------------------------------------------------------------------------
// Copyright (c) 2018                  Qualcomm Technologies International, Ltd.
//
#ifndef __SBC_ENCODE_GEN_ASM_H__
#define __SBC_ENCODE_GEN_ASM_H__

// CodeBase IDs
.CONST $M.SBC_ENCODE_SBCENC_CAP_ID       	0x0014;
.CONST $M.SBC_ENCODE_SBCENC_ALT_CAP_ID_0       	0x4060;
.CONST $M.SBC_ENCODE_SBCENC_SAMPLE_RATE       	0;
.CONST $M.SBC_ENCODE_SBCENC_VERSION_MAJOR       	0;

// Constant Values


// Piecewise Disables


// Statistic Block
.CONST $M.SBC_ENCODE.STATUS.SAMPLING_FREQUENCY		0*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.STATUS.CHANNEL_MODE      		1*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.STATUS.BITPOOL           		2*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.STATUS.NUM_BLOCKS        		3*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.STATUS.NUM_CHANNELS      		4*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.STATUS.NUM_SUBBANDS      		5*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.STATUS.ALLOC_METHOD      		6*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.STATUS.BLOCK_SIZE             	7;

// Parameter Block
.CONST $M.SBC_ENCODE.PARAMETERS.OFFSET_CONFIG		0*ADDR_PER_WORD;
.CONST $M.SBC_ENCODE.PARAMETERS.STRUCT_SIZE 		1;


#endif // __SBC_ENCODE_GEN_ASM_H__
