/*
 *  Filename: MID_CAN_Interface.h
 *
 *  Created on: 11-08-2024
 *      Author: Ndhieu131020@gmail.com
*/

#ifndef MID_CAN_INTERFACE_H_
#define MID_CAN_INTERFACE_H_

/*******************************************************************************
 * Include
 ******************************************************************************/

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define FLEXCAN_INSTANCE        0u

/** @defgroup Initialize Connection Message ID
  * @{
  */
#define RX_MSG_CONNECTION_ID            0xF0
#define TX_MSG_CONFIRM_CONNECTION_ID    0xF1

/** @defgroup Ping Message ID
  * @{
  */
#define RX_PING_MSG_ID       0x60
#define TX_CONFIRM_PING_ID   0x61

/** @defgroup Data ID
  * @{
  */
#define TX_MSG_ROTATION_DATA_ID   0x10
#define RX_MSG_CONFIRM_DATA_ID    0x11

/** @defgroup Stop operation Message ID
  * @{
  */
#define RX_MSG_STOPOPR_ID       0x40
#define TX_CONFIRM_STOPOPR_ID   0x41

#define RX_MSG_STOP_OPR_DATA    0x10
#define RX_MSG_RESUME_OPR_DATA  0xFF


#define TX_MSG_CONFIRM_CONNECTION_DATA  0xFF

/** @defgroup Allocate Tx mailboxs
  * @{
  */
#define TX_ROTATION_DATA_MB        0u
#define TX_CONFIRM_CONNECTION_MB   1u
#define TX_CONFIRM_STOPOPR_MB      2u
#define TX_CONFIRM_PING_MB         3u

/** @defgroup Allocate Rx mailboxs
  * @{
  */
#define RX_STOPOPR_MB       4u
#define RX_CONNECTION_MB    5u
#define RX_CONFIRM_DATA_MB  6u
#define RX_PING_MSG_MB      7u

/** @defgroup CAN comming message state
  * @{
  */
#define CAN_MSG_RECEIVED      1u
#define CAN_MSG_NO_RECEIVED   0u

typedef struct MID_CAN_Interface
{
    uint32_t ID;
    uint32_t Data;
}Data_Typedef;

/*******************************************************************************
 * API
 ******************************************************************************/

void MID_CAN_Init(void);

void MID_CAN_MailboxInit(void);

void MID_CAN_RegisterRxNotificationCallback(void (*cb_ptr)(void));

void MID_CAN_ReceiveMessage(uint8_t mbIdx, Data_Typedef *data);

void MID_CAN_SendCANMessage(uint8_t Tx_Mb, uint16_t Data);

void MID_ClearMessageCommingEvent(uint8_t Mailbox);

uint8_t MID_CheckCommingMessageEvent(uint8_t Mailbox);

#endif /* MID_CAN_INTERFACE_H_ */
