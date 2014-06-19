/*
 *  C_BLOB.cpp
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#include "C_BLOB.h"

void CBytes::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)
	{		
		PA_Handle h = *(PA_Handle *)(pParams[index - 1]);
		unsigned int size = PA_GetHandleSize(h);
		
		this->_CBytes.resize(size);
		
		PA_MoveBlock(PA_LockHandle(h), (char *)&this->_CBytes[0], size);		
		PA_UnlockHandle(h);
	}
}

void CBytes::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)
	{
		PA_Handle *h = (PA_Handle *)(pParams[index - 1]);
		
		if (*h) PA_DisposeHandle(*h);
				
		PA_Handle d = PA_NewHandle((unsigned int)this->_CBytes.size());
		PA_MoveBlock((char *)&this->_CBytes[0], PA_LockHandle(d), (unsigned int)this->_CBytes.size());
		PA_UnlockHandle(d);
		
		*h = d;
	}
}

void CBytes::setBytes(const uint8_t *bytes, unsigned int len)
{	
	if(bytes)
	{
		this->_CBytes.resize(len);
		PA_MoveBlock((void *)bytes, (char *)&this->_CBytes[0], len);	
	}
}

void CBytes::addBytes(const uint8_t *bytes, unsigned int len)
{	
	if(bytes)
	{
		unsigned int originalSize = this->_CBytes.size();
		this->_CBytes.resize(originalSize + len);
		PA_MoveBlock((void *)bytes, (char *)&this->_CBytes[originalSize], len);	
	}
}


void CBytes::setReturn(sLONG_PTR *pResult)
{
	PA_Handle *h = (PA_Handle *)pResult;
	
	PA_Handle d = PA_NewHandle((unsigned int)this->_CBytes.size());
	PA_MoveBlock((char *)&this->_CBytes[0], PA_LockHandle(d), (unsigned int)this->_CBytes.size());
	PA_UnlockHandle(d);
	
	*h = d;
}

const uint8_t *CBytes::getBytesPtr()
{
	return (const uint8_t *)&this->_CBytes[0];
}

uint32_t CBytes::getBytesLength()
{
	return (unsigned int)this->_CBytes.size();
}

CBytes::CBytes()
{	
}

CBytes::~CBytes()
{
}

void C_BLOB::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	this->_CBytes->fromParamAtIndex(pParams, index);
}

void C_BLOB::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	this->_CBytes->toParamAtIndex(pParams, index);	
}

void C_BLOB::setReturn(sLONG_PTR *pResult)
{
	this->_CBytes->setReturn(pResult);
}

void C_BLOB::setBytes(const uint8_t *bytes, unsigned int len)
{
	this->_CBytes->setBytes(bytes, len);
}

void C_BLOB::addBytes(const uint8_t *bytes, unsigned int len)
{
	this->_CBytes->addBytes(bytes, len);
}

const uint8_t *C_BLOB::getBytesPtr()
{
	return this->_CBytes->getBytesPtr();
}

uint32_t C_BLOB::getBytesLength()
{
	return this->_CBytes->getBytesLength();	
}

C_BLOB::C_BLOB() : _CBytes(new CBytes)
{
	
}

C_BLOB::~C_BLOB()
{ 
	delete _CBytes; 
}