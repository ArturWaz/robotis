/*
 * _base_FT232.h
 *
 *  Created on: Jul 7, 2015
 *      Author: szymek
 */

#ifndef BASE_FT232R_H_
#define BASE_FT232R_H_

#include <cstdint>
#include "ftdi/ftd2xx.h"

#ifndef CAST_TO_LPDWORD
#define CAST_TO_LPDWORD(value) static_cast<DWORD*>(static_cast<void*>(value))
#endif

/*
 *  Wrapper class (from c language)
 */
class _base_FT232R {
public:

	FT_HANDLE handle_;

	_base_FT232R(): handle_(nullptr) {}

	inline FT_STATUS open(void *pArg1, std::uint32_t Flags) {
		return FT_OpenEx(pArg1,Flags,&handle_); }
	inline FT_STATUS close() {
		return FT_Close(handle_); }
	inline FT_STATUS resetDevice() {
		return FT_ResetDevice(handle_); }

	inline FT_STATUS setBaudRate(std::uint32_t BaudRate) {
		return FT_SetBaudRate(handle_,BaudRate); }
	inline FT_STATUS setDataCharacteristics(std::uint8_t WordLength, std::uint8_t StopBits, std::uint8_t Parity) {
		return FT_SetDataCharacteristics(handle_,WordLength,StopBits,Parity); }

	inline FT_STATUS getQueueStatus(std::uint32_t *RxBytes) {
		return FT_GetQueueStatus(handle_,CAST_TO_LPDWORD(RxBytes)); }
	inline FT_STATUS getStatus(std::uint32_t *RxBytes, std::uint32_t *TxBytes, std::uint32_t *EventDWord) {
		return FT_GetStatus(handle_,CAST_TO_LPDWORD(RxBytes),CAST_TO_LPDWORD(TxBytes),CAST_TO_LPDWORD(EventDWord)); }

	inline FT_STATUS purge(std::uint32_t Mask) {
		return FT_Purge(handle_,Mask); }
	inline FT_STATUS read(std::uint8_t *Buffer, std::uint32_t BytesToRead, std::uint32_t *BytesReturned) {
		return FT_Read(handle_,Buffer,BytesToRead,CAST_TO_LPDWORD(BytesReturned)); }
	inline FT_STATUS write(std::uint8_t *Buffer, std::uint32_t BytesToWrite, std::uint32_t *BytesWritten) {
		return FT_Write(handle_,Buffer,BytesToWrite,CAST_TO_LPDWORD(BytesWritten)); }

};


#endif /* BASE_FT232_H_ */
