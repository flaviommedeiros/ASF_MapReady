/*
get_ceos_names.h

Functions that match CEOS files with each other using their extensions and
testing to see if the files actually exist

*/

#ifndef _GET_CEOS_NAMES_H_
#define _GET_CEOS_NAMES_H_

#include "asf_meta.h"

/* Useful stuff for meta initialization from CEOS metadata */
typedef struct {
  struct dataset_sum_rec dssr;
  struct scene_header_rec shr;
  enum {
    unknownFacility,
    ASF,
    ESA,
    CDPF,
    EOC,
    RSI,
    JPL,
    CSTARS,
    DPAF,
    IPAF
  } facility;
  enum {
    unknownSatellite,
    ERS,
    JERS,
    RSAT,
    ALOS,
    SIR_C
  } satellite;
  enum {
    unknownSensor,
    SAR,
    PALSAR,
    AVNIR,
    PRISM
  } sensor;
  double version;/*Processor version number, or zero.*/
  enum {
    unknownProcessor,
    ASP,
    SPS,
    ARDOP,
    PREC,
    PP,
    SP2,
    AMM,
    LZP,
    FOCUS,
    SP3,
    DPS,
    MSSAR
  } processor;
  enum {
    unknownProduct,
    CCSD,
    RAW,
    LOW_REZ,
    HI_REZ,
    RAMP,
    SCANSAR,
    SLC,
    PRI,
    SGF,
    SGX,
    SGI,
    SSG,
    SPG,
    SCN,
    LEVEL_1A,
    LEVEL_1B1,
    LEVEL_1B2R,
    LEVEL_1B2G
  } product;
} ceos_description;

/* Enum & strings for ceos metadata file extensions */
typedef enum {
  NO_CEOS_METADATA=0,
  CEOS_LEA_TRA,
  CEOS_sarl_sart,
  CEOS_L,
  CEOS_LDR,
  CEOS_ldr,
  CEOS_LEA,
  CEOS_lea,
  CEOS_LED,
  NUM_CEOS_METADATA_EXTS
} ceos_metadata_ext_t;
extern const char ceos_metadata_extensions[][12];

/* Enum & strings for ceos data file extensions */
typedef enum {
  NO_CEOS_DATA=0,
  CEOS_DAT_,
  CEOS_sard,
  CEOS_D,
  CEOS_RAW,
  CEOS_raw,
  CEOS_DAT,
  CEOS_dat,
  CEOS_IMG,
  NUM_CEOS_DATA_EXTS
} ceos_data_ext_t;
extern const char ceos_data_extensions[][12];

/* Enum for pairs of ceos extensions */
typedef enum {
   NO_CEOS_FILE_PAIR=0, /* Maybe an individual match, but not a pair */
   CEOS_DAT_LEA_TRA_TRIPLE,
   CEOS_sard_sarl_sart_TRIPLE,
   CEOS_D_L_PAIR,
   CEOS_RAW_LDR_PAIR,
   CEOS_raw_ldr_PAIR,
   CEOS_DAT_LEA_PAIR,
   CEOS_dat_lea_PAIR,
   CEOS_IMG_LED_PAIR,
   NUM_CEOS_FILE_PAIRS
} ceos_file_pairs_t;


/* Given the name of a file (potentially with path in front of it), determine
   if it is a CEOS leader file (depending on our accepted CEOS extensions). If
   so populate metaName with the appropriate name and return the appropriate
   ENUM ceos_metadata_ext_t value.  */
ceos_metadata_ext_t get_ceos_metadata_name(const char *ceosName, char **metaName,
					   int *trailer);

/* If get_ceos_metadata_name fails to find a file, then exit the program.  */
ceos_metadata_ext_t require_ceos_metadata(const char *ceosName, char **metaName,
					  int *trailer);

/* Given the name of a file (potentially with path in front of it), determine
   if it is a CEOS data file (depending on our accepted CEOS extensions). If
   so, populate dataName with the appropriate name and return the appropriate
   ENUM ceos_data_ext_t value.  */
ceos_data_ext_t get_ceos_data_name(const char *ceosName, char **dataName, int *nBands);

/* If get_ceos_data_name fails to find a file, then exit the program.  */
ceos_data_ext_t require_ceos_data(const char *ceosName, char **dataName, int *nBands);

/* Given the name of a file (potentially with path in front of it), determine
   if it is one of a CEOS file pair (depending on our accepted CEOS file
   extensions). If so populate dataName & metaName with the appropriate names
   and return the appropriate ENUM ceos_file_pairs_t value.  */
ceos_file_pairs_t get_ceos_names(const char *ceosName, char **dataName,
                                 char **metaName, int *nBands, int *trailer);

/* Do as get_ceos_names unless there is no pair in which case exit the program
   with a failure.  */
ceos_file_pairs_t require_ceos_pair(const char *ceosName, char **dataName, 
				    char **metaName, int *nBands, int *trailer);


#endif