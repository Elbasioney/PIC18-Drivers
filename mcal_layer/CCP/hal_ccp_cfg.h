/* 
 * File:   hal_ccp_cfg.h
 * Author: Ahmed Elbasioney
 *
 * Created on May 7, 2023, 9:25 PM
 */

#ifndef HAL_CCP_CFG_H
#define	HAL_CCP_CFG_H

/*                                        includes                          */


/*                                            macros                         */



#define CCP_CFG_CAPTURE_MODE_SELECTED   0x00
#define CCP_CFG_COMPARE_MODE_SELECTED   0x01
#define CCP_CFG_PWM_MODE_SELECTED       0x02

#define CCP1_CFG_SELECTED_MODE   (CCP_CFG_PWM_MODE_SELECTED)
#define CCP2_CFG_SELECTED_MODE   (CCP_CFG_PWM_MODE_SELECTED)

/*                                        macro like functions                */

/*                                           data types                       */

/*                                            functions                       */


#endif	/* HAL_CCP_CFG_H */

