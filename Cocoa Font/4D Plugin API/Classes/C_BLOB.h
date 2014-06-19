/*
 *  C_BLOB.h
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#ifndef __C_BLOB_H__
#define __C_BLOB_H__ 1

#include "4DPluginAPI.h"
	
#ifdef __cplusplus
extern "C" {
#endif
	
	class CBytes
	{
		
	private:
		
		std::vector<uint8_t> _CBytes;		
		
	public:
		
		void fromParamAtIndex(PackagePtr pParams, uint32_t index);
		void toParamAtIndex(PackagePtr pParams, uint32_t index);	
		void setReturn(sLONG_PTR *pResult);	
		
		void setBytes(const uint8_t *bytes, uint32_t len);
		void addBytes(const uint8_t *bytes, uint32_t len);
		
		const uint8_t *getBytesPtr();
		uint32_t getBytesLength();	
		
		CBytes();	
		~CBytes();
		
	};
	
	class C_BLOB
	{
		
	private:
		
		CBytes* _CBytes;
		
	public:
		
		void fromParamAtIndex(PackagePtr pParams, uint32_t index);
		void toParamAtIndex(PackagePtr pParams, uint32_t index);	
		void setReturn(sLONG_PTR *pResult);		
		
		void setBytes(const uint8_t *bytes, uint32_t len);
		void addBytes(const uint8_t *bytes, uint32_t len);
		
		const uint8_t *getBytesPtr();
		uint32_t getBytesLength();		
		
		C_BLOB();
		~C_BLOB();
		
	};
	
#ifdef __cplusplus
}
#endif

#endif